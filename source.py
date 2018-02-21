"""
A simple game I developed 
in order to sharpen my Python
skills
"""
import random
import collections  #for the use of tuples 
import input_commands as ic
from tempfile import mkstemp
from shutil import move
from os import fdopen, remove
from debug import debug_write as dbg_wrt

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
        dbg_wrt(False,"Zombie:" + str(self))

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
        self.Direction = collections.namedtuple('Direction', 'x y')
        self.read_map()

    def erase(self, character):
        """
        erase will delete the
        character off the map
        and replace it with a
        blank space
        """
        line = list(self.board[character.posx])
        line[character.posy]= ' '
        self.board[character.posx]="".join(line)

    def draw(self,character):
        """
        draw will draw the 
        character at its 
        posx and posy
        """
        line = list(self.board[character.posx])
        line[character.posy]=character.character
        self.board[character.posx]="".join(line)

    def move_permitted(self,direction,character):
        """
        Check if move is permitted
        by checking if the square where
        you want to move is free
        and inside the map
        """
        x = direction.x+character.posx
        y = direction.y+character.posy
        if (x>=0) and (x<=self.maxx):   #if it is boundary
            if (y>=0) and (y<=self.maxy):
                if self.board[x][y] is " ": 
                    return 1
                elif self.board[x][y] is "X":
                    return 2
                else:
                    return 0
        return 0

    def translate_move(self,moveWay):
        if moveWay is 0 :
            return (-1,0)
        elif moveWay is 1 :
            return (0,-1)
        elif self.moveWay is 2 :
            return (1,0)
        elif self.moveWay is 3 :
            return (0,1)

    def look_zombie(self,zom):
        """
        Define zombie looking for the player
        """
        direction=self.Direction(0,0)
        zombie_moved=False
        for look_x in range(-4,4):
            for look_y in range(-4,4):
                    direction=self.Direction(look_x,look_y)
                    ok = self.move_permitted(direction,zom)

                    if ok is 2:
                        if look_x != 0 :
                            look_x=int(look_x/abs(look_x))
                            direction=self.Direction(look_x,0)
                            if self.move_permitted(direction,zom):
                                dbg_wrt(False,str(zom) + ' moves to ' + str(direction))
                                return direction
                        else :
                            look_y=int(look_y/abs(look_y))
                            direction=self.Direction(0,look_y)
                            if self.move_permitted(direction,zom):
                                dbg_wrt(False,str(zom) + ' moves to ' + str(direction))
                                return direction

        while zombie_moved is False:
            look_move_x = random.randint(-1,1)
            look_move_y = random.randint(-1,1)
            direction=self.Direction(look_move_x,look_move_y)
            if self.move_permitted(direction,zom):
                return direction
        
    def move_zombies(self):
        for zom in self.zombies :
            where_to = self.look_zombie(zom)
            self.move (where_to,zom)
        
    def move (self,direction,character):
        """
        test and move
        """
        if self.move_permitted(direction,character):
            self.erase(character)
            character.posx += direction.x
            character.posy += direction.y
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
        
    def won(self):
        for zom in self.zombies:
            if zom.posx==self.player.posx and zom.posy==self.player.posy:
                return 1
        return 0

    def refresh (self,force):
        """
        printing function
        """
        state = self.won()
        if force is True:
            state = 0
        if state is 0:   
            screen = "\n" * 100
            print (screen)
            for i in range(len(self.board)):
                print (self.board[i]),
        elif state is 1:
            self.GAME=0

    def move_player (self, character):
        message = "Which way are you going to move: \n(Use WASD to move and q to quit)"
        print (message)
        self.moveWay = ic.get()
        if self.moveWay in range(0,4):
            if self.moveWay is 0 :
                direction=self.Direction(-1,0)
            elif self.moveWay is 1 :
                direction=self.Direction(0,-1)
            elif self.moveWay is 2 :
                direction=self.Direction(1,0)
            elif self.moveWay is 3 :
                direction=self.Direction(0,1)
            self.move(direction,character)
        elif self.moveWay == "q" :
            self.GAME=0
        else :
            print "Why loose a move like that?"

    def game_loop (self):
        self.GAME = 1
        force = True    #force helps with forcing a 
        weak = False    #last refresh before breaking
        while self.GAME :
            self.refresh(weak)
            if self.GAME is 0:
                self.refresh(force)
                print ("you just lost!")
                print ("thanks for playing")
                break
            self.move_player(self.player)
            self.move_zombies()

if __name__ == "__main__":
    print '\n' * 100
    print  ("Welcome to escape the troll\n"+
            "Incredible\n")
    user_interface=CLI()
    user_interface.game_loop()


