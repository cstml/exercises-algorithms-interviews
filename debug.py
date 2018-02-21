import os

filename_for_debugger = 'log_debugging' #name of *.txt
filename_for_debugger += '.txt'

f= open(filename_for_debugger,'w')

def debug_reset():
	f.seek(0)

def debug_write(status,text):
	if status is True:
		f.seek(0)
	f.write(text)
	f.write('\n')

def debug_close(self):
	f.close()

