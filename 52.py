#!/usr/bin/python
#

#It can be seen that the number, 125874, and its double, 251748, contain 
#exactly the same digits, but in a different order.
#Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, 
#contain the same digits.

def listify (  num ):
	strnum = str(num)
	listified = []
	for a in range( len(strnum)):
		listified.append( strnum[a] )
	listified.sort()
	return listified

def main():
	a = 10
	nummy = []
	notFound = True
	while notFound :
		for b in range(1,8):
			nummy.append(listify(b*a))
		notFound = False
		for c in range(1,len(nummy)):
			if nummy[0] != nummy[c]:
				notFound = True
				break
		nummy = []
		if notFound == False :
			print a
		a+=1


if __name__ == '__main__' :
	main()

