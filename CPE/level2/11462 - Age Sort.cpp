11462 - Age Sort
http://knightzone.org/?p=2580



#include <stdio.h>
#include <algorithm>

int main() {
	int n;
	while (scanf("%d", &n),n) {
		int *age = new int[n + 5];
		for (int i = 0; i < n; ++i) {
			scanf("%d", &age[i]);
		}

		std::sort(age, age + n);

		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d", age[i]);
		}
		puts("");

		delete[] age;
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
int main() {
	int n;
	while (scanf("%d", &n), n) {
		int *age = new int[n + 1];
		for (int i = 0; i < n; i++)
			scanf("%d", &age[i]);
		std::sort(age, age + n);
		for (int i = 0; i < n; i++) {
			if (i)
				putchar(' ');
			printf("%d", age[i]);
		}
		puts("");
		delete[] age;
	}
	return 0;
}



You are given the ages (in years) of all people of a country with 
at least 1 year of age. You know that
no individual in that country lives for 100 or more years. 
Now, you are given a very simple task of
sorting all the ages in ascending order.



Input
There are multiple test cases in the input le. Each case starts 
with an integer n (0 < n  2000000), the total number of people.
 In the next line, there are n integers indicating the ages. 
 Input is terminated with a case where n = 0. 
 This case should not be processed.
 
Output
For each case, print a line with n space separated integers. 
These integers are the ages of that country
sorted in ascending order.
Warning: Input Data is pretty big ( 25 MB) so use faster IO.



Sample Input
5
3 4 2 1 5
5
2 3 2 3 1
0

Sample Output
1 2 3 4 5
1 2 2 3 3