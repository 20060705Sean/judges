strs = "0123456789"
ops = "+-*/%"
n = int(input())
for i in range(n):
	st = input()
	f, s = '', ''
	p = False
	o = ''
	for j in st:
		if j in strs:
			if p:
				s += j
			else:
				f += j
		elif j in ops:
			o = j
			p = True
	print(int(eval(str(int(f)) + o + str(int(s)))))