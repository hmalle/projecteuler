#!/usr/bin/python
#The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases 
#by 3330, is unusual in two ways: (i) each of the three terms are prime, and, 
#(ii) each of the 4-digit numbers are permutations of one another.
#There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, 
#exhibiting this property, but there is one other 4-digit increasing sequence.
#What 12-digit number do you form by concatenating the three terms in this sequence?

from itertools import permutations

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

def combine ( tp):
  strnum = ""
  for a in range(len(tp)):
    strnum += str(tp[a])
  return int(strnum)

def const_difference ( pecan ):
  sor = []
  for a in range(len(pecan)):
    for b in range(a,len(pecan)):
      for c in range(b,len(pecan)):
        if pecan[a]!=pecan[b] and pecan[b]!=pecan[c] and pecan[a]!=pecan[c]:
          if 2*abs(pecan[c]-pecan[b]) == abs(pecan[a]-pecan[c]) :
            sor.append(pecan[a])
            sor.append(pecan[b])
            sor.append(pecan[c])
            return sor.sort() 

def main():
  a = 1000
  found = 0
  pecan = []
  ans = []
  notFound = True
  while notFound and a<10000:
    if prime(a):
      for item in permutations(str(a)):
        if prime(combine(item)):
          pecan.append(combine(item))
      ans =  const_difference (pecan)
      if ans:
        print ans.sort()
    pecan = []
    a+=1

if __name__ == '__main__' :
  main()
