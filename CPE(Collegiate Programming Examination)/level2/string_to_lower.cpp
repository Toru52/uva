string to lower
http://www.programmingsimplified.com/c/program/c-program-change-case



strlwr in c

#include <stdio.h>
#include <string.h>
 
int main()
{
   char string[1000];
 
   printf("Input a string to convert to lower case\n");
   gets(string);
 
   printf("Input string in lower case: \"%s\"\n",strlwr(string));
 
   return  0;
}




strupr in c

#include <stdio.h>
#include <string.h>
 
int main()
{
   char string[1000];
 
   printf("Input a string to convert to upper case\n");
   gets(string);
 
   printf("Input string in upper case: \"%s\"\n",strupr(string));
 
   return  0;
}