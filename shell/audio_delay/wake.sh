#!/bin/bash
wake_label_path="wake_label.txt"
audio_csv="audio.csv"

wake_label=(`cat $wake_label_path`)  # 标签唤醒时间
wake_time=()  # 实际唤醒时间
delay_time=() # 唤醒延迟时间

echo "----------- label $1 time is -----------"
for(( i=0;i<${#wake_label[@]};i++))
do
	echo ${wake_label[i]}
done

temp=`cat $audio_csv | grep START`
start_time=`echo $temp | awk -F ',' '{print $NF}'`


echo "----------- real $1 time is -----------"
while read line 
do
	result=$(echo $line | grep $1)
	if [ "$result" != "" ]; then
		temp_time=`echo $line | awk -F ',' '{print $NF}'`
		let time1=`echo $start_time | awk '{print int($0)'}`
		let time2=`echo $temp_time | awk '{print int($0)'}`
		interval_time1=`expr $time2 - $time1`
		wake_time+=($interval_time1)
		echo $interval_time1
	fi
done < $audio_csv  #cat会新打开一个窗口


echo "----------- delay $1 time is -----------"
label_number=${#wake_label[@]}
real_number=${#wake_time[@]}

if [[ label_number -ne real_number ]]; then
	echo "$1 label number is not equal  to real number"
	exit 1
fi



for(( i=0;i<$label_number;i++))
do
	let temp_time=`echo ${wake_label[i]} | awk '{print int($0)'}`
	temp_delay_time=`expr ${wake_time[i]} - $temp_time`
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