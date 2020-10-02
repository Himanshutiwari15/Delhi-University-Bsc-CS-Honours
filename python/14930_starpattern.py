n = int(input("Enter the no:"))
i = 0
j = 0
k = 0
for i in range(1, (n+1)//2 + 1):
    for j in range((n+1)//2 - i):
        print(" ", end = "")
    for k in range((i*2)-1):
        print("*", end = "")
    print()

for i in range((n+1)//2 + 1, n + 1): 
    for j in range(i - (n+1)//2):
        print(" ", end = "")
    for k in range((n+1 - i)*2 - 1):
        print("*", end = "")
    print()
