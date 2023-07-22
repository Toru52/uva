488	Triangle Wave



#include <cstdio>

int main() {
	int tc, f, a;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d\n%d", &a, &f);

		for (int i = 0; i < f; i++) {
			for (int j = 1; j <= a; j++) {
				for (int k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			for (int j = a - 1; j >= 1; j--) {
				for (int k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			if (i != f - 1)
				printf("\n");
		}
		if (tc)
			printf("\n");
	}
	return 0;
}



no2.
#include<cstdio>
int main()
{
	int cas, top, num;
	scanf("%d", &cas);
	getchar();
	for (int n = 1; n <= cas; n++)
	{
		scanf("%d %d", &top, &num);
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= top; j++) {
				for (int k = 1; k <= j; k++)
					printf("%d", j);
				puts("");
			}
			for (int j = top - 1; j > 0; j--) {
				for (int k = 1; k <= j; k++)
					printf("%d", j);
				puts("");
			}
			if (i < num)
				puts("");
		}
		if (n < cas)
			puts("");
	}
}





In this problem you are to generate a triangular wave form 
according to a specified pair of Amplitude and Frequency.



Input
The input begins with a single positive integer on a line by 
itself indicating the number of the cases following, each of 
them as described below. This line is followed by a blank line, 
and there is also a blank line between two consecutive inputs.
Each input set will contain two integers, each on a separate 
line. The first integer is the Amplitude;
the second integer is the Frequency.

Output
For each test case, the output must follow the description 
below. The outputs of two consecutive cases will be separated 
by a blank line. For the output of your program, you will be 
printing wave forms each separated by a blank line. The total 
number of wave forms equals the Frequency, and the horizontal 
“height” of each wave equals the Amplitude. The Amplitude will 
never be greater than nine. The waveform itself should be 
filled with integers on each line which indicate the “height” 
of that line.
NOTE: There is a blank line after each separate waveform, 
excluding the last one.



Sample Input
1
3
2

Sample Output
1
22
333
22
1
1
22
333
22
1
