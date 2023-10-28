#!/bin/bash 
#echo "" >> salida.dat
printf "" > $1.dat
i=5000
while [ "$i" -le 130000 ]
do
    ./$1 $i >> $1.dat
	echo "Terminado $i" 
      i=$(( $i + 5000 ))
	
done
      
