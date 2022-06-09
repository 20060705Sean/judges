"""
You are given an array of n integers a1,a2,…,an. After you watched the amazing film "Everything Everywhere 
All At Once", you came up with the following operation.

In one operation, you choose n−1 elements of the array and replace each of them with their arithmetic mean 
(which doesn't have to be an integer). For example, from the array [1,2,3,1] we can get the array [2,2,2,1], 
if we choose the first three elements, or we can get the array [4/3,4/3,3,4/3], if we choose all elements 
except the third.

Is it possible to make all elements of the array equal by performing a finite number of such operations?

#strategy

"""
for test_case in range(int(input())):
	input()
	numbers = list(map(int, input().split()))
	flag = False
	avg = sum(numbers) / len(numbers)
	for n in numbers:
		if n == avg:
			flag = True
			break
	print("YES" if flag else "NO")