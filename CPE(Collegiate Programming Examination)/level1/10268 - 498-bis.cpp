10268 - 498-bis

 
 
#include <cstdio>  
  
int main()  
{  
    int x, a, temp;  
    while (scanf("%d",&x) != EOF) {  
        getchar();  
        temp = getchar();  
        int sum = 0, ans = 0;  
        while (temp != '\n' && temp != EOF) {  
            if (temp == '-' || '0'<=temp && temp <= '9') {  
                ungetc(temp, stdin);  
                scanf("%d",&a);  
                ans = ans * x + sum;  
                sum = sum * x + a;  
            }  
            temp = getchar();  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  



Looking throw the “Online Judge’s Problem Set Archive” 
I found a very interesting problem number
498, titled “Polly the Polynomial”. Frankly speaking, 
I did not solve it, but I derived from it this problem.
Everything in this problem is a derivative of something from 498. 
In particular, 498 was “... designed to help you remember ... 
basic algebra skills, make the world a better place, etc., etc.”. 
This problem is designed to help you remember basic derivation 
algebra skills, increase the speed in which world becomes a better 
place, etc., etc. In 498 you had to evaluate the values of polynomial
//a0x n + a1x n−1 + . . . + an−1x + an.
In this problem you should evaluate its derivative. 
Remember that derivative is defined as
//a0nxn−1 + a1(n − 1)x n−2 + . . . + an−1.
All the input and output data will fit into integer, i.e. 
its absolute value will be less than 231.



Input
Your program should accept an even number of lines of text. 
Each pair of lines will represent one problem. The first line will 
contain one integer - a value for x. The second line will contain a 
list of integers a0, a1, ..., an−1, an, which represent a set of 
polynomial coefficients. Input is terminated by ¡EOF¿.

Output
For each pair of lines, your program should evaluate the derivative 
of polynomial for the given value x and output it in a single line.



Sample Input
7
1 -1
2
1 1 1

Sample Output
1
5