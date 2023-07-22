608 - Counterfeit Dollar



#include <stdio.h>
struct record {
	char l[7], r[7], judge[5];
}data[3];
int main()
{
	int T, i, j, k;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < 3; i++)
			scanf("%s%s%s", data[i].l, data[i].r, data[i].judge);
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 3; j++) {
				int suml = 0, sumr = 0;
				for (k = 0; data[j].r[k]; k++) {
					suml += (data[j].l[k] - 'A' != i);
					sumr += (data[j].r[k] - 'A' != i);
				}
				if (suml == sumr && data[j].judge[0] == 'e')    continue;
				if (suml > sumr && data[j].judge[0] == 'u')     continue;
				if (suml < sumr && data[j].judge[0] == 'd')     continue;
				break;
			}
			if (j == 3)  break;
		}
		if (i != 12)
			printf("%c is the counterfeit coin and it is light.\n", i + 'A');
		else {
			for (i = 0; i < 12; i++) {
				for (j = 0; j < 3; j++) {
					int suml = 0, sumr = 0;
					for (k = 0; data[j].r[k]; k++) {
						suml += (data[j].l[k] - 'A' == i);
						sumr += (data[j].r[k] - 'A' == i);
					}
					if (suml == sumr && data[j].judge[0] == 'e')    continue;
					if (suml > sumr && data[j].judge[0] == 'u')     continue;
					if (suml < sumr && data[j].judge[0] == 'd')     continue;
					break;
				}
				if (j == 3)  break;
			}
			printf("%c is the counterfeit coin and it is heavy.\n", i + 'A');
		}
	}
	return 0;
}



#include<stdio.h>

struct balance {
	char l[7], r[7], eud[4];
}B[3];

int main() {
	int n, i, j;
	scanf("%d", &n);
	while (n--) {
		for (i = 0; i < 3; i++)
			scanf("%s %s %s", &B[i].l, &B[i].r, &B[i].eud);

		for (i = 0; i < 12; i++) {
			for (j = 0; j < 3; j++) {
				int suml = 0, sumr = 0;
				for (int k = 0; B[j].r[k]; k++) {
					suml += (i != B[j].l[k]-'A');
					sumr += (i != B[j].r[k]-'A');		
				}
				if (suml == sumr&&B[j].eud[0] == 'e')
					continue;
				if (suml > sumr&&B[j].eud[0] == 'u')
					continue;
				if (suml < sumr&&B[j].eud[0] == 'd')
					continue;
				break;
			}
			if (j == 3)
				break;
		}
		if (i != 12)
			printf("%c is the counterfeit coin and it is light.\n", i + 'A');
		else {
			for (i = 0; i < 12; i++) {
				for (j = 0; j < 3; j++) {
					int suml = 0, sumr = 0;
					for (int k = 0; B[j].r[k]; k++) {
						suml += (i == B[j].l[k] - 'A');
						sumr += (i == B[j].r[k] - 'A');
					}
					if (suml == sumr&&B[j].eud[0] == 'e')
						continue;
					if (suml > sumr&&B[j].eud[0] == 'u')
						continue;
					if (suml < sumr&&B[j].eud[0] == 'd')
						continue;
					break;
				}
				if (j == 3)
					break;
			}
			if (i != 12)
				printf("%c is the counterfeit coin and it is heavy.\n", i + 'A');
		}
	}
}



*algorithm
think case which have counterfeit or not

no have counterfeit 
this case is impossible
suml == sumr && data[j].eud[0] == 'e'
suml > sumr && data[j].eud[0] == 'u'
suml < sumr && data[j].eud[0] == 'd'

have counterfeit 
that case is react.






Sally Jones has a dozen Voyageur silver dollars. However, only 
eleven of the coins are true silver dollars; one coin is 
counterfeit even though its color and size make it 
indistinguishable from the real silver dollars. 
The counterfeit coin has a different weight from the other 
coins but Sally does not know if it is heavier or lighter than 
the real coins. Happily, Sally has a friend who loans her a 
very accurate balance scale. The friend will permit Sally
three weighings to find the counterfeit coin. For instance, 
if Sally weighs two coins against each other and the scales 
balance then she knows these two coins are true. Now if Sally 
weighs one of the true coins against a third coin and the 
scales do not balance then Sally knows the third coin is 
counterfeit and she can tell whether it is light or heavy 
depending on whether the balance on which it is placed goes up
or down, respectively. By choosing her weighings carefully, 
Sally is able to ensure that she will find the counterfeit 
coin with exactly three weighings.



Input
The first line of input is an integer n (n > 0) specifying 
the number of cases to follow. Each case consists of three 
lines of input, one for each weighing. Sally has identified 
each of the coins with the letters A–L. Information on a 
weighing will be given by two strings of letters and then one 
of the words “up”, “down”, or “even”. The first string of 
letters will represent the coins on the left balance; the
second string, the coins on the right balance. (Sally will 
always place the same number of coins on the right balance as 
on the left balance.) The word in the third position will 
tell whether the right side of the balance goes up, down, 
or remains even.

Output
For each case, the output will identify the counterfeit coin 
by its letter and tell whether it is heavy or
light. The solution will always be uniquely determined.



Sample Input
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even

Sample Output
K is the counterfeit coin and it is light.


