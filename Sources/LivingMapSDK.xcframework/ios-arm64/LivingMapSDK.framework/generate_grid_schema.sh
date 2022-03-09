#!/bin/bash

#--------------------------------------------------------------------------
# Proto Schema generator
#
# This file utilises a Swift wrapper of the Googles Protocol buffer library
# to generate swift classes that match the data structure defined within the
# provided .proto file. These classes allow for easy encoding and decoding of
# positioning grid data. All configuration for the script is manual, update
# the relevant variables where appropriate.
#
# This script assums you have Google Protocol buffer installed and the Swift
# wrapper correctly configered. Reference the following link for help:
# https://livingmap.atlassian.net/wiki/spaces/LM/pages/2845442049/Google+Protocol+Buffers
#
# The script should be run as follows:
#
#       $ ./generate_grid_schema.sh
#
#--------------------------------------------------------------------------

THIS_DIR=$(dirname "$BASH_SOURCE")

# Proto file name
proto_file="Grid.proto"

echo ""
echo "Generating swift classes based on the ${proto_file} file"
echo ""

protoc --swift_out=$THIS_DIR ${THIS_DIR}/${proto_file}
EXECUTION_RESULT=$?

echo ""
if [ $EXECUTION_RESULT -eq 0 ]; then
    echo "Swift classes were successfully generated"
else
    echo "There was an issue generating the requested swift classes"
fi
echo ""
