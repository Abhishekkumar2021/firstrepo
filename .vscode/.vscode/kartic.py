#Tic Tac Toe
#providing reference for user for choosing a correct input easily

print(20*' ',"   reference:    ")
print(20*' ','     |    |      ') 
print(20*' ','  1  | 2  | 3    ')
print(20*' ',"-----+----+----- ")
print(20*' ',"     |    |      ")
print(20*' ',"  4  | 5  | 6    ")
print(20*' ',"-----+----+----- ")
print(20*' ',"     |    |      ")
print(20*' ',"  7  | 8  | 9    \n")

#Displaying board so that user can see which places are remaining and how he can win
def drawBoard(board):
    print()
    print('                               reference:')
    print('     |    |     ',10*' ','     |    |   ',)
    print('  '+board[1]+'  | '+board[2]+'  | '+board[3]+'   ',10*' ','  1  | 2  | 3  ')
    print('-----+----+-----',10*' ',"-----+----+-----")
    print('     |    |     ',10*' ',"     |    |     ")
    print('  '+board[4]+'  | '+board[5]+'  | '+board[6]+'   ',10*' ',"  4  | 5  | 6   ")
    print('-----+----+-----',10*' ',"-----+----+-----")
    print('     |    |     ',10*' ',"     |    |      ")
    print('  '+board[7]+'  | '+board[8]+'  | '+board[9]+'   ',10*' ',"  7  | 8  | 9    \n\n")

import random

def whoGoesFirst():
	print('Do you want to go first? (Yes or No)')
	if  input().lower().startswith('y'):
		return 'player'
	else:
		return 'computer'
	
# Randomly choose the player who goes first.


def inputPlayerLetter():
	letter=''
	while not(letter=='X' or letter=='O'):
		print("Do you want to be 'X' or 'O'?")
		letter = input().upper() 

	if letter == 'X':
		return ['X','O']
	else:
		return ['O','X']


def whoGoesFirst():
	print('Do you want to go first? (Yes or No)')
	if  input().lower().startswith('y'):
		return 'player'
	else:
		return 'computer'
	

def playAgain():
	print('Do you want to play again? (Yes or No)')
	return input().lower().startswith('y')


def makeMove(board, letter, move):
	board[move] = letter


def isWinner(board,letter):
    winning_place = [[1,2,3],[4,5,6],[7,8,9],[1,4,7],[2,5,8],[3,6,9],[1,5,9],[3,5,7]]#places where someone wil win
    for win_place in winning_place:
        if board[win_place[0]] == board[win_place[1]] == board[win_place[2]] == letter:#checking for wining of someone
            return True


def getBoardCopy(board):
	dupBoard = []# Make a duplicate of the board list and return it the duplicate.

	for i in board:
		dupBoard.append(i)

	return dupBoard


def isSpaceFree(board, move):
	return board[move] == ' '


def getPlayerMove(board):
	move = '' # Let the player type in their move.
	while move not in '1 2 3 4 5 6 7 8 9'.split() or not isSpaceFree(board,int(move)):
		print('What is your next move? (1-9)')
		move = input()
	return int(move)


def chooseRandomMoveFromList(board, movesList):
	possibleMoves = []# Returns a valid move from the passed list on the passed board.
	for i in movesList:
		if isSpaceFree(board, i):
			possibleMoves.append(i)

	if len(possibleMoves) != 0:
		return random.choice(possibleMoves)
	else:
		return None
	# Returns None if there is no valid move.


def minimax(board, depth, isMax, alpha, beta, computerLetter):
	if computerLetter == 'X':
		playerLetter = 'O'  # Given a board and the computer's letter, determine where to move and return that move.
	else:
		playerLetter = 'X'

	if isWinner(board, computerLetter):
		return 10
	if isWinner(board, playerLetter):
		return -10
	if isBoardFull(board):
		return 0

	if isMax:
		best = -1000

		for i in range(1,10):
			if isSpaceFree(board, i):
				board[i] = computerLetter
				best = max(best, minimax(board, depth+1, not isMax, alpha, beta, computerLetter) - depth)
				alpha = max(alpha, best)
				board[i] = ' '

				if alpha >= beta:
					break

		return best
	else:
		best = 1000

		for i in range(1,10):
			if isSpaceFree(board, i):
				board[i] = playerLetter
				best = min(best, minimax(board, depth+1, not isMax, alpha, beta, computerLetter) + depth)
				beta = min(beta, best)
				board[i] = ' '

				if alpha >= beta:
					break

		return best


def findBestMove(board, computerLetter):
	if computerLetter == 'X':
		playerLetter = 'O'	# Given a board and the computer's letter, determine where to move and return that move.
	else:
		playerLetter = 'X'

	bestVal = -1000
	bestMove = -1


	for i in range(1,10):
		if isSpaceFree(board, i):
			board[i] = computerLetter

			moveVal = minimax(board, 0, False, -1000, 1000, computerLetter)

			board[i] = ' '

			if moveVal > bestVal:
				bestMove = i
				bestVal = moveVal

	return bestMove


def isBoardFull(board):	# Return True if every space on the board has been taken. Otherwise return False.
	for i in range(1,10):
		if isSpaceFree(board, i):
			return False
	return True


print('\nWelcome to Tic Tac Toe!\n')

while True:
	theBoard = [' '] * 10
	playerLetter, computerLetter = inputPlayerLetter()
	turn = whoGoesFirst()
	print('The ' + turn + ' will go first.')# Reset the board
	gameIsPlaying = True

	while gameIsPlaying:
		if turn == 'player':
			drawBoard(theBoard)
			move = getPlayerMove(theBoard)
			makeMove(theBoard, playerLetter, move)

			if isWinner(theBoard, playerLetter):
				drawBoard(theBoard)
				print('You won the game')
				gameIsPlaying = False
			else:
				if isBoardFull(theBoard):
					drawBoard(theBoard)
					print('The game is a tie')
					break
				else:
					turn = 'computer'
		else:
			move = findBestMove(theBoard, computerLetter)
			makeMove(theBoard, computerLetter, move)

			if isWinner(theBoard, computerLetter):
				drawBoard(theBoard)
				print('You lose the game')
				gameIsPlaying = False
			else:
				if isBoardFull(theBoard):
					drawBoard(theBoard)
					print('The game is a tie')
					break
				else:
					turn = 'player'
	if not playAgain():
		break