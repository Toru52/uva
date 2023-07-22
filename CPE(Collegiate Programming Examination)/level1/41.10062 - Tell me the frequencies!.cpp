41.10062 - Tell me the frequencies!



#include<stdio.h>
#include<string.h>
int main()
{
	char str[9999];
	int f = 0;
	while (fgets(str,sizeof(str),stdin) != NULL)
	{
		if (f != 0)
			printf("\n");
		f++;
		int a[95] = { 0 }, i, j, len = strlen(str);
		for (i = 0; i<len; i++)
			a[str[i] - ' ']++;
		for (i = 1; i <= len; i++)
			for (j = 94; j >= 0; j--)
				if (a[j] == i)
					printf("%d %d\n", j + ' ', i);
	}
	return 0;
}



no2.
#include<cstdio>
#include<string.h>
int main()
{
	char c[9999];
	int flag = 0;
	while (fgets(c, sizeof(c), stdin)!=NULL)
	{
		if(flag)
			puts("");
		flag++;

		int a[95] = {0};
		for (int i = 0; c[i]; i++)
			a[c[i] - ' ']++;
		for (int i = 1; c[i]; i++)
			for (int j = 94; j >= 0; j--)
				if (a[j] == i)
					printf("%d %d\n", j+' ', i);
	}
}

//   while (fgets(c, sizeof(c), stdin)!=NULL)
  


Given a line of text you will have to find out the frequencies of 
the ASCII characters present in it. The given lines will contain 
one of the first 32 or last 128 ASCII characters. Of course lines 
may end with \n and \r but always keep those out of consideration.



Input
Several lines of text are given as input. Each line of text is 
considered as a single input. Maximum length of each line is 1000.

Output
Print the ASCII value of the ASCII characters which are present 
and their frequency according to the given format below. 
A blank line should separate each set of output. Print the ASCII 
characters in the ascending order of their frequencies. 
If two characters are present the same time print the information
of the ASCII character with higher ASCII value first. 
Input is terminated by end of file.



Sample Input
AAABBC
122333

Sample Output
67 1
66 2
65 3
49 1
50 2
51 3