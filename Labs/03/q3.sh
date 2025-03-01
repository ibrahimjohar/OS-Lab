#!/bin/bash

read -p "enter filename: " filename

#checking if file exists
if [ -f "$filename" ]; then
    #append current-date & time
    echo "$(date)" >> "$filename"
    echo "date & time appended to $filename"
else
    echo "error: file '$filename' doesn't exist."
fi
