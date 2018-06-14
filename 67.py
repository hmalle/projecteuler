#!/usr/bin/python
#
#
#By starting at the top of the triangle below and moving to adjacent numbers on 
#the row below, the maximum total from top to bottom is 23.
#
#3
#7 4
#2 4 6
#8 5 9 3
#
#That is, 3 + 7 + 4 + 9 = 23.
#
#NOTE: As there are only 16384 routes, it is possible to solve this problem by 
#trying every route. However, Problem 67, is the same challenge with a triangle 
#containing one-hundred rows; it cannot be solved by brute force, and requires 
#a clever method! ;o)

def largest_sum( zz ):
	y = len(zz)-1
	while y>0:
		x = len(zz[y])-1
		for b in range(x):
			if zz[y][b] > zz[y][b+1] :
				zz[y-1][b] += zz[y][b]
			else :
				zz[y-1][b] += zz[y][b+1]
		y-=1

	return zz[0][0]

def main():
	f = open("67.txt")
	zz = []
	for line in f.readlines():
		zz.append(line.split())
	for a in range(len(zz)):
		for b in range(len(zz[a])):
			zz[a][b] = int(zz[a][b])

	print largest_sum(zz)
	

if __name__ == '__main__':
	main()
