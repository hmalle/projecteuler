#!/usr/bin/python

#A googl(10^100) is a massive number: one followed by one-hundred zeros;
#100^100 is almost unimaginably large: one followed by two-hundred zeros.
#Despite their size, the sum of the digits in each number is only 1
#Considering all natural numbers of the form a^b, where a,b <100,
#what is the maximum digital sum

def digit_sum ( num ):
	strnum = str(num)
	dig_sum = 0
	for a in range(len(strnum)):
		dig_sum += int(strnum[a])

	return dig_sum


def main():
	big_a = 0
	big_b = 0
	big_sum = 0
	for a in range(100):
		for b in range(100):
			dig_sum = digit_sum (a**b)
			if dig_sum > big_sum :
				big_sum = dig_sum
				big_a = a
				big_b = b
	print big_a ,"^",big_b," digit sum = ",big_sum

if __name__ == '__main__' :
	main()
