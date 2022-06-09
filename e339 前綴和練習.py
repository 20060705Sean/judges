n = int(input())
k = [0] + list(map(int, input().split()))
for i in range(1, len(k)):k[i] += k[i - 1]
k.pop(0)
print(" ".join(list(map(str, k))))