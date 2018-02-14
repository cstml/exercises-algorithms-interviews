"""
A simple game I developed to learn 
Python
"""
import random
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

    def move_permitted(self,direction,character,step):
        """
        Check if move is permitted
        by checking if the square where
        you want to move is free
        and inside the map
        """
        if (direction == 0) :   #if direction is up
            if character.posx > step:    
                if self.board[character.posx-step][character.posy] is " ": 
                    return 1
                elif self.board[character.posx-step][character.posy] is "X":
                    return 2
                else:
                    return 0

        elif (direction == 3):    #if direction is right
            if character.posy +step < self.maxy:
                if self.board[character.posx][character.posy+step]==" ": 
                    return 1
                elif self.board[character.posx][character.posy+step] is "X": 
                    return 2
            else:
                return 0

        elif (direction == 2):    #if direction is down
            if character.posx + step < self.maxx:
                if self.board[character.posx+step][character.posy]==" ": 
                    return 1
                if self.board[character.posx+step][character.posy] is "X": 
                    return 2                
                else:
                    return 0
            else:
                return 0

        elif (direction == 1):    #if direction is left
            if character.posy > step:
                if self.board[character.posx][character.posy-step]==" ": 
                    return 1
                elif self.board[character.posx][character.posy-step] is "X": 
                    return 2
                else:
                    return 0
        return 0

    def look_zombie(self,zom):
        """
        Define zombie seeing the player
        """
        for look_move in range(0,3,1):
            for step in range(1,4,1):
                if self.move_permitted(look_move,zom,step) is 2:
                    self.move(look_move,zom)
                    return look_move
                elif self.move_permitted(look_move,zom,step) is 0:
                    break
        counter = True
        while counter:
            look_move = random.randint(0,3)
            if self.move_permitted(look_move,zom,1):
                counter = False
                return look_move
        
    def move_zombie(self):
        for zom in self.zombies :
            where_to = self.look_zombie(zom)
            self.move (where_to,zom)
        
    def move (self,direction,character):
        """
        test and move
        """
        if self.move_permitted(direction,character,1):
            if (direction == 3):        #if direction of movement is up (w)
                self.erase(character)
                character.posy += 1
                self.draw(character)

            elif (direction == 1):      #if direction of movement is left (a) 
                self.erase(character)
                character.posy -= 1
                self.draw(character)

            elif (direction == 0):      #if direction of movement is down (s)
                self.erase(character)
                character.posx -= 1
                self.draw(character)

            elif (direction == 2):      #if direction of movement is down (d)         
                self.erase(character)
                character.posx += 1
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
                        self.zombies.append(zombie_character(counter,i))
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
            print (zom.posx)
            print (zom.posy)
            print (self.look_zombie(zom))

    def move_character (self, character):
        message = "Which way are you going to move: \n(Use WASD to move and q to quit)"
        print (message)
        self.moveWay = ic.get()
        print (self.moveWay)
        if self.moveWay in {0,1,2,3} :
            self.move(self.moveWay,character)
        elif self.moveWay == "q" :
            self.GAME=0
        else :
            print ("Bla bla bla")

    def game_loop (self):
        self.GAME = 1
        while self.GAME :
            self.refresh()
            self.move_character(self.player)
            self.move_zombie()

if __name__ == "__main__":
    print '\n' * 100
    print  ("Welcome to escape the troll\n"+
            "Incredible\n")
    user_interface=CLI()
    user_interface.game_loop()


