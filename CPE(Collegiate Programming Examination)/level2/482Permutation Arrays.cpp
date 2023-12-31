482	Permutation Arrays



#include <stdio.h>
#include <string.h>
#define N 1000
int pos[N];
char arr[N][N];
int main()
{
	int n,tmp,cnt;
	bool state = true;

	scanf("%d\n", &n);
	while (n--)
	{
		if (!state)  
			printf("\n");
		state = false;
		cnt = 0;
		while (true)
		{
			scanf("%d", &tmp);
			pos[tmp - 1] = cnt++;

			if (getchar() == '\n')
				break;
		}
		for (int i = 0; i < cnt; i++)
			scanf("%s", arr[i]);
		for (int i = 0; i < cnt; i++)
			printf("%s\n", arr[pos[i]]);
	}
}



#include<cstdio>
int pos[1000];
char arr[1000][1000];
int main() {
	int n, rank;
	bool F = false;

	scanf("%d\n", &n);
	while (n--) {
		int cnt = 0;

		if (F)
			puts("");
		F = true;
		while (1) {
			scanf("%d", &rank);
			pos[rank - 1] = cnt++;
			if ((rank = getchar()) == '\n')
				break;
		}
		for (int i = 0; i < cnt; i++)
			scanf("%s", &arr[i]);
		for (int i = 0; i < cnt; i++)
			printf("%s\n", arr[pos[i]]);
	}
}


In many computer problems, it is necessary to permute data 
arrays. That is, the data in an array must be re-arranged in 
some specified order. One way to permute arbitrary data arrays 
is to specify the permutations with an index array to point 
out the position of the elements in the new array. Let x be an
array that is to be permuted and let x′ be the permuted array. Then, we have the relationship
between x and x′ that x′ pi = xi.



Input
The input begins with a single positive integer on a line by 
itself indicating the number of the cases
following, each of them as described below. 
This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
Each input set will contain two lines of numbers. 
The first line will be an index array p containing
the integers 1 . . . n, where n is the number of integers in 
the list. The numbers in the first line will have
been permuted in some fashion. The second line will contain a
list numbers in floating point format.



Output
For each test case, the output must follow the description 
below. The outputs of two consecutive cases
will be separated by a blank line.
The output for this program will be the list of floating 
point numbers from the input set, ordered
according to the permutation array from the input file. 
The output numbers must be printed one per
line in the same format in which they each appeared in the 
input file.



Sample Input
1
3 1 2
32.0 54.7 -2

Sample Output
54.7
-2
32.0