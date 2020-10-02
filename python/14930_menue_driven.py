import math
import sys
#Program to find LCM of two number
def LCM():
   n1 = int(input("Enter the first number: "))
   n2 = int(input("Enter the second number: "))
   if n1 > n2:
       g = n1
   else:
       g = n2

   while(True):
       if((g % n1 == 0) and (g % n2 == 0)):
           lcm = g
           break
       g += 1
   print("The L.C.M. is",lcm)

#Program to find HCF of two numbers
def HCF():
    n1 = int(input("Enter the first number: "))
    n2 = int(input("Enter the second number: "))
    if n1 > n2:
        s = n2
    else:
        s = n1
    for i in range(1, s + 1):
        if((n1 % i == 0) and (n2 % i == 0)):
            hcf = i 
    print("The H.C.F. is", hcf)    

#Program to find the area of triangle
def triangle_area():
        side1 = int(input("Enter side1: "))
        side2 = int(input("Enter side2: "))
        side3 = int(input("Enter side3: "))
        assert side1 + side2 > side3 or side2 + side3 > side1 or side1 + side3 > side2,"Invalid Input!!!"
        print("Here, Sum of two sides is greater than the third side")
        s = (side1 + side2 + side3) / 2
        area = math.sqrt(s * (s - side1) + s * (s - side2) + s * (s - side3))
        print("Area: ",area)
def main():            
        print("/n**MAIN MENU**")
        print("1. LCM of Two numbers by taking the 2 numbers as input")
        print("2. HCF of Two numbers by taking the 2 numbers as input")
        print("3. Find the Area of Triangle by taking the 3 sides as input")
        option = int(input("\n\nEnter your Choice:"))
        if option == 1 or option == 2 or option == 3:
            if option == 1:
                LCM()
            if option == 2:
                HCF()
            if option == 3:
                triangle_area()
        else:
            print("Invalid choice!!!!!!")
        choice = input("Do you want to continue(y/n):")
        return choice
         
choice = main()
while choice == 'y':
    if choice == 'y':
        choice = main()
    else:
        sys.exit()
