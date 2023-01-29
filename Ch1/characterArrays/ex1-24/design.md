# Requirement:

> Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces.  Don't forget
about quotes, both single and double, escape sequences, and comments.  (This program is hard if you do it in full generality

# Plan

Checking for unbalanced parens, brackets, braces, etc is easy enough, just count up and down.  The nuance will be making sure that we 
don't do things like count braces that are part of a quoted string or comment or other edge case.

- If we're in a comment then we don't care to count parens and the like, just that there is a closing symbol for every opening comment
symbol.
- If we're in a quoted string (single or double) then we also don't care to count parens and the like (or /\*'s and \*/'s (I think)).
We just care that every string that is opened is subsequently closed.  (Can a string run over more than one line?)
- We don't want escaped characters to contribute to the counts of non-escaped characters (since they are not the same character!) so
when we encounter a '/' we should ignore the subsequent character (possibly more than one character?).

## Structure

Re-use the get-line fct from earlier exercises to read input, line-by-line, into a char array.  Store the count of each char we
are concerned with in int vars declared in main.  When we encounter an opening char the increment the value and when we encounter
a closing char then decrement the value.  We can re-use some of the function from the previous exercise to avoid counting symbols
in a comment, quoted string, or escape sequence.

# Improvements

Just counting the occurrences of brackets, braces, and parens won't do as they could be in the wrong order.
For example: ')(' is not valid, but '()' is.

We don't handle escape sequences in strings, which is a bug.
