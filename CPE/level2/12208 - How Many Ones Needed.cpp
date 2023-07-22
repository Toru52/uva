12208 - How Many Ones Needed?
http://mypaper.pchome.com.tw/zerojudge/post/1324022699



#include <stdio.h>
typedef long long ll;
ll digit[50] = { 1 };

ll cntOnes(ll n) {
	//bit1 1 or 0
	if (n < 1)  return 0;
	if (n == 1)  return 1;
	ll sum = 0;
	int high_bit;
	for (int i = 0; i < 40; i++) 
		if ((n >> i) & 1)//1 or 0 at bit//search where is high_bit
			high_bit = i;   //standard is two base //overwrite(not break)
	if (high_bit)//ex 10 bit3 is high_bit
		sum += digit[high_bit - 1];//include at least sum of high_bit-1(one lag)
	//printf("n %lld bit %d sum %lld tot(+1or+0) %lld\n",n, high_bit,sum,(n - (1 << high_bit)+1));
	return sum + (n - (1 << high_bit) + 1) + cntOnes(n - (1 << high_bit));
	//tot
	//ex 15 ->15-8(3bitfull)+1(1000)=8
	//ex 10 ->10-8+1=3
	//recursion
}
int main() {
	int cas = 0;
	ll a, b;
	//sum of ones at i bits (N(i)=N(i-1)^2+2^i)
	for (int i = 1; i < 30; i++)
		digit[i] = (digit[i - 1] << 1) + (1 << i);//dp
	//ex 1<<3 = 2^3=8   3<<1 = 3^2=6
	while (scanf("%lld %lld", &a, &b) == 2) {
		if (a == 0 && b == 0)
			break;
		printf("Case %d: %lld\n", ++cas, cntOnes(b) - cntOnes(a - 1));
	}
	return 0;
}



#include<stdio.h>
typedef long long ll;
ll digit[50] = { 1 };
ll ones(ll n) {
	if (n < 1)return 0;
	else if (n == 1)return 1;
	int high_bit;
	ll sum;
	for (int i = 0; i < 40; i++)
		if ((n >> i) & 1)
			high_bit = i;
	sum = digit[high_bit - 1];
	return sum + (n - (1 << high_bit) + 1) + ones(n - (1 << high_bit));
}
int main() {
	for (int i = 1; i < 50; i++)
		digit[i] = (digit[i - 1] << 1) + (1 << i);
	int cas = 0;
	ll a, b;
	while (scanf("%lld %lld", &a, &b), b) 
		printf("Case %d: %lld\n",++cas, ones(b) - ones(a - 1));
	return 0;
}

/*
bit number | max sum of ones  
1 1   (1)
2 4   (1+3)
3 12  (1+3+8)
4 32  (1+3+8+20)
5 80  (1+3+8+20+48)
6 192 (1+3+8+20+48+80)
,,,
ex
0 1 ->2(1 ones)
10 (1)    11 ->2(3 ones)
100 101 (2)   110 111->4(8 ones) since double with bit2(10 11),so N(i-1)*2       
1000 1001 1010 1011 (4)    1100 1101 1110 1111->8(20 ones)
->1,2,4,,,,
->(i-1)*2



explain about code
	for (int i = 0; i < 40; i++) 
		if ((n >> i) & 1)
			high_bit = i;
10->1010
high_bit=4bit-1=3

15
1111
->3

129
10000001
->7
128
10000000
->7




recursion concept(start from right bottom)
#{
	1bit_1(0,1)
    2bit_4(10,11)
    3bit_12(100,101,110,111)  
	}
ex n=15(1111->since 1111 hasfour ones,so recursion time is 3)
0001               
0010 0011           
0100 0101 0110 0111 
1000 1001 1010 1011 1100 1101 1110 1111

convert position
1111 1110 1101 1100 1011 1010 1001 1000
0100 0101 0110 0111
0010 0011
0001

->bit1  111~   return 1   (1111)
recursion
n=3->bit2  11~~   sum_bit1 1(110|1 111|0)  tot_bit2(2) (11|10 11|11)
recursion
n=7->bit3  1~~~   sum_bit1~2 4(11|00 11|01 11|10 11|11)  tot_bit3 4(1|100 1|101 1|110 1|111) 
recursion 
n=15->bit4  ~~~~   sum_bit1~3 12(,) tot_bit4 8(1000 1001 1010 1011 1100 1101 1110 1111)

->1+(1+2)+(4+4)+(12+8)=32
->tot(high_bit must be 1)


	
	
ex n=10(1010->recursion time 2(bit1 include recursion time even if bit1is 0))
0001                 
0010 0011             
0100 0101 0110 0111  
1000 1001 1010      
          
->bit1  111~   return 0   (101|0)
recursion
n=2->bit2  1~~~   sum_in_bit1 1(100|0 100|1)  tot_bit2 1(10|10) 
recursion 
n=10->bit4  ~~~~   sum_in_bit1~3 12(,) tot_bit4 3(1000 1001 1010 )


*/


To write binary numbers we need only two digits `0' and `1'. 
To write a specic value we need a xed number of ones, but of course 
number of zeroes may vary because of leading zeroes. 
For example to write values between 5 and 10 (inclu-sive) 
we need total 12 ones as shown in the gure on the left. 
You have to write a program that nds total number of ones that are 
required to write numbers in binary within a given range a and b.



Input
The input le can contain up to 11000 lines of inputs. Each line 
contains two positive integers a and b (0  a  b  2000000000).
Input is terminated by a line containing two zeroes. This line should not 
be processed.

Output
For each line of input of input produce one line of output. 
This line contains the serial of output followed by an integer which 
denotes the number of 1's required to write all the values between 
a and b (inclusive) in binary. 
Look at the output for sample input for details.



Sample Input
5 10
20 30
0 0

Sample Output
Case 1: 12
Case 2: 35



