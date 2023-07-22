38.10642 - Can You Solve It?



no1.
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for(int times=1;times<=N;times++)
    {
        int x[2],y[2];
        for(int i=0;i<2;i++) cin>>x[i]>>y[i];
        int t1=0,t2=0;
        for(int i=1;i<=x[0]+y[0];i++)
        {
            t1+=i;
        }
        t1+=x[0];
        for(int i=1;i<=x[1]+y[1];i++)
        {
            t2+=i;
        }
        t2+=x[1];
        int ans=t2-t1;
        cout<<"Case "<<times<<": "<<ans<<endl;
    }
    return 0;
}



no2
#include<iostream>
using namespace std;

int main()
{
	int x[2],y[2],cas;
	cin >> cas;
	for (int j = 1; j <= cas; j++)
	{
		int t1 = 0, t2 = 0;
		cin >> x[0] >> y[0] >> x[1] >> y[1];

		for (int i = 1; i <= x[0] + y[0]; i++)
			t1 += i;
		t1 += x[0];
		for (int i = 1; i <= x[1] + y[1]; i++)
			t2 += i;
		t2 += x[1];
		cout << "Case " << j << ": " << t2-t1 << endl;
	}
}



First take a look at the following picture. In this picture, 
each circle has a coordinate according to
Cartesian Coordinate System. You can move from one circle to 
another following the path denoted by forward arrow symbols. 
To go from a source circle to a destination circle,total number 
of step(s) needed = number of intermediate circles you pass + 1
For example, to go from (0, 3) to (3, 0) you have to pass two 
intermediate circles (1, 2) and (2, 1). So,
in this case, total number of steps needed is 2 + 1 = 3. 
In this problem, you are to calculate number of
step(s) needed for a given source circle and a destination 
circle. You can assume that, it is not possible
to go back using the reverse direction of the arrows.



Input
The first line in the input is the number of test cases 
n (0 < n ≤ 500) to handle. Following there are n lines each 
containing four integers (0 ≤ each integer ≤ 100000) the first 
pair of which represents the coordinates of the source circle 
and the other represents that of the destination circle. 
The coordinates are listed in a form (x, y).

Output
For each pair of integers your program should output the case 
number first and then the number of step(s) to reach the 
destination from the source. You may assume that it is always 
possible to reach the destination circle from the source circle.



Sample Input
3
0 0 0 1
0 0 1 0
0 0 0 2

Sample Output
Case 1: 1
Case 2: 2
Case 3: 3