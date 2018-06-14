
#!usr/bin/python

# It is possible to show that the square root of two can be expressed as an infinte continued fraction
# (2^0.5) = 1+ 1/(2+1/(2+1/2+1/(2+...))) = 1.414213...
# By expanding this for the first 4 iterations, we get:
# 1+1/2 = 3/2 = 1.5
# 1+1/(2+1/2) = 7/4 = 1.4
# 1+1/(2+1/(2+1/2)) = 17/12 = 1.41666...
#
# In the first one-thousand expanseions, how many fractions contain a numerator whth more digits thatn demoninator?
#

# After analysis I realized that the 1+x will be 1+(1/2), 1+(2/5) , 1+5/12 ...
# ie 1/2, 2/5, 5/12, 12/29, 92/70,...
# numerator+1 = denominator
# denomiator+1 = 2*denominator+numerator 
#

def calculate (numer, denom):
  ans = denom+numer
  if(len(str(ans)) > len(str(denom))):
    print ans, "/",denom
    return True
  return False

def main():
  expansion_index = 1000
  count, numer, denom = 0,1,2
  for a in range(expansion_index):
    if calculate(numer, denom) > 0:
      count+=1
    tmp = denom
    denom = denom*2 +numer
    numer = tmp
  print "count ", count


if __name__ == "__main__":
    main()

