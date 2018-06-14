#!/usr/bin/python
#
#The number, 197, is called a circular prime because all rotations 
#of the digits: 197, 971, and 719, are themselves prime.

#There are thirteen such primes below 100: 
#2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
#
#How many circular primes are there below one million?


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

	

def circular( p ):
	p_p = []
	pn = ""
	span = len(p)
	for a in range(span):
		pn+=p[span-1]
		for b in range(span-1):
			pn+=p[b]
		p = pn
		pn = ""
		p_p.append(int(p))
	return p_p

def main():
	many = 1
	found = False
	a = 3
	while a < 1000000:
		if prime( a ):
			found = True
			for num in circular((str(a))):
				if not prime( num ):
					found = False
					break
			if found :
				print a
				many +=2
		a+=1
	print many

if __name__ == '__main__' :
	main()
