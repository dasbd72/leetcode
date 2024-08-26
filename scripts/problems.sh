#!/bin/sh

id=$1
name=$2
if [ -z $id ] || [ -z $name ]; then
    echo "Usage: ./problems.sh <id> <name>"
    exit 1
fi
id=$(printf "%04d" $id)
dir=problems/$id-$name
file=$dir/main.cpp

mkdir -p $dir
if [ ! -f $file ]; then
    echo """#include <bits/stdc++.h>
using namespace std;
""" > $file
    echo "Generated $file"
fi

if [ -n "$EDITOR" ]; then
    $EDITOR $file
    echo "Opened $file with $EDITOR"
fi
