#!/usr/bin/python
#

#There are exactly ten ways of selecting three from five, 12345:
#123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
#In combinatorics, we use the notation, 5C3 = 10.
#In general,
#nCr = n!/(r!(n-r)!)
#where r <n, n! = factorial(n)
#It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
#How many, not necessarily distinct, values of  nCr, for 1<= n <= 100, 
#are greater than one-million?

from math import factorial

def combinatoric ( n , r ):
	return factorial(n)/(factorial(r)*factorial(n-r))

def main():
	n = 1
	r = 0
	counter = 0
	while n <= 100:
		r = 0
		while r <= n :
			comb = combinatoric (n ,r )
			if comb > 1000000:
				counter +=1
			r +=1
		n +=1 
	print counter 

if __name__ == '__main__' :
	main()
