#!/bin/sh

max=11
for i in `seq 1 $max`
do
  cp "lab$i/lab$i.docx" ./reports
done