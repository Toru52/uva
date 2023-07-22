10903 - Rock-Paper-Scissors Tournament



#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
		int n, k;
		map<string, int> rank;
		rank["rock"] = 0;
		rank["paper"] = 1;
		rank["scissors"] = 2;
		int t = 0;
		while (cin >> n >> k && n) {
				t++;
				int won[101] = { 0 }, lost[101] = {0};
		
				for (int i = 0; i < k * n * (n - 1) / 2; i++) {	
				//n*(n-1)/2*1 (use conbinations)
						int p1, p2;
						string m1, m2;
						cin >> p1 >> m1 >> p2 >> m2;
						if (rank[m1] == rank[m2])
							continue;
						if ((rank[m1] + 1) % 3 == rank[m2]) {		
								won[p2]++;
								lost[p1]++;				
						}
						else {
								won[p1]++;			
								lost[p2]++;			
						}		
				}
				if (t > 1)
					cout << endl;
				for (int i = 1; i <= n; i++)
					if (won[i] + lost[i] > 0)		
						printf("%.3f\n", won[i] * 1.0 / (won[i] + lost[i]));
					else	
						cout << "-" << endl;		
		}
}



#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int k, n,cnt=0;
	map<string, int>RPS;
	RPS["rock"] = 0, RPS["paper"] = 1, RPS["scissors"]=2;

	while (cin>>n>>k&& n)
	{
		cnt++;
		int p1, p2;
		double won[101] = { 0 }, lost[101] = { 0 };
		string m1, m2;
		for (int i = 0; i < k*n*(n - 1) / 2; i++)
		{
			cin >> p1 >> m1 >> p2 >> m2;
			if (m1 == m2)
				continue;
			else if ((RPS[m1] + 1) % 3 == RPS[m2])
				won[p2]++, lost[p1]++;
			else
				won[p1]++, lost[p2]++;
		}
		if (cnt > 1)
			cout << endl;
		for (int i = 1; i <= n; i++)
			if (won[i] + lost[i] > 0)
				printf("%.3f\n", won[i] / (won[i] + lost[i]));
			else
				puts("-");
	}
}



Rock-Paper-Scissors is game for two players, A and B, 
who each choose, independently of the other,
one of rock, paper, or scissors. A player chosing paper 
wins over a player chosing rock; a player chosing
scissors wins over a player chosing paper; a player chosing 
rock wins over a player chosing scissors. A player chosing 
the same thing as the other player neither wins nor loses.



A tournament has been organized in which each of n players 
plays k rock-scissors-paper games with each of the other 
players — k ∗ n ∗ (n− 1)/2 games in total. Your job is to 
compute the win average for each player, defined as 
w/(w + l) where w is the number of games won, and l is the 
number of games lost, by the player.



Input
Input consists of several test cases. The first line of 
input for each case contains 1 ≤ n ≤ 100 1 ≤ k ≤ 100
as defined above. For each game, a line follows containing 
p1, m1, p2, m2. 1 ≤ p1 ≤ n and 1 ≤ p2 ≤ n
are distinct integers identifying two players; m1 and m2 
are their respective moves (‘rock’, ‘scissors’,or ‘paper’). 
A line containing ‘0’ follows the last test case.

Output
Output one line each for player 1, player 2, and so on, 
through player n, giving the player’s win average
rounded to three decimal places. If the win average is 
undefined, output ‘-’. Output an empty line between cases.



Sample Input
2 4
1 rock 2 paper
1 scissors 2 paper
1 rock 2 rock
2 rock 1 scissors
2 1
1 rock 2 paper
0

Sample Output
0.333
0.667
0.000
1.000
