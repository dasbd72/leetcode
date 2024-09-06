#!/bin/sh
value=$(<words.txt)
# Get descending word frequency
echo "$value" | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2" "$1}'