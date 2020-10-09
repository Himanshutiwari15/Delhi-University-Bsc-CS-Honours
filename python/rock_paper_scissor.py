#Program for rock paper scissor game 
#CREATED by ANSH RASTOGI
import time
player1=input("Enter the Name of Player 1:")
player2=input("Enter the Name of player 2:")
print(f'Hi {player1} and {player2},WELCOME to ROCK, PAPER, SCISSORS!!!!!!!!!!!!!!!!!')
time.sleep(5)
print('''KINDLY ATTENTION PLEASE,Here are the instructions:
	1.Don't use all uppercase letters.
	2.Always start the word with an uppercase letter.
	3.Marking 'No' in ready or not statement marks the end of the game.
	4. The game will be of five points, the one who scores more than the other will win.''')
i=1
f=0
point1=0
point2=0
ready1=input(f'{player1},Are you ready(Yes/No)?')
ready2=input(f'{player2},Are you ready(Yes/No)?')
while i==1:
	if(ready1=="Yes" and ready2=="Yes"):
		i=1
		f+=1;
		play1=input(f'{player1} , Its your turn (choose Rock , Paper or Scissor):')
		play2=input(f'{player2} , Its your turn (choose Rock , Paper or Scissor):')
		if(play1=='Rock' and play2=='Paper')or(play1=='Rock' and play2=='Scissor'):
   			point1+=1
   			print(f'{player1},You got this one ,huh!')
		elif(play2=='Rock' and play1=='Paper')or(play2=='Rock' and play1=='Scissor'):
   			point2+=1
   			print(f'{player2},You got this one ,huh!')
		elif(play1=='Scissor' and play2=='Paper'): 
   			point1+=1   
   			print(f'{player1},You got this one ,huh!')
		elif(play2=='Scissor' and play1=='Paper'):    
   			point2+=1
   			print(f'{player2},You got this one ,huh!')
		elif(play1==play2):
   			print('WOW!You are the same kinda people ,huh?')
	elif(ready1=='No' or ready2=='No'):	      	
		print("Thanks for playing!!,See you next time rasta ;)")
		i=0	
	if f==5:
   		print("THE GAME ENDS NOW!!!!!!!!!")
   		break		
if(point1>point2):
	print(f'{player1}, Congrats!!! You Won,having {point1} points')
if(point2>point1):
	print(f'{player2}, Congrats!!! You Won,having {point2} points.')
