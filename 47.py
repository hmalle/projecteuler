#!/usr/bin/python
#The first two consecutive numbers to have two distinct prime factors are:
#14 = 2 x 7
#15 = 3 x 5
#The first three consecutive numbers to have three distinct prime factors are:
#644 = 2^2x7x23
#645 = 3 x5x43
#646 = 2 x17x19.
#Find the first four consecutive integers to have four distinct primes factors. 
#What is the first of these numbers?

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

def main():
  p0 = 2
  p1 = 1
  p2 = 0
  p3 = -1
  last3 = []
  last2 = []
  last1 = []
  last0 = []
  notFound = True
  a = 3
  while notFound :
    last0 = []
    if not prime(p0) :
      if p0%2 == 0 :
        last0.append(2)
        last0.append(p0/2)
      a = 3
      while a <= p0**0.5 :
        if p0%a == 0 and prime(a):
          last0.append(a)
        a+=2

    len0 = len(last0)
    len1 = len(last1)
    len2 = len(last2)
    len3 = len(last3)
    if  len3 == 4 and len2==4 and len1==4 and len0 == 4 :
      if last0 != last1 and last0!=last2 and last0!=last3 and last1!=last2 and last1!=last3 and last2!=last3 :
        print p0-3,"=", last3
        print p0-2,"=",last2
        print p0-1,"=", last1
        print p0, "=",last0
        notFound = False
    last3 = last2
    last2 = last1
    last1 = last0
    p0+=1


if __name__ == '__main__':
  main()
