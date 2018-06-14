#!/usr/bin/python

#The number, 1406357289, is a 0 to 9 pandigital number because it is 
#made up of each of the digits 0 to 9 in some order, but it also 
#has a rather interesting sub-string divisibility property.

#Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, 
#we note the following:
#
#    d2d3d4=406 is divisible by 2
#    d3d4d5=063 is divisible by 3
#    d4d5d6=635 is divisible by 5
#    d5d6d7=357 is divisible by 7
#    d6d7d8=572 is divisible by 11
#    d7d8d9=728 is divisible by 13
#    d8d9d10=289 is divisible by 17
#
#Find the sum of all 0 to 9 pandigital numbers with this property.

from itertools import permutations

def property ( num_str):
	stst2 = int(num_str[1] + num_str[2] + num_str[3])
	stst3 = int(num_str[2] + num_str[3] + num_str[4])
	stst5 = int(num_str[3] + num_str[4] + num_str[5])
	stst7 = int(num_str[4] + num_str[5] + num_str[6])
	stst11 = int(num_str[5] + num_str[6] + num_str[7])
	stst13 = int(num_str[6] + num_str[7] + num_str[8])
	stst17 = int(num_str[7] + num_str[8] + num_str[9])
	if stst17%17==0 and stst13%13==0 and stst11%11==0 and stst7%7==0 and stst5%5==0 and stst3%3==0 and stst2%2==0:
		return True
	else:
		return False
	

def pandigital ( num_str ) :
	numlen = len(num_str )
	for a in range( numlen):
		for b in range( numlen):
			if a!=b and int(num_str[a]) == int(num_str[b]):
				return False
			if int(num_str[a])>numlen or int(num_str[b])>numlen :
				return False
	return True

def main():
	pansum = 0
	panadd = ""
	a = 1023456789
	for p in permutations(str(a)):
		if property(p) :
			for item in p:
				panadd+=str(item)
			pansum += int(panadd)
			print panadd
			panadd = ""
			
	print pansum 


if __name__ == '__main__' :
	main()

