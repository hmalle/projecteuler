#!/usr/bin/python

import sys

#The following iterative sequence is defined for the set of positive integers:

#n ? n/2 (n is even)
#n ? 3n + 1 (n is odd)

#Using the rule above and starting with 13, we generate the following sequence:
#13 ? 40 ? 20 ? 10 ? 5 ? 16 ? 8 ? 4 ? 2 ? 1

#It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

#Which starting number, under one million, produces the longest chain?

#NOte: Once the chain starts the terms are allowed to go above one million.
#----------------------------------------------------------------------------
#PAWNED
def cycles ( n ) :
	cycles = 1
	while n != 1 :
		if n%2 == 0 :
			n /=2 
		else :
			n = n*3 +1
		cycles+=1
	return cycles

def main() :
	num = long(sys.argv[1])
	now_cycles = last_cycles = holder = 0
	while num > 0 :
		now_cycles = cycles(num)
		if now_cycles > last_cycles :
			last_cycles = now_cycles
			holder = num
		num -= 1

	print "ceil=",sys.argv[1],"  num=",holder," cycles=",last_cycles
#ceil= 1000000   num= 837799  cycles= 525

if __name__ == '__main__': main()
