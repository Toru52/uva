127 - "Accordian" Patience



#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
bool matches(string &a, string &b) {
	return a[0] == b[0] || a[1] == b[1];
}
int main()
{
	string card;
	while (cin >> card&&card != "#") {
		vector<stack<string> > piles(52);
		piles[0].push(card);
		for (int i = 1; i < piles.size(); i++) {
			cin >> card;
			piles[i].push(card);
		}

		for (int i = 0; i < piles.size(); i++) {
			if (i - 3 >= 0 && matches(piles[i - 3].top(), piles[i].top())) {
				piles[i - 3].push(piles[i].top());
				piles[i].pop();
				if (piles[i].empty()) {
					piles.erase(piles.begin() + i);
				}
				i = 0;
			}
			else if (i - 1 >= 0 && matches(piles[i - 1].top(), piles[i].top())) {
				piles[i - 1].push(piles[i].top());
				piles[i].pop();
				if (piles[i].empty()) {
					piles.erase(piles.begin() + i);
				}
				i = 0;
			}
		}

		cout << piles.size() << " pile";
		if (piles.size() != 1) cout << 's';
		cout << " remaining: ";
		for (int i = 0; i < piles.size() - 1; i++) {
			cout << piles[i].size() << ' ';
		}
		cout << piles.back().size() << endl;
	}
	return 0;
}



#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int matches(string &a, string &b) { return a[0] == b[0] || a[1] == b[1]; }
int main()
{
	string card;
	while (cin >> card&&card != "#")
	{
		vector<stack<string>>piles(52);
		piles[0].push(card);
		for (int i = 1; i < piles.size(); i++)
			cin >> card, piles[i].push(card);
		for (int i = 0; i < piles.size(); i++)
		{
			if (i - 3 >= 0 && matches(piles[i-3].top(), piles[i].top()))
			{
				piles[i - 3].push(piles[i].top());
				piles[i].pop();
				if (piles[i].empty())
					piles.erase(piles.begin()+i);
				i = 0;
			}
			if (i - 1 >= 0 && matches(piles[i - 1].top(), piles[i].top()))
			{
				piles[i - 1].push(piles[i].top());
				piles[i].pop();
				if (piles[i].empty())
					piles.erase(piles.begin() + i);
				i = 0;
			}
		}
		cout << piles.size() << " pile";
		if (piles.size() > 1)
			cout << 's';
		cout << " remaining: ";
		for (int i = 0; i < piles.size()-1; i++)
			cout<<piles[i].size()<<' ';
		cout<<piles.back().size() << endl;
	}
}



You are to simulate the playing of games of ``Accordian'' 
patience, the rules for which are as follows:
Deal cards one by one in a row from left to right, 
not overlapping. Whenever the card matches its immediate 
neighbour on the left, or matches the third card to the 
left, it may be moved onto that card. Cards match if they 
are of the same suit or same rank. After making a move, 
look to see if it has made additional moves possible. 
Only the top card of each pile may be moved at any given 
time. Gaps between piles should be closed up as soon as 
they appear by moving all piles on the right of the gap 
one position to the left. Deal out the whole pack, 
combining cards towards the left whenever possible. 
The game is won if the pack is reduced to a single pile.
Situations can arise where more than one play is possible. 
Where two cards may be moved, you should adopt the 
strategy of always moving the leftmost card possible. 
Where a card may be moved either one position to the left 
or three positions to the left, move it three positions.



Input
Input data to the program specifies the order in which 
cards are dealt from the pack. The input contains pairs of 
lines, each line containing 26 cards separated by single 
space characters. The final line of the input file contains
 a # as its first character. Cards are represented as a 
 two character code. The first character is the 
 face-value (A=Ace, 2-9, T=10, J=Jack, Q=Queen, K=King) 
 and the second character is the 
 suit (C=Clubs, D=Diamonds, H=Hearts, S=Spades).

Output
One line of output must be produced for each pair of 
lines (that between them describe a pack of 52 cards) in 
the input. Each line of output shows the number of cards 
in each of the piles remaining after playing ``Accordian 
patience'' with the pack of cards as described by the 
corresponding pairs of input lines.



Sample Input

QD AD 8H 5S 3H 5H TC 4D JH KS 6H 8S JS AC AS 8D 2H QS TS 3S AH 4H TH TD 3C 6S
8C 7D 4C 4S 7S 9H 7C 5D 2S KD 2D QH JD 6D 9D JC 2C KH 3D QC 6C 9S KC 7H 9C 5C
AC 2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AD 2D 3D 4D 5D 6D 7D 8D TD 9D JD QD KD
AH 2H 3H 4H 5H 6H 7H 8H 9H KH 6S QH TH AS 2S 3S 4S 5S JH 7S 8S 9S TS JS QS KS
#
Sample Output

6 piles remaining: 40 8 1 1 1 1
1 pile remaining: 52