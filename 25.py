#!/usr/bin/python

from math import log
import sys

"""
What is the first term in the Fibonacci sequence to contain 1000 digits?

PAWNED!!
"""

def main ():
	digits =  int(sys.argv[1])
	i = 3
	last_one = 1
	last_two = 1
	new_one = 0
	while i: 
		new_one = last_one+last_two
		if log(new_one, 10) + 1 >= digits :
			print i
			break
		else :
			last_two = last_one
			last_one = new_one
		i+=1

if __name__ == '__main__' : main()

