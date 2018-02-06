import sys,tty,termios
class _Getch:
    def __call__(self):
            fd = sys.stdin.fileno()
            old_settings = termios.tcgetattr(fd)
            try:
                tty.setraw(sys.stdin.fileno())
                ch = sys.stdin.read(1)
            finally:
                termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
            return ch

def get():
        inkey = _Getch()
        while(1):
                k=inkey()
                if k!='':break
        if k=='w':
                return "w"
        elif k=='a':
                return "a"
        elif k=='s':
                return "s"
        elif k=='d':
                return "d"
        elif k=='q':
                return "q"
        else:
                print (k)

def get_main(): 
        for i in range(0,20):
                get()

if __name__=='__main__':
        get_main()
