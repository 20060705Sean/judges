'''
given a, b, c

operate a and c is meaningless, so the operation must include b and another one

for each increasement/decreasement on a or c, it will make b decrease/increase 2 times effect

so the concept is that the dev. A.M. will be 0 iff.:
	->  {k|a b c in Z, exist k in Z [2b + 2k = c - k + a]}
'''

for i in range(int(input())):
	a, b, c = list(map(int, input().split()))
	if (a + c - 2 * b) % 3 == 0:
		print(0)
	else:
		print(1)