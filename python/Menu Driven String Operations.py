def main():
    while(1):
        string=input("enter any string")
        choice=eval(input("Enter your choice\n1.finding the position of given substring\n2.replace substring with another substring in the srting\n3.substring seperated by delimiter;\n4.convert the given text in title form\n5.convert lowercase into uppercase and vica versa\n6.exit\nEnter your choice:"))
        if(choice==1):
            search=input("enter the substring to be searched")
            print(string.find(search))
        if(choice==2):
            x=input("enter the substring you want to replace")
            y=input("substring to be replaced with")
            print(string.replace(x,y))
        if(choice==3):
            r=string.split(";")
            print(r)
            for i in r:
                print(i)        
        if(choice==4):
            print(string.title())
        if(choice==5):
            print(string.swapcase())
        if(choice==6):
            return 0


main()
