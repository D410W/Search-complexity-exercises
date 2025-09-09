#!/bin/bash

for i in {1..50}; do
  
  echo " == commencing test: "$i
  ./build/automated_hot_cold 50 $i > debug.txt
  echo " -- test successful."
done

echo " ## All tests done."

# if any of the program's tries gets stuck, the
# user has to stop the execution of this script
# and analyze the output of the program in debug.txt
