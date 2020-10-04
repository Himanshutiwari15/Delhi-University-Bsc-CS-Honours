n=int(input("enter value of n:"))
term1=0
term2=1
for i in range(0,n):
	if(i==0): #to print 1st term
	  print(term1)
	  continue
	if(i==1): #to print 2nd term
	  print(term2)
	  continue
	newterm=term1+term2
	term1=term2
	term2=newterm
	print(newterm)
