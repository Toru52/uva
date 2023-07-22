No1.

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int add1, add2, carry, count;
	while (scanf("%d%d", &add1, &add2) != EOF && (add1 || add2)) {
		carry = 0;
		count = 0;
		while (add1 || add2) {
			carry = add1 % 10 + add2 % 10 + carry;
			carry /= 10;
			add1 /= 10;
			add2 /= 10;
			if (carry)
				count++;
		}
		if (count == 1)
			printf("1 carry operation.\n");
		else if (count > 1)
			printf("%d carry operations.\n", count);
		else
			printf("No carry operation.\n");
	}
	return 0;
}


No2.

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a, b;
	int carry, cnt;
	int yorn;

	while (scanf("%d%d", &a, &b) != EOF && (a || b))
	{
		carry = 0;
		cnt = 0;
		while (a||b)
		{
			yorn = a % 10 + b % 10 + carry;
			if (yorn >= 10)
				carry = 1;
			else
				carry = 0;
			yorn = 0;
			a /= 10;
			b /= 10;

			if (carry)
				cnt++;	
		}
		if (cnt == 1)
			cout << "1 carry operation." << endl;
		else if(cnt)
			cout << cnt << " carry operations." << endl;
		else
			cout << "No carry operation." << endl;
	}
}




Children are taught to add multi-digit numbers from
right-to-left one digit at a time. Many find the
“carry” operation - in which a 1 is carried from 
one digit position to be added to the next - to be asignificant 
challenge. Your job is to count the number of carry operations 
for each of a set of addition problems so that educators may 
assess their difficulty.

Input
Each line of input contains two unsigned integers 
less than 10 digits. The last line of input contains ‘00’.

Output
For each line of input except the last you should compute 
and print the number of carry operations that would result 
from adding the two numbers, in the format shown below.

Sample Input
123 456
555 555
123 594
0 0

Sample Output
No carry operation.
3 carry operations.
1 carry operation.

