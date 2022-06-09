n = int(input())
for i in range(n):
  k,p,q = tuple(map(int, input().split()))
  if k == 1:print(int(p+q))
  elif k == 2:print(int(p-q))
  elif k == 3:print(int(p*q))
  else:print(int(p/q))