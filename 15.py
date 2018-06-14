#!/usr/bin/python
import sys

#PWNED BY THE OWNER

def calculate_path( a ,b ) :
	matrix = [[0 for i in range(a)] for i in range(b) ]
	matrix[0][0] = 0
	path = 0
	for i in range(1,a):
		matrix[i][0] = 1
	for j in range(1,b):
		matrix[0][j] = 1
	for i in range(1,a):
		for j in range(1,b):
			matrix[i][j] = matrix[i][j-1] + matrix[i-1][j]
	return matrix[a-1][b-1]
			


def main():
	if len(sys.argv) <2 or len(sys.argv) > 3 :
		print sys.argv[0]," <i> <j> \n\tOR\n",sys.argv[0]," <i> //for a square matrix"
		sys.exit(0)
	if len(sys.argv) == 2:
		i = j = int(sys.argv[1])
	else :
		i = int(sys.argv[1])
		j = int(sys.argv[2])
	paths = calculate_path(i+1, j+1)
	print "\npaths (",i,j,") = " , paths

if __name__ == '__main__' : main()
