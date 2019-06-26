import serial
ser = serial.Serial('COM3', 9600, timeout=0,parity=serial.PARITY_EVEN, rtscts=1)  # open serial port
print("conexão aberta em: " + ser.name)         # check which port was really used
ser.write(b'hello')     # write a string
ser.close()             # close port