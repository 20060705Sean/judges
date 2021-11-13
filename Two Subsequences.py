alphabets = 'abcdefghijklmnopqrstuvwxyz'
for i in range(int(input())):
	i = input()
	m = 0
	while alphabets[m] not in i:
		m += 1
	n = i.index(alphabets[m])
	i = i[:n] + i[n+1:]
	print(f'{alphabets[m]} {i}')