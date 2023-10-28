#!/bin/bash

#find ~ -mtime 1 > ./modificados_`date +%d-%H-%Y`
ls ./ -laih > ls`date +%d-%H-%Y`
