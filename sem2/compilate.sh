#!/bin/bash
outPath='results'
j=1
inFiles=$(ls -a | grep .cpp)
for i in $inFiles; do echo $outPath"/"${i//.cpp/.out};
	if [ "$j" -eq "4" ]; then addict="-lncurses"; else addict=""; fi
	g++ -std=c++11 -Wall $i -o $outPath"/"${i//.cpp/.out} $addict 2> debug.txt
	j=$[$j+1]
done