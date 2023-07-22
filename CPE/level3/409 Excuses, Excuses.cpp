409 Excuses, Excuses! 
https://github.com/morris821028/UVa/blob/master/volume004/409%20-%20Excuses%2C%20Excuses.cpp



#include<iostream>
#include<string>
using namespace std;
int main(){
	int K, E, cas = 0;
	while (scanf("%d %d ", &K, &E) == 2){
		string s;
		int m,flag[30]{};
		char num[30][30]{}, excuse[30][100]{};
		for (int i = 0; i<K; i++)	{
			getline(cin, s);
			num[i][0] = s.length();
			for (int j = 1; j <= s.length(); j++) 
				num[i][j] = s[j - 1]; 
		}
		for (int i = 0; i<E; i++)	{
			int cnt = 0;
			getline(cin, s);
			excuse[i][0] = s.length();
			for (int j = 1; j <= s.length(); j++) 
				excuse[i][j] = s[j - 1];
			for (int j = 0; j<s.length(); j++) 	{
				int tmp[100]{};
				for (int k = 1; j<s.length(); j++, k++) 	{
					if (s[j]<65 || (s[j] >= 91 && 
						s[j] <= 96) || s[j] >= 123) 
						break;
					tmp[k] = s[j];
				}
				for (int k = 0; k<K; k++) {
					for (m = 1; m<=20; m++)
						if (tmp[m] != num[k][m] && 
							tmp[m] != num[k][m] - 32)
							break;
					if (m == 21) { cnt++; break; }
				}
			}
			flag[i] = cnt;
		}
		printf("Excuse Set #%d\n", ++cas);
		int max = -1;
		for (int i = 0; i<E; i++)
			if (flag[i]>max) 
				max = flag[i];
		for (int i = 0; i<E; i++)
			if (flag[i] == max)	{
				for (int j = 0; j<excuse[i][0]; j++)
					printf("%c", excuse[i][j + 1]);
				puts("");
			}
		puts("");
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	int K, E, cas = 0;
	while (scanf("%d %d ", &K, &E) == 2) {
		string s;
		int m, max = -1, flag[30]{};
		char num[30][30]{}, excuses[30][100]{};
		for (int i = 0; i < K; i++) {
			getline(cin, s);
			num[i][0] = s.length();
			for (int j = 1; j <= s.length(); j++)
				num[i][j] = s[j - 1];
		}
		for (int i = 0; i < E; i++) {
			int cnt = 0;
			getline(cin, s);
			excuses[i][0] = s.length();
			for (int j = 1; j <= s.length(); j++)
				excuses[i][j] = s[j - 1];
			for (int j = 0; j < s.length(); j++) {
				int tmp[100]{};
				for (int k = 1; j < s.length(); j++, k++) {
					if (s[j] < 65 ||
						(s[j] >= 91 && s[j] <= 96)
						|| s[j] >= 123)
						break;
					tmp[k] = s[j];
				}
				for (int k = 0; k < K; k++) {
					for (m = 1; m < 21; m++)
						if (tmp[m] != num[k][m] &&
							tmp[m] != num[k][m] - 32)
							break;
					if (m == 21) { cnt++; break; }
				}
			}
			flag[i] = cnt;
			if (max < cnt)
				max = cnt;
		}
		printf("Excuse Set #%d\n", ++cas);
		for(int i=0;i<E;i++)
			if (flag[i] == max) {
				for (int j = 1; j <= excuses[i][0]; j++)
					printf("%c", excuses[i][j]);
				puts("");
			}
		puts("");
	}
	return 0;
}



/*
ex
5 3
dog
ate
homework
canary
died

My dog ate my homework. 
->2(ate homework)
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
->3(dog canary homework) ->largest keyword
This excuse is so good that it contain 0 keywords.
->0

superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
->2(superhighway bedroom)
I am actually crazy.
->1(crazy) 
1234567890.....,,,,,0987654321?????!!!!!!
->0
There was a thermonuclear war!
->2(thermonuclear war)
I ate my dog, my canary, and my homework ... note outdated keywords?
->0
*/
Judge Ito is having a problem with people subpoenaed for jury duty 
giving rather lame excuses in order to avoid serving. 
In order to reduce the amount of time required listening to goofy 
excuses, Judge Ito has asked that you write a program that will 
search for a list of keywords in a list of excuses identifying lame 
excuses. Keywords can be matched in an excuse regardless of case.



Input
Input to your program will consist of multiple sets of data.
• Line 1 of each set will contain exactly two integers. The first 
number (1  K  20) defines the
number of keywords to be used in the search. The second number 
(1  E  20) defines the
number of excuses in the set to be searched.
• Lines 2 through K + 1 each contain exactly one keyword.
• Lines K + 2 through K + 1 + E each contain exactly one excuse.
• All keywords in the keyword list will contain only contiguous 
lower case alphabetic characters of length L (1  L  20) and 
will occupy columns 1 through L in the input line.
• All excuses can contain any upper or lower case alphanumeric 
character, a space, or any of the following punctuation marks 
[".,!?] not including the square brackets and will not exceed 70
characters in length.
• Excuses will contain at least 1 non-space character.

Output
For each input set, you are to print the worst excuse(s) from the 
list.
• The worst excuse(s) is/are defined as the excuse(s) which 
contains the largest number of incidences of keywords.
• If a keyword occurs more than once in an excuse, each occurrance 
is considered a separate incidence.
• A keyword “occurs” in an excuse if and only if it exists in the 
string in contiguous form and is delimited by the beginning or end 
of the line or any non-alphabetic character or a space.
For each set of input, you are to print a single line with the 
number of the set immediately after the string ‘Excuse Set #’. 
(See the Sample Output). The following line(s) is/are to contain 
the worst excuse(s) one per line exactly as read in. 
If there is more than one worst excuse, you may print them in any 
order. After each set of output, you should print a blank line.



Sample Input
5 3
dog
ate
homework
canary
died
My dog ate my homework.
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
This excuse is so good that it contain 0 keywords.
6 5
superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
I am actually crazy.
1234567890.....,,,,,0987654321?????!!!!!!
There was a thermonuclear war!
I ate my dog, my canary, and my homework ... note outdated keywords?

Sample Output
Excuse Set #1
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
Excuse Set #2
I am having a superhighway built in my bedroom.
There was a thermonuclear war!