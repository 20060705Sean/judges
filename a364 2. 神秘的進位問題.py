C_x_1 = [0] + [i for i in range(1, 101)]
C_x_2 = [0, 0] + [int(i * (i - 1) / 2) for i in range(2, 101)]
C_x_3 = [0, 0, 0] + [int(i * (i - 1) * (i - 2) / 3 / 2) for i in range(3, 101)]

dictt = {i:"9999999" for i in range(0, 501)}

for a in range(2, 41):
	for b in range(1, a):
		for c in range(0, b):
			x = C_x_3[a] + C_x_2[b] + C_x_1[c]
			if x <= 500:
				dictt[x] = min(dictt[x], f"{a}{b}{c}")

n = int(input())
for i in range(n):
	k = int(input())
	print(dictt[k])