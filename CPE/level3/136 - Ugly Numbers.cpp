136 - Ugly Numbers
https://acmproblemsolution.blogspot.tw/2013/01/solution-of-136-ugly-numbers.html



#include<stdio.h>
#include<algorithm>
int main()
{
	long ugly[1502]{1,1};
	int x, y, z, a = 1, b = 1, c = 1, n = 1;
	while (n != 1500) {
		x = 2 * ugly[a], y = 3 * ugly[b], z = 5 * ugly[c];
		//ugly is smmalest number in x,y,z
		ugly[++n] = std::min(x, std::min(y, z));
		if (ugly[n] == x)
			a++;
		if (ugly[n] == y)
			b++;
		if (ugly[n] == z)
			c++;
	}
	printf("The 1500'th ugly number is %ld.\n", ugly[1500]);
	return 0;
}



/*
ugly numbers -> 2,3,5 common numbers
*/
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 1500’th ugly number.



Input
There is no input to this program.
Output
Output should consist of a single line as shown below, with ‘<number>’ 
replaced by the number computed.

Sample Output
The 1500'th ugly number is 859963392.