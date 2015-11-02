#!/usr/bin/env bash

echo "Installing: ( 1 ) java 7"

# Add repository:
#   It's add the repository of packages related of Java
#
echo "Install Java: Adding repository"
sudo add-apt-repository ppa:webupd8team/java -y >>/tmp/provision-script.log 2>&1

# Update the packages
#
echo "Install Java: updating packages"
sudo apt-get update -y >>/tmp/provision-script.log 2>&1

# Accept Licenses
#
echo oracle-java7-installer shared/accepted-oracle-license-v1-1 select true | /usr/bin/debconf-set-selections

# Install Java 8
#
echo "Install Java: starting"
sudo apt-get install oracle-java7-installer -y >>/tmp/provision-script.log 2>&1
echo "Install Java: DONE"
