170 - Clock Patience



#include <cstdio>
#include <deque>
#include <string>
using namespace std;

int toIndex(char c) {
	if (c == 'A') return 0;
	if (c >= '2' && c <= '9') return c - '1';
	if (c == 'T') return 9;
	if (c == 'J') return 10;
	if (c == 'Q') return 11;
	if (c == 'K') return 12;
}

struct Card {
	Card(const string & s) : s(s), open(false) {}
	string s;
	bool open;
};

int main() {
	char s[2];
	while (scanf("%s", s) && s[0] != '#') {
		deque<Card> pile[13];
		pile[12].push_front(Card(s));
		for (int i = 0; i < 4; i++) {
			for (int j = 12 - !i; j >= 0; j--) {
				scanf("%s", s);
				pile[j].push_front(Card(s));
			}
		}
		int select = 12, count = 0;
		string last;
		while (!pile[select].back().open) {
			Card now = pile[select].back();
			pile[select].pop_back();
			last = now.s;
			count++;
			now.open = true;
			select = toIndex(now.s[0]);
			pile[select].push_front(now);
		}
		printf("%02d,%s\n", count, last.c_str());
	}
	return 0;
}



#include<cstdio>
#include<deque>
#include<string>
using namespace std;

int move(char c)
{
	if (c == 'A')return 0;
	if ('2' <= c&&c <= '9')return c - '1';
	if (c == 'T')return 9;
	if (c == 'J')return 10;
	if (c == 'Q')return 11;
	if (c == 'K')return 12;
}

struct card {
	card(const string &s) :s(s), open(false) {}
	string s;
	bool open;
};

int main()
{
	char s[2];
	while (scanf("%s", s) && s[0] != '#')
	{
		deque<card>pile[13];
		pile[12].push_front(card(s));
		for(int i=0;i<4;i++)
			for (int j = 12 - !i; j >= 0; j--) {
				scanf("%s", s);
				pile[j].push_front(card(s));
			}
		int select = 12, count = 0;
		string last;
		while (!pile[select].back().open) {
			count++;
			card now = pile[select].back();
			pile[select].pop_back();
			last = now.s;
			now.open = true;
			select = move(now.s[0]);
			pile[select].push_front(now);
		}
		printf("%02d,%s\n", count, last.c_str());
	}
}


point
1,
for (int j = 12 - !i; j >= 0; j--)
->!i if(!0)->true  ->j=12-1  ->   start from j=11
     if(!1)->false ->j=12-0  ->   start from j=12 
	 if(!2),,,
Therefore !i is used as a bool function which true or false


2,
Card(const string & s) : s(s), open(false) {}

card input to "s" with open(false) together
ex 8S    8S->s   8S->false or s->false


3,
while (!pile[select].back().open)
->   !true->stop     !false->continue
->   pile[select].back() of "deque" is the finallest 
     that is 12 . So "!pile[select].back().open" means that 
	 ask you pile[12].back() is true or false.
->    false -> facedown   true -> faceup
	 

Card sharp Albert (Foxy) Smith is writing a book on patience 
games. To double check the examples in the book, he is writing 
programs to find the optimal play of a given deal. 
The description of Clock Patience reads as follows: 
``The cards are dealt out (face down) in a circle, representing 
a clock, with a pile in each hour position and an extra pile in 
the centre of the clock. The first card goes face down on one 
o'clock, the next on two, and so on clockwise from there, 
with each thirteenth card going to the center of the clock. 
This results in thirteen piles, with four cards face down in 
each pile.

picture23

The game then starts. The top card of the `king' 
pile (the last card dealt) is exposed to become the current card.
 Each move thereafter consists of placing the current card face 
 up beneath the pile corresponding to its value and exposing 
 the top card of that pile as the new current card. Thus 
 if the current card is an Ace it is placed under the 
 `one' pile and the top card of that pile becomes the current 
 card. The game ends when the pile indicated by the current 
 card has no face down cards in it. You win if the entire deck 
 is played out, i.e. exposed.''
Write a program that will read in a number of shuffled decks, 
and play the game.



Input and Output
The input will consist of decks of cards arranged in four lines 
of 13 cards, cards separated by a single blank. Each card is 
represented by two characters, the first is the 
rank (A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K) followed by the 
suit (H, D, C, S). The input will be terminated by a line 
consisting of a single #. The deck is listed from bottom to top,
so the first card dealt is the last card listed.
The output will consist of one line per deck. Each line will
contain the number of cards exposed during the game (2 digits, 
with a leading zero if necessary), a comma, and the last card 
exposed (in the format used in the input).



Sample Input
TS QC 8S 8D QH 2D 3H KH 9H 2H TH KS KC
9D JH 7H JD 2S QS TD 2C 4H 5H AD 4D 5D
6D 4S 9S 5S 7S JS 8H 3D 8C 3S 4C 6S 9C
AS 7C AH 6H KD JC 7D AC 5C TC QD 6C 3C
#
Sample output
44,KD



[12] [11] [10] [9] [8] [7] [6] [5] [4] [3] [2] [1] [0] 
 TS   QC   8S   8D  QH  2D  3H  KH  9H  2H  TH  KS  KC   BACK
 9D   JH   7H   JD  2S  QS  TD  2C  4H  5H  AD  4D  5D
 6D   4S   9S   5S  7S  JS  8H  3D  8C  3S  4C  6S  9C
 AS   7C   AH   6H  KD  JC  7D  AC  5C  TC  QD  6C  3C   FRONT