11286　	Conformity
https://www.davidudelson.com/blog/2015/07/07/uva-11286-conformity/



#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		map<vector<int>, int> m{};
		for (int i = 0; i<n; i++) {
			vector<int> c(5);
			for (auto &x : c) cin >> x;
			sort(c.begin(), c.end());
			m[c]++;
		}
		int max_val = 0,cnt = 0;
		for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); ++it) 
			max_val = max(max_val, it->second);

		for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); ++it) 
			if (it->second == max_val) 
				cnt++;	
		cout << max_val*cnt << '\n';
	}
}



#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main() {
	int n,x;
	while (scanf("%d", &n), n) {
		map<vector<int>, int>m{};
		int max = 0, type = 0;
		for (int i = 0; i < n; i++) {
			vector<int>c(5);
			for(auto&x:c)
				scanf("%d", &x);
			sort(c.begin(),c.end());
			m[c]++;
			if (max < m[c])
				max = m[c];
		}
		for (map<vector<int>,int>::iterator it = m.begin(); it != m.end(); it++)
			if (it->second == max)
				type++;
		printf("%d\n", type*max);
	}
	return 0;
}



/*
concept 
count student number that choose most popular course 
ex
4
1 1 1 1 1
1 1 1 1 1
2 2 2 2 2
2 2 2 2 2
4
->if there are two or more most popular(most pupular number are same),
  most pupular number multiple duplication number
*/


Frosh commencing their stud-
ies at Waterloo have diverse
interests, as evidenced by
their desire to take vari-
ous combinations of courses
from among those available.
University administrators
are uncomfortable with this
situation, and therefore wish
to offer a conformity prize
to frosh who choose the
most popular combination of
courses. How many frosh
will win the prize?



Input
The input consists of several test cases followed by a line containing `0'. 
Each test case begins with an integer 1  n  10000, 
the number of frosh. For each frosh, a line follows containing the course
numbers of ve distinct courses selected by the frosh. 
Each course number is an integer between 100 and 499.
The popularity of a combination is the number of frosh selecting exactly 
the same combination of courses. 
A combination of courses is considered most popular if no other 
combination has higher popularity.

Output
For each line of input, you should output a single line giving the total 
number of students taking some
combination of courses that is most popular.



Sample Input
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0

Sample Output
2
3