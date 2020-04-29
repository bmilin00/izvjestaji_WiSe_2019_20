import serial
import paho.mqtt.client as mqtt

BROKER = "mqtt.eclipse.org"
CLIENTID = "MQTTExample"
TOPIC_ONE = "A507/sensors/temperature"
TOPIC_TWO = "A507/sensors/humidity"
COMPORT = "COM9" # please replace this with your port number
QOS = 1

import time

mqttc = mqtt.Client(CLIENTID)
mqttc.connect(BROKER)

ser = serial.Serial(COMPORT, 115200, timeout=5) 
while True:
	message = ser.readline()
	print (message)
	if "T:" in message:
		string, temp = message.split(" ")
		mqttc.publish(TOPIC_ONE, payload=temp, qos=QOS, retain=False)
	if "H:" in message:
		string, hum = message.split(" ")
		mqttc.publish(TOPIC_TWO, payload=hum, qos=QOS, retain=False)
	time.sleep(0.01)
mqttc.disconnect()
time.sleep(1)