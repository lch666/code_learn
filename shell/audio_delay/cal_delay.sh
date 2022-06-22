#!/bin/bash
audio_csv=$1

vad_end_time=()  # vad end时间
real_time=() # 实际感知时间
delay_time=() # 延迟时间

echo "----------- $2 vad end time is -----------"
while read line || [[ -n ${line} ]]
do
	result=$(echo $line | grep "FINISH")
	if [ "$result" != "" ]; then
		temp_time=`echo $line | awk -F ',' '{print $NF}'`
		let time=`echo $temp_time | awk '{print int($0)'}`
		vad_end_time+=($time)
		echo $time
	fi
done < $audio_csv  #cat会新打开一个窗口


echo "----------- $2 perception real time is -----------"
while read line || [[ -n ${line} ]]
do
	result=$(echo $line | grep $2)
	if [ "$result" != "" ]; then
		temp_time=`echo $line | awk -F ',' '{print $NF}'`
		let time=`echo $temp_time | awk '{print int($0)'}`
		real_time+=($time)
		echo $time
	fi
done < $audio_csv  #cat会新打开一个窗口


vad_number=${#vad_end_time[@]}
real_number=${#real_time[@]}

if [[ vad_number -ne real_number ]]; then
	echo "$1 vad number $vad_number is not equal  to real number $real_number"
	exit 1
else
	echo "$1 vad number is $vad_number"
	echo "$1 vad real_number is $real_number"
fi


echo "----------- $2 perception delay time is -----------"
for(( i=0;i<$vad_number;i++))
do
	temp_delay_time=`expr ${real_time[i]} - ${vad_end_time[i]}`
	delay_time+=($temp_delay_time)
	echo $temp_delay_time
done


function cal_result() {
    echo "----------- cal result time is -----------"
	time=$1
	time_num=$2
	let min=${delay_time[0]}
	let max=${min}
	let sum=0
	
	for i in ${time[*]}; do 
		[[ ${min} -gt $i ]] && min=$i
        [[ ${max} -lt $i ]] && max=$i
        let sum=sum+$i
	done
	
	average=$(printf "%.3f" `echo "scale=3;$sum/$2"|bc`)
	echo "min delay time is $min"
	echo "max delay time is $max"
	echo "average delay time is $average"
}

# echo ${delay_time[*]}  # 打印数组全部内容
cal_result "${delay_time[*]}" ${#delay_time[@]}  #传递数组全部参数