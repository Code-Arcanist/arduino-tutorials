# TO RUN:
#  Install the libraries in requirements.txt file (in pip freeze format)
#  Then run `python main.py` to execute the program below

import serial
from time import sleep

# Setup the connection to the NANO.
# The COM? could be different on windows or be something like /tty/USB? on Linux
connection = serial.Serial("COM3", baudrate=9600, timeout=5000)

# Need to wait for a second or two for the connection to establish
# Note: Not sure why I haven't been able to find any documentation on why this is.
sleep(1.8)

print('Sending Command')
connection.write('<id><id><id>'.encode(encoding='ascii', errors='strict'))
connection.flush()

print('Reading Response')
print(connection.readline().decode())
print(connection.readline().decode())
print(connection.readline().decode())

