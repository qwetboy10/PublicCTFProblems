from pwn import *

p = remote('ctf.isss.io',5500)
with open('sol','rb') as file:
    stuff = file.read()
    print(str(len(stuff)))
    p.send(stuff)
    p.interactive()
