#!/usr/bin/python

#Starting with 1 and spiralling anticlockwise in the following way, a square 
#spiral with side length 7 is formed.
#37 36 35 34 33 32 31
#38 17 16 15 14 13 30
#39 18  5  4  3 12 29
#40 19  6  1  2 11 28
#41 20  7  8  9 10 27
#42 21 22 23 24 25 26
#43 44 45 46 47 48 49
#It is interesting to note that the odd squares lie along the bottom right 
#diagonal, but what is more interesting is that 8 out of the 13 numbers lying 
#along both diagonals are prime; that is, a ratio of 8/13 ~= 62%.

#If one complete new layer is wrapped around the spiral above, a square 
#spiral with side length 9 will be formed. If this process is continued, 
#what is the side length of the square spiral for which the ratio of 
#primes along both diagonals first falls below 10%?

import random

_mrpt_num_trials = 5

def miller_rabin ( n ):
    assert n >= 2
    if n==2 :
        return True
    if n %2 == 0 :
        return False
    s = 0
    d = n-1
    while True:
        quotient, remainder  = divmod (d,2)
        if remainder == 1 :
            break
        s+=1
        d = quotient
    assert(2**s *d == n-1 )
    def try_composite (a):
        if pow(a,d,n) ==1:
            return False
        for i in range (s):
            if pow(a, 2**i *d,n ) == n-1:
                return False
        return True

    for i in range (_mrpt_num_trials ): 
        a = random.randrange(2,n)
        if try_composite (a):
            return False

    return True


def prime ( num ):
	if num < 2 :
		return False
	if num ==2 or num==3 :
		return True
	if num%2==0 or num%3==0 :
		return False
	if num %6 ==1 or num%6==5 :
		sx= 6
		i = 1
		while 6*i-1 <= int(num**0.5): 
			sx = 6*i
			if  num%(sx-1)==0 or num%(sx+1)==0  :
				return False
			i+=1
		return True
	return False

def main():
	num = 1
	step = 2
	notFound  = True
	diagonal_numbers =  1
	diagonal_primes =  0
	while notFound :
		for a in range(4):
			num+= step 
			diagonal_numbers +=1
			if  miller_rabin( num ):
				diagonal_primes += 1
		ratio =  float(diagonal_primes)/ diagonal_numbers
		if ratio < 0.10 : 
			notFound = False
			print step+1, ratio
		step += 2

if __name__ == '__main__' :
	main()
