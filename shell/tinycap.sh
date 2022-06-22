#!/bin/bash

period_size=(768 1536 2304)
period_num=(1 2 3 4)

size=${#period_size[@]}
num=${#period_num[@]}
for(( i=0;i<$size;i++))
do
	for(( j=0;j<$num;j++ ))
	do	
		echo "period_size is ${period_size[i]}, period_num is ${period_num[j]}"
		echo period_size_${period_size[i]}_count_${period_num[j]}.wav
		tinycap /userdata/changheng/wav/period_size_${period_size[i]}_count_${period_num[j]}.wav -D 0 -d 0 -c 8 -b 16 -r 48000 -p ${period_size[i]} -n ${period_num[j]} -t 20
		sleep 3
	done
done