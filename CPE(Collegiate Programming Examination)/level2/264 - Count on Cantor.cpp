264 - Count on Cantor

#include<cstdio>

int main() {
	int n, value, diagonal, a, b;
	while (scanf("%d", &n) == 1) {
		value = n;
		for (diagonal = 1; value > diagonal; diagonal++)
			value -= diagonal;
		printf("diagonal %d value%d\n", diagonal,value);

		if (diagonal % 2)
			a = 1 + diagonal - value;
		else 
			a = value;

		b = diagonal - a + 1;
		printf("TERM %d IS %d/%d\n", n, a, b);
	}
}



#include<cstdio>

int main()
{
	int n,value, diagonal, numerator, denomirator;
	while (~scanf("%d", &n))
	{
		value = n;
		for (diagonal = 1; value > diagonal; diagonal++)
			value -= diagonal;
		if (diagonal%2)
			numerator = diagonal - value + 1;
		else
			numerator = value;
		denomirator = diagonal - numerator + 1;
		
		printf("TERM %d IS %d/%d\n",n, numerator, denomirator);
	}
}



One of the famous proofs of modern mathematics is 
Georg Cantor’s demonstration that the set of
rational numbers is enumerable. The proof works by using an 
explicit enumeration of rational numbers
as shown in the diagram below.
1/1 1/2 1/3 1/4 1/5 . . .
2/1 2/2 2/3 2/4
3/1 3/2 3/3
4/1 4/2
5/1

->1/1, 2/1, 1/2, 3/1, 2/2, 1/3, 4/1,3/2 2/3 1/4...

 diagonal -> 1 2   3     4       5        ,,,
 value    -> 1 1 2 1 2 3 1 2 3 4 1 2 3 4 5,,,
             1 2 3 4 5 6 7 8 9 ,,,
numerator  ->1 2,1 3,2,1 4,3,2,1 5,4,3,2,1,,,
denominator->1 1,2 1,2,3 1,2,3,4 1,2,3,4,5,,,

numerator  =diagonal-value+1
denominator=diagonal-numerator+1



ex n=5,value=5
value=2 diagonal=3
a=2 b=3-a+1=2   ->2/2



In the above diagram, the first term is 1/1, 
the second term is 1/2, the third term is 2/1, the fourth
term is 3/1, the fifth term is 2/2, and so on.

http://www.gizmodo.jp/2011/07/post_8960.



Input and Output
You are to write a program that will read a list of numbers in the 
range from 1 to 107 and will print
for each number the corresponding term in Cantor’s enumeration as 
given below. No blank line should
appear after the last number.
The input list contains a single number per line and will be 
terminated by end-of-file.



Sample input
3
14
7

Sample output
TERM 3 IS 2/1
TERM 14 IS 2/4
TERM 7 IS 1/4