#!/usr/bin/python
#
#It was proposed by Christian Goldbach that every odd composite number 
#can be written as the sum of a prime and twice a square.
#
#9 = 7 + 2x1^2
#15 = 7 + 2x2^2
#21 = 3 + 2x3^2
#25 = 7 + 2x3^2
#27 = 19 + 2x2^2
#33 = 31 + 2x1^2

#It turns out that the conjecture was false.
#What is the smallest odd composite that cannot be written as the 
#sum of a prime and twice a square?


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
	a = 9
	chk = 0
	notFound = True
	while notFound :
		if not prime(a):
			notFound = False
			for b in range(1,int(a**0.5)):
				chk = a - (2*b**2)
				if prime( chk):
					#print a," = ",chk,"+",2,"x",b,"^2"
					notFound = True
					break
		if notFound == False :
			print a
		a+=2

if __name__ == '__main__':
	main()
