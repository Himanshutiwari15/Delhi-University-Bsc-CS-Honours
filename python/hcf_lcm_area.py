import math

def lcm():
    a=int(input("Enter first number: "))
    b=int(input("Enter second number: "))
    if(a > b):   
        maximum = a
    else:
        maximum = b
    while(True):
        if(int(maximum % a) == 0 and int(maximum % b) == 0):
            l = maximum
            break
        maximum = maximum + 1
    print("LCM of ",a," and ",b,": ",l)
def hcf():
    a=int(input("Enter first number: "))
    b=int(input("Enter second number: "))
    if a<=b:
        for i in range(1,a+1):
            if int(a%i)==0 and int(b%i)==0:
                h=i
        print("HCF of ",a,"and ",b,": ",h)
    else:
        for i in range(1,b+1):
            if int(a%i)==0 and int(b%i)==0:
                h=i
        print("HCF of ",a,"and ",b,": ",h)


def area():
    a=int(input("Enter first side: "))
    b=int(input("Enter second side: "))
    c=int(input("Enter third side: "))
    assert a+b>c and a+c>b and b+c>a
    s=(a+b+c)/2
    a1=s*(s-a)*(s-b)*(s-c)
    a=math.sqrt(a1)
    print("Area Of Triangle: ",a)


print("\n\t*******MENU*******")
print("\t1.LCM")
print("\t2.HCF")
print("\t3.Area Of Triangle")
ch=int(input("\n\tEnter Choice: "))
assert ch>=1 and ch<=3
if ch==1:
     lcm()
elif ch==2:
     hcf()
else:
     area()
