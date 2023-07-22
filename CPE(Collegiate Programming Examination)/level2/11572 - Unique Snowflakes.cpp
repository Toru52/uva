11572 - Unique Snowflakes
https://www.davidudelson.com/blog/2015/07/23/uva-11572-unique-snowflakes/

concept
https://www.redgreencode.com/uva-11572-unique-snowflakes/



#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		map<int, int> lastseen;

		int x,ans = 0, cnt = 0, block = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			int lx = lastseen[x];
			printf("lx %d\n", lx);
			if (lx != 0) {
				block = max(block, lx);
				cnt = i - block - 1;
			}
			cnt++;
			lastseen[x] = i;
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}
}



#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		map<int, int>once;
		int x,ans = 0, cnt = 0,block=0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			if (once[x]) {
				block = max(block, once[x]);
				cnt = i - block - 1;
			}
			cnt++;
			ans = max(ans, cnt);
			once[x] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}



/*
key point
"bags of uniqueness."

largest possible package of unique snowflakes that can be created
->package of unique snowflakes(time count)

->like to know that 
  how many different snowflakes machine can to create at most
->create identical->need a disposole

once it starts, all snowflakes owing from the machine must 
go into the package until the package is completed and sealed.

The package can be completed and sealed before all of the 
snowflakes have owed out of the machine.
  
  
  
ex 
5
1
2
3
2
1

image
1
2
3

  3
 23
123
->(threen section)

2(double)
take out 

2
2->(2 has two)

section 4-two-1=1

  3
 23
1232

1(double)
take out

1->(1 have one)

section 5 - one-1 =3

  3 1  1
 23 1  1
12321  1(block(double) max is 3)
->leagest size is 3

7
1
2
3
4
3
2
1

   4
  34
 234
1234

3(double)
take out
3
3
3(have three)
section 5- three-1=1

   4
  34
 234
12343

*/
Emily the entrepreneur has a cool business idea: packaging and 
selling snow akes. She has devised amachine that captures snow
akes as they fall, and serializes them into a stream of snow
akes that ow,
one by one, into a package. Once the package is full, 
it is closed and shipped to be sold.
The marketing motto for the company is \bags of uniqueness.
" To live up to the motto, every snow ake in a package must be 
different from the others. Unfortunately, 
this is easier said than done, 
because in reality, many of the snow akes owing through the 
machine are identical. Emily would like to know the size of the 
largest possible package of unique snow akes that can be created.
The machine can start lling the package at any time, 
but once it starts, all snow akes owing from the machine
must go into the package until the package is completed and 
sealed. The package can be completed and sealed before all of 
the snow akes have owed out of the machine.



Input
The rst line of input contains one integer specifying the 
number of test cases to follow. Each test case begins with a 
line containing an integer n, the number of snow
akes processed by the machine.
The following n lines each contain an integer 
(in the range 0 to 109, inclusive) uniquely identifying a snow
ake. 
Two snow akes are identied by the same integer if and only if 
they are identical. The input will contain no more than one 
million total snow akes.

Output
For each test case output a line containing single integer, 
the maximum number of unique snow akes that can be in a package.



Sample Input
1
5
1
2
3
2
1

Sample Output
3