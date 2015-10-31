#!/usr/bin/env bash

echo "Installing: ( 1 ) g++, ( 2 ) flex and ( 3 ) bison"

# Install g++:
#   g++ is a compiler to C++
#
echo "Install g++: starting"
sudo apt-get install g++ -y >>/tmp/provision-script.log 2>&1
echo "Install g++: DONE"

# Install flex:
#   Recognize lexical standards
#
echo "Install flex: starting"
sudo apt-get install flex -y >>/tmp/provision-script.log 2>&1
echo "Install flex: DONE"

# Install flex++:
#   Recognize lexical standards and create a parser in C++
#
echo "Install flex++: starting"
sudo apt-get install flex++ -y >>/tmp/provision-script.log 2>&1
echo "Install flex++: DONE"

# Install bison:
#   Generator of interpreter of languages
#
echo "Install bison: starting"
sudo apt-get install bison -y >>/tmp/provision-script.log 2>&1
echo "Install bison: DONE"

# Install bison++:
#   Generator of interpreter of languages and create a parser in C++
#
echo "Install bison++: starting"
sudo apt-get install bison++ -y >>/tmp/provision-script.log 2>&1
echo "Install bison++: DONE"
