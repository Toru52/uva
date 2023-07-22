11309 Counting Chaos 
http://mypaper.pchome.com.tw/zerojudge/post/1322923782


#include <stdio.h>
#include <string.h>

int main() {
	int t, x, y, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d:%d", &x, &y);
		int time = x * 60 + y;
		char str[10]{};
		do {
			time++;
			if (time >= 1440)   
				time = 0;
			x = time / 60, y = time % 60;
			//because sprintf can ignore zero
			sprintf(str, "%02d%02d", x, y);
			sscanf(str, "%d", &n);
			sprintf(str, "%d", n);
	//		printf("n %d\n", n);
	//		for (int i = 0; str[i]; i++)
	//			printf("%d", str[i]-'0');
	//		puts("");
			int flag = 0;
			for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
				if (str[i] != str[j])
					flag = 1;
			if (!flag) {
				sprintf(str, "%02d:%02d", x, y);
				puts(str);
				break;
			}
		} while (true);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main() {
	int t,h,m,n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d:%d", &h, &m);
		int time = h * 60 + m;	
		do {
			time++;
			if (time >= 1440)
				time = 0;
			h = time / 60, m = time % 60;
			char str[10]{};
			sprintf(str, "%02d%02d", h, m);
			sscanf(str, "%d", &n);
			sprintf(str, "%d", n);
			bool flag = false;
			for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
				if (str[i] != str[j])
					flag = true;
			if (!flag) {
				printf("%02d:%02d\n", h, m);
				break;
			}
		} while (1);
	}
	return 0;
}

/*
concept
make palindrome time at next time from current time
ex 
23:30 ->23:32

condition
1 if HH are zero,make palindrome in MM
2 if HH are zero and just one digit (ex 00:01,00:05),
  ignore three zero and make palindrome by just one digit 
  at next time

*/


Wolfgang Puck's rival, Emeril Lagasse (\BAM!"), 
recently set the world culinary record in the category of 
smallest souffle measuring in at a mere 2 cm! Wolfgang, 
not to be outdone, decided that he would set a culinary 
record of his own: the most symmetric marble cake in the 
world. This is clearly not an easy feat!
As we all know from Wolfgang's bestselling biography, 
he is a very superstitious chef. In his attempts to create 
the symmetric cake, 
he has vowed to remove the cake from the oven only at a
palindromic time, i.e., 
a time that reads the same when read from left-to-right as 
right-to-left. Not including the current time, 
when is the next opportunity for Wolfgang to remove his cake?



Input
On the rst line of the input you are given n, the number 
of attempts Wolfgang makes to make his symmetric cake. 
The following n lines contain a string formatted as 
`HH:MM' indicating the current time on a twenty-four 
hour clock. 
(So 0  HH  23 and 0  MM  59 and `00:00' 
follows \23:59")

Output
For each attempt, output a string indicating the next 
palindromic time (not including the current time)
on a single line formatted as `HH:MM'. When determining 
if HH : MM is palindromic, ignore all
leading zeroes in HH. If HH is zero then ignore all leading 
zeroes in MM.



Sample Input
3
00:00
23:30
14:59

Sample Output
00:01
23:32
15:51

