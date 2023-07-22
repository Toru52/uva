11063 - B2-Sequence


no1.
#include <cstdio>
#include <cstring>

int main()
{
	int n, total = 0, num[101],V[20001];

	while (scanf("%d", &n) == 1) {
		int judge = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			if (i == 0 && num[i] <= 0)  
				judge = 0;
			if (i >= 1 && (num[i] <= num[i - 1] || num[i] < 0)) 
				judge = 0;
		}
		memset(V, 0, sizeof(V));

		for (int i = 0; i < n && judge; i++)
			for (int j = i; j < n && judge; j++) {
				V[num[i] + num[j]]++;
				if (V[num[i] + num[j]] >= 2)   
					judge = 0;
			}
		if (judge)  
			printf("Case #%d: It is a B2-Sequence.\n\n", ++total);
		else        
			printf("Case #%d: It is not a B2-Sequence.\n\n", ++total);
	}
	return 0;
}



no2.
#include<cstdio>
#include<cstring>

int main()
{
	int seq[101], arr[20001], cnt=0, n;

	while (~scanf("%d", &n))
	{
		int flag = 1;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &seq[i]);
			if (seq[i] <= 0)
				flag = 0;
			if (i >= 1 && seq[i] <= seq[i - 1])
				flag = 0;
		}

		for (int i = 0; i < n&&flag; i++)
			for (int j = i; j < n&&flag; j++)
			{
				arr[seq[i] + seq[j]]++;
				if (arr[seq[i] + seq[j]] >= 2)
					flag = 0;
			}

		if (flag)
			printf("Case #%d: It is a B2-Sequence.\n\n", ++cnt);
		else
			printf("Case #%d: It is not a B2-Sequence.\n\n", ++cnt);
	}
}





A B2-Sequence is a sequence of positive integers
1 ≤ b1 < b2 < b3 . . .
such that all pairwise sums bi +bj , where i ≤ j, are different.
Your task is to determine if a given sequence is a B2-Sequence or not.

Input
Each test case starts with 2 ≤ N ≤ 100, the number of elements in a 
sequence. Next line will have N integers, representing the value of 
each element in the sequence. Each element bi is an integer such that
bi ≤ 10000. There is a blank line after each test case. The input is 
terminated by end of file (EOF).

Output
For each test case you must print the number of the test case, 
starting from 1, and a message indicating if the corresponding 
sequence it is a B2-Sequence or not. See the sample output below. 
After each test case you must print a blank line.



Sample Input
4
1 2 4 8
4
3 7 10 14

4
1 2 3 3
4
15 16 17 18
4
-5 0 5 9
6
1 9 19 0 45 70
6
1 9 19 45 70 150
5
15 16 -1 17 18
4
2 2 2 3

Sample Output
Case #1: It is a B2-Sequence.
Case #2: It is not a B2-Sequence.

Case #1: It is not a B2-Sequence.
Case #2: It is not a B2-Sequence.
Case #3: It is not a B2-Sequence.
Case #4: It is not a B2-Sequence.
Case #5: It is a B2-Sequence.
Case #6: It is not a B2-Sequence.
Case #7: It is not a B2-Sequence.