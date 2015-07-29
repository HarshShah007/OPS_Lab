#!/bin/bash

diff $1 $2

if [ $? -eq 0 ]
then
	echo "Files are same"
	rm -f $2
else
	echo "Files are different."
fi
