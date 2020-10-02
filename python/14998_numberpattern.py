no = 5
num = 1
p = no - 1
for j in range(1, no + 1) : 
    num = j 
    for i in range(1, p + 1) : 
        print(" ", end="") 
    p = p - 1
          
    for i in range(1, j + 1) : 
        print(num, end="") 
        num = num + 1
      
    num = num - 2
    for i in range(1, j) : 
        print(num, end="") 
        num = num - 1
      
    print()
