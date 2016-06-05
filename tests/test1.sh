#!/bin/bash
cdir=$(pwd)
if [[ "$1" ==  "" ]]; 
	then echo "Введите имя проекта: "; read prjn; 
	else prjn=$1;
fi
if [[ "$2" ==  "" ]]; 
	then echo "Введите название эллемента проекта: "; read eln; 
	else eln=$2;
fi
if [[ "$3" ==  "" ]]; 
	then echo "Начальное кол-во элементов: "; read elc; 
	else elc=$3;
fi
mkdir $HOME/Documents/$prjn
cd $HOME/Documents/$prjn
#git elit
for i in $(seq $elc); do
	mkdir $HOME/Documents/$prjn/$eln$elc
	mkdir $HOME/Documents/$prjn/$eln$elc/results
done
cd $cdir
exit 0;