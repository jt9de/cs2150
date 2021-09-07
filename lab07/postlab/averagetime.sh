#!/bin/bash
# averagetime.sh
#Author: Jinghui Tian
#Date: 4.10.2021

echo "enter the exponent for counter.cpp:"

read input

if [ $input == "quit" ]
then
 exit 0
fi


total=0
counter=1
while [ $counter -le 5 ]
do
    echo "Running iteration ${counter}..."
    RUNNING_TIME=`./a.out ${input}`
    echo "time taken: ${RUNNING_TIME} ms"
    total=$((total + RUNNING_TIME))
    let counter=counter+1

done

echo "Average time was $((total/5)) ms"

