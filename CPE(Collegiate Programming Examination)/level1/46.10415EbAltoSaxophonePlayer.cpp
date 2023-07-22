46.10415	Eb Alto Saxophone Player



#include <iostream>
#define finger 10
#define asc 256
using namespace std;
int main() {
	int t, sign[asc];
	char song[asc];

	char key[][11] = {
		"0111001111",
		"0111001110",
		"0111001100",
		"0111001000",
		"0111000000",
		"0110000000",
		"0100000000",
		"0010000000",
		"1111001110",
		"1111001100",
		"1111001000",
		"1111000000",
		"1110000000",
		"1100000000"
	};
	sign['c'] = 0, sign['d'] = 1, sign['e'] = 2, sign['f'] = 3,
		sign['g'] = 4, sign['a'] = 5, sign['b'] = 6, sign['C'] = 7,
		sign['D'] = 8, sign['E'] = 9, sign['F'] = 10, sign['G'] = 11,
		sign['A'] = 12, sign['B'] = 13;

	cin >> t;
	cin.ignore(256, '\n');

	while (t--) {
		int i = 0, j;
		int ans[finger] = { 0 };
		bool check[finger] = { false };

		cin.getline(song, asc);
		while (song[i]) {
			int k = sign[song[i]];
			for (j = 0; j<finger; j++) {
				if (key[k][j] == '1' && !check[j]) {
					ans[j]++;
					check[j] = true;
				}
				if (key[k][j] == '0')
					check[j] = false;
			}
			i++;
		}
		cout << ans[0];
		for (i = 1; i<finger; i++)
			cout << " " << ans[i];
		cout << endl;

	}
}



no2.
#include<iostream>
#include<cstdio>
#define finger 10
#define ASC 256
using namespace std;

int main()
{
	char song[ASC];
	int sign[ASC];
	int cas;
	char key[][11] = {
		"0111001111",
		"0111001110",
		"0111001100",
		"0111001000",
		"0111000000",
		"0110000000",
		"0100000000",
		"0010000000",
		"1111001110",
		"1111001100",
		"1111001000",
		"1111000000",
		"1110000000",
		"1100000000",
	};
	sign['c'] = 0, sign['d'] = 1, sign['e'] = 2, sign['f'] = 3;
	sign['g'] = 4, sign['a'] = 5, sign['b'] = 6, sign['C'] = 7;
	sign['D'] = 8, sign['E'] = 9, sign['F'] = 10, sign['G'] = 11;
	sign['A'] = 12, sign['B'] = 13;

	cin>>cas;
	cin.ignore(256, '\n');
	for (int m = 1; m <= cas; m++)
	{
		int ans[finger] = { 0 };
		bool check[finger] = { false };
		cin.getline(song, ASC);
		for (int i = 0; song[i]; i++)
		{
			int k = sign[song[i]];
			for (int j = 0; j < finger; j++)
				if (key[k][j] == '1'&&!check[j])
				{
					ans[j]++;
					check[j] = true;
				}
				else if (key[k][j] == '0')
					check[j] = false;
		}
		printf("%d", ans[0]);
		for (int i = 1; i < finger; i++)
			printf(" %d", ans[i]);
		puts("");
	}
}



Do you like saxophone? I have a Eb Alto Saxophone, shown on the right.
My fingers move A LOT when playing some music, and I’m quite
interested in how many times each finger PRESS the button. Assume
that the music is composed of only 8 kinds of note. They are:
C D E F G A B in one octave and C D E F G A B in a higher
octave. We use c,d,e,f,g,a,b,C,D,E,F,G,A,B to represent them. The
fingers I use for each note are:
• c: finger 2∼4, 7∼10
• d: finger 2∼4, 7∼9
• e: finger 2∼4, 7, 8
• f: finger 2∼4, 7
• g: finger 2∼4
• a: finger 2, 3
• b: finger 2
• C: finger 3
• D: finger 1∼4, 7∼9
• E: finger 1∼4, 7, 8
• F: finger 1∼4, 7
• G: finger 1∼4
• A: finger 1∼3
• B: finger 1∼2
(Note that every finger is controlling a specified button, different
fingers are controlling different buttons.)
Write a program to help count the number of times each finger presses 
the button. A finger presses a button if it is needed in a note, 
but not used in the last note. Also, if it is the first note, every 
finger required presses the button.



Input
The first line of the input is a single integer t (1 ≤ t ≤ 1000), 
indicating the number of test cases. For each case, there is only one 
line containing the song. The only allowed characters are
{‘c’,‘d’,‘e’,‘f’,‘g’,‘a’,‘b’, ‘C’,‘D’,‘E’,‘F’,‘G’,‘A’,‘B’}. 
There are at most 200 notes in a song, and the song maybe empty.

Output
For each test case, print 10 numbers indicating the number of presses 
for each finger. Numbers are separated by a single space.



Sample Input
3
cdefgab
BAGFEDC
CbCaDCbCbCCbCbabCCbCbabae

Sample Output
0 1 1 1 0 0 1 1 1 1
1 1 1 1 0 0 1 1 1 0
1 8 10 2 0 0 2 2 1 0