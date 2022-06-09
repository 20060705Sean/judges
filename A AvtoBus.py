from decimal import Decimal
for i in range(int(input())):
	k = int(input())
	if k < 4 or k % 2 == 1:print("-1")
	else:print(f"{int(Decimal(k) / Decimal(6)) + (0 if k % 6 == 0 else 1)} {int(Decimal(k) / Decimal(4))}")