from tempfile import mkstemp
from shutil import move
from os import fdopen, remove

#initialize the map and create the player
def initialize_map (this_file,g_map,main_player):
    a = open (this_file,"r")
    line=1;
    x = a.readline()
    while x:
        g_map[line]=list(x)
        position = x.find("X")
        if position > 0:
            main_player.pos_x=line
            main_player.pos_y=position
        x=a.readline()
        line += 1
        
#replace line to allow for move
def replace_line(file_path,pattern,subst):
    fh, abs_path = mkstemp()
    with fdopen (fh,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_file.write(line.replace(pattern, subst))
    remove (file_path)
    move (abs_path, file_path)

#find the the position where the player is located
def find_player(this_file):
    a = open (this_file,"r")
    lines = 0
    x = a.readline()
    while x:
        lines +=1
        position=0
        position=x.find("X")
        print (x)
        print (position)
        if position > 0:
            return lines
        x = a.readline()

def file_len(this_file):
    a = open (this_file,"r")
    lines = 0
    readline=a.readline
    while readline():
        lines +=1
    return lines


# A class defining the character's properties
class Character:
    
    def move_right(self):
        if in_bound(sel.pos_x,self.pos_y,0,1):
            self.pos_x=self.pos_x+1

    def move_left(self):
        self.pos_y=1

    def __init__ (self):
        self.pos_y=0
        self.pos_x=0
        friendly = 0

def action_do(who):
    move = "asd"
    input (move)

#    if move == "w":
#        move_up(who)
#        if move == "a":
#            move_left(who)
#            if move == "s":
#                move_down(who)
#                if move == "d":
#                    move_right(who)
#                else:
#                   print ("please re-enter")
#                   action_do(who)

def play_game():
    while running: 
        action_do(player)
        if running:
            enemy_move(enemy)
        

#THIS IS A NICE GAME
w,h = 100, 100
game_map = [[0 for x in range(w)] for y in range (h)]
running = 1

main_player = Character()

initialize_map("map.in",game_map,main_player)
play_game ()

print(main_player.pos_x)
print(main_player.pos_y)

xx = main_player.pos_x
yy = main_player.pos_y
print (game_map[xx][yy])
        
