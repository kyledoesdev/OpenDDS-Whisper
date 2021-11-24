# Whipser 
## An OpenDDS Prototype Application

Currently this Prototype functions on Windows 10x64 and this setup readme will explain
how to configure the app for that specific OS.

## Prerequisites
* [OpenDDS Version 3.18.1 + ](https://opendds.org/quickstart/GettingStartedWindows.html)
* [Strawberry Perl](https://strawberryperl.com/)
* [Visual Studios 2019 Community with C++](https://visualstudio.microsoft.com/downloads/)
* [libcurl](https://github.com/curl/curl) by following the guide here: (https://medium.com/@farhabihelal/how-to-set-up-libcurl-on-visual-studio-2019-a9fdacce6945)
* [Yelp fusion Developer Account](https://fusion.yelp.com/)

### Be sure all of these dependencies are added to your PATH variable

## First we will conquer OpenDDS
* Unzip the downloaded zip archive
* Start a Visual Studios Command Prompt. 
  - Do this by starting visual studios without code
  - Go to properties -> command line
  - Launch a developer command line
> cd /d <i>DDS_ROOT</i>

> configure

This may take a moment

> devenv DDS_TAO.sln

Another Visual Studios IDE will open.

> Build -> Build Solution

<B>This will take a little while</B>
This also occasionaly fails on building.
If it does, the best thing I've found to do is to repeat the entire sequence over again

If the build is succesful, go back to you command line instance. 

> setenv.cmd

> cd DevGuideExamples\DCPS\Messenger

> perl run_test.pl

If this test runs succesfully, then OpenDDS has been configured succesfully.

## Get a Yelp Fusion API Key

* Sign up on Yelp Fusion's website and get a developer API Key

## Now for configuring the Whisper Prototype
* If you haven't already, clone this repo.
* Copy the Client Folder into <i>DDS_ROOT</i>/DevGuideExamples/DCPS/
* In a visual studios command line (explained how to access earlier)
* cd /d <i>DDS_ROOT</i>\DevGuideExamples\DCPS\Client
* create a file named key.txt
* Paste your Yelp Fusion API Key into that file.

## The project should be built properly but you may need to manually set libcurl as a project dependency. (Reference above)

You should now be able to test the application by running
> server.bat

> publisher.bat

> subscriber.bat

# See the (Coming Soon) video on a successful instalation
