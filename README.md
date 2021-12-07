# Data-Distribution-Service-DDS
RI:  Kevin Tooley       KTooley@asrcfederal.com 

Students will develop a server application that feeds data, via an OpenDDS service, to multiple clients.  After receiving a DDS request from the clients, the server will fetch data from Yelp using the appropriate application program interface (API), package the data, and return it to the client via DDS.  The server application will utilize a command line interface (CLI) at a minimum, with the option to add a front-end graphical user interface (GUI).  The client will provide a GUI as the primary method of input with CLI permitted for testing and administration.  The team will gain knowledge and experience with JavaScript Object Notation (JSON), developing a data distribution service, and utilizing an API from a data factory.    

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

Next run configure.cmd

> configure

This may take a moment

If running configure.cmd fails, you may have Strawberry Perl not properly added to your path. Double check this.
If it is added to your Path try restarting your machine if you just installed Strawberry Perl.
Otherwise, try re-installing it.

Next we will build the solution

> devenv DDS_TAO.sln

Another Visual Studios IDE will open.
Navigate to

> Build -> Build Solution

<B>This will take a little while</B>
This also occasionaly fails on building.
If it does, try building it again, if it still fails the best thing I've found to do is to repeat the entire sequence over again

If the build is succesful, go back to you command line instance. 

> setenv.cmd

> cd DevGuideExamples\DCPS\Messenger

> perl run_test.pl

If this test runs succesfully, then OpenDDS has been configured succesfully.

## Get a Yelp Fusion API Key

* Sign up on Yelp Fusion's website and get a developer API Key

## Now for configuring the Whisper Prototype
* If you haven't already, clone this repo.
* Copy and paste the <B>FILES</B> from the Client Folder into <i>DDS_ROOT</i>/DevGuideExamples/DCPS/Messenger_ZeroCopy
* In a visual studios command line (explained how to access earlier)
* cd /d <i>DDS_ROOT</i>\DevGuideExamples\DCPS\Messenger_ZeroCopy
* create a file named key.txt
* Paste your Yelp Fusion API Key into that file with no spaces or sybmols before or after pasting, just the key that was given to you.

## The project should be built already so all you need to run is:

You should now be able to test the application by running
> server.bat

> publisher.bat

> subscriber.bat

# See the video below on a successful instalation
[Link to youtube video](https://www.youtube.com/watch?v=U47jY-IYkIc)
