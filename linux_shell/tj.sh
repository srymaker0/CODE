#!/bin/bash
read text

echo ${text} | tr -s " " "\n" | sort | uniq -c | sort -n -r | awk '{print $1, $2}' | head -n 3 
