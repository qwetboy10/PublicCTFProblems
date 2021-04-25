UTF8 parser is dumb and eats characters, so you can trick it into eating the quotes. If you look at this [table](https://en.wikipedia.org/wiki/UTF-8) you will see that a byte starting with 11110 (like 0xf7) means the next 3 bytes are part of the codepoint. A good parser would notice that the next three bytes don't start with 10 and refuse to consume them, but my parser is bad. That means the parser will eat 3 single quotes, allowing you to have a simple command injection

echo -ne "bob\xf7'; cat flag.txt; \xf7'wait" | ./prob
