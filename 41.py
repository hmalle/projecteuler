#!/usr/bin/python
#
#We shall say that an n-digit number is pandigital if it makes use of all
#the digits 1 to n exactly once. For example, 2143 is a 4-digit 
#pandigital and is also prime.
#
#What is the largest n-digit pandigital prime that exists?
#


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

def pandigital ( number ) :
	numlen = len(number)
	for a in range( numlen):
		for b in range( numlen):
			if int(number[b]) == 0 :
				return False
			if a!=b and int(number[a]) == int(number[b]):
				return False
			if int(number[a])>numlen or int(number[b])>numlen :
				return False
	return True

def main():
	#all the pandigitals with 1 to 9 are divisible by 3
	#so is all by 1 to 8
	a = 7654321
	while  a > 1234567:
		if pandigital(str(a)) and prime(a):
			print a
			break;
		a-=9

if __name__ == '__main__' : 
	main()
