#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys

audio_csv = sys.argv[1]
key_word = sys.argv[2]
discard_time = 1500
vad_end_time = []
real_time = [] 
delay_time = []

def get_time():
  print "----------- grep vad end time -----------"
  with open(audio_csv, 'r') as fp:
    lines = fp.readlines()
    for line in lines:
      datas = line.strip().split(',')
      if len(datas) >= 3 and datas[1] == "FINISH":
        vad_end_time.append(datas[-1])
      if len(datas) >= 3 and datas[1] == key_word:
        real_time.append(datas[-1])
  fp.close()

def is_number_valid():
  vad_number = len(vad_end_time)
  real_number = len(real_time)
  print "vad number is", vad_number
  print "real number is", real_number
  if (vad_number != real_number):
    print("vad number is not equal to real time")
    return 1
  else:
    return 0

def cal_delay_time():
  print "----------- cal result time -----------"
  if is_number_valid() == 1:
    print "grep appear error, do not calculate the result"
  for i in range(0, len(vad_end_time)):
    temp_time = int(real_time[i]) - int(vad_end_time[i])
    if temp_time > discard_time:
      print "discard the delay time, real time is", real_time[i], " vad end time", vad_end_time[i]
      continue
    delay_time.append(temp_time)
  print "min delay time is", min(delay_time)
  print "max delay time is", max(delay_time)
  print "average delay time is", sum(delay_time)/len(delay_time)
  
if __name__ == '__main__':
  get_time()
  cal_delay_time()