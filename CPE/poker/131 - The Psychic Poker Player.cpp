131 - The Psychic Poker Player  
http://blog.tobygameac.com/2013/08/uva-131-psychic-poker-player.html



#include <cstdio>
#include <string>
using namespace std;

const string best[9] = { "straight-flush", "four-of-a-kind", "full-house", "flush",
                         "straight", "three-of-a-kind", "two-pairs", "one-pair", "highest-card" };
char hand[9][9], deck[9][9];
int T;

void judge(int now, bool * used) {
	if (now == 5) {
		char face[5], suit[5];
		int newL = 0;
		//There are be not necessarily always five card completed in this 'for'  
		for (int i = 0; i < 5; i++) 
			if (used[i]) {
				face[newL] = hand[i][0];
				suit[newL++] = hand[i][1];
				//printf("%c", face[newL-1]);
			}
		//make up card  until five card complete
		for (int i = 0; newL < 5; i++, newL++) {
			face[newL] = deck[i][0];
			suit[newL] = deck[i][1];
			//printf("%c", face[newL]);
		}
		int cnt[13] = {};
		for (int i = 0; i < 5; i++) {
			switch (face[i]) {
			case 'A':
				cnt[0]++;
				break;
			case 'T':
				cnt[9]++;
				break;
			case 'J':
				cnt[10]++;
				break;
			case 'Q':
				cnt[11]++;
				break;
			case 'K':
				cnt[12]++;
				break;
			default:
				cnt[face[i] - '1']++;
			}
		}
		bool flush = true;
		for (int i = 1; i < 5; i++) 
			if (suit[i] != suit[0]) 
				flush = false;

		bool straight = false;
		for (int i = 0; i < 10; i++) {
			int num = 0;
			for (int j = 0; j < 5; j++) 
				num += (cnt[(i + j) % 13] > 0);

			if (num == 5) {
				straight = true;
				break;
			}
		}
		bool four = false, three = false;
		int pairs = 0;
		for (int i = 0; i < 13; i++) {
			if (cnt[i] == 4) 
				four = true;	
			if (cnt[i] == 3) 
				three = true;
			pairs += cnt[i] == 2;
		}
		if (flush && straight) 
			T = 0;
		else if (four) 
			T = 1 < T ? 1 : T;
		else if (three && pairs) 
			T = 2 < T ? 2 : T;
		else if (flush) 
			T = 3 < T ? 3 : T;
		else if (straight) 
			T = 4 < T ? 4 : T;
		else if (three) 
			T = 5 < T ? 5 : T;
		else if (pairs >= 2) 
			T = 6 < T ? 6 : T;
		else if (pairs) 
			T = 7 < T ? 7 : T;
		return;
	}
	//permutation principle
	used[now] = true;
	judge(now + 1, used);
	used[now] = false;
	judge(now + 1, used);
}

int main() {
	       //read two character ex TH JH QC
	while (scanf("%s", hand[0]) == 1) {
		for (int i = 1; i < 5; i++) 
			scanf("%s", hand[i]);
		for (int i = 0; i < 5; i++) 
			scanf("%s", deck[i]);

		bool used[9] = {};
		T = 8;
		judge(0, used);
		printf("Hand: ");
		for (int i = 0; i < 5; i++) 
			printf("%s ", hand[i]);
		printf("Deck: ");
		for (int i = 0; i < 5; i++) 
			printf("%s ", deck[i]);
		printf("Best hand: %s\n", best[T].c_str());
	}
	return 0;
}



http://blog.csdn.net/llx523113241/article/details/43067945

#include<stdio.h>  
#include<string.h>  
int faceNum, binary[6], saveCard, record[6], count[6];
char cardFace[10][20] = { "highest-card","one-pair","two-pairs","three-of-a-kind",
                          "straight","flush","full-house","four-of-a-kind","straight-flush" };
struct POC {   //扑克牌的结构体  
	char rank, suit;
	int num;
};
POC poc[15], hpoc[6];  //总牌情况和手牌情况  
void getCardFace() {  //获取手牌最优牌面  
	int fn = 0, flush = 1, stra = 1;
	for (int i = 1; i < 5; i++) 
		if (hpoc[i].num + 1 != hpoc[i + 1].num) { //是否顺子  
			stra = 0;
			break;
		}
	if (hpoc[1].num == 1 && hpoc[2].num == 10 && hpoc[3].num == 11 &&
		hpoc[4].num == 12 && hpoc[5].num == 13)   //是否顺子  
		stra = 1;
	for (int i = 1; i < 5; i++) 
		if (hpoc[i].suit != hpoc[5].suit)  //是否同花  
			flush = 0;
	for (int i = 1; i <= 5; i++) {
		count[i] = 0;
		for (int j = 1; j <= 5; j++) 
			if (hpoc[i].num == hpoc[j].num)    //统计重复的牌数  
				count[i]++;
	}
	int t;
	for (int i = 1; i <= 5; i++)   //将统计的牌数按大小排列以便于之后的分析  
		for (int j = i + 1; j <= 5; j++) 
			if (count[i] >count[j]) {
				t = count[i];
				count[i] = count[j];
				count[j] = t;
			}
	if (count[5] == 2) fn = 1;                        //one-pair  
	if (count[2] + count[3] == 4) fn = 2;      //two-pair  
	if (count[5] == 3) fn = 3;                        //three-of-a-kind  
	if (stra) fn = 4;                                     //straight  
	if (flush) fn = 5;                                   //flush  
	if (count[2] + count[3] == 5) fn = 6;    //full-house  
	if (count[2] == 4) fn = 7;                     //four-of-a-kind  
	if (stra && flush) fn = 8;                    //straight-flush   
	if (fn > faceNum) faceNum = fn;
}
int main() {
	int num[15];
	while (scanf("%c%c", &poc[1].rank, &poc[1].suit) == 2) {
		for (int i = 2; i <= 10; i++) 
			scanf(" %c%c", &poc[i].rank, &poc[i].suit);

		for (int i = 1; i <= 10; i++) {           //由字符类型转化为整型  
			if (poc[i].rank == 'T') num[i] = 10;
			else if (poc[i].rank == 'J') num[i] = 11;
			else if (poc[i].rank == 'Q') num[i] = 12;
			else if (poc[i].rank == 'K') num[i] = 13;
			else if (poc[i].rank == 'A') num[i] = 1;
			else num[i] = poc[i].rank - '0';
		}
		faceNum = 0;
		for (int i = 0; i < 32; i++) {        //2^5  
			int cnt = 5, j = i;
			saveCard = 0;
			memset(binary, 0, sizeof(binary));
			memset(record, 0, sizeof(record));
			while (j > 0) {       //二进制形式存储于binary数组中  
				binary[cnt--] = j % 2;
				j = j / 2;
			}
			for (j = 1; j <= 5; j++) 
				if (!binary[j]) {  //统计固定手牌个数  
					saveCard++;
					record[saveCard] = j;   //记录调换手牌  
				}	
			for (j = saveCard + 1; j <= 5; j++) 
				record[j] = j - saveCard + 5; //要从牌堆中取的牌  
			for (j = 1; j <= 5; j++) {       //确认手牌  
				hpoc[j].suit = poc[record[j]].suit;
				hpoc[j].num = num[record[j]];
			}
			POC temp;
			for (int k = 1; k < 5; k++)     //按大小排序  
				for (j = k + 1; j <= 5; j++) 
					if (hpoc[k].num > hpoc[j].num) {
						temp = hpoc[k];
						hpoc[k] = hpoc[j];
						hpoc[j] = temp;
					}
			getCardFace();
		}
		printf("Hand: ");
		for (int k = 1; k <= 5; k++) 
			printf("%c%c ", poc[k].rank, poc[k].suit);		
		printf("Deck: ");
		for (int k = 6; k <= 10; k++) 
			printf("%c%c ", poc[k].rank, poc[k].suit);	
		printf("Best hand: %s\n", cardFace[faceNum]);
		getchar();
	}
	return 0;
}



/*
hand              deck
TH JH QC QD QS    QH KH AH 2S 6S
2H 2S 3H 3S 3C    2D 3D 6C 9C TH
2H 2S 3H 3S 3C    2D 9C 3D 6C TH
2H AD 5H AC 7H    AH 6H 9H 4H 3C
AC 2D 9C 3S KD    5S 4D KS AS 4C
KS AH 2H 3C 4H    KC 2C TC 2D AS
AH 2C 9S AD 3C    QH KS JS JD KD
6C 9C 8C 2D 7C    2H TC 4C 9S AH
3D 5S 2H QD TD    6S KH 9H AD QH


veiw num part
3 5 2 Q T    6 K 9 A Q
->
352QT
352Q6
352T6
3526K
35QT6
,,,
6K9AQ
->32 pattern

http://sintra.web.fc2.com/episode/epsd21.html
(1) 全部のカードを交換する場合　　：１通り
(2) ４枚のカードを交換する場合　　：５通り
(3) ３枚のカードを交換する場合　　：10通り
(4) ２枚のカードを交換する場合　　：10通り
(5) １枚のカードを交換する場合　　：５通り
(6) 全部のカードをホールドする場合：１通り

abcde
abcd
abc
ab
a
ab
abc 
abcd 
 
*/
In 5-card draw poker, a player is dealt a hand of five cards 
(which may be looked at). The player may then discard between zero 
and five of his or her cards and have them replaced by the same 
number of cards from the top of the deck (which is face down). 
The object is to maximize the value of the final hand. 
The different values of hands in poker are given at the end of this 
problem.
Normally the player cannot see the cards in the deck and so must 
use probability to decide which cards to discard. 
In this problem, we imagine that the poker player is psychic and 
knows which cards are on top of the deck. 
Write a program which advises the player which cards to discard so 
as to maximize the value of the resulting hand.



Input
Input will consist of a series of lines, each containing the initial 
five cards in the hand then the first five cards on top of the deck. 
Each card is represented as a two-character code. 
The first character is the face-value 
(A=Ace, 2–9, T=10, J=Jack, Q=Queen, K=King) and the second character
is the suit (C=Clubs, D=Diamonds, H=Hearts, S=Spades).
Cards will be separated by single spaces. 
Each input line will be from a single valid deck, 
that is there will be no duplicate cards in each hand and deck.

Output
Each line of input should produce one line of output, consisting of 
the initial hand, the top five cards on the deck, 
and the best value of hand that is possible. 
Input is terminated by end of file.
Note: Use the sample input and output as a guide.
Note that the order of the cards in the player’s hand is irrelevant, 
but the order of the cards in the deck is important because the 
discarded cards must be replaced from the top of the deck. 
Also note that examples of all types of hands appear in the sample 
output, with the hands shown in decreasing order of value.



Sample Input
TH JH QC QD QS QH KH AH 2S 6S
2H 2S 3H 3S 3C 2D 3D 6C 9C TH
2H 2S 3H 3S 3C 2D 9C 3D 6C TH
2H AD 5H AC 7H AH 6H 9H 4H 3C
AC 2D 9C 3S KD 5S 4D KS AS 4C
KS AH 2H 3C 4H KC 2C TC 2D AS
AH 2C 9S AD 3C QH KS JS JD KD
6C 9C 8C 2D 7C 2H TC 4C 9S AH
3D 5S 2H QD TD 6S KH 9H AD QH

Sample Output
Hand: TH JH QC QD QS Deck: QH KH AH 2S 6S Best hand: straight-flush
Hand: 2H 2S 3H 3S 3C Deck: 2D 3D 6C 9C TH Best hand: four-of-a-kind
Hand: 2H 2S 3H 3S 3C Deck: 2D 9C 3D 6C TH Best hand: full-house
Hand: 2H AD 5H AC 7H Deck: AH 6H 9H 4H 3C Best hand: flush
Hand: AC 2D 9C 3S KD Deck: 5S 4D KS AS 4C Best hand: straight
Hand: KS AH 2H 3C 4H Deck: KC 2C TC 2D AS Best hand: three-of-a-kind
Hand: AH 2C 9S AD 3C Deck: QH KS JS JD KD Best hand: two-pairs
Hand: 6C 9C 8C 2D 7C Deck: 2H TC 4C 9S AH Best hand: one-pair
Hand: 3D 5S 2H QD TD Deck: 6S KH 9H AD QH Best hand: highest-card