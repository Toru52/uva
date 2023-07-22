160	Factors and Factorials



#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  bool composite[105] = { true, true };
  int prime_num[105];
  int N, temp, output;

  for( int i = 2 ; i <= 100 ; i++ )
    if( !composite[i] )
      for( int j = i+i ; j <= 100 ; j += i )
        composite[j] = true;//true->not prime   false->prime

  while( scanf( "%d", &N ) != EOF && N != 0 ){
    memset( prime_num, 0, sizeof(prime_num) );
    for( int i = 2 ; i <= N ; i++ )
      if( !composite[i] ){
        temp = N;
        while( temp / i ){
          prime_num[i] += temp / i;
          temp /= i;
        } 
      }

    output = 0;
    printf( "%3d! =", N );
    for( int i = 2 ; i <= N ; i++ )
      if( !composite[i] ){
        if( output == 15 ){
          printf( "\n      " );
          output = 0;
        }
        printf( "%3d", prime_num[i] );
        output++;
      }
    printf( "\n" );
  }

  return 0;
}



#include<cstdio>

int main() {
	bool composite[105] = { true, true };
	int N, temp, output,c=0;

	for (int i = 2; i <= 100; i++)
		if (!composite[i])
			for (int j = i + i; j <= 100; j += i)
				printf("ok c %d i%d j %d\n",c++,i,j),composite[j] = true;

	while (scanf("%d", &N) != EOF && N != 0) {
		int prime_num[105] = {};
		for (int i = 2; i <= N; i++)
			if (!composite[i]) {
				temp = N;
				while (temp / i) {
					prime_num[i] += temp / i;
					temp /= i;
				}
			}

		output = 0;
		printf("%3d! =", N);
		for (int i = 2; i <= N; i++)
			if (!composite[i]) {
				if (output == 15) {
					printf("\n      ");
					output = 0;
				}
				printf("%3d", prime_num[i]);
				output++;
			}
		printf("\n");
	}
	return 0;
}



#include<cstdio>
int main()
{
	bool nprime[101] = {true,true};
	int N;
	for (int i = 2; i <= 100; i++)
		if (!nprime[i])
			for (int j = i + i; j <= 100; j += i)
				nprime[j] = true;
	while (~scanf("%d",&N)&&N)
	{
		int pnum[101] = {};
		for(int i=2;i<=100;i++)
			if (!nprime[i])
			{
				int temp = N;
				while (temp / i)
				{
					pnum[i] += temp / i;
					temp /= i;
				}
			}
		int line = 0;
		printf("%3d! =",N);
		for (int i = 2; i <= 100; i++)
			if (pnum[i])
			{
				if (line == 15)
					printf("\n      "), line = 0;
				printf("%3d", pnum[i]);
				line++;
			}
		puts("");
	}
}


	
	
	
The factorial of a number N (written N!) is defined as the 
product of all the integers from 1 to N. It is often defined 
recursively as follows:
displaymath27
displaymath28

Factorials grow very rapidly--5! = 120, 10! = 3,628,800. 
One way of specifying such large numbers is by specifying the 
number of times each prime number occurs in it, thus 825 could 
be specified as (0 1 2 0 1) meaning no twos, 1 three, 2 fives, 
no sevens and 1 eleven.
Write a program that will read in a number N 
( tex2html_wrap_inline39 ) and write out its factorial in 
terms of the numbers of the primes it contains.



Input
Input will consist of a series of lines, each line containing 
a single integer N. The file will be terminated by a line 
consisting of a single 0.

Output
Output will consist of a series of blocks of lines, one block 
for each line of the input. Each block will start with the 
number N, right justified in a field of width 3, and the 
characters `!', space, and `='. This will be followed by a 
list of the number of times each prime number occurs in N!.
These should be right justified in fields of width 3 and each 
line (except the last of a block, which may be shorter) should 
contain fifteen numbers. Any lines after the first should be 
indented. Follow the layout of the example shown below exactly.



Sample input
5
53
0
Sample output

  5! =  3  1  1
 53! = 49 23 12  8  4  4  3  2  2  1  1  1  1  1  1
        1


