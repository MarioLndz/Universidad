#!/bin/bash 
#echo "" >> salida.dat
printf "" > $1.dat
i=50000
while [ "$i" -le 1750000 ]
do
    ./$1 $i >> $1.dat
	echo "Terminado $i" 
      i=$(( $i + 50000 ))
	
done
      
