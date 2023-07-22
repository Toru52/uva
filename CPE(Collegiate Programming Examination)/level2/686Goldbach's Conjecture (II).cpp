686	Goldbach's Conjecture (II)



#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	bool composite[33000] = { true,true,false };
	for (int i = 2; i < 33000; i++)
		if (!composite[i])
			for (int j = i + i; j < 33000; j += i)
				composite[j] = true;
			//prime -> false   not prime -> true

	int n, count;
	while (scanf("%d", &n) != EOF && n) {

		count = 0;
		for (int i = 2; i <= n / 2; i++)
			if (!composite[i] && !composite[n - i]) count++;

		printf("%d\n", count);
	}
	return 0;
}


#include<iostream>
using namespace std;
int main() {
	bool np[33000] = {};
	for (int i = 2; i < 33000; i++)
		if (!np[i])
			for (int j = i + i; j < 33000; j += i)
				np[j] = true;
	int n;
	while (~scanf("%d", &n) && n) {
		int cnt = 0;
		for (int i = 2; i <= n / 2; i++)
			if (!np[i] && !np[n - i])
				cnt++;	
		cout << cnt << endl;
	}
}



Goldbach’s Conjecture: For any even number n greater than or equal 
to 4, there exists at least one pair of prime numbers p1 and p2 
such that n = p1 + p2.
This conjecture has not been proved nor refused yet. 
No one is sure whether this conjecture actually holds. 
However, one can find such a pair of prime numbers, if any, 
for a given even number. The problem here is to write a program 
that reports the number of all the pairs of prime numbers 
satisfying the condition in the conjecture for a given even number.
A sequence of even numbers is given as input. Corresponding to 
each number, the program should output the number of pairs 
mentioned above. Notice that we are interested in the number of 
essentially different pairs and therefore you should not 
count (p1, p2) and (p2, p1) separately as two different pairs.



Input
An integer is given in each input line. You may assume that each 
integer is even, and is greater than
or equal to 4 and less than 2 15. 
The end of the input is indicated by a number ‘0’

Output
Each output line should contain an integer number.
No other characters should appear in the output.



Sample Input
6
10
12
0

Sample Output
1
2
1