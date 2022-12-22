#!/bin/sh

name=$1

mkdir $name;
echo "main:\n\tg++ -std=c++2b -O3 -o main $name.cpp" > $name/Makefile;
cp template.docx $name/$name.docx;
touch $name/$name.cpp;
