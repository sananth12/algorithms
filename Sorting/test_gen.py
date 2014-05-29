from random import randint
file = open('data','w') 
file.write('50000\n')
for x in range(0,50000):
	file.write(str(randint(123,100000))+'\n')	
