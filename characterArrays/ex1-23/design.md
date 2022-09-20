# Requirement:

>Write a program to remove all comments from a C program.  Don't forget to handle quoted strings and character
constants properly.  C comments do not nest.


# Plan

Re use the get_line fct from earlier exercises to get input line by line.  Then we'll just worry about removing
comments from single arrays and can handle everyting as fcts on arrays of characters.

Get a line, then:
- iterate through it's contents, adding them to a second array, until we hit a `/` character.
    - see if the next character is `*`, and if so stop adding characters to the 'print' array until we find the next
    uncomment.
- if we find a `'` character, then we don't want to stop copying characters to the print array as we are then dealing
with character constants, so don't stop copying even if we encounter `/*`. *Is this actually true?  What about if there are loads of characters between the `'` ?*
    - when we're between single quotes we'll have to ignore any `"`'s since they don't mean what they usually do in
    that context.
- if we find a `"` the we know that, until we encounter another `"`, we are in a quoted string, and so want to keep
copying over characters since you can't put a comment in a quoted string. *I think...*
    - so, we'll need to keep track of whether or not we are in a quoted string.
    - we should ignore all special characters in a quoted string (such as `'` which we discussed a moment ago).