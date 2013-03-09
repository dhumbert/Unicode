Unicode
=======

I've been taking part in a database migration, and we have had issues related to character encoding. Since this is an area that I didn't know too much about, I decided to do some research. I read a bunch of articles about various character sets, particularly Unicode. This is a repo for my experiments playing with Unicode. The first file, utf8.c is a program that takes a Unicode code point and produces the bytes for the UTF-8 character (in hex), and also prints the character.

Example:

    Enter a Unicode code point: 200A0
    Hex bytes: f0 a0 82 a0 
    Character: 𠂠
