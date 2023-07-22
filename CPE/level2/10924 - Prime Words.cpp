10924 - Prime Words
https://sites.google.com/site/pcshic/solutions/102-2-zi-xun-di-yi-ci-xiao-kao-can-kao-jie-da



no1
#include <cstdio>
#include <cstring>
using namespace std;

bool is_prime(int n){
    if(n <= 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n/ i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int main(){
    char s[21];
    
    while(scanf("%s",s) == 1){
        int L = strlen(s),n = 0;
        
        for(int i = 0;i < L;++i)
            n += s[i] >= 'a' && s[i] <= 'z'? s[i] - 'a' + 1 : s[i] - 'A' + 27;
        //a-z(1~26) A-Z(27-53)
        puts(is_prime(n)? "It is a prime word." : "It is not a prime word.");
    }
    
    return 0;
}



no2
#include<string.h>
#include<stdio.h>

int prime(int n)
{
	if (n <= 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= n / i; i += 2)
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	char s[21];

	while (~scanf("%s", s))
	{
		int sum = 0;
		for (int i = 0; s[i]; i++)
			sum += ('a' <= s[i] && s[i] <= 'z' ? s[i] - 'a' + 1 : s[i] - 'A' + 27);
		puts(prime(sum) ? "It is a prime word." : "It is not a prime word.");
	}
}



#include <iostream>
#include <string>
using namespace std;

int main () {
    int i, n, n2;
    string s;

    while (cin >> s) {
        n = 0;
        for (i=0; i<(int)s.size(); i++)
            n += (s[i] < 'a' ? s[i] - 38 : s[i] - 96);
        for (i=2; n%i && i*i<=n; i++);                  //求第一個 <= 平方根的因數
            cout << (i*i > n ? "It is a prime word.\n" : "It is not a prime word.\n");
    }
}



A prime number is a number that has only two divisors: 
itself and the number one. Examples of prime numbers are: 
1, 2, 3, 5, 17, 101 and 10007.
In this problem you should read a set of words, each word is 
composed only by letters in the range
a-z and A-Z. Each letter has a specific value, 
the letter a is worth 1, letter b is worth 2 and so on until
letter z that is worth 26. In the same way, letter A is worth 27, 
letter B is worth 28 and letter Z is worth 52.
You should write a program to determine if a word is a prime 
word or not. A word is a prime word if the sum of its letters 
is a prime number.



Input
The input consists of a set of words. Each word is in a line 
by itself and has L letters, where 1 ≤ L ≤ 20.
The input is terminated by enf of file (EOF).

Output
For each word you should print: ‘It is a prime word.’, 
if the sum of the letters of the word is a prime number, 
otherwise you should print: ‘It is not a prime  word.’.



Sample Input
UFRN
contest
AcM

Sample Output
It is a prime word.
It is not a prime word.
It is not a prime word.