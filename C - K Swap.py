import sys
n, k = tuple(map(int, input().split()))
l = list(map(int, input().split()))
dic = {}
for i, elem in enumerate(sorted(l)):
	if elem in dic:
		dic[elem].append(i)
	else:
		dic[elem] = [i]
for i, elem in enumerate(l):
	flag = False
	for each in dic[elem]:
		if (each - i) % k == 0:
			flag = True
			break
	if (not flag):
		print("No")
		sys.exit()
print("Yes")
