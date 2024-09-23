number, system = input().split()

decimal = int(number,int(system))

print ("BIN:",bin(decimal)[2:])
print ("OCT:",oct(decimal)[2:])
print ("DEC:",decimal)
print ("HEX:",hex(decimal)[2:])