#program for python for making tic toc toe
global a
a = [' ',' ',' ',' ',' ',' ',' ',' ',' ']
k=1
while k<9:
    import random
    b=True
    while b:
        n = random.randint(0,8)
        if(a[n]==1):
          b=False
          break
          
    print(n)
    a[n]=0
    h=int(input())
    a[h]=2
    j=0
    while j<8: 
        print(a[j],end=" " )
        if j==2 or j==5 or j==8:
         print() 
        j=j+1
    i=0
    for i in range(2):
        if a[i]==a[i+3] and a[i+3]==a[i+6] and a[i]==2:
            print("You won")
        elif a[i]==a[i+3] and a[i+3]==a[i+6] and a[i]==0:
            print("You Lost!")
        i=i+1
    i=0
    for i in range(8,3):
        if a[i]==a[i+1] and a[i+2]==a[i+3] and a[i+3]==2:
           print("You Won")
        elif a[i]==a[i+1] and a[i+2]==a[i+3] and a[i+3]==0:
           print("You Lost!")
        i=i+1
    if a[0]==a[4] and a[4]==a[8] and a[0]==2:
        print("You Won")
    elif a[4]==a[2] and a[2]==a[6] and a[2]==2:
        print("You Won")
    elif a[0]==a[4] and a[4]==a[8] and a[0]==0:
        print("You Lost!")
    elif a[4]==a[2] and a[2]==a[6] and a[2]==0:
        print("You Lost!")


#import numpy as np
#
#board = np.zeros((3, 3)).astype(int)
#
#def check_win():
#    if any(np.sum(board, 1)==3) or any(np.sum(board, 0)==3) or sum(np.diag(board))==3 or sum(np.diag(board[::-1]))==3:
#        return True
#    if any(np.sum(board, 1)==-3) or any(np.sum(board, 0)==-3) or sum(np.diag(board))==-3 or sum(np.diag(board[::-1]))==-3:
#        return True
#    return False
#
#def play_turn():
#    x = int(input(f"What is player {turn}'s x position?"))
#    y = int(input(f"What is player {turn}'s y position?"))
#    try:
#        if board[y, x]==0:
#            board[y, x]=turn
#        else:
#            play_turn()
#    except IndexError:
#        play_turn()
#
#turn = 1
#move = 9
#while move >0:
#    print (board)
#    play_turn()
#    if check_win():
#        print (f"Player {turn} has won!")
#        break
#    turn = turn*-1
#    move = move -1 