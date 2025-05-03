#!/bin/bash
# Change to the directory of the script
cd "$(dirname "$0")/.."

# Check if premake5 is available
if ! command -v premake5 &> /dev/null
then
    echo "Error: premake5 is not installed or not in the PATH."
    exit 1
fi

# Run Premake to generate Xcode project
echo "Running Premake to generate Xcode project..."
premake5 xcode4

# Pause (optional, for debugging purposes)
read -p "Press any key to continue..."