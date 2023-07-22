47.118 - Mutant Flatworld Explorers 



no1.
using namespace std;

int main() {
	pair<int, int> dis[5];
	char dir_print[5] = { 'N', 'E', 'S', 'W' };
	int uprightx, uprighty;
	char dc;
	int x, y, d;
	string action;
	bool lost, scent[55][55] = { 0 };

	dis[0].first = 0, dis[0].second = 1;
	dis[1].first = 1, dis[1].second = 0;
	dis[2].first = 0, dis[2].second = -1;
	dis[3].first = -1, dis[3].second = 0;

	scanf("%d%d", &uprightx, &uprighty);
	while (scanf("%d %d %c", &x, &y, &dc) != EOF) {
		lost = false;
		switch (dc) {
		case 'N': d = 0; break;
		case 'E': d = 1; break;
		case 'S': d = 2; break;
		case 'W': d = 3; break;
		}
		getchar();
		getline(cin, action);
		for (int i = 0; i < action.length() && !lost; i++) {
			if (action[i] == 'L') 
				d = (d - 1 + 4) % 4;
			else if (action[i] == 'R') 
				d = (d + 1) % 4;
			else if (action[i] == 'F') {
				x += dis[d].first;
				y += dis[d].second;
				if (x > uprightx || x < 0 || y > uprighty || y < 0) {
					x -= dis[d].first;
					y -= dis[d].second;
					if (!scent[x][y]) {
						lost = true;
						scent[x][y] = true;
					}
				}
			}
		}

		printf("%d %d %c", x, y, dir_print[d]);
		if (lost) printf(" LOST");
		printf("\n");
	}
	return 0;
}



no2.
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int x, y, urx, lly,d;
	char inid;
	bool scent[55][55] = { false };
	string act;
	char dir[5] = { 'N','E','S','W' };
	pair<int, int>mov[5];
	mov[0].first = 0, mov[0].second = 1;
	mov[1].first = 1, mov[1].second = 0;
	mov[2].first = 0, mov[2].second = -1;
	mov[3].first = -1, mov[3].second = 0;

	scanf("%d %d", &urx, &lly);
	while (~scanf("%d %d %c", &x, &y, &inid))
	{
		bool lost = false;
		switch (inid)
		{
		case'N':d = 0; break;
		case'E':d = 1; break;
		case'S':d = 2; break;
		case'W':d = 3; break;
		}
		getchar();
		getline(cin, act);
		for (int i = 0; act[i] && !lost; i++)
		{
			if (act[i] == 'R')
				d = (d + 1) % 4;
			else if (act[i] == 'L')
				d = (d - 1 + 4) % 4;
			else if (act[i] == 'F')
			{
				x += mov[d].first;
				y += mov[d].second;
				if (x<0 || x>urx || y<0 || y>lly)
				{
					x -= mov[d].first;
				    y -= mov[d].second;
					if (!scent[x][y])
					{
						lost = true;
						scent[x][y] = true;
					}
				}
			}
		}
		printf("%d %d %c", x, y, dir[d]);
		if (lost)
			printf(" LOST");
		puts("");
	}
}



Background

Robotics, robot motion planning, and machine learning are areas 
that cross the boundaries of many of the subdisciplines that 
comprise Computer Science: artificial intelligence, algorithms 
and complexity, electrical and mechanical engineering to name a 
few. In addition, robots as ``turtles'' (inspired by work by 
Papert, Abelson, and diSessa) and as ``beeper-pickers'' 
(inspired by work by Pattis) have been studied and used by 
students as an introduction to programming for many years.
This problem involves determining the position of a robot 
exploring a pre-Columbian flat world.

The Problem
Given the dimensions of a rectangular grid and a sequence of 
robot positions and instructions, you are to write a program 
that determines for each sequence of robot positions and 
instructions the final position of the robot.
A robot position consists of a grid coordinate 
(a pair of integers: x-coordinate followed by y-coordinate) 
and an orientation (N,S,E,W for north, south, east, and west). 
A robot instruction is a string of the letters 
'L', 'R', and 'F' which represent, respectively, the 

instructions:
Left: the robot turns left 90 degrees and remains on the 
current grid point.

Right: the robot turns right 90 degrees and remains on the 
current grid point.

Forward: the robot moves forward one grid point in the 
direction of the current orientation and mantains the same 
orientation.

The direction North corresponds to the direction from grid 
point (x,y) to grid point (x,y+1).
Since the grid is rectangular and bounded, 
a robot that moves ``off'' an edge of the grid is lost forever. 
However, lost robots leave a robot ``scent'' that prohibits 
future robots from dropping off the world at the same grid point. 
The scent is left at the last grid position the robot occupied 
before disappearing over the edge. An instruction to move 
``off'' the world from a grid point from which a robot has 
been previously lost is simply ignored by the current robot.



The Input
The first line of input is the upper-right coordinates of the 
rectangular world, the lower-left coordinates are assumed to be 
0,0. The remaining input consists of a sequence of robot 
positions and instructions (two lines per robot). A position 
consists of two integers specifying the initial coordinates of 
the robot and an orientation (N,S,E,W), all separated by white 
space on one line. A robot instruction is a string of the 
letters 'L', 'R', and 'F' on one line.
Each robot is processed sequentially, i.e., finishes executing 
the robot instructions before the next robot begins execution.
Input is terminated by end-of-file.
You may assume that all initial robot positions are within the 
bounds of the specified grid. The maximum value for any 
coordinate is 50. All instruction strings will be less than 100 
characters in length.

The Output
For each robot position/instruction in the input, the output
should indicate the final grid position and orientation of the 
robot. If a robot falls off the edge of the grid the word 
``LOST'' should be printed after the position and orientation.



Sample Input
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL

Sample Output

1 1 E
3 3 N LOST
2 3 S