10931－Parity
https://sites.google.com/site/pcshic/solutions/100-1-zi-xun-she-qi-mo-kao-can-kao-jie-da
http://mypaper.pchome.com.tw/zerojudge/post/1322192662


#include <iostream>
#include <string>
using namespace std;

int main () {
    int n, i, s;
    string b, d="01";
    while (cin >> n, n) {
        s = 0;
        b = "";
        while (n) {
            s += n % 2;
            b = d[n % 2] + b;
            n /= 2;
        }
        cout << "The parity of " << b << " is " << s << " (mod 2).\n";
    }
}



#include<stdio.h>
int t, N;
void D(int N) {
	if (N) {
		D(N / 2);
		printf("%d", N & 1);
		t += N & 1;
	}
}
int main() {
	while (scanf("%d", &N) == 1 && N) {
		printf("The parity of ");
		t = 0, D(N);
		printf(" is %d (mod 2).\n", t);
	}
	return 0;
}


