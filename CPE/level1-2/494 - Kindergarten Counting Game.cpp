494 - Kindergarten Counting Game



#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;

int main() {
	string s, temp;
	int count;
	bool alphap = 0;
	while (getline(cin, s)) {
		count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i]) && !alphap) {
				alphap = 1;
				count++;
			}
			else if (!isalpha(s[i]) && alphap) {
				alphap = 0;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}



no2
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		bool al = 0;
		int c = 0;
		for (int i = 0; s[i]; i++)
			if (isalpha(s[i]) &&!al)
				al = 1, c++;
			else if(!isalpha(s[i]) && al)
				al = 0;
		printf("%d\n", c);
	}
}



Everybody sit down in a circle. Ok. Listen to me carefully.
“Woooooo, you scwewy wabbit!”
Now, could someone tell me how many words I just said?



Input
Input to your program will consist of a series of lines, 
each line containing multiple words (at least one).
A “word” is defined as a consecutive sequence of letters 
(upper and/or lower case).

Output
Your program should output a word count for each line of input. 
Each word count should be printed on a separate line.



Sample Input
Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

Sample Output
2
7
10
9