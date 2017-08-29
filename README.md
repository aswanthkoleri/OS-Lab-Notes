# OS-Lab-Notes
To better understand the results, I’ve created a simple text file on which we will run our Grep searches; the file contains the following lines:
```
Hi
this
is test file
to carry out few regular expressions
practical with grep
123 456
Abcd
ABCD
```
## Grep command
### grep -i
As you can see, the -i flag causes a search for “abcd” to return matches that have different cases for the characters from what the search string does.
```
[manish@clone ~]$ grep -i 'abcd' testfile
Abcd
ABCD
```
### grep -w
```
[manish@clone ~]$ grep -w 'test' testfile
is test file

```
This type of search only returns lines where the sought-for string is a whole word and not part of a larger word.
### 
