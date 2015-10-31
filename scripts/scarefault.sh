#!/usr/bin/env bash

echo "Installing: ( 1 ) unzip and ( 2 ) curl"

# Update the packages
#
echo "Update: starting"
sudo apt-get update -y >>/tmp/provision-script.log 2>&1
echo "Update: DONE"

# Install Unzip:
#   Unzip is a package that enables the compression and
#   decompression of files
#
echo "Install unzip: starting"
sudo apt-get install unzip -y >>/tmp/provision-script.log 2>&1
echo "Install unzip: DONE"

# Install Curl:
#   Curl is a client to get documents and files from or send
#   documents to a server.
#
echo "Install Curl: starting"
sudo apt-get install curl -y >>/tmp/provision-script.log 2>&1
echo "Install Curl: DONE"
