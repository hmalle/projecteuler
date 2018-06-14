#!/usr/bin/python
#
#Take the number 192 and multiply it by each of 1, 2, and 3:
#
#    192 x 1 = 192
#    192 x 2 = 384
#    192 x 3 = 576
#
#By concatenating each product we get the 1 to 9 pandigital, 192384576. 
#We will call 192384576 the concatenated product of 192 and (1,2,3)
#
#The same can be achieved by starting with 9 and multiplying by 
#1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the 
#concatenated product of 9 and (1,2,3,4,5).
#
#What is the largest 1 to 9 pandigital 9-digit number that can be formed 
#as the concatenated product of an integer with (1,2, ... , n) where n > 1?


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
	strnum = "";
	largest_pandigital = 0
	for a in range(1,100000):
		strnum = ""
		for b in range(1,30):
			strnum += str(a*b)
			if len(strnum) > 9 :
				break
			if len(strnum) == 9 and pandigital(strnum):
				if largest_pandigital < int(strnum):
					largest_pandigital = int(strnum)

	print largest_pandigital
if __name__ == '__main__' :
	main()
