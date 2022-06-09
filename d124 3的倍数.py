while(True):
	try:
		n = int(input())
	except:
		break
	print('no' if n % 3 else 'yes')