#!/bin/sh

g++ main10.cpp

for a in $(seq 1 24)
do
	./a.out < in/$a.txt > out/$a.txt
done

g++ sum.cpp
./a.out