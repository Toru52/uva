UVa：253－Cube painting



#include<iostream>
#include<string>
using namespace std;

int main(){
  string input;
  string cube[2];
  bool used[3];
  while( getline( cin, input ) ){
    cube[0] = input.substr( 0, 6 );
    cube[1] = input.substr( 6, 6 );

    fill( used, used+3, false ); 
    for( int i = 0 ; i < 3 ; i++ ){
      for( int j = 0 ; j < 3 ; j++ ){
        if( !used[j] && 
            ((cube[1][j] == cube[0][i] && cube[1][5-j] == cube[0][5-i]) ||
              cube[1][5-j] == cube[0][i] && cube[1][j] == cube[0][5-i]) ){
          used[j] = true;
          break;
        }
      }
    }

    if( used[0] && used[1] && used[2] ) printf( "TRUE\n" );
    else printf( "FALSE\n" );
  }
  return 0;
}



#include<iostream>
#include<string>
using namespace std;

int main()
{
	string cube[2], twocube;
	while (getline(cin, twocube))
	{
		
		cube[0] = twocube.substr(0, 6);
		cube[1] = twocube.substr(6, 6);
		bool used[3] = {};

		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if (!used[j] &&
					cube[1][j] == cube[0][i] && cube[1][j] == cube[0][5-i] &&
					cube[1][5-j] == cube[0][5-i] || cube[1][5-j] == cube[0][i]) {
					used[j] = true;
					break;
				}
		if (used[0] && used[1] && used[2])
			puts("TRUE");
		else
			puts("FALSE");
	}
}



We have a machine for painting cubes. It is supplied with three
different colors: blue, red and green. Each face of the cube 
gets one of these colors. The cube’s faces are numbered as in 
Figure 1.
Since a cube has 6 faces, our machine can paint a face-numbered
cube in 3
6 = 729 different ways. When ignoring the face-numbers,
the number of different paintings is much less, because a cube 
can
be rotated. See example below.
We denote a painted cube by a string of 6 characters, where each
character is a ‘b’, ‘r’, or ‘g’. The i-th character (1 ≤ i ≤ 6) 
from the left gives the color of face i. For example, 
Figure 2 is a picture of “rbgggr” and Figure 3 corresponds to 
“rggbgr”. Notice that both cubes are painted in the same way: 
by rotating it around the vertical axis by 90°, 
the one changes into the other. Figure 2 Figure 3



Input
The input of your program is a textfile that ends with the 
standard end-of-file marker. Each line is a string of 
12 characters. The first 6 characters of this string are the 
representation of a painted cube, 
the remaining 6 characters give you the representation of 
another cube. Your program determines whether
these two cubes are painted in the same way, that is, 
whether by any combination of rotations one can
be turned into the other. (Reflections are not allowed.)

Output
The output is a file of boolean. For each line of input, 
output contains ‘TRUE’ if the second half can be
obtained from the first half by rotation as describes above, 
‘FALSE’ otherwise.



Sample Input
rbgggrrggbgr
rrrbbbrrbbbr
rbgrbgrrrrrg

Sample Output
TRUE
FALSE
FALSE




rbgggr
rggbgr

rrrbbb
rrbbbr

rbgrbg
rrrrrg