# Pwn: Jump
Distribute the binary

Writeup is writeup.md

## Prompt
Haha! I removed the obvious security hole! Now you will never be able to exploit
my code!

`nc forever.isss.io 1303`

Author: Tristan (trab or qwetboy10#8354 on discord)

## Hint
Since we removed the if statement and the integer, what else could we overwrite?
Google buffer overflows if you get stuck (This type of buffer overflow is
actually far more common than the last problem)

## Flag
`utflag{cool_cool_cool90820}`
