#!/bin/bash
cfiles=`find . -name "*.sh"`
files=0
lines=0
for file in $cfiles
do
  echo $file
  #cat $file
  file_l=`cat $file | wc -l`
  echo $file_l
  let files=files+1
  let lines=$lines+$file_l
done
echo “total files: $files”
echo “total lines: $lines”

