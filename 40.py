#!/usr/bin/python

#An irrational decimal fraction is created by concatenating the positive integers:
#
#0.123456789101112131415161718192021...
#
#It can be seen that the 12th digit of the fractional part is 1.
#
#If dn represents the nth digit of the fractional part, find the value 
#of the following expression.
#d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000
#

def main():
	strnum = ""
	a = 1
	while a < 1000001:
		strnum += str(a)
		a+=1
	prod = 1
	for a in range(7):
		prod *= int(strnum[10**a-1])

	print prod

if __name__ == '__main__' :
	main()
