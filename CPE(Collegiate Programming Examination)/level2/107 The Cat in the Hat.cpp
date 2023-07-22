107 - The Cat in the Hat



#include<iostream>
#include<cstdio>
#include<cmath>
#define ERROR 1e-8//(1/10^8)
using namespace std;

int main(){
  int H, num, m, N;

  while( scanf( "%d%d", &H, &num ) != EOF && !(H == 0 && num == 0)){
    if( H == 1 && num == 1 ){
      printf( "0 1\n");
      continue;
    }

    m = 1;//start from power of 1 (H^1)
    while( H != (int)(pow(pow(num,1.0/m)+1.0, m)+ERROR) ) m++;
    N = (int)(pow(num,1.0/m)+ERROR);
    if( N != 1 ) printf( "%d %d\n", (1-num)/(1-N), (H-num)*(N+1)+num );
    else printf( "%d %d\n", m, (H-num)*(N+1)+num );
  }
  return 0;
}



#include<cstdio>
#include<cmath>
#define ERROR 1e-8
int main()
{
	int h, cats;
	while (~scanf("%d %d", &h, &cats) && h)
	{
		if (h == 1 && cats == 1)
		{
			puts("0 1");
			continue;
		}
		int m = 1;
		while (h != (int)(pow(pow(cats, 1.0 / m) + 1.0, m) + ERROR))
			m++;
		int N = (int)(pow(cats,1.0/m) + ERROR);
		if (N != 1)
			printf("%d %d\n", (1 - cats) / (1 - N), (h - cats)*(N + 1)+cats);
		else
			printf("%d %d\n", m, (h - cats)*(N + 1)+cats);
	}
}



Explanation
Point
1, The smallest cats are of height one
2, The height of these cats-in-a-hat is  1/N+1 times the height 
of the cat whose hat they are in

Therefore we can imagine how to divide the cats 
from Heighest initial cat to smallest cats

ex
Heights(h): 216  36   6    1
Numbers(N):   1   5  25  125
N=n-1
h1=1/(N+1)*h2   ->216=1/(N+1)*h2
h2=1/(N+1)*h3
,,,,


Algorithm
125->25->5->1  --->   1->-6>-36->216
->
->while( H != (int)(pow(pow(num,1.0/m)+1.0, m)+ERROR) ) m++;

ex 216 125
while(216!=(1/(N+1)))
	
m=1   125->125^(1/1)->125+1->126^1  no 
m=2   125->125^(1/2)->25+1->26^2    no
m=3   125->125^(1/3)->5+1->6^3      yes

N=125^(1/3)=5

(1 - num) / (1 - N), (H - num)*(N + 1) + num
(1-125)/(1-5),(216-125)*(5+1)+125
-124/-4,91*6+125
31,671

other way
1+5+25=31
216*1+36*5+6*25+1*125=671




(An homage to Theodore Seuss Geisel)
The Cat in the Hat is a nasty creature,
But the striped hat he is wearing has a rather nifty 
feature.
With one flick of his wrist he pops his top off.
Do you know what's inside that Cat's hat?
A bunch of small cats, each with its own striped hat.
Each little cat does the same as line three,
All except the littlest ones, who just say ``Why me?''
Because the littlest cats have to clean all the grime,
And they're tired of doing it time after time!

The Problem
A clever cat walks into a messy room which he needs to 
clean. Instead of doing the work alone, it decides to have 
its helper cats do the work. It keeps its (smaller) helper 
cats inside its hat. Each helper cat also has helper cats 
in its own hat, and so on. Eventually, the cats reach a 
smallest size. These smallest cats have no additional cats 
in their hats. These unfortunate smallest cats have to do 
the cleaning.
The number of cats inside each (non-smallest) cat's hat is
a constant, N. The height of these cats-in-a-hat is  
tex2html_wrap_inline35 times the height of the cat whose 
hat they are in.
The smallest cats are of height one; 
these are the cats that get the work done.
All heights are positive integers.
Given the height of the initial cat and the number of 
worker cats (of height one), find the number of cats that 
are not doing any work (cats of height greater than one) 
and also determine the sum of all the cats' heights 
(the height of a stack of all cats standing one on top of 
another).



The Input
The input consists of a sequence of cat-in-hat 
specifications. Each specification is a single line 
consisting of two positive integers, separated by white 
space. The first integer is the height of the initial cat, 
and the second integer is the number of worker cats.
A pair of 0's on a line indicates the end of input.

The Output
For each input line (cat-in-hat specification), 
print the number of cats that are not working, 
followed by a space, followed by the height of the stack 
of cats. There should be one output line for each input 
line other than the ``0 0'' that terminates input.



Sample Input
216 125
5764801 1679616
0 0

Sample Output
31 671
335923 30275911