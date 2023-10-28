#!/bin/bash

x=`df | grep -c .`
echo "Numero de discos y particiones=`expr $x - 1`"

