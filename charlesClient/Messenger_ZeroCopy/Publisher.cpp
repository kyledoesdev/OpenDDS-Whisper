/*
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include <ace/Log_Msg.h>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include "dds/DCPS/StaticIncludes.h"

#include "MessengerTypeSupportImpl.h"

#include "json.hpp"
#include <string>

#include <cstdint>
#include <iostream>
#include <memory>
#include "curl/curl.h"
#include <json/json.h>

namespace
{
    std::size_t callback(
        const char* in,
        std::size_t size,
        std::size_t num,
        std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}


int ACE_TMAIN(int argc, ACE_TCHAR* argv[]) {

    BOOLEAN isLocationEnabled = true;
    const char* myBusinessName = "";
    double BusinessRating = 0;
    // double myBusinessDistance = dblBusinessDistance / 1609.344;
    const char* myBusinessReviewCount = "";
    double myBusinessDistance = 0;
    const char* myBusinessDistanceString = "";
    const char* myBusinessAlias = "";
    int reviewCount = 0;
    const char* myBusinessAddress1 = "";
    const char* myBusinessCity = "";
    const char* myBusinessState = "";
    const char* myBusinessZipCode = "";
    const char* myBusinessPhoneNum = "";
    std::string myBusinessPhoneNumString = "";
    BOOLEAN myBusinessIsOpen = true;
    int resultsReturned = 0;
    int resultsLimit = 0;

    std::string searchURL = "https://api.yelp.com/v3/businesses/search?term=";
    std::string in;
    std::string answer = "";
    std::string myLocation = "";
    std::string publishing_term = "";

    do {
        std::string searchURL = "https://api.yelp.com/v3/businesses/search?term=";
        std::cout << "Please input a search term\n";
        std::cin >> in;
        publishing_term = in;
        char* converted_term = const_cast<char*>(publishing_term.c_str());
        searchURL = searchURL + in;
        if (isLocationEnabled) {
            std::cout << "Please input your location\n";
            std::cin >> in;
            myLocation = in;
            searchURL = searchURL + "&location=" + in;
        }
        else {
            std::cout << "Please input a latitude (ex 39.7029)\n";
            std::cin >> in;
            searchURL = searchURL + "&latitude=" + in;
            std::cout << "Please input a longitude (ex 75.1118)\n";
            std::cin >> in;
            searchURL = searchURL + "&longitude=" + in;
        }
        do {
            std::cout << "Please input the max amount of results you would like (Max 50)\n";
            std::cin >> in;
        } while (std::stoi(in) > 50);

        resultsLimit = std::stoi(in);
        searchURL = searchURL + "&limit=" + in;
        std::cout << "Please input a suggested search radius (max is 40000)\n";
        std::cin >> in;
        //for debug
        if (in == "0") { in = ""; }
        searchURL = searchURL + "&radius=" + in;

        Json::Reader jsonReader;
        Json::Value jsonData;

        CURL* req = curl_easy_init();
        if (req) {
            curl_easy_setopt(req, CURLOPT_URL, searchURL.c_str());
            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, "Authorization: Bearer 8uZBQKRUxpFZJG65jmtQCgCVwzsDjwYHi06qI1wvuPi1PCdKadGQKKcYhOpvl5ITMDHUScQHZ62xH19F9LB52UH0UJWQ_tFUqDyC88-PUjoT1nLRmGLHQ1t2t0lyYXYx");
            curl_easy_setopt(req, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(req, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(req, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
            curl_easy_setopt(req, CURLOPT_TIMEOUT, 10);
            curl_easy_setopt(req, CURLOPT_FOLLOWLOCATION, 1L);

            // Response information.
            long httpCode(0);
            std::unique_ptr<std::string> httpData(new std::string());
            curl_easy_setopt(req, CURLOPT_WRITEFUNCTION, callback);
            curl_easy_setopt(req, CURLOPT_WRITEDATA, httpData.get());
            curl_easy_perform(req);
            curl_easy_getinfo(req, CURLINFO_RESPONSE_CODE, &httpCode);
            curl_easy_cleanup(req);

            try {

                if (jsonReader.parse(*httpData.get(), jsonData)) 
                {
                    std::cout << jsonData << std::endl;
                }

                // Initialize DomainParticipantFactory
                DDS::DomainParticipantFactory_var dpf =
                    TheParticipantFactoryWithArgs(argc, argv);

                // Create DomainParticipant
                DDS::DomainParticipant_var participant =
                    dpf->create_participant(42,
                        PARTICIPANT_QOS_DEFAULT,
                        DDS::DomainParticipantListener::_nil(),
                        OpenDDS::DCPS::DEFAULT_STATUS_MASK);

                if (CORBA::is_nil(participant.in())) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" create_participant failed!\n")),
                        -1);
                }

                // Register TypeSupport (Messenger::Message)
                Messenger::MessageTypeSupport_var ts =
                    new Messenger::MessageTypeSupportImpl();

                if (ts->register_type(participant.in(), "") != DDS::RETCODE_OK) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" register_type failed!\n")),
                        -1);
                }

                // Create Topic (Movie Discussion List)
                CORBA::String_var type_name = ts->get_type_name();
                DDS::Topic_var topic =
                    participant->create_topic(converted_term,
                        type_name.in(),
                        TOPIC_QOS_DEFAULT,
                        DDS::TopicListener::_nil(),
                        OpenDDS::DCPS::DEFAULT_STATUS_MASK);

                if (CORBA::is_nil(topic.in())) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" create_topic failed!\n")),
                        -1);
                }

                // Create Publisher
                DDS::Publisher_var publisher =
                    participant->create_publisher(PUBLISHER_QOS_DEFAULT,
                        DDS::PublisherListener::_nil(),
                        OpenDDS::DCPS::DEFAULT_STATUS_MASK);

                if (CORBA::is_nil(publisher.in())) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" create_publisher failed!\n")),
                        -1);
                }

                // Create DataWriter
                DDS::DataWriter_var writer =
                    publisher->create_datawriter(topic.in(),
                        DATAWRITER_QOS_DEFAULT,
                        DDS::DataWriterListener::_nil(),
                        OpenDDS::DCPS::DEFAULT_STATUS_MASK);

                if (CORBA::is_nil(writer.in())) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" create_datawriter failed!\n")),
                        -1);
                }

                Messenger::MessageDataWriter_var message_writer =
                    Messenger::MessageDataWriter::_narrow(writer.in());

                if (CORBA::is_nil(message_writer.in())) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" _narrow failed!\n")),
                        -1);
                }

                // Block until Subscriber is available
                DDS::StatusCondition_var condition = writer->get_statuscondition();
                condition->set_enabled_statuses(DDS::PUBLICATION_MATCHED_STATUS);

                DDS::WaitSet_var ws = new DDS::WaitSet;
                ws->attach_condition(condition);

                DDS::ConditionSeq conditions;
                DDS::PublicationMatchedStatus matches = { 0, 0, 0, 0, 0 };
                DDS::Duration_t timeout = { 300, 0 };

                do {
                    if (ws->wait(conditions, timeout) != DDS::RETCODE_OK) {
                        //ACE_ERROR_RETURN((LM_ERROR,
                           // ACE_TEXT("ERROR: %N:%l: main() -")
                            //ACE_TEXT(" wait failed!\n")),
                            //-1);
                        std::cout << "No subscribers online waiting for this after 30 seconds!" << std::endl;
                    }

                    if (writer->get_publication_matched_status(matches) != ::DDS::RETCODE_OK) {
                        ACE_ERROR_RETURN((LM_ERROR,
                            ACE_TEXT("ERROR: %N:%l: main() -")
                            ACE_TEXT(" get_publication_matched_status failed!\n")),
                            -1);
                    }

                } while (matches.current_count < 1);

                ws->detach_condition(condition);

                if (jsonReader.parse(*httpData.get(), jsonData)) {
                    std::cout << jsonData << std::endl;
                    resultsReturned = jsonData["total"].asInt();
                    if (resultsLimit < resultsReturned) {
                        resultsReturned = resultsLimit;
                    }
                    if (resultsReturned == 0) {
                        std::cout << "No results were returned for that Location and Search Term!" << std::endl;
                    }
                    else {
                        for (int i = 0; i < resultsReturned; i++) {
                            myBusinessName = jsonData["businesses"][i]["name"].asCString();
                            BusinessRating = jsonData["businesses"][i]["rating"].asFloat();
                            //BusinessRating = round(BusinessRating * 100.0) / 100.0;
                            reviewCount = jsonData["businesses"][i]["review_count"].asInt();
                            myBusinessDistance = jsonData["businesses"][i]["distance"].asDouble();
                            myBusinessDistance = myBusinessDistance / 1609.344;
                            myBusinessDistance = round(myBusinessDistance * 10.0) / 10.0;
                            myBusinessPhoneNumString = jsonData["businesses"][i]["display_phone"].asString();
                            myBusinessAddress1 = jsonData["businesses"][i]["location"]["address1"].asCString();
                            myBusinessCity = jsonData["businesses"][i]["location"]["city"].asCString();
                            myBusinessState = jsonData["businesses"][i]["location"]["state"].asCString();
                            myBusinessZipCode = jsonData["businesses"][i]["location"]["zip_code"].asCString();
                            myBusinessIsOpen = !jsonData["businesses"][i]["is_closed"].asBool();
                            const char* myBusinessIsOpenString;
                            if (myBusinessIsOpen == true)
                            {
                                myBusinessIsOpenString = "Open";
                            }
                            else { myBusinessIsOpenString = "Closed"; }

                            std::string BusinessRatingString = std::to_string(BusinessRating);
                            const char* myBusinessRating = BusinessRatingString.c_str();
                            std::string BusinessReviewCount = std::to_string(reviewCount);
                            myBusinessReviewCount = BusinessReviewCount.c_str();
                            std::string BusinessDistance = std::to_string(myBusinessDistance);
                            const char* myBusinessDistanceString = BusinessDistance.c_str();

                            Messenger::Message message;
                            message.Name = myBusinessName;
                            message.rating = BusinessRating;
                            message.reviews = myBusinessReviewCount;
                            message.distance = myBusinessDistance;
                            message.address = myBusinessAddress1;
                            message.city = myBusinessCity;
                            message.zip = myBusinessZipCode;
                            message.state = myBusinessState;
                            message.count = reviewCount;
                            message.isOpen = myBusinessIsOpenString;
                            message.myLocation = myLocation.c_str();
                            if (myBusinessPhoneNumString.empty())
                            {
                                message.phoneNum = "";
                            }
                            else {
                                myBusinessPhoneNum = myBusinessPhoneNumString.c_str();
                                std::string formattedString("      ");
                                formattedString.append(myBusinessPhoneNum);
                                formattedString.append("\n");
                                message.phoneNum = formattedString.c_str();
                                //message.phoneNum = strcat(myBusinessPhoneNum, "are ");
                            }
                            

                            DDS::ReturnCode_t error = message_writer->write(message, DDS::HANDLE_NIL);

                            if (error != DDS::RETCODE_OK) {
                                ACE_ERROR((LM_ERROR,
                                    ACE_TEXT("ERROR: %N:%l: main() -")
                                    ACE_TEXT(" write returned %d!\n"), error));
                            }
                        }
                        std::cout << "Your Messages were recieved and sent!" << std::endl;
                    }
                }

                // Wait for samples to be acknowledged
                if (message_writer->wait_for_acknowledgments(timeout) != DDS::RETCODE_OK) {
                    ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT("ERROR: %N:%l: main() -")
                        ACE_TEXT(" wait_for_acknowledgments failed!\n")),
                        -1);
                }

            }
            catch (const CORBA::Exception& e) {
                e._tao_print_exception("Exception caught in main():");
                return -1;
            }

            std::cout << "Submit another request? Enter yes/no" << std::endl;
            std::cin >> answer;
        }
    } while (answer == "yes");
    // Clean-up!
    //participant->delete_contained_entities();
    //dpf->delete_participant(participant.in());
    TheServiceParticipant->shutdown();

    return 0;
}