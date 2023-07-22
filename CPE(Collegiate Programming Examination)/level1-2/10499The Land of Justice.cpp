10499	The Land of Justice



#include<iostream>

int main() {

	long long int n;
	while (scanf("%lld", &n) == 1) {
		if (n<0) 
			break;
		if (n == 1)
			printf("0%%\n");
		else
			printf("%lld%%\n", n * 25);
	}
	return 0;
}



#include<iostream>
int main()
{
	long long int n;
	while (scanf("%lld", &n)==1)
	{
		if (n < 0)
			break;
		if (n == 1)
			printf("0%%\n");
		else
			printf("%lld%%\n", n*25);
	}
}



Algorithm
http://bruce30262.pixnet.net/blog/post/88223347-%5Bc-c%2B%2B%5D-uva-10499-the-land-of-justice
球體表面積公式4*pi*r^2
每切一塊出來，表面積就多出pi*r^2
所以分成n塊，就多出n*pi*r^2
要注意1除外(根本沒增加，所以要輸出0%)
經過計算化簡後答案就是25n%

http://maplewing.blogspot.tw/2011/03/uva10499the-land-of-justice.html
分2塊的時候，表面積會比原本球的表面積多2塊半圓，
一塊半圓會佔利潤的25%((π*r)/(4*π*r)=1/4=25%)，
所以2塊的時候是50%的利潤。
分3塊的時候，表面積會比原本球的表面積多3塊半圓=>75%。
分4塊的時候，表面積會比原本球的表面積多4塊半圓=>100%。



In the Land of Justice the selling price of everything is 
fixed all over the country. Nobody can buy a thing and sell 
it in double price. But, that created problems for the 
businessmen. They left their business and went to the 
production. So, after some days everybody was in production 
and nobody in business. And the people didn’t get their 
necessary things though the country was self-sufficient in
every sector.
The government became very much anxious. But, they were 
intelligent enough to call the mathematicians.
The mathematicians gave a solution. They suggested setting 
the surface area of an object as its
selling-unit instead of its volume. Actually the clever 
mathematicians were very much interested to establish their 
own business. Now, the government asks the programmers to 
build the software that would calculate the profit
things. Here your job is to calculate the business profit 
for a solid sphere. A businessman buys a complete
sphere and to maximize his profit he divides it in n equal 
parts. All cut should go through the axis of
the sphere. And every part should look like the picture 
below:



Input
You are given a sequence of integers N (0 < N < 2
31), indicating the numbers of parts of the sphere.
The input file is terminated with a negative number. 
This number should not be processed.

Output
Calculate the profit over the sold pieces. The result should 
be in percentage and rounded to the nearest integer.



Sample Input
2
2
-1

Sample Output
50%
50%
