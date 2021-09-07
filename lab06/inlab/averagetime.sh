#!/bin/bash
# averagetime.sh
echo "dictionary: $1"
echo "grid: $2"
total=0
#clang++ timer.cpp wordPuzzle.cpp hashTable.cpp
RUNNING_TIME=`./a.out $1 $2| tail -1`
total=$((total + RUNNING_TIME))

#clang++ timer.cpp wordPuzzle.cpp hashTable.cpp
RUNNING_TIME=`./a.out $1 $2| tail -1`
total=$((total + RUNNING_TIME))

#clang++ timer.cpp wordPuzzle.cpp hashTable.cpp
RUNNING_TIME=`./a.out $1 $2| tail -1`
total=$((total + RUNNING_TIME))

#clang++ timer.cpp wordPuzzle.cpp hashTable.cpp
RUNNING_TIME=`./a.out $1 $2| tail -1`
total=$((total + RUNNING_TIME))

#clang++ timer.cpp wordPuzzle.cpp hashTable.cpp
RUNNING_TIME=`./a.out $1 $2| tail -1`
total=$((total + RUNNING_TIME))

echo $((total/5))
