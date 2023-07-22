no_input_dif_12414 - Calculating Yuan Fen
http://mypaper.pchome.com.tw/zerojudge/post/1323237872



#include <stdio.h>
int main() {
	char s[100], buf[100];
	while (fgets(s,sizeof(s),stdin)) {
		int ST = 1;
		int i, j, ok = 1;
		while (ST <= 10000 && ok) {
			char tmp[100] = {};
			int tt = 0;
			for (i = 0; s[i]; i++) {
				int num = s[i] - 'A' + ST;
				sprintf(tmp + tt, "%d", num);
				while (tmp[tt] != '\0')
					tt++;
			}
			for (i = 0; i < tt; i++)
				tmp[i] -= '0';
			while (tt) {
				for (i = 0; i < tt - 1; i++) {
					tmp[i] = tmp[i] + tmp[i + 1];
					if (tmp[i] >= 10)    tmp[i] -= 10;
				}
				tt--;
				if (tt == 2 && tmp[0] == 1 && tmp[1] == 0 && tmp[2] == 0) {
					printf("%d\n", ST);
					ok = 0;
				}
			}
			ST++;
		}
		if (ok)
			puts(":(");
	}
	return 0;
}



Yuanfen (http://en.wikipedia.org/wiki/Yuanfen) is a 
Chinese term that is hard to understand for people in other 
countries. Roughly speaking, yuanfen means the pre-determined 
\binding force" that links two people (usually two lovers) 
together. Although it is a blind faith, many people, 
especially girls like to calculate it.
Unfortunately, my girlfriend is one of them. One day, 
she asked me, \Sweetie, shall we nd out our yuanfen?" Oh, 
I really hate that question, but I cannot reject it... Luckily, 
I'm a programmer, so the only thing I need to do is to nd a 
seemingly good algorithm and write a yuanfen calculator. After
several hours' searching in the web, I decided to implement 
the following popular yuanfen algorithm:
Step 1: Pick up the name abbreviations of the couple and 
concatenate them. For example, 
if the couple named Jiang Yun Fan and Tang Yu Rou, 
the concatenation of abbreviations is JYFTYR.
Step 2: Replace each letter with a number string. 
For some predened positive integer ST, replace A with
ST, and B with ST + 1, C with ST + 2, . . . , Z with ST + 25. 
For example, if ST = 81, A should be replaced with 81, 
B should be replaced with 82, . . . , Z will be replaced by 106.
In the case above, JYFTYR will be replaced by 901058610010598.
Step 3: Repeat the following: add up each pair of consecutive 
digits, and write down the last digit of each sum. 
It's not difficult to see that each time we perform this action,
the number of digits is decreased by 1. 
When the number string is exactly 100, or has no more than 2 
digits, the process ends. The current number is the yuanfen 
between the couple. In the case above, the process is
as follows:
901058610010598
91153471011547
0268718112691
284589923850
02937815135
2120596648
332545202
65799722
1268694
384453
12898
3077
374
01
So if ST = 81, Jiang Yun Fan and Tang Yu Rou's yuanfen is only 
1! Too bad! I know my girlfriend very well. 
I know that even the result is as high as 99, she'll still be
unhappy. Could you nd the value of ST such that the yuanfen 
between my sweetheart and I is 100?



Input
There will be at most 50 test cases. Each case contains a 
string of at least four and at most ten capital letters.

Output
For each test case, print the smallest positive integer ST
(note that ST should not be zero). 
If it does not exist or larger than 10000, 
print a string `:(' (without quotes). Disclaimer
Don't be sad if the result of you and your sweetie is larger 
than 10000. That's no big deal.



Sample Input
JYFTYR
ABCDEF
YTHHLS
YTHLML
LYXM
JYFLY
CBTZX
LXYZLE
LXYLYR
QWERTY

Sample Output
148
634
:(
910
96
4284
631
850
149
2277