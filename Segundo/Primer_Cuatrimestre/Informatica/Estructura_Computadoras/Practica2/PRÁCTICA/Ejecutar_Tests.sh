#!/bin/bash

if (( $# == 2 )); then
	for i in $(seq 1 $2); do
		gcc -x assembler-with-cpp -D TEST=$i -no-pie $1.s -o $1
		printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./$1
		rm $1
	done
fi
