#!/bin/bash

echo "|$1|";
echo "|$2|";

echo;

if [[ "$1" ==  "" ]]; 
	then echo "Введите имя проекта: "; 
	else m=$1;
fi
if [[ "$2" ==  "" ]]; 
	then echo "Введите  кличку собаки: "; read l; 
	else l=$2;
fi

exit 0;