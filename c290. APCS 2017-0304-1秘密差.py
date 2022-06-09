k=input()
X=0
Y=0
for i, char in enumerate(k):
  if(i%2):Y+=int(char)
  else: X+=int(char)
print(abs(X-Y))