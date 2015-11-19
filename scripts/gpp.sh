#!/usr/bin/env bash

echo "Installing: ( 1 ) g++, ( 2 ) flexc++ and ( 3 ) bisonc++"

# Install g++:
#   g++ is a compiler to C++
#
echo "Install g++: starting"
sudo apt-get install g++ -y >>/tmp/provision-script.log 2>&1
echo "Install g++: DONE"

# Install flexc++:
#   Recognize lexical standards and create a scanner in C++
#
echo "Install flexc++: starting"
sudo apt-get install flexc++ -y >>/tmp/provision-script.log 2>&1
echo "Install flexc++: DONE"

# Install bisonc++:
#   Generator of interpreter of languages and create a parser in C++
#
echo "Install bisonc++: starting"
sudo apt-get install bisonc++ -y >>/tmp/provision-script.log 2>&1
echo "Install bisonc++: DONE" 
