<!--
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership. The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License. You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

-->

Apache River Examples - README
=====================

This project contains a set of examples that show how to use Apache River.

## Building the examples

The project uses Apache Maven to manage the dependencies and build the examples.
There is no need to download and build the main River distribution or tools;
the River artifacts are deployed to Maven Central, so Maven will automatically
download the binary artifacts as needed for the examples build.

You'll need Apache Maven 3.2.5 or later installed.  See [Apache Maven](http://maven.apache.org).

To build the examples, simply unpack the source distribution of 'river-examples',
and then,

    cd river-examples
    mvn install
    mvn site

Once the site is built, please read the project documentation at 
[target/site/index.html](target/site/index.html).

##Note on IDE's:

This project can be built using an IDE that supports Maven.

At time of writing (April 2015) NetBeans and Eclipse both include an earlier
version of Maven that doesn't process Markdown files.  To build this tutorial 
in either of these IDE's, you'll need to download the latest Maven and then 
configure the IDE to use the external Maven rather than the bundled version.

- Download Maven 3.2.5 from http://maven.apache.org/download.cgi.  If you’re on 
Windows, download the zip file.  If on Linux/Unix, get the “.tar.gz”.  
- Unpack it to a convenient directory (Windows: right-click on the zip and 
select “Extract all”.  OSX: Just open the tar.gz file.  *nix: should be something 
like ‘tar xvzf apache-maven-3.2.5.bin.tar.gz /usr/local/apache-maven-3.2.5  
- In Netbeans, select Preferences (OSX: Netbeans —> Preferences.  Windows: 
Tools —> Options) then select the “Maven” tab) and then set the Maven Home 
field to point to your local installation.  
- In Eclipse, select Window -> Preferences -> Maven -> Installations, and then
click "Add" to add the external Maven instalallation.

At the top-level project, use the IDE's menus to execute the Maven goals 
"install" and "site".
