from sys import exit
final = [list('R' * 11)] + [list('R' + input() + 'R') for i in range(9)] + [list('R' * 11)]
def count_it(x, y):
	d = {'.':0,'W':0,'B':0,'R':0}
	d[final[x][y - 1]] += 1
	d[final[x][y + 1]] += 1
	d[final[x - 1][y]] += 1
	d[final[x + 1][y]] += 1
	return d['.'], d['W'], d['B']
for i in range(16):
	for x in range(1, 10):
		for y in range(1, 10):
			if final[x][y] == '.':
				dot, W, B = count_it(x, y)
				if W == 0 and B == 0:continue
				elif W != 0 and B != 0:
					print("Wrong")
					exit()
				final[x][y] = 'W' if B == 0 else 'B'

final_str = ''
for x in range(1, 10):
	for y in range(1, 10):
		final_str += final[x][y]
	final_str += '\n'

W = final_str.count('W')
B = 81 - W
print("Black wins!!\n" if B > W else "White wins!!\n")
print(f"{B}:{W}\n")
print(final_str)