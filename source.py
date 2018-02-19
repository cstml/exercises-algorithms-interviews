"""
A simple game I developed to learn 
Python
"""
import random
import collections  #for the use of tuples 
import input_commands as ic
from tempfile import mkstemp
from shutil import move
from os import fdopen, remove

class zombie_character (object):
    """
    A class defining the zombie 
    character
    """

    def __init__(self,x=0,y=0):
        """
        initialise the zombie
        and the zombie's position
        """
        self.posx = x     
        self.posy = y
        self.character='Z'
        self.health=100
        self.aware=[][]

class player_character (object):
    """
    a class that defines the player's
    instance and position of character
    """

    def __init__ (self,x=0,y=0):
        """
        initialise the character
        """
        self.posx=0
        self.posy=0
        self.character='X'
        self.health=100
    
class CLI ():

    def __init__ (self):
        """
        initialise
        the map and the player
        read the map from the input file
        find the player's & zombies' position
        """
        self.board = []
        self.player = player_character()
        self.zombies=[]
        self.maxx = 0
        self.maxy = 0
        self.read_map()

    def erase(self, character):
        line = list(self.board[character.posx])
        line[character.posy]= ' '
        self.board[character.posx]="".join(line)

    def draw(self,character):
        line = list(self.board[character.posx])
        line[character.posy]=character.character
        self.board[character.posx]="".join(line)

    def move_permitted(self,direction_x,direction_y,character):
        """
        Check if move is permitted
        by checking if the square where
        you want to move is free
        and inside the map
        """
        x = direction_x+character.posx
        y = direction_y+character.posy
        if (x>=0) && (x<=self.maxx) :   #if it is boundary
            if (y>=0) && (y<=self.maxy)
                if self.board[x][y] is " ": 
                    return 1
                elif self.board[x][y] is "X":
                    return 2
                else:
                    return 0
        return 0

    def translate_move(self,moveWay):
        if moveWay is 0 :
            self.move(-1,0,character)
        elif self.moveWay is 1 :
            self.move(0,-1,character)
        elif self.moveWay is 2 :
            self.move(1,0,character)
        elif self.moveWay is 3 :
            self.move(0,1,character)

    def look_zombie(self,zom):
        """
        Define zombie seeing the player
        """
        zombie_moved=0
        for look_x in range(-4,4):
            for look_y in range(-4,4):
                    position_x=zom.posx+look_x
                    position_y=zom.posy+look_y
                    ok = self.move_permitted(position_x,position_y,zom)

                    if  ok is 2:
                        if look_x != 0 :
                            move(position_x/mod(position_x),0,zom)
                            zombie_moved = 1
                        else :
                            move(0,position_y,zom)
                    
                    elif ok is 0:
                        break

        while zombie_moved is 0:
            look_move = random.randint(0,3)
            if self.move_permitted(look_move,zom,1):
                counter = False
                return look_move
        
    def move_zombies(self):
        for zom in self.zombies :
            where_to = self.look_zombie(zom)
            self.move (where_to,zom)
        
    def move (self,direction_x,direction_y,character):
        """
        test and move
        """
        if self.move_permitted(direction_x,direction_y,character):
            self.erase(character)
            character.posx += direction_x
            character.posy += direction_y
            self.draw(character)

    def read_map(self):
        """
        open map.in 
        read the map
        read the position of the characters 
        """
        i=0
        zc=0
        with open("map.in") as textFile:
            for line in textFile:
                self.board.append(line)
                counter=0
                for j in line:
                    if j is "X" :
                        self.player.posy=counter
                        self.player.posx=i
                    if j is "Z":
                        self.zombies.append(zombie_character(i,counter))
                    counter+=1
                i+=1
        self.maxy=len(self.board[self.player.posx])
        self.maxx=i
        
    def refresh (self):
        screen = "\n" * 100
        print (screen)
        for i in range(len(self.board)):
            print (self.board[i]),
        print (self.player.posx)
        print (self.player.posy)
        for zom in self.zombies:
            print (zom.posx,zom.posy)
           

    def move_player (self, character):
        message = "Which way are you going to move: \n(Use WASD to move and q to quit)"
        print (message)
        self.moveWay = ic.get()
        print (self.moveWay)
        if self.moveWay is 0 :
            self.move(-1,0,character)
        elif self.moveWay is 1 :
            self.move(0,-1,character)
        elif self.moveWay is 2 :
            self.move(1,0,character)
        elif self.moveWay is 3 :
            self.move(0,1,character)
        elif self.moveWay == "q" :
            self.GAME=0
        else :
            print ("Bla bla bla")

    def game_loop (self):
        self.GAME = 1
        while self.GAME :
            self.refresh()
            self.move_player(self.player)
            self.move_zombies()

if __name__ == "__main__":
    print '\n' * 100
    print  ("Welcome to escape the troll\n"+
            "Incredible\n")
    user_interface=CLI()
    user_interface.game_loop()


