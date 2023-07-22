311 - Packets
http://programming-study-notes.blogspot.tw/2014/01/uva-311-packets.html


#include <cstdio>
using namespace std;
int main()
{
	int n[7];
	while (scanf("%d %d %d %d %d %d", &n[1], &n[2], &n[3], &n[4], &n[5], &n[6]),
		n[1]+n[2]+n[3]+n[4]+n[5]+n[6]) {
		int box = n[6] + n[5] + n[4];
		n[1] -= 11 * n[5];  //一個5x5搭配11個1x1
		n[2] -= 5 * n[4];   //一個4x4搭配5個2x2(如果2x2不夠的情況最底下會考慮)

		box += (n[3] / 4); if (n[3] % 4) box++;
		switch (n[3] % 4) {  //3x3情況要特別討論
		case 0: break;
		case 1:
			n[2] -= 5,n[1] -= 7;
			break;
		case 2:
			n[2] -= 3,n[1] -= 6;
			break;
		case 3:
			n[2] -= 1,n[1] -= 5;
			break;
		}

		if (n[2]>0) {   //如果2x2還有剩
			box += n[2] / 9;
			if (n[2] % 9) 
				box++;
			n[1] -= (36 - (n[2] % 9) * 4);
		}
		else if (n[2]<0)
			n[1] -= (-n[2]) * 4; //將不夠的2x2用4個1x1來補

		if (n[1]>0) {   //如果1x1還有剩
			box += (n[1] / 36); 
			if (n[1] % 36)
				box++;
		}
		printf("%d\n", box);
	}
	return 0;
}