import math
def sine():
    for i in range(0,360,45):
        y=math.radians(i)
        print("sin(",i,")",int(math.sin(y)),"\n")
def cosine():
    for i in range(0,360,45):
        y=math.radians(i)
        print("cos(",i,")",int(math.cos(y)),"\n")
def tangent():
     for i in range(0,360,45):
        y=math.radians(i)
        (print("tan(",i,")",int(math.tan(y)),"\n"))

def main():
    while(1):
        print("enter the choice of  trignometric function whose value you want\n1.sine\n2.cosine\n3.tangent\n4.exit")
        choice=int(input("enter your choice"))
        if(choice==1):
            sine()
        elif(choice==2):
            cosine()
        elif(choice==3):
            tangent()
        elif(choice==4):
            return 0
        else:
            print("wrong input!!!!")
main()
