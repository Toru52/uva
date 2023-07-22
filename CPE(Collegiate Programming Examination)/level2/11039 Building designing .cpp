 11039 Building designing 
 https://github.com/Diusrex/UVA-Solutions/blob/master/11039%20Building%20designing.cpp
 
 
 
 #include <iostream>
#include <algorithm>
using namespace std;

struct Floor{
 int size, color;
 bool operator<(const Floor & other){return size > other.size;}
};
int N;
Floor floors[500005];

int sc(int color)
{
	int count = 0, neededColor = 1 - color;
	for (int i = 0; i < N; ++i)
		if (floors[i].color == neededColor){
			++count;
			neededColor = 1 - neededColor;
		}
	return count;
}
int main()
{
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; ++i)	{
			cin >> floors[i].size;
			floors[i].color = (floors[i].size < 0);
			//1->red(minus)  0->blue(plus)
			//It's not compare operator. It's struct operator.
			floors[i].size = abs(floors[i].size);
		}
		sort(floors, floors + N);
		cout << max(sc(0), sc(1)) << '\n';
	}
}



#include<iostream>
#include<algorithm>
using namespace std;
struct floors {
	int color, size;
	bool operator<(const floors&others) { return size > others.size; }
};
floors f[500005];
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &f[i].size);
			f[i].color = (f[i].size < 0);
			f[i].size = abs(f[i].size);
		}
		sort(f, f + n);
		int cnt = 1, precolor = f[0].color;
		for (int i = 0; i < n; i++)
			if (precolor^f[i].color)
				cnt++, precolor ^= 1;
		cout << cnt << endl;
	}
	return 0;
}




An architect wants to design a very high building. 
The building will consist of some colors, and each

oor has a certain size. The size of a 
oor must be greater than the size of the 
oor immediately
above it. In addition, the designer (who is a fan of a famous 
Spanish football team) wants to paint
the building in blue and red, each 
oor a colour, and in such a way that the colours of two consecutive

oors are different.
To design the building the architect has n available 
oors, with their associated sizes and colours.
All the available 
oors are of different sizes. The architect wants to design the 
highest possible building
with these restrictions, using the available oors.
Input
The input le consists of a rst line with the number p of cases
to solve. The rst line of each case
contains the number of available 
oors. Then, the size and colour of each 
oor appear in one line.
Each 
oor is represented with an integer between -999999 and 999999.
There is no 
oor with size 0.
Negative numbers represent red 
oors and positive numbers blue 
oors. The size of the 
oor is the
absolute value of the number. There are not two 
oors with the same size. The maximum number of

oors for a problem is 500000.
Output
For each case the output will consist of a line with the number of 
oors of the highest building with
the mentioned conditions.



Sample Input
2
5
7
-2
6
9
-3
8
11
-9
2
5
18
17
-15
4


3

3

-1 -2 -3

3

1 -2 3

3

1 2 -3
Sample Output
2
5

 
1

3

2
 