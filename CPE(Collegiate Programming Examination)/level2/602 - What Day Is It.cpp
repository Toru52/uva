602 - What Day Is It? 



#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char month[12][10] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
	char day[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int m, d, y, w;
	while (scanf("%d%d%d", &m, &d, &y) == 3 && m) {
		int judge = 0;
		if (y < 1 || m < 0 || m > 12 || d < 0 || (m != 2 && d > monthday[m - 1]) || (y == 1752 && m == 9 && d > 2 && d < 14))   judge = 1;
		if (m == 2) {
			if (y <= 1752) {
				if (y % 4 && d > 28)    judge = 1;
				else if (y % 4 == 0 && d > 29)  judge = 1;
			}
			else {
				if ((y % 4 == 0 && y % 100) || y % 400 == 0) {
					if (d > 29)  judge = 1;
				}
				else {
					if (d > 28)  judge = 1;
				}
			}
		}
		if (judge) { printf("%d/%d/%d is an invalid date.\n", m, d, y);  continue; }
		if (y > 1752 || (y == 1752 && m > 9) || y == 1752 && m == 9 && d >= 14) {
			if (y == 1752) {
				w = 4;
				for (int i = 9; i < m; i++)
					w += monthday[i - 1];
				w += (d - 14);
			}
			else {
				w = 1;
				for (int i = 1753; i < y; i++) {
					w += 365;
					if ((i % 4 == 0 && i % 100) || i % 400 == 0)    w++;
				}
				for (int i = 1; i < m; i++)
					w += monthday[i - 1];
				if (((y % 4 == 0 && y % 100) || y % 400 == 0) && m > 2)   w++;
				w += (d - 1);
			}
		}
		else {
			w = (6 + (y - 1) + (y - 1) / 4) % 7;
			for (int i = 1; i < m; i++)
				w += monthday[i - 1];
			if (y % 4 == 0 && m > 2)   w++;
			w += (d - 1);
		}
		printf("%s %d, %d is a %s\n", month[m - 1], d, y, day[w % 7]);
	}
	return 0;
}