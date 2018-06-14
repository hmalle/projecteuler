#!/usr/bin/python


def main():
	y = 0
	for x in range (1 , 1000):
		y += x**x
		x +=1
	y

if __name__ == '__main__' :
	main()
