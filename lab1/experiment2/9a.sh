#!/bin/bash

read -p "Enter string: " string
read -p "Enter starting index: " start_index
read -p "Enter end index: " end_index

echo ${string:$start_index:$((end_index - start_index + 1))}

