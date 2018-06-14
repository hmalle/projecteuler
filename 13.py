#!/usr/bin/python

import sys
from string import atol
#Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

file = open (sys.argv[1])

zoo = 0L

for line in file:
	zoo += long(str(line))
print zoo

