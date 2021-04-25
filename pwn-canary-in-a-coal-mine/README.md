# Pwn: Canary in a Coal Mine
Distribute the binary

Writeup is writeup.md

## Prompt
Quiz time! Better not get the question wrong. I wonder what this weird message
about stack smashing means?

`nc forever.isss.io 1308`

Author: Tristan (trab or qwetboy10#8354 on discord)

## Hint
This problem is based on stack canaries. You need to find some way to bypass the
canary, but besides that it's a normal buffer overflow

## Flag
`utflag{cool_cool_cool90820}`
