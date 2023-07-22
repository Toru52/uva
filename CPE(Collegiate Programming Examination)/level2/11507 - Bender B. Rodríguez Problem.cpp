11507 - Bender B. Rodríguez Problem
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/11507%20-%20Bender%20B.%20Rodr%C3%ADguez%20Problem.cpp



#include<stdio.h>
bool change(char cur, char c1, char c2) {
	if (cur == 'x' && c1 == '-') return true;
	if (cur == 'y' && c1 == '+' && c2 == 'y') return true;
	if (cur == 'z' && c1 == '+' && c2 == 'z') return true;
	return false;
}
int main() {
	int L;

	while (scanf("%d", &L),L) {
		int sign = 1;
		char c = 'x',dic[3]{};

		for (int i = 0; i < L-1; ++i) {
			scanf("%s", dic);
			if (dic[0] == 'N')
				continue;
			if (change(c, dic[0], dic[1])) 
				sign = -sign;
			if (c == 'x') c = dic[1];
			else if (c == 'y' && dic[1] == 'y') 
				c = 'x';
			else if (c == 'z' && dic[1] == 'z')
				c = 'x';
		}
		printf("%c%c\n", sign == 1 ? '+' : '-', c);
	}
	return 0;
}



#include<stdio.h>
bool change(char be, char op, char af) {
	if (be == 'x'&&op == '-')return true;
	if (be == 'y'&&af == 'y'&&op == '+')return true;
	if (be == 'z'&&af == 'z'&&op == '+')return true;
	return false;
}
int main() {
	int L;
	while (scanf("%d", &L), L) {
		char c = 'x',dic[5]{};
		int sign = 1;
		for(int i=0;i<L-1;i++){
			scanf("%s", dic);
			if (dic[0] == 'N')
				continue;
			if (change(c, dic[0], dic[1]))
				sign = -sign;
			if ('x' == c)
				c = dic[1];
			else if (c == 'y'&&dic[1] == 'y')
				c = 'x';
			else if (c == 'z'&&dic[1] == 'z')
				c = 'x';
		}
		printf("%c%c\n", (sign == 1) ? '+' : '-', c);
	}
	return 0;
}



/*
concept 

• Not to bend the wire at point (i; 0; 0).
• To bend the wire at point (i; 0; 0) an angle of 
2 to be parallel to the axis +y, -y, +z or -z.


sign invert minus plus condition
be x af -
be y af +y
be z af +z
->denote that wire invert to plus direction



x-x   y-x(y)     z-x(z)
 -y    -y(x,z)    -z(x,y)
 -z 

+y+y
right(standard(x))->top->left(-x)
*/



Bender is a robot built by Mom’s Friendly Robot Company at its 
plant in Tijuana, Mexico in 2996. He is a Bending-Unit 22, 
serial number 2716057 and chassis number 1729. He was created for 
the task of bending metal wires.
Bender needs to bend a wire of length L (L  2 an integer). 
The wire is represented in the Bender’s
brain (a MOS Technology 6502 microprocessor) as a line stucked in 
the origin of a tridimensional cartesian coordinate system, 
and extended along the x positive axis (+x), 
so that the fixed extreme of the wire is in the coordinate 
(0; 0; 0) and the free extreme of the wire is in the coordinate 
(L; 0; 0).
Bender bends the wire at specific points, starting at the point 
(L 􀀀 1; 0; 0) and ending at the point(1; 0; 0). 
For each i from L 􀀀 1 to 1, 
Bender can take one of the following decisions:
• Not to bend the wire at point (i; 0; 0).
• To bend the wire at point (i; 0; 0) an angle of 
2 to be parallel to the axis +y, -y, +z or -z.
For example, if L = 3 and Bender bends the wire at (2; 0; 0) on 
the +y axis direction, and at (1; 0; 0) on the -y axis direction, 
the result would be:
Initial After bend +y at (2; 0; 0) After bend -y at (1; 0; 0)
Given a sequence of bends, you must determine what direction is 
pointed by the last segment of the wire (+x in the example). 
You can suppose that the wire can intercept itself, 
after all it is the future!



Input
The first line of each test case gives an integer L 
(2  L  100000) indicating the length of the wire.
The second line of each test case contains the L 􀀀 1 decisions 
taken by Bender at each point,
separated by spaces. The j-th decision in the list 
(for each 1  j  L 􀀀 1) corresponds to the decision
taken at the point (L 􀀀 j; 0; 0), 
and must be one of the following:
• ‘No’ if the wire isn’t bended at point (L 􀀀 j; 0; 0).
• ‘+y’ if the wire is bended at point (L 􀀀 j; 0; 0) on the +y axis.
• ‘-y’ if the wire is bended at point (L 􀀀 j; 0; 0) on the -y axis.
• ‘+z’ if the wire is bended at point (L 􀀀 j; 0; 0) on the +z axis.
• ‘-z’ if the wire is bended at point (L 􀀀 j; 0; 0) on the -z axis.
The end of the input is indicated when L = 0.

Output
For each case in the input, print one line with the direction 
pointed by the last segment of the wire,
‘+x’, ‘-x’, ‘+y’, ‘-y’, ‘+z’ or ‘-z’ depending on the case.



Sample Input
3
+z -z
3
+z +y
2
+z
4
+z +y +z
5
No +z No No
0

Sample Output
+x
+z
+z
-x
+z


