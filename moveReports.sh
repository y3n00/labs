#!/bin/sh

max=11
for i in `seq 1 $max`
do
  mv "lab$i/lab$i.docx" ./reports
done