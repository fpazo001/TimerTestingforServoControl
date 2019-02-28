import serial
import time
import random

arduinoData = serial.Serial('com11',9600)
#arduinoData = serial.Serial('/dev/',9600) for Rapberry 

# Let Arduino some time to reset
time.sleep(2)

global xposition
global yposition
global xAngle
global yAngle
global tosend

def servoAngle (x,y) :
        global xAngle
        global yAngle
        
        xAngle = xposition 
        yAngle = yposition 
        
        #x =  arduinoData.write(str(xAngle).encode())
        #y =  arduinoData.write(str(yAngle).encode())


        tosend = "Ready,"+str(x)+","+ str(y) + "*"
        #arduinoData.write(str(tosend).encode())
        
       




def executeSomething(x,y):
    tosend = "Ready,"+str(x)+","+ str(y) + "*"
    arduinoData.write(str(tosend).encode())
    time.sleep(0.015)
    print(tosend)

while True:
    #executeSomething()
    
    
    global xposition
    low = 0; high = 240
    xposition = random.randint(low, high)
    time.sleep(0.015)
    

    global yposition
    low = 0; high = 320
    yposition = random.randint(low, high)
    time.sleep(0.015)   

    
                 
                           
       


    servoAngle(xposition, yposition)
    executeSomething(xAngle,yAngle)


    #ran_number must be populated by panServoAngle (x,y)  
    #ran_number = input("Enter number")
    #print(ran_number)
    #arduinoData.write(str(ran_number).encode())

time.sleep(1)
