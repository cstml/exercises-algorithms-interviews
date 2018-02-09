"""
A simple game I developed to learn 
Python
"""

import input_commands as ic
from tempfile import mkstemp
from shutil import move
from os import fdopen, remove

#initialize the map and create the player
class character (object):
    """
    a class that defines the player's
    instance and position of character
    """
    def __init__ (self):
        """
        initialise the character
        """
        self.posx=0
        self.posy=0
        self.character='X'
        self.health=100
        self.maxx=0
        self.maxy=0
    
    def erase(self,board):
        line = list(board[self.posx])
        line[self.posy]= ' '
        board[self.posx]="".join(line)

    def replace(self,board,symbol):
        line = list(board[self.posx])
        line[self.posy]=symbol
        board[self.posx]="".join(line)

    def move_permitted(self,direction,board):
        """
        Check if move is permitted
        by checking if the square where
        you want to move is free
        and inside the map
        """
        print (direction,board)
        if "d" == direction :
            line = list(board[self.posx])
            print (line)
            if line[self.posy+1] is " ": 
                return 1
            else:
                return 0

        if (direction == "w"):
            if self.posx > 1:
                line = list(board[self.posx-1])
                if line[self.posy]==" ": 
                    return 1
                else:
                    return 0

        if (direction == "s"):
            if self.posx < self.maxx:
                line = list(board[self.posx+1])
                if line[self.posy]==" ": 
                    return 1
                else:
                    return 0
            else:
                return 0

        if (direction == "a"):
            if self.posy > 1:
                line = list(board[self.posx])
                if line[self.posy-1]==" ": 
                    return 1
                else:
                    return 0


    def move_right (self,board):
        if self.move_permitted("d",board):
            self.erase(board)
            self.posy += 1
            self.replace(board,self.character)


    def move_left (self,board):
        if self.move_permitted("a",board):
            self.erase(board)
            self.posy -= 1
            self.replace(board,self.character)

    def move_up (self,board):
        if self.move_permitted("w",board):
            self.erase(board)
            self.posx -= 1
            self.replace(board,self.character)


    def move_down (self,board) :
        if self.move_permitted("s",board):
            self.erase(board)
            self.posx += 1
            self.replace(board,self.character)


class CLI ():

    def __init__ (self):
        """
        initialise
        the map and the player
        read the map from the input file
        find the players position
        """
        self.board = []
        self.player = character()
        self.read_map(self.board,self.player)
        self.game_loop()

    def read_map(self,board,player):
        """
        open map.in and read the map 
        """
        i=0
        with open("map.in") as textFile:
            for line in textFile:
                board.append(line)
                counter=0
                for j in line:
                    if j is "X" :
                        player.posy=counter
                        player.posx=i
                    counter+=1
                i+=1
        player.maxy=len(board[player.posx])
        player.maxx=i
        
    def refresh (self):
        screen = "\n" * 100
        print (screen)
        for i in range(len(self.board)):
            print (self.board[i]),
        print (self.player.posx)
        print (self.player.posy)

    def move (self, player):
        message = "Which way are you going to move: \n(Use WASD to move and 2xQ to quit)"
        print (message)
        self.moveWay = ic.get()
        if "w" in self.moveWay :
            player.move_up(self.board)
        elif "a" in self.moveWay:
            player.move_left(self.board)
        elif "s" in self.moveWay:
            player.move_down(self.board)
        elif self.moveWay == "d" :
            player.move_right(self.board)
        elif self.moveWay == "q" :
            self.GAME=0
        else :
            print ("Bla bla bla")

    def game_loop (self):
        self.GAME = 1
        while self.GAME :
            self.refresh()
            self.move (self.player)

if __name__ == "__main__":
    print '\n' * 100
    print  ("Welcome to escape the troll\n"+
            "Incredible\n")
    user_interface=CLI()
    user_interface.game_loop()


