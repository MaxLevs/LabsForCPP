#!/bin/bash

outPath='results'
echo $(ls -a | grep .cpp) > iajsdpfijasdfpoiasdjfpoij
detectedFiles=`cat iajsdpfijasdfpoiasdjfpoij`

for i in `seq 1 4`; do
	if expr match "$detectedFiles" '\(\S*\.cpp \)'
	then fnd=$(expr match "$detectedFiles" '\(\S*\.cpp \)')
	else fnd=$(expr match "$detectedFiles" '\(\S*\.cpp\)')
	fi
	detectedFiles=${detectedFiles//${fnd}/}
	outf=${outPath}'/'${fnd//.cpp/.out};
	g++ -std=c++11 -Wall $fnd -o $outf
done

rm iajsdpfijasdfpoiasdjfpoij