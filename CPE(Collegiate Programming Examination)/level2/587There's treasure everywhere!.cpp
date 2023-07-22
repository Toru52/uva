587	There's treasure everywhere!



#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	char str[201];
	int total = 0, first = 0;
	//get_s
	while (gets(str) && strcmp(str, "END")) {
		double  x = 0, y = 0;
		for (int i = 0; str[i];) {
			if (str[i] >= 47 && str[i] <= 57) {
				char temp[15] = { '\0' };
				int top = 0;
				while (str[i] >= 47 && str[i] <= 57)
					temp[top++] = str[i++];
				int distance = atoi(temp);
				char direction[3] = { '\0' };
				top = 0;
				while (str[i] != ',' && str[i] != '.')
					direction[top++] = str[i++];
				if (!strcmp(direction, "N"))       
					y += distance;
				else if (!strcmp(direction, "NE"))  
					x += sqrt((distance*distance) / 2.0), y += sqrt((distance*distance) / 2.0);
				else if (!strcmp(direction, "NW")) 
					x -= sqrt((distance*distance) / 2.0), y += sqrt((distance*distance) / 2.0);
				else if (!strcmp(direction, "E"))  
					x += distance;
				else if (!strcmp(direction, "W")) 
					x -= distance;
				else if (!strcmp(direction, "S"))  
					y -= distance;
				else if (!strcmp(direction, "SE")) 
					x += sqrt((distance*distance) / 2.0), y -= sqrt((distance*distance) / 2.0);
				else if (!strcmp(direction, "SW"))
					x -= sqrt((distance*distance) / 2.0), y -= sqrt((distance*distance) / 2.0);
			}
			else   
				i++;
		}
		printf("Map #%d\n", ++total);
		printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
		printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x + y*y));
	}
	return 0;
}



#include <iostream>
#include <cmath>
#include <cstring>


int main() {
	int cas = 1;
	char str[201];
	//visual studio ->get_s
	while (gets(str)) {
		if (!strcmp(str, "END"))
			break;
		double x = 0, y = 0;
		for (int i = 0; str[i];) {
			if (47 <= str[i] && str[i] <= 57) {
				int top = 0;
				char temp[15] = {}, dir[3] = {};
				while (47 <= str[i] && str[i] <= 57)
					temp[top++] = str[i++];
				int dis = atoi(temp);
				top = 0;
				while (str[i] != '.' && str[i] != ',')
					dir[top++] = str[i++];
				if (!strcmp(dir, "N"))
					y += dis;
				else if (!strcmp(dir, "E"))
					x += dis;
				else if (!strcmp(dir, "S"))
					y -= dis;
				else if (!strcmp(dir, "W"))
					x -= dis;
				else if (!strcmp(dir, "NE"))
					x += sqrt(dis*dis / 2.0), y += sqrt(dis*dis / 2.0);
				else if (!strcmp(dir, "SE"))
					x += sqrt(dis*dis / 2.0), y -= sqrt(dis*dis / 2.0);
				else if (!strcmp(dir, "NW"))
					x -= sqrt(dis*dis / 2.0), y += sqrt(dis*dis / 2.0);
				else if (!strcmp(dir, "SW"))
					x -= sqrt(dis*dis / 2.0), y -= sqrt(dis*dis / 2.0);
			}
			else
				i++;
		}
		printf("Map #%d\n", cas++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
		printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x+ y*y));
	}
}


Finding buried treasures is simple: all you need is a map! 
The pirates in the Caribbean were famous for their enormous 
buried treasures and their elaborate maps. The maps usually 
read like “Start at the lone palm tree. Take three steps 
towards the forest, then seventeen step towards the small 
spring, . . . blahblah . . . , finally six steps toward the 
giant rock. Dig right here, and you will find my treasure!”
Most of these directions just boil down to taking the 
mentioned number of steps in one of the eight principal 
compass directions (depicted in the left of the figure).
Obviously, following the paths given by these maps may lead to
an interesting tour of the local scenery, but if one is in 
a hurry, there is usually a much faster way: just march 
directly from your starting point to the place where the 
treasure is buried. Instead of taking three steps north, 
one step east, one step north, three steps east, two steps 
south and one step west (see figure), following the
direct route (dashed line in figure) will result in a path of 
about 3.6 steps. You are to write a program that computes the 
location of and distance to a buried treasure, given a 
‘traditional’ map.



Input
The input file contains several strings, each one on a line 
by itself, and each one consisting of at most 200 characters. 
The last string will be ‘END’, signaling the end of the input.
All other strings describe one treasure map each, according 
to the following format:
The description is a comma-separated list of pairs of lengths
(positive integers less than 1000) and directions 
(‘N’ (north), ‘NE’ (northeast), ‘E’ (east), ‘SE’ (southeast), 
‘S’ (south), ‘SW’ (southwest), ‘W’ (west) or ‘NW’ (northwest)).
For example, ‘3W’ means 3 steps to the west, and ‘17NE’ means 
17 steps to the northeast. A full stop (.) 
terminates the description, which contains no blanks.

Output
For every map description in the input, first print the 
number of the map, as shown in the sample
output. Then print the absolute coordinates of the treasure, 
in the format ‘The treasure is located at (x,y).’. 
The coordinate system is oriented such that the x-axis points 
east, and the y-axis points north. 
The path always starts at the origin (0, 0).
On the next line print the distance to that position from the 
point (0, 0), in the format ‘The distance to the treasure is d.
’. The fractional values x, y, d must be printed exact to 
three digits to the right of the decimal point. 
Print a blank line after each test case.



Sample Input
3N,1E,1N,3E,2S,1W.
10NW.
END

Sample Output
Map #1
The treasure is located at (3.000,2.000).
The distance to the treasure is 3.606.
Map #2
The treasure is located at (-7.071,7.071).
The distance to the treasure is 10.000.

