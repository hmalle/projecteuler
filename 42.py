#!/usr/bin/python

#The nth term of the sequence of triangle numbers is given by, 
#tn = 0.5n(n+1); so the first ten triangle numbers are:
#
#1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
#
#By converting each letter in a word to a number corresponding to its alphabetical 
#position and adding these values we form a word value. For example, the word 
#value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number 
#then we shall call the word a triangle word.
#
#Using words.txt (right click and 'Save Link/Target As...'), a 16K text file 
#containing nearly two-thousand common English words, how many are triangle words?

import re

def triangle(  tn ):
	if  ((-1 + (1+8*tn)**0.5 )/2)%1 == 0.0:
		return True
	else :
		return False

def ascii_sum ( word ):
	t_value = 0
	for a in range(len(word)):
		t_value += (ord(word[a]) - 64 )
	return t_value
		

def main():
	triangle_words = 0
	f = open("42.txt")
	for line in f.readlines():
		for word in line.split(","):
			if triangle( ascii_sum( word.strip('"') ) ):
				triangle_words +=1

	print triangle_words
if __name__ == '__main__' : 
	main()
