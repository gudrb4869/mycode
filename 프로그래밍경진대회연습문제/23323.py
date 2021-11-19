import sys
from math import *

t = int(sys.stdin.readline())

for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    result = 1 + m + floor(log2(n))
    print(result)