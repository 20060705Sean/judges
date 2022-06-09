n, m, q = tuple(map(int, input().split()))
L = [i for i in range(n)]
for move in range(m):
	M = input().split()
	if M[1] == M[2]:continue
	move = int(M[1])
	L.remove(move)
	L.insert(L.index(int(M[2])) + (M[0] == 'F'), move)
	# print(L)
Q_origin = list(map(int, input().split()))
Q = {i : () for i in Q_origin}
if L[0] in Q:Q[L[0]] = (L[-1], L[1])
if L[-1] in Q:Q[L[-1]] = (L[-2], L[0])
for i, each in enumerate(L[1:-1]):
	if each in Q:Q[each] = (L[i], L[i + 2])
for q in Q_origin:
	print(f"{Q[q][0]} {Q[q][1]}",end=' ')
