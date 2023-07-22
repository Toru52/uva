10167	Birthday Cake
https://github.com/Sharknevercries/Online-Judge/blob/master/UVA/Volume%20CI/10167%20Birthday%20Cake.cpp

about ax+by=0
http://math.nakaken88.com/textbook/basic-linear-indefinite-equation/



#include<iostream>
#include<ctime>
struct Point { double x, y; };

int main() {
	int n;
	Point P[105];

	while (scanf("%d", &n) == 1 && n) {
		n <<= 1;
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		int A, B;
		while (true) {
			A = -500 + rand() % 1001;
			B = -500 + rand() % 1001;
			int cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < n; i++)
				if (A*P[i].x + B*P[i].y > 0)
					cnt1++;
				else if (A*P[i].x + B*P[i].y < 0)
					cnt2++;
			if (cnt1 == n / 2 && cnt2 == n / 2)
				break;
		}
		printf("%d %d\n", A, B);
	}
	return 0;
}



#include<iostream>
#include<ctime>
struct P { double x, y; };

int main() {
	P p[200];
	int n;
	while (scanf("%d", &n) == 1 && n) {
		n <<= 1;
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		int a, b;
		while (1) {
			a = -500 + rand() % 1001;
			b = -500 + rand() % 1001;
			int cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < n; i++) 
				if (a*p[i].x + b*p[i].y > 0)
					cnt1++;
				else if (a*p[i].x + b*p[i].y < 0)
					cnt2++;
			if (cnt1 == n / 2 && cnt2 == n / 2)
				break;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}