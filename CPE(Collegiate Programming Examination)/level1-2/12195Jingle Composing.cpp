12195	Jingle Composing



#include <stdio.h>
#include <string.h>
int main()
{
	char str[1000];
	int cnt = 0, i;
	double drtn = 0.0;
	while (fgets(str,1000,stdin))
	{
		if (str[0] == '*') break;
		for (i = 0, cnt = 0; str[i]; i++)
		{
			if (str[i] == '/')
			{
				if (drtn == 1.00) cnt++;
				drtn = 0.00;
			}
			else if (str[i] == 'W') drtn += (1.00);
			else if (str[i] == 'H') drtn += (1.00 / 2.0);
			else if (str[i] == 'Q') drtn += (1.00 / 4.0);
			else if (str[i] == 'E') drtn += (1.00 / 8.0);
			else if (str[i] == 'S') drtn += (1.00 / 16.0);
			else if (str[i] == 'T') drtn += (1.00 / 32.0);
			else if (str[i] == 'X') drtn += (1.00 / 64.0);
		}
		printf("%d\n", cnt);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	double du;
	while (fgets(s, sizeof(s), stdin))
	{
		if (s[0] == '*')
			break;
		int cnt = 0;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == '/')
			{
				if (du == 1)
					cnt++;
				du = 0;
			}
			if (s[i] == 'W')du += 1.0;
			if (s[i] == 'H')du += 1/2.0;
			if (s[i] == 'Q')du += 1/4.0;
			if (s[i] == 'E')du += 1/8.0;
			if (s[i] == 'S')du += 1/16.0;
			if (s[i] == 'T')du += 1/32.0;
			if (s[i] == 'X')du += 1/64.0;
		}
		printf("%d\n", cnt);
	}
}



hints
The sum between shape must be 1, otherwise become wrong duration.



A. C. Marcos is taking his first steps in the direction of jingle 
composition. He is having some troubles, but at least he is 
achieving pleasant melodies and attractive rhythms. In music, 
a note has a pitch (its frequency, resulting in how high or low is
the sound) and a duration(for how long the note should sound). In 
this problem we are interested only in the duration of the notes.
A jingle is divided into a sequence of measures, and a measure is 
formed by a series of notes. The duration of a note is indicated 
by its shape. In this problem, we will use uppercase letters to
indicate a note’s duration. The following table lists all the 
available notes: The duration of a measure is the sum of the 
durations of its notes. In Marcos’ jingles, each measure
has the same duration. As Marcos is just a beginner, 
his famous teacher Johann Sebastian III taught
him that the duration of a measure must always be 1.
For example, Marcos wrote a composition containing five measures, 
of which the first four have the correct duration and the last 
one is wrong. In the example below, each measure is surrounded 
with slashes and each note is represented as in the table above.
/HH/QQQQ/XXXTXTEQH/W/HW/
Marcos likes computers as much as music. He wants you to write a 
program that determines, for each one of his compositions, 
how many measures have the right duration.



Input
The input contains several test cases. Each test case is described
in a single line containing a string whose length is between 3 
and 200 characters, inclusive, representing a composition. 
A composition begins and ends with a slash ‘/’. Measures in a 
composition are separated by a slash ‘/’. Each note in a measure 
is represented by the corresponding uppercase letter, as 
described above. You may assume that each composition contains at 
least one measure and that each measure contains at least 
one note. All characters in the input will be either slashes or 
one of the seven uppercase letters used to represent notes, 
as described above. The last test case is followed by a line 
containing a single asterisk.

Output
For each test case your program must output a single line, 
containing a single integer, the number of measures that have the 
right duration.



Sample Input
/HH/QQQQ/XXXTXTEQH/W/HW/
/W/W/SQHES/
/WE/TEX/THES/
*

Sample Output
4
3
0