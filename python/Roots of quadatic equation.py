def main():
    import cmath
    print("\t","Roots of quadatic equation")
    print("for the equation of type ax^^2+bx+c")
    a=eval(input("enter the value of a"))
    b=eval(input("enter the value of b"))
    c=eval(input("enter the value of c"))
    d=cmath.sqrt((b**2)-(4*a*c))
    #print("discriminant=",d)
    x=(-b+d)/(2*a)
    y=(-b-d)/(2*a)
    print("root of the equation are",x,"and",y)
main()    
    
