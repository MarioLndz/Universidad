#!/bin/bash

PATHLISTA="/home/mario/Escritorio/Sistemas_Operativos/Entorno_Practicas/Ejercicios/varios/"

head -n 1 $PATHLISTA/listacores > $PATHLISTA/tmp
rm $PATHLISTA/listacores
mv $PATHLISTA/tmp $PATHLISTA/listacores

