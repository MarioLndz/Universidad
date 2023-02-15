#!/bin/bash

nombrearchivo=`date +%Y-%j-%T`

ps -ef > $nombrearchivo

echo >> $nombrearchivo

echo Mi pid = $$ >> $nombrearchivo
