import serial
import time
import thingspeak
#import matplotlib.pyplot as plt
channel_id = 1260898
read_key ='NEUGQEEQ9A7XD6K8'
ser = serial.Serial('COM15',57600)
channel = thingspeak.Channel(id=channel_id, api_key=read_key)
while 1:
     data= ser.readline().rstrip()
     a,b,c,d= data.split(b",")
     #print(b"delta:"+ a)
     print(b"theta :"+ b)
     print(b"low alpha:"+ c)
     print(b"attention:"+d)
     #response = channel.update({'fie1d1':d})
     response = channel.update({'field4':d})
     response = channel.update({'field2':b})
     #time.sleep(2)
     response = channel.update({'field3':c})
     #time.sleep(1)
   
