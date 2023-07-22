11038 - How Many O's?  
https://github.com/morris821028/UVa/blob/master/volume110/11038%20-%20How%20Many%20O's.cpp
http://blog.csdn.net/keshuai19940722/article/details/26357969
http://mypaper.pchome.com.tw/zerojudge/post/1322853650

#include <stdio.h>

long long calcZeros(long long n) {
	if (n < 0)	
		return 0;
	long long sum = 1, n10 = 1, ntail = 0;
	//zero ->add one to sum ->sum=1
	while (n) {
		if (n % 10 != 0) 
			sum += n / 10 * n10;
		//because no ten multiple, can calculate no need to separate 
		//calculate from higest digit
	    //ex 123 ->sum=123/10=12 12+1 13 12->12/10*10=10  ->23
		else 
			sum += (n / 10 - 1)*n10 + (ntail + 1);
		    //calculate ten multiple ex 10->2 50->6
			//because ten multiple have more zero, 
			//so calculate two part separately
			//ex 105->100 101 102 103 104 (ntail=5)
			//more zero part and no part ex 0~100 -> 0~99 and 10 100 
            //sub 1 from n/10 and add one to ntail 			
			
			//calculate from higest digit
	        //ex 100 ->sum=99/10=9 9+1(ntail+1)+1(sum) 11 
			//         10->9/10*10=0 0(ntail+1)  ->12
			
			//ntail+1 
		ntail += n % 10 * n10;//only iff no ten multiple number
		n /= 10, n10 *= 10;
	}
	return sum;
}
int main() {
	long long m, n;
	while (scanf("%lld %lld", &m, &n),m!=-1) 
		printf("%lld\n", calcZeros(n) - calcZeros(m - 1));
	return 0;
}



#include<stdio.h>
long long sum(long long n){
	long long sum = 1, ten = 1, ntail = 0;
	if (n < 0)
		return 0;
	while (n) {
		if (n % 10 != 0)
			sum += n / 10 * ten;
		else
			sum += (n / 10 - 1)*ten + ntail + 1;
		ntail += n % 10 * ten;
		n /= 10; ten *= 10;
	}
	return sum;
}
int main() {
	long long n, m;
	while (scanf("%lld%lld", &n, &m), n != -1)
		printf("%lld\n", sum(m) - sum(n - 1));
	return 0;
}



A Benedict monk No. 16 writes down the decimal representations
of all natural numbers between and including m and n, m  n. How
many 0's will he write down?



Input
Input consists of a sequence of lines. 
Each line contains two un-signed 32-bit integers m and n,
m  n. 
The last line of input has the value of m negative and this
line should not be processed.

Output
For each line of input print one line of output with one 
integer number giving the number of 0's written down by the 
monk.



Sample Input
10 11
100 200
0 500
1234567890 2345678901
0 4294967295
-1 -1

Sample Output
1
22
92
987654304
3825876150