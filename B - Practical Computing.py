N = int(input())
L = [1]
def prefix(m):
	m += [1]
	return [1] + [m[i + 1] + m[i] for i in range(0, len(m) - 2)] + [1]
for i in range(N):
	print(" ".join(list(map(str, L))))
	L = prefix(L)
