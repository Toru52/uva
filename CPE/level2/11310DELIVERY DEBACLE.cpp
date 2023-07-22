11310　	DELIVERY DEBACLE
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/11310%20-%20Delivery%20Debacle.cpp



#include <cstdio>
int main() {
	int T, n;
    long long f[41];
	f[0] = 1;f[1] = 1;f[2] = 5;

	for (int i = 3; i <= 40; ++i)
		f[i] = f[i - 1] + 4 * f[i - 2] + 2 * f[i - 3];

    scanf("%d", &T);
	while (T--) 
		scanf("%d", &n),printf("%lld\n", f[n]);
	
	return 0;
}

/*
solutions made of sequence
1,2, 3, 4, 5,  6,  7,   8,   9,   10
1,5,11,33,87,241,655,1793,4895,13377

f(1)=1
f(2)=5
f(n)=f(n-1)+4*f(n-2)+2*f(n-3)

*/

Wolfgang Puck has two very peculiar habits:
• I. He only makes two shapes of cakes. One is square and has 
an area of one unit. 
The other is L-shaped and has an area of three units.
• II. He will only deliver cakes packed in very specic box 
sizes. The boxes are always 2 units wide and are of varying 
length.
One day Wolfgang wondered in how many different ways he can 
pack his cakes into certain sized boxes. Can you help him?
The precise sizes of the cakes Wolfgang makes and one way to
pack them in a box of length 6. 
The ve ways to pack a box of length 2.



Input
The input begins with t, the number of different box lengths.
The following t lines contain an integer n (1  n  40).

Output
For each n output on a separate line the number of different 
ways to pack a 2-by-n box with cakes
described above. Output is guaranteed to be less than 1018.



Sample Input
2
1
2

Sample Output
1
5