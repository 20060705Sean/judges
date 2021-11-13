k = int(input())
for i in range(k):
	keys = {c:i for i, c in enumerate(input())}
	word = input()
	ans = 0
	for i in range(1, len(word)):
		ans += abs(keys[word[i-1]] - keys[word[i]])
	print(ans)