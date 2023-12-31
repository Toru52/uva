10714 - Ants
http://mypaper.pchome.com.tw/zerojudge/post/1322993165


#include <stdio.h>

int main() {
	int t, x;
	scanf("%d", &t);
	while (t--) {
		int l, n, min = 0, max = 0;
		scanf("%d %d", &l, &n);
		while (n--) {
			scanf("%d", &x);
			x = x < l - x ? x : l - x;
			if (x > min)
				min = x;
			if (l - x > max)
				max = l - x;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}



#include<stdio.h>
int main() {
	int x,l, t,n;
	scanf("%d", &t);
	while (t--) {
		int max = 0, min = 0;
		scanf("%d %d", &l, &n);
		while (n--) {
			scanf("%d", &x);
			if (x >= l - x)x=l-x;
			if (min < x)min = x;
			if (max < l - x)max = l - x;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}

An army of ants walk on a horizontal pole of length l cm, 
each with a constant speed of 1 cm/s. 
When a walking ant reaches an end of the pole, 
it immediatelly falls off it. When two ants meet they turn
back and start walking in opposite directions. We know the 
original positions of ants on the pole,
unfortunately, we do not know the directions 
in which the ants are walking. Your task is to compute
the earliest and the latest possible times needed 
for all ants to fall off the pole



Input
The rst line of input contains one integer giving the 
number of cases that follow. The data for each case start 
with two integer numbers: the length of the pole (in cm) and 
n, the number of ants residing on the pole. These two numbers 
are followed by n integers giving the position of each ant 
on the pole as the distance measured from the left end of the 
pole, in no particular order. All input integers are
not bigger than 1000000 and they are separated by whitespace.

Output
For each case of input, output two numbers separated by a 
single space. The rst number is the earliest
possible time when all ants fall off the pole 
(if the directions of their walks are chosen appropriately)
and the second number is the latest possible such time.



Sample Input
2
10 3
2 6 7
214 7
11 12 7 13 176 23 191

Sample Output
4 8
38 207