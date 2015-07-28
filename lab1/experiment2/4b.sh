#!/bin/bash

word="/${1}/d"
for file in ${@:2}
do
	 sed  -i $word $file 
	 
done


