#!/bin/bash

for var in $@
do
	capital=`echo "$var" | tr [a-z] [A-Z]`
	`mv $var $capital`	
done

