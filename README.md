# Unicode

I've been taking part in a database migration, and we have had issues related to character encoding. Since this is an area that I didn't know too much about, I decided to do some research. I read a bunch of articles about various character sets, particularly Unicode. This is a repo for my experiments playing with Unicode.

## utf8.c

Takes a Unicode code point (in hex) and produces the bytes for the UTF-8 character (in hex), and also prints the character.

Example:

    Enter a Unicode code point: 20ac
    Hex bytes: e2 82 ac 
    Character: €

## iso88951toutf8.c

Takes a file encoded in ISO-8859-1 and converts it to UTF-8. Prints the file to STDOUT, so you'll need to redirect to save.
