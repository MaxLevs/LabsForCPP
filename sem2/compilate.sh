#!/bin/bash
outPath='results'
debug='debug.txt'
inFiles=$(ls -a | grep .cpp)
for i in $inFiles; do echo $outPath"/"${i//.cpp/.out};
	g++ -std=c++11 -Wall $i -o $outPath"/"${i//.cpp/.out} 2>> $debug
	echo "|---------------------------------------------|" >> $debug
done

g++ -std=c++11 -Wall $i -lncursesw -o $outPath"/"${i//.cpp/.out} 2>> $debug