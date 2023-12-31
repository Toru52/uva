105 - The Skyline Problem
http://knightzone.org/?p=1565



#include<stdio.h>
int main() {
	int L, H, R,right = 0, skyline[10005]{};
	bool space = false;
	while (scanf("%d%d%d", &L, &H, &R)==3) {
		for (int left = L; left < R; left++)
			if (H > skyline[left]) skyline[left] = H;
		if (R > right) right = R;
	}	
	//for (int i = 0; i <= last; i++)
//		printf("i %d %d\n",i, skyline[i]);
	for (int left = 1; left <= right; left++)
		if (skyline[left - 1] != skyline[left]) {
			if (space) printf(" ");
			space = true;
			printf("%d %d", left, skyline[left]);
		}
	printf("\n");
	return 0;
}



#include<stdio.h>
int main() {
	int L, H, R, right = 0, skyline[10005]{};
	while (scanf("%d %d %d", &L, &H, &R) == 3) {
		for (int left = L; left < R; left++) 
			if (H > skyline[left])skyline[left] = H;
		if (right < R)right = R;
	}
	bool space = 0;
	for(int left=1;left<=right;left++)
		if (skyline[left - 1] != skyline[left]) {
			if (space)putchar(' ');
			space = true;
			printf("%d %d", left, skyline[left]);
		}
	puts("");
	return 0;
}



/*
skyline[i]=0 ->i=right(last line in a square)
*/

With the advent of high speed graphics workstations, 
CAD (computer-aided design) and other areas (CAM, VLSI design) 
have made increasingly effective use of computers. 
One of the problems with drawing images is the elimination of 
hidden lines — lines obscured by other parts of a drawing.
You are to design a program to assist an architect in drawing the 
skyline of a city given the locations of the buildings in the city. 
To make the problem tractable, 
all buildings are rectangular in shape and they share a common 
bottom (the city they are built in is very flat). 
The city is also viewed as twodimensional.
A building is specified by an ordered triple (Li;Hi;Ri) where Li 
and Ri are the left and right coordinates, respectively, 
of building i (0 < Li < Ri) and Hi is the height of the building. 
In the diagram below buildings are shown on the left with triples
(1; 11; 5); (2; 6; 7); (3; 13; 9); (12; 7; 16); (14; 3; 25); 
(19; 18; 22); (23; 13; 29); (24; 4; 28)
the skyline, shown on the right, is represented by the sequence:
(1; 11; 3; 13; 9; 0; 12; 7; 16; 3; 19; 18; 22; 3; 23; 13; 29; 0)



Input
The input is a sequence of building triples. All coordinates of 
buildings are integers less than 10,000 and there will be at least 
one and at most 5,000 buildings in the input file. 
Each building triple is on a line by itself in the input file. 
All integers in a triple are separated by one or more spaces. 
The triples will be sorted by Li, the left x-coordinate of the 
building, so the building with the smallest left
x-coordinate is first in the input file.

Output
The output should consist of the vector that describes the skyline 
as shown in the example above.
In the skyline vector (v1; v2; v3; : : : ; vn􀀀2; vn􀀀1; vn), 
the vi such that i is an even number represent a horizontal line 
(height). The vi such that i is an odd number represent a vertical 
line (x-coordinate).
The skyline vector should represent the “path” taken, for example, 
by a bug starting at the minimum x-coordinate and 
traveling horizontally and vertically over all the lines that 
define the skyline. 
Thus the last entry in all skyline vectors will be a ‘0’.



Sample Input
1 11 5
2 6 7
3 13 9
12 7 16
14 3 25
19 18 22
23 13 29
24 4 28

Sample Output
1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0