#!/bin/bash

#check if 2 args are provided here
if [ $# -ne 2 ]; then
	echo "Usage: $0 <num1> <num2>"
	exit 1
fi

#multiply the 2 nums
result=$(( $1 * $2 ))

#print result 
echo "product of $1 & $2 is: $result"

