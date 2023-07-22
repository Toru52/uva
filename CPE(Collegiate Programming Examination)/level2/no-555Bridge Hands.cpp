555	Bridge Hands



#include <cstdio>
#include <map>

int main()
{
	std::map<char, int> cardConversion, suitConversion, playerConversion;
	playerConversion['S'] = 1;
	playerConversion['W'] = 2;
	playerConversion['N'] = 3;
	playerConversion['E'] = 0;

	cardConversion['2'] = suitConversion['C'] = 0;
	cardConversion['3'] = suitConversion['D'] = 1;
	cardConversion['4'] = suitConversion['S'] = 2;
	cardConversion['5'] = suitConversion['H'] = 3;
	cardConversion['6'] = 4;
	cardConversion['7'] = 5;
	cardConversion['8'] = 6;
	cardConversion['9'] = 7;
	cardConversion['T'] = 8;
	cardConversion['J'] = 9;
	cardConversion['Q'] = 10;
	cardConversion['K'] = 11;
	cardConversion['A'] = 12;

	char starter, cardSuit, cardValue, printout[4], cardOut[13], suitOut[4];
	printout[0] = 'S';
	printout[1] = 'W';
	printout[2] = 'N';
	printout[3] = 'E';

	cardOut[0] = '2';
	cardOut[1] = '3';
	cardOut[2] = '4';
	cardOut[3] = '5';
	cardOut[4] = '6';
	cardOut[5] = '7';
	cardOut[6] = '8';
	cardOut[7] = '9';
	cardOut[8] = 'T';
	cardOut[9] = 'J';
	cardOut[10] = 'Q';
	cardOut[11] = 'K';
	cardOut[12] = 'A';

	suitOut[0] = 'C';
	suitOut[1] = 'D';
	suitOut[2] = 'S';
	suitOut[3] = 'H';

	int current;

	// is [player][suit][card]
	bool hasCard[4][4][13];

	for (int i = 0; i < 4; ++i)
		for (int x = 0; x < 4; ++x)
			for (int y = 0; y < 13; ++y)
				hasCard[i][x][y] = false;

	while (scanf("%c", &starter), starter != '#')
	{
		current = playerConversion[starter];

		for (int i = 0; i < 52; ++i)
		{
			if (i % 26 == 0)
				scanf("%*c");

			scanf("%c%c", &cardSuit, &cardValue);

			hasCard[current][suitConversion[cardSuit]][cardConversion[cardValue]] = true;

			current = (current + 1) % 4;


		}

		scanf("%*c");
		for (int player = 0; player < 4; ++player)
		{
			printf("%c:", printout[player]);

			for (int suit = 0; suit < 4; ++suit)
				for (int card = 0; card < 13; ++card)
				{
					if (hasCard[player][suit][card])
					{
						printf(" %c%c", suitOut[suit], cardOut[card]);
						hasCard[player][suit][card] = false;
					}
				}

			printf("\n");
		}
	}
}



#include <cstdio>
#include <map>

int main()
{
	std::map<char, int> card, suit, player;
	player['S'] = 1;player['W'] = 2;player['N'] = 3;player['E'] = 0;

	card['2'] = suit['C'] = 0;card['3'] = suit['D'] = 1;
	card['4'] = suit['S'] = 2;card['5'] = suit['H'] = 3;
	card['6'] = 4;card['7'] = 5;card['8'] = 6;card['9'] = 7;
	card['T'] = 8; card['J'] = 9;card['Q'] = 10;
	card['K'] = 11;card['A'] = 12;

	char starter, cardSuit, cardValue, print[4], CARD[13], SUIT[4];
	print[0] = 'S';print[1] = 'W';print[2] = 'N';print[3] = 'E';

	CARD[0] = '2';CARD[1] = '3';CARD[2] = '4';CARD[3] = '5';
	CARD[4] = '6';CARD[5] = '7';CARD[6] = '8';CARD[7] = '9';
	CARD[8] = 'T';CARD[9] = 'J';CARD[10] = 'Q';CARD[11] = 'K';
	CARD[12] = 'A';

	SUIT[0] = 'C';SUIT[1] = 'D';SUIT[2] = 'S';SUIT[3] = 'H';

	int current;
	bool hasCard[4][4][13];

	for (int i = 0; i < 4; ++i)
		for (int x = 0; x < 4; ++x)
			for (int y = 0; y < 13; ++y)
				hasCard[i][x][y] = false;

	while (scanf("%c", &starter), starter != '#')
	{
		current = player[starter];

		for (int i = 0; i < 52; ++i)
		{
			if (i % 26 == 0)
				scanf("%*c");
			scanf("%c%c", &cardSuit, &cardValue);
			hasCard[current][suit[cardSuit]][card[cardValue]] = true;
			current = (current + 1) % 4;
		}
		scanf("%*c");
		for (int player = 0; player < 4; ++player)
		{
			printf("%c:", print[player]);
			for (int suit = 0; suit < 4; ++suit)
				for (int card = 0; card < 13; ++card)
				{
					if (hasCard[player][suit][card])
					{
						printf(" %c%c", SUIT[suit], CARD[card]);
						hasCard[player][suit][card] = false;
					}
				}
			printf("\n");
		}
	}
}



Many games, such as Bridge, involve dealing a standard deck of 52 
cards to 4 players, so each receives 13 cards. Good players can 
then play with the hand as it is dealt, but most ordinary players 
will need to sort it, firstly by suit, and then by rank within suit.
There is no fixed ranking of the suits for this purpose, but it is 
useful to alternate the colours, so we will presume the following 
ordering: ♣ < ♢ < ♠ < ♡. (Note that from now on we will use the 
more conventional ‘C’, ‘D’, ‘S’, ‘H’ for CLUBS, DIAMONDS, SPADES 
and HEARTS). Within a suit Ace is high, so the ordering is 
2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < T < J < Q < K < A.
The players are usually designated North, South, East and West,
and they sit at the points of the compass they name. One player is
designated the dealer and he (or she) deals one card to each player
starting with the player on his (her) left hand and proceeding 
clockwise until he (she) deals the last card to himself (herself).
Write a program that will read in a presentation of a deck of
cards, deal them, sort them, and then display the 4 sorted hands 
in the format shown below.



Input
Input will consist of a series of deals. Each deal will consist of
the letter representing the dealer (N, E, S, W) followed by two lines
representing the deck as shown below.
The file will be terminated by a line consisting of a single ‘#’.

Output
Output will consist of a series of sets of four lines, one set for 
each deal. Each set will consist of four lines displaying the 
sorted hands, in the order and format shown below. Sets must follow
each other immediately, with no blank line between them.



Sample Input
N
CQDTC4D8S7HTDAH7D2S3D6C6S6D9S4SAD7H2CKH5D3CTS8C9H3C3
DQS9SQDJH8HAS2SKD4H4S5C7SJC8DKC5C2CAHQCJSTH6HKH9D5HJ
#

Sample Output
S: C3 C5 C7 CT CJ D9 DT DJ S3 SK H2 H9 HT
W: C2 C4 CK D4 D5 D6 DQ DA S4 S8 ST SJ H8
N: C6 C8 C9 CA D8 S9 SA H4 H5 H6 H7 HJ HA
E: CQ D2 D3 D7 DK S2 S5 S6 S7 SQ H3 HQ HK