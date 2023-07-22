UVa 10188 - Automated Judge Script
https://github.com/rezwan4029/UVA-CODES/blob/master/10188%20-%20Automated%20Judge%20Script.cpp


#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[207] = {};
	int given, ans, cs = 1;
	while (scanf("%d", &given) && given) {
		getchar();
		string x = "", y = "", r1 = "", r2 = "";
		for (int i = 0; i < given; i++) {
			fgets(str,sizeof(str),stdin);
			r1 += str;
			int len = strlen(str);
			for (int j = 0; j < len; j++) 
				if (isdigit(str[j])) 
					x += str[j];
		}
		scanf("%d", &ans);
		getchar();
		for (int i = 0; i < ans; i++) {
			fgets(str, sizeof(str), stdin);
			r2 += str;
			int len = strlen(str);
			for (int j = 0; j < len; j++) 
				if (isdigit(str[j])) 
					y += str[j];
		}
		printf("Run #%d: ", cs++);
		if (r1 == r2 && ans == given) 
			puts("Accepted");
		else if (x == y) 
			puts("Presentation Error");
		else 
			puts("Wrong Answer");
	}
}



#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int a, b, cnt = 1;
	while (scanf("%d", &a) == 1 && a) {
		getchar();
		char str[210] = {};
		string s1 = "", s2 = "", x = "", y = "";
		for (int i = 0; i < a; i++) {
			fgets(str, sizeof(str), stdin);
			s1 += str;
			for (int j = 0; j[str]; j++)
				if (isdigit(str[j]))
					x += str[j];
		}
		scanf("%d", &b);
		getchar();
		for (int i = 0; i < b; i++) {
			fgets(str, sizeof(str), stdin);
			s2 += str;
			for (int j = 0;j[str]; j++)
				if (isdigit(str[j]))
					y += str[j];
		}
		printf("Run #%d: ", cnt++);
		if (a == b&&s1 == s2)
			puts("Accepted");
		else if (x == y)
			puts("Presentation Error");
		else
			puts("Wrong Answer");
	}
	return 0;
}


The judges from the programming contests are known to be very 
mean and very lazy. We, judges, want less work and more Wrong 
Answers! So, we’d like you to help us and write an automated 
judge script to judge solution runs from teams all over the world.
 All you have to do is write a program which receives the 
 standard solution and a team output and gives as answer one of 
 the following messages: “Accepted”, “Presentation Error” or
 “Wrong Answer”. We define each one as: Accepted: As we are very 
 mean judges, we only want you to give ‘Accepted’ as answer if 
 the team output matches the standard solution integrally. 
 That is, ALL characters must match and must be in the same order.
Presentation Error: We want you to give ‘Presentation Error’ 
if all NUMERIC characters match (and in the same order) 
but there is at least one non-numeric character wrong 
(or in wrong order). For instance, ‘15 0’ and ‘150’ would 
receive a ‘Presentation Error’, whereas ‘15 0’ and ‘1 0’
would not (it would receive ‘Wrong Answer’, see bellow).
Wrong Answer: If the team output could not be classified as any 
of the two above, then you have no option but to give 
‘Wrong Answer’ as an answer!



Input
The input will consist of an arbitrary number of input sets. 
Each input set begins with a positive integer n < 100, 
alone in a line, which describes the number of lines of the 
standard solution. The next n lines contain the standard solution.
Then there is a positive integer m < 100, alone in a line, 
which describes the number of lines of the team output. 
The next m lines contain the team output. 
The input is terminated by a value of n = 0,
and should not be processed. 
No line will have more than 120 characters.

Output
For each set you should output one of the following lines:
Run #x: Accepted
Run #x: Presentation Error
Run #x: Wrong Answer
Where x stands for the number of the input set (starting from 1).



Sample Input
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 15
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 5
3
Input Set #1: YES
Input Set #2: NO
Input Set #3: NO
3
Input Set #0: YES
Input Set #1: NO
Input Set #2: NO
1
1 0 1 0
1
1010
1
The judges are mean!
1
The judges are good!
0

Sample Output
Run #1: Accepted
Run #2: Wrong Answer
Run #3: Presentation Error
Run #4: Wrong Answer
Run #5: Presentation Error
Run #6: Presentation Error