#!/usr/bin/python

"""
The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

"""
#PAWNED BUT THE UNDERLYING UPPER_LIMIT ISNT UNDERSTOOD YET. JUST BRUTEFORCING HERE

from math import log

def main():
	many = 0
	for x in range(1, 10):
		for length in range( 1, 22):
			number = x**length
			if  len(str(number)) == length :
				print x,"^",length," = ",number
				many +=1
	print "\nTOTAL = ", many

if __name__ == '__main__' : main ()
