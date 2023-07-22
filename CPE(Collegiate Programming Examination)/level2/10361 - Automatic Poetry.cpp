10361 - Automatic Poetry
http://knightzone.org/?p=3089



#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	while (~scanf("%d ", &n)) {
		for (int cas = 0; cas < n; ++cas) {
			string s[5];
			char c;
			for (int i = 0; i < 5; ++i) 
				while ((c = getchar()) && c != '<' && c != '>' && c != '\n') 
					s[i] += c;
		//s[1] -> <first>      s[3] -> <second>
			for (int i = 0; i < 5; ++i) 
				printf("%s", s[i].c_str());
			printf("\n");

			string c2;
			getline(cin, c2);
			//c2.substr(0, c2.length() - 3) -> remove (...)
			c2 = c2.substr(0, c2.length() - 3) + s[3] + s[2] + s[1] + s[4];
			printf("%s\n", c2.c_str());
		}
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	scanf("%d ", &n);
	for (int j = 0; j < n; j++) {
		string s[5];
		char c;
		for (int i = 0; i < 5; i++)
			while ((c = getchar()) && c != '<'&&c != '>'&&c != '\n')
				s[i] += c;
		for (int i = 0; i < 5; i++)
			printf("%s", s[i].c_str());
		puts("");
		string c2;
		getline(cin, c2);
		c2 = c2.substr(0,c2.length()- 3) + s[3] + s[2] + s[1] + s[4];
		printf("%s\n", c2.c_str());
	}
	return 0;
}

Oh God", Lara Croft exclaims, \it's one of these dumb riddles 
again!"
In Tomb Raider XIV, Lara is, as ever, gunning her way through 
ancient Egyptian pyramids, pre-historic caves and medival 
hallways. Now she is standing in front of some important 
Germanic looking doorway and has to solve a linguistic riddle 
to pass.  As usual, the riddle is not very intellectually
challenging.
This time, the riddle involves poems containing a
\Schuttelreim". An example of a Schuttelreim is
the following short poem:
Ein Kind halt seinen Schnabel nur,
wenn es hangt an der Nabelschnur.
Note:
German users, please, forgive me. I had to modify something 
as they were not appearing
correctly in plain text format
A Schuttelreim seems to be a typical German invention. 
The funny thing about this strange type
of poetry is that if somebody gives you the  rst line and the 
beginning of the second one, you can
complete the poem yourself. Well, even a computer can do that, and your task is to write a program
which completes them automatically. This will help Lara 
concentrate on the \action" part of Tomb
Raider and not on the \intellectual" part.



Input
The input will begin with a line containing a single number
n
. After this line follow
n
pairs of lines
containing Schuttelreims. The  rst line of each pair will be 
of the form
s
1
<
s
2
>
s
3
<
s
4
>
s
5
where the
s
i
are possibly empty, strings of lowercase characters or blanks. 
The second line will be
a string of lowercase characters or blanks ending with three 
dots `
...
'.  Lines will we at most 100
characters long.

Output
For each pair of Schuttelreim lines
l
1
and
l
2
you are to output two lines
c
1
and
c
2
in the following way:
c
1
is the same as
l
1
only that the bracket marks `
<
' and `
>
' are removed. Line
c
2
is the same as
l
2
,
except that instead of the three dots the string
s
4
s
3
s
2
s
5
should appear.



SampleInput
3
ein kind haelt seinen <schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...

SampleOutput
ein kind haelt seinen schnabel nur
wenn es haengt an der nabel schnur
weil wir zu spaet zur oma kamen
verpassten wir das koma amen
du bist
bu dist