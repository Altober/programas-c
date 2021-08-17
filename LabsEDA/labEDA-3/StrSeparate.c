/*http://www.cplusplus.com/reference/clibrary/cstring/strtok/

Take a look at this, and use whitespace characters as the delimiter. If you need more hints let me know.

From the website:

char * strtok ( char * str, const char * delimiters );
On a first call, the function expects a C string as argument for str, whose first character is used as the starting location to scan for tokens. In subsequent calls, the function expects a null pointer and uses the position right after the end of last token as the new starting location for scanning.

Once the terminating null character of str is found in a call to strtok, all subsequent calls to this function (with a null pointer as the first argument) return a null pointer.

Parameters
str
C string to truncate.
Notice that this string is modified by being broken into smaller strings (tokens). Alternativelly [sic], a null pointer may be specified, in which case the function continues scanning where a previous successful call to the function ended.
delimiters
C string containing the delimiter characters.
These may vary from one call to another.
Return Value
A pointer to the last token found in string. A null pointer is returned if there are no tokens left to retrieve.

Example*/
/* strtok example */
#include <stdio.h>
#include <string.h>

int main (){
  char str[] ="Juan 10 Pedro 5 Catalina 7.8 Adrian 6.7 Marcela 9.1 Javiera 8.3";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL){
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}