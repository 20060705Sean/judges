prices = list(map(int, input().split()))
delta = [prices[i + 1] - prices[i] for i in range(len(prices) - 1)]
best_sum = 0
currect_sum = 0
best_start = best_end = 0
for i, d in enumerate(delta):
	if currect_sum <= 0:
		current_start = i
		currect_sum = d
	else:
		currect_sum += d
	if currect_sum > best_sum:
		best_sum = currect_sum
		best_start = current_start
		best_end = i + 1
print(f"{best_sum} {-1 if best_sum == 0 else prices[best_start]} {-1 if best_sum == 0 else prices[best_end]}")