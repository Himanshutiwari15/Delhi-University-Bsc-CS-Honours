
#function to calculate area of rectangle
import math
import sys
def rectangle(length,breadth):
    print('length=',length,'breadth=',breadth)
    area=length*breadth
    print('area of rectangle=',area)
def square(side):
    print('side of square is=',side)
    area=side**2
    print('area of square=',area)
def triangle(base,height):
    print('base=',base,'height=',height)
    area=1/2*(base*height)
    print('area of triangle =',area)
def circle(radius):
    print("radius of the circle is:",radius)
    area= (math.pi*(radius**2))
    print("area of the given radius circle is :",area)

def main():
    while(1):    
        print("WELCOME TO AREA CALCULATOR\n1.rectangle\n2.square\n3.triangle\n4.circle")
        choice=int(input("pls enter your choice"))
        
        if(choice==1):
            length=eval(input("enter the value of length of rectangle"))
            breadth=eval(input("enter the value of breadth of rectancle"))
            rectangle(length,breadth)
        elif(choice==2):
            side=eval(input("enter the side of the sqaure"))
            square(side)
        elif(choice==3):
            base=eval(input("enter the value of base of triangle"))
            height=eval(input("enter the value of height of triangle"))
            triangle(base,height)
        elif(choice==4):
            radius=eval(input("enter the radoius of the circle"))
            circle(radius)
        else:
            print("wrong choice")
            return 0
            
main()
