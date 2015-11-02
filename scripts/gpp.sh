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
#   Recognize lexical standards and create a scanner in C++
#
echo "Install flex++: starting"
sudo apt-get install flex++ -y >>/tmp/provision-script.log 2>&1
echo "Install flex++: DONE"

# Install flex++:
#   Recognize lexical standards and create a scanner in C++
#
echo "Install flexc++: starting"
sudo apt-get install flexc++ -y >>/tmp/provision-script.log 2>&1
echo "Install flexc++: DONE"

# Install flexc++:
#   Recognize lexical standards and create a scanner in C++
#
echo "Install flexc++: starting"
sudo apt-get install flexc++ -y >>/tmp/provision-script.log 2>&1
echo "Install flexc++: DONE"

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

# Install bisonc++:
#   Generator of interpreter of languages and create a parser in C++
#
echo "Install bisonc++: starting"
sudo apt-get install bisonc++ -y >>/tmp/provision-script.log 2>&1
echo "Install bisonc++: DONE" 
