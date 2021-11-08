questions = int(input())
for i in range(questions):
	i = input()
	# find what it want to express, if the last char is equal to the first char, then the AB(s) will be equal to BA(s) 
	if i[0] != i[-1]:
		print(i[:-1] + i[0])
	else:
		print(i)