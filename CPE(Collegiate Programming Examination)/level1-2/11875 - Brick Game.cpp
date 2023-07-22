11875 - Brick Game



#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int T;
  int N;
  int teammate[15];
  while( scanf( "%d", &T ) != EOF ){
    for( int i = 1 ; i <= T ; i++ ){
      scanf( "%d", &N );
      for( int j = 0 ; j < N ; j++ )
        scanf( "%d", &teammate[j] );

      printf( "Case %d: %d\n", i, teammate[N/2] );
    }
  }
  return 0;
}



#include<iostream>

int main()
{
	int cas, n, mem[15] = {};
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d",&mem[j]);
		printf("Case %d: %d\n",i,mem[n/2]);
	}
}


There is a village in Bangladesh, where brick game is very popular.
 Brick game is a team game. Each team consists of odd number of 
 players. Number of players must be greater than 1 but cannot be
greater than 10. Age of each player must be within 11 and 20. 
No two players can have the same age. There is a captain for each 
team. The communication gap between two players depends on their 
age difference, i.e. the communication gap is larger if the age 
difference is larger. Hence they select the captain of a team in 
such a way so that the number of players in the team who are 
younger than that captain is equal to the number of players who 
are older than that captain. Ages of all members of the team are 
provided. You have to determine the age of the captain.



Input
Input starts with an integer T (T ≤ 100), the number of test cases.
Each of the next T lines will start with an integer N (1 < N < 11),
number of team members followed by N space separated integers 
representing ages of all of the members of a team. Each of these
N integers will be between 11 and 20 (inclusive). Note that, ages 
will be given in strictly increasing order or strictly decreasing 
order. We will not mention which one is increasing and which one 
is decreasing, you have to be careful enough to handle both 
situations.

Output
For each test case, output one line in the format ‘Case x: a’ 
(quotes for clarity), where x is the case number and a is the 
age of the captain.



Sample Input
2
5 19 17 16 14 12
5 12 14 16 17 18

Sample Output
Case 1: 16
Case 2: 16