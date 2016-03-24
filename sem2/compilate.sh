#!/bin/bash
outPath='results'
inFiles=$(ls -a | grep .cpp)
for i in $inFiles; do echo $outPath"/"${i//.cpp/.out};
	g++ -std=c++11 -Wall $i -o $outPath"/"${i//.cpp/.out}
done