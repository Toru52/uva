439 - Knight Moves
http://programming-study-notes.blogspot.tw/2014/02/uva-439-knight-moves.html



#include <cstdio>
#include <queue>
using namespace std;
struct p {int i,j;};
const int dir[8][2] = { -2,-1 ,-1,-2 ,1,-2, 2,-1, 2,1, 1,2, -1,2, -2,1};
int BFS(p S, p E)
{
	int step[9][9]{};
	queue<p> Q;
	p u, v;

	Q.push(S);
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		if (u.i == E.i && u.j == E.j)
			return step[u.i][u.j];
		for (int i = 0; i < 8; ++i) {
			v.i = u.i + dir[i][0],v.j = u.j + dir[i][1];
			if (v.i < 1 || v.i > 8 || v.j < 1 || v.j > 8) 
				continue;
			if (!step[v.i][v.j]) 
				step[v.i][v.j] = step[u.i][u.j] + 1,Q.push(v);
		}
	}
	return step[u.i][u.j];
}
int main()
{
	char s1[3], s2[3];
	while (scanf("%s%s", s1, s2) ==2) {
		p S, E;
		S.i = s1[0] - 'a' + 1;S.j = s1[1] - '0';
		E.i = s2[0] - 'a' + 1;E.j = s2[1] - '0';
		int moves = BFS(S, E);
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, moves);
	}
	return 0;
}


A friend of you is doing research on the Traveling Knight Problem (TKP) 
where you are to find the shortest closed tour of knight moves that 
visits each square of a given set of n squares on a chessboard exactly 
once. He thinks that the most difficult part of the problem is 
determining the smallest number of knight moves between two given 
squares and that, once you have accomplished this, finding the tour
would be easy.
Of course you know that it is vice versa. So you offer him to write a 
program that solves the ”difficult” part.
Your job is to write a program that takes two squares a and b as input 
and then determines the number of knight moves on a shortest route from 
a to b.



Input
The input file will contain one or more test cases. Each test case 
consists of one line containing two squares separated by one space. 
A square is a string consisting of a letter (a..h) representing the 
column and a digit (1..8) representing the row on the chessboard.

Output
For each test case, print one line saying ‘To get from xx to yy takes 
n knight moves.’.



Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.