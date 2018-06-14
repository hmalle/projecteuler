#!/usr/bin/python
#
#We shall say that an n-digit number is pandigital if it makes use of all 
#the digits 1 to n exactly once; for example, the 5-digit number, 
#15234, is 1 through 5 pandigital.
#
#The product 7254 is unusual, as the identity, 39x186 = 7254, 
#containing multiplicand, multiplier, and product is 1 through 9 pandigital.
#
#Find the sum of all products whose multiplicand/multiplier/product 
#identity can be written as a 1 through 9 pandigital.
#HINT: Some products can be obtained in more than one way so 
#be sure to only include it once in your sum.

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

def unique_sum ( product ):
	product.sort()
	previous_num = 0;
	summm = 0
	for  num in product:
		if num != previous_num :
			summm += num
			previous_num = num

	return summm


def main():
	productzz = []
	str_num = ""
	multiplicand = 1
	while multiplicand < 5000:
		multiplier = multiplicand
		while multiplier < 5000:
			product = multiplicand*multiplier 
			str_num = str(multiplicand)+str(multiplier)+str(product)
			if len(str_num) > 9 : 
				break
			if len(str_num)== 9 and pandigital( str_num ):
				productzz.append(product)
			multiplier +=1
		multiplicand+=1

	print unique_sum(productzz)

if __name__ == '__main__' :
	main()
