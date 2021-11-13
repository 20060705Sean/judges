# https://codeforces.com/problemset/problem/1604/A
n = int(input())
for i in range(n):
	input()
	data = list(map(int, input().split()))
	k = 1
	operation = 0
	for i in data:
		if k < i:
			operation += i - k
			k = i
		k += 1
	print(operation)