#!/bin/bash

echo "PATH=`pwd`/:$HOME/Escritorio/Sistemas_Operativos/Entorno_Practicas/Ejercicios:$PATH" > crontab-reducelista
echo "* * * * * reducelista" >> crontab-reducelista
