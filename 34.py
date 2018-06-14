#!/usr/bin/python

"""


145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

"""
#PWNED BUT I DONT KNOW HOW THE UPPER LIMIT OF ITERRATION IS TO BE KNOWN
from math import factorial

def main():
	big_sum = 0
	for num in range( 10, 400000):
		str_num = str(num)
		upper = len(str_num)
		summy = 0
		for pos in range( 0, upper) :
			summy += factorial( int(str_num[pos]))
		if summy == num :
			big_sum += num
	print big_sum

if __name__ == '__main__' : main()

