# Pwn: Tricky Indices
Distribute the source, and the binary

Writeup is writeup.md

## Prompt
Find the bug, and print out the flag. Make sure you have a file named `flag.txt`
in the same directory as the binary if you're testing locally. Of course, the
actual flag is on the remote server. If you don't know how to look at a binary
and figure out what it does, do some reversing challenges first.

Connect with `nc forever.isss.io 1301`

Author: Tristan (trab or qwetboy10#8354 on discord)

## Hint
What would happen if you input substring indices that aren't in the bounds of
the string? Where in memory is the flag?

## Flag
`utflag{lul_no_bounds_checks8791342}`
