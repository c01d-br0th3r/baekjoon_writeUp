import sys
from collections import deque
input = sys.stdin.readline

n = input()
exp = input()[:-1]
len_exp = len(exp)
while True:
    if n.find(exp) == -1:
        break
    idx = n.index(exp)
    n = n[:idx] + n[idx+len_exp:]

n = n[:-1]
if len(n) == 0:
    print("FRULA")
else:
    print(n)
