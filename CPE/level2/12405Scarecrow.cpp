12405	Scarecrow
https://sites.google.com/site/pcshic/solutions/2010-xiao-qing-bei-yi-zu-can-kao-jie-da



#include <cstdio>
using namespace std;

int main() {
	int T, N;
	char s[100];
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %s", &N, s);

		int ans = 0;
		for (int i = 0; i < N;) {
			if (s[i] == '#') ++i;
			else {
				++ans;
				i += 3;
			}
		}
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}



#include<cstdio>
int main()
{
	int cas,n;
	char s[123];
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++)
	{
		int cnt = 0;
		scanf("%d %s", &n, &s);
		for (int j = 0; j < n;)
		{
			if (s[j] == '#')
				j++;
			else
				cnt++, j += 3;
		}
		printf("Case %d: %d\n", i, cnt);
	}
}



#include <iostream>
#include <string>
using namespace std;

int main () {
    string s;
    int t, n, tc=1, i;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ns = 0;                             //no of s(carecrow)
        for (i=0; i<n; i++)
            if (s[i]=='.')
                ns++, i+=2;
        cout << "Case " << tc++ << ": " << ns << endl;
    }
}



Taso owns a very long field. He plans to grow different 
types of crops in the upcoming growing season. The area, 
however, is full of crows and Taso fears that they might 
feed on most of the crops. For this reason, he has decided
to place some scarecrows at different locations of the 
field. The field can be modeled as a 1×N grid. Some parts 
of the field are infertile and that means you cannot grow 
any crops on them. A scarecrow, when placed on a spot, 
covers the cell to its immediate left and right along 
with the cell it is on. Given the description of the field,
what is the minimum number of scarecrows that needs to be 
placed so that all the useful section of the field is 
covered? Useful section refers to cells where crops can
be grown.



Input
Input starts with an integer T (≤ 100), denoting the 
number of test cases.Each case starts with a line 
containing an integer N (0 < N < 100). The next line 
contains N characters that describe the field. 
A dot (.) indicates a crop-growing spot and a hash (#) 
indicates an infertile region.

Output
For each case, output the case number first followed by 
the number of scarecrows that need to be placed.



Sample Input
3
3
.#.
11
...##....##
2
##

Sample Output
Case 1: 1
Case 2: 3
Case 3: 0