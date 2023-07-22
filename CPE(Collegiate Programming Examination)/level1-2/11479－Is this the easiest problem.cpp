11479－Is this the easiest problem?
https://sites.google.com/site/pcshic/solutions/100-1-zi-xun-she-qi-mo-kao-can-kao-jie-da


#include<iostream>
#include<algorithm>

int main() {
	int n;
	int edge[3];
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &edge[0], &edge[1], &edge[2]);
			if (abs(edge[0] - edge[1]) >= edge[2] ||
				abs(edge[1] - edge[2]) >= edge[0] ||
				abs(edge[0] - edge[2]) >= edge[1])      ///triangle condition
				printf("Case %d: Invalid\n", i);
			else if (edge[0] == edge[1] && edge[1] == edge[2])
				printf("Case %d: Equilateral\n", i);
			else if (edge[0] == edge[1] ||
				edge[1] == edge[2] ||
				edge[2] == edge[0])
				printf("Case %d: Isosceles\n", i);
			else printf("Case %d: Scalene\n", i);
		}
	}
	return 0;
}



#include<iostream>
#include<algorithm>
int main()
{
	int n, edge[3];

	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &edge[0], &edge[1], &edge[2]);

			if (abs(edge[0] - edge[1]) >= edge[2] ||
				abs(edge[1] - edge[2]) >= edge[0] ||
				abs(edge[2] - edge[0]) >= edge[1])
				printf("Case %d: Invalid\n", i);
			else if (edge[0] == edge[1] && edge[1] == edge[2])
				printf("Case %d: Equilateral\n", i);
			else if (edge[0] == edge[1] || edge[1] == edge[2] || edge[2] == edge[0])
				printf("Case %d: Isosceles\n", i);
			else
				printf("Case %d: Scalene\n", i);
		}
	}
}




#include <iostream>
using namespace std;
int main () {
    long long T, x, a, b, c;
    cin >> T;
    for (x=1; x<=T; x++) {
        cin >> a >> b >> c;
        if (a <= 0 || b <= 0 || c <= 0 || a+b <= c || a+c <= b || b+c <= a)
            cout << "Case " << x << ": Invalid\n";
        else if (a == b && b == c)
            cout << "Case " << x << ": Equilateral\n";
        else if (a == b || b == c || c == a)
            cout << "Case " << x << ": Isosceles\n";
        else
            cout << "Case " << x << ": Scalene\n";
    }
}


A triangle is a geometric shape with three positive sides. However, any given three sides won’t necessarily
form a triangle. The three sides must form a closed region. Triangles are categorized depending
on the values of the sides of a valid triangle. In this problem you are required to determine the type of
a triangle.



Input
The first line of input will contain a positive integer T < 20, where T denotes the number of test cases.
Each of the next T lines will contain three 32 bit signed integer.
Output
For each case of input there will be one line of output. It will be formatted as:
Case x: triangle type.
Where x denotes the case number being processed and triangle type is the type of the triangle.
triangle type will be one of the following, depending on the values of the three sides:
• Invalid - The three sides can not form a triangle
• Equilateral - All three sides of valid triangle are equal
• Isosceles - Exactly two of the sides of a valid triangle are equal.
• Scalene - No pair of sides are equal in a valid triangle.



Sample Input
4
1 2 5
1 1 1
4 4 2
3 4 5
Sample Output
Case 1: Invalid
Case 2: Equilateral
Case 3: Isosceles
Case 4: Scalene