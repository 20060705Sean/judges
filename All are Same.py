# D1. All are Same
# https://codeforces.com/problemset/problem/1593/D1
from math import gcd
t = int(input())
for i in range(t):
	i = input()
	intergers = list(map(int, input().split()))
	flag = True
	for i in range(len(intergers) - 1):
		if not(intergers[i] == intergers[i + 1]):
			flag = False
			break
	if flag:
		print(-1)
		continue
	i = min(intergers)
	intergers = list(map(lambda x:x+abs(i), intergers))
	LOL = 1
	while LOL == 1:
		if not intergers[0] in (0, 1):
			LOL *= intergers[0]
		else:
			intergers.pop(0)
	for n in intergers:
		if n != 0:
			LOL = gcd(LOL, n)
		if LOL == 1:
			break
	print(LOL)
