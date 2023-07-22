10976 - Fractions Again?!
http://blog.csdn.net/qq_38158040/article/details/69487385



#include<stdio.h>
int main()
{
	int k;
	while (scanf("%d",&k)==1) {
		int p = 0;
		for (int h = k + 1; h <= 2 * k; h++) 
			if (h*k % (h - k) == 0)
				p++;
		printf("%d\n", p);
		for (int h = k + 1; h <= 2 * k; h++)
			if (h*k % (h - k) == 0)
				printf("1/%d = 1/%d + 1/%d\n",
					k, (h*k) / (h - k), h);
	}
	return 0;
}



#include<stdio.h>
int main() {
	int k;
	while (scanf("%d", &k) == 1) {
		int p = 0;
		for (int i = k + 1; i <= k * 2; i++)
			if (i*k % (i - k) == 0)
				p++;
		printf("%d\n", p);
		for (int i = k + 1; i <= k * 2; i++)
			if (i*k % (i - k) == 0)
				printf("1/%d = 1/%d + 1/%d\n",
					k, i*k / (i - k), i);
	}
	return 0;
}

It is easy to see that for every fraction in the form 1
k (k > 0), we can always nd two positive integers
x and y, x  y, such that:
1
k
=
1
x
+
1
y
Now our question is: can you write a program that counts how 
many such pairs of x and y there are for any given k?



Input
Input contains no more than 100 lines, each giving a value 
of k (0 < k  10000).

Output
For each k, output the number of corresponding (x; y) pairs, 
followed by a sorted list of the values of
x and y, as shown in the sample output.



Sample Input
2
12

Sample Output
2
1/2 = 1/6 + 1/3
1/2 = 1/4 + 1/4
8
1/12 = 1/156 + 1/13
1/12 = 1/84 + 1/14
1/12 = 1/60 + 1/15
1/12 = 1/48 + 1/16
1/12 = 1/36 + 1/18
1/12 = 1/30 + 1/20
1/12 = 1/28 + 1/21
1/12 = 1/24 + 1/24