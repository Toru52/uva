11526 - H(n)
What is "H"
http://mathtrain.jp/tyohukuc



http://blog.csdn.net/synapse7/article/details/12873437



#include<cstdio>  
#include<cmath>  
typedef long long ll;  
  
inline ll ans(ll n)  
{  
    ll r = 0, m = sqrt(n), i;  
    for (i = 1; i <= m; ++i) r += n / i;  
    return (r << 1) - m * m;  
}  
  
int main()  
{  
    int t;  
    ll n;  
    scanf("%d", &t);  
    while (t--)  
    {  
        scanf("%lld", &n);  
        printf("%lld\n", ans(n));  
    }  
    return 0;  
}  



http://hoyusun.blogspot.tw/2012/05/uva-11526-hn.html

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        long long int Ans = 0, n;
        scanf("%lld", &n);
        int sq = sqrt(n), last = n;
        for(int i = 1; i <= sq; i++){
            long long count = n/i-n/(i+1);
            if(i == n/i)    Ans += n/i;
            else    Ans += i*count+n/i;
        }
        printf("%lld\n", Ans);
    }
    return 0;
}



#include<stdio.h>
#include<math.h>
typedef long long ll;
inline ll H(ll n) {
	ll res = 0, m = sqrt(n);
	for (ll i = 1; i <= m; i++)res += n / i;
	return res * 2 - m*m;
}
int main() {
	int t;
	ll n;
	scanf("%d", &t);
	while (t--)
		scanf("%lld", &n), printf("%lld\n", H(n));
	return 0;
}



What is the value this simple C++ function will return?
long long H(int n){
long long res = 0;
for( int i = 1; i <= n; i=i+1 ){
res = (res + n/i);
}
return res;
}
Input
The rst line of input is an integer T (T  1000) that 
indicates the number of test cases. Each of the
next T line will contain a single signed 32 bit integer n.
Output
For each test case, output will be a single line containing H(n).



Sample Input
2
5
10

Sample Output
10
27