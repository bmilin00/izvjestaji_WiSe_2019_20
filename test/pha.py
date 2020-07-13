import serial
import paho.mqtt.client as mqtt

BROKER = "mqtt.eclipse.org"
CLIENTID = "MQTTExample"
TOPIC_ONE = "A507/sensors/distance"

COMPORT = "COM10" 
QOS = 1

import time

flag_connected = 0

def on_connect(client, userdata, flags, rc):
	logging.debug("Connected result code "+str(rc))
	client.loop_stop()

def on_disconnect(client, userdata, rc):
	logging.debug("DisConnected result code "+str(rc))
	client.loop_stop()

def on_publish(client,userdata,result):            
	print("data published \n")
	pass

mqttc = mqtt.Client(CLIENTID)
mqttc.on_connect = on_connect
mqttc.on_disconnect = on_disconnect
mqttc.on_publish = on_publish
mqttc.connect(BROKER)
mqttc.loop_start()

ser = serial.Serial(COMPORT, 9600, timeout=5) 
while True:
	message = ser.readline()
	print (message)
	if b'P:' in message:
		string, distance= message.split(b' ')
		distance, rest = distance.split(b'!')
		print(distance.decode('utf-8'))
		mqttc.publish(TOPIC_ONE, payload=distance.decode('utf-8'), qos=QOS, retain=False)
	time.sleep(0.01)
mqttc.disconnect()
time.sleep(1)