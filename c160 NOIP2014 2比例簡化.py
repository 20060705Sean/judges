from math import gcd
A, B, L = tuple(map(int, input().split()))
R = A / B
miss = 1
ap = 0
bp = 0
for a in range(1, L + 1):
	for b in range(1, L + 1):
		if gcd(a, b) == 1:
			if a / b >= R:
				if a / b - R < miss:
					miss = a / b - R
					ap = a
					bp = b
print(f"{ap} {bp}")