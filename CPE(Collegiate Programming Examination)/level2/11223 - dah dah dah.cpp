11223 - O: dah dah dah!
http://mypaper.pchome.com.tw/zerojudge/post/1323086944



#include <iostream>
#include<string>
#include <map>
using namespace std;

int main() {
	map<string, char> r;
	r[".-"] = 'A',   r[".---"] = 'J', r["..."] = 'S',   r[".----"] = '1', r[".-.-.-"] = '.',  r["---..."] = ':',
	r["-..."] = 'B', r["-.-"] = 'K' , r["-"] = 'T',     r["..---"] = '2'; r["--..--"] = ',',  r["-.-.-."] = ';',
	r["-.-."] = 'C', r[".-.."] = 'L', r["..-"] = 'U',   r["...--"] = '3', r["..--.."] = '?',  r["-...-"] = '=',
	r["-.."] = 'D',  r["--"] = 'M',   r["...-"] = 'V',  r["....-"] = '4', r[".----."] = '\'', r[".-.-."] = '+',
	r["."] = 'E',    r["-."] = 'N',   r[".--"] = 'W',   r["....."] = '5', r["-.-.--"] = '!',  r["-....-"] = '-',
	r["..-."] = 'F', r["---"] = 'O',  r["-..-"] = 'X',  r["-...."] = '6', r["-..-."] = '/',   r["..--.-"] = '_',
	r["--."] = 'G',  r[".--."] = 'P', r["-.--"] = 'Y',  r["--..."] = '7', r["-.--."] = '(',   r[".-..-."] = '\"',
	r["...."] = 'H', r["--.-"] = 'Q', r["--.."] = 'Z',  r["---.."] = '8', r["-.--.-"] = ')',  r[".--.-."] = '@',
	r[".."] = 'I',   r[".-."] = 'R',  r["-----"] = '0', r["----."] = '9', r[".-..."] = '&';
	 
	int t, cas = 0;
	string in;
	scanf("%d ", &t);
	while (t--) {
		cout << "Message #" << ++cas << endl;
		getline(cin, in);
		int len = in.length(), flag = 0;
		for (int i = 0; i < len; i++) {
			if (isspace(in[i])) {
				if (flag == 1)
					cout << ' ', flag = false;
				else
					flag = true;
				continue;
			}
			string s = "";
			while (!isspace(in[i]) && i < len) 
				s += in[i],i++;
			cout << r[s];
			flag = false;
			i--;
		}
		cout << endl;
		if (t)
			cout << endl;
	}
	return 0;
}



#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map<string, char>r;
	r[".-"] = 'A', r[".---"] = 'J', r["..."] = 'S', r[".----"] = '1', r[".-.-.-"] = '.', r["---..."] = ':',
	r["-..."] = 'B', r["-.-"] = 'K', r["-"] = 'T', r["..---"] = '2'; r["--..--"] = ',', r["-.-.-."] = ';',
	r["-.-."] = 'C', r[".-.."] = 'L', r["..-"] = 'U', r["...--"] = '3', r["..--.."] = '?', r["-...-"] = '=',
	r["-.."] = 'D', r["--"] = 'M', r["...-"] = 'V', r["....-"] = '4', r[".----."] = '\'', r[".-.-."] = '+',
	r["."] = 'E', r["-."] = 'N', r[".--"] = 'W', r["....."] = '5', r["-.-.--"] = '!', r["-....-"] = '-',
	r["..-."] = 'F', r["---"] = 'O', r["-..-"] = 'X', r["-...."] = '6', r["-..-."] = '/', r["..--.-"] = '_',
	r["--."] = 'G', r[".--."] = 'P', r["-.--"] = 'Y', r["--..."] = '7', r["-.--."] = '(', r[".-..-."] = '\"',
	r["...."] = 'H', r["--.-"] = 'Q', r["--.."] = 'Z', r["---.."] = '8', r["-.--.-"] = ')', r[".--.-."] = '@',
	r[".."] = 'I', r[".-."] = 'R', r["-----"] = '0', r["----."] = '9', r[".-..."] = '&';
	int t,cas=0;
	string str;
	scanf("%d ", &t);
	while(t--){
		printf("Message #%d\n", ++cas);
		bool flag = 0;
		getline(cin, str);
		for (int i = 0; str[i]; i++) {
			if (isspace(str[i])) {
				if (flag)
					cout<<' ', flag = 0;
				else
					flag = 1;
				continue;
			}
			string s = "";
			while (!isspace(str[i]) && i < str.length())
				s += str[i++];
			cout << r[s];
			i--; flag = 0;
		}
		puts("");
		if (t)
			puts("");
	}
	return 0;
}



/*
	r[".-"] = 'A',   r[".---"] = 'J', r["..."] = 'S',   r[".----"] = '1', r[".-.-.-"] = '.',  r["---..."] = ':',
	r["-..."] = 'B', r["-.-"] = 'K' , r["-"] = 'T',     r["..---"] = '2'; r["--..--"] = ',',  r["-.-.-."] = ';',
	r["-.-."] = 'C', r[".-.."] = 'L', r["..-"] = 'U',   r["...--"] = '3', r["..--.."] = '?',  r["-...-"] = '=',
	r["-.."] = 'D',  r["--"] = 'M',   r["...-"] = 'V',  r["....-"] = '4', r[".----."] = '\'', r[".-.-."] = '+',
	r["."] = 'E',    r["-."] = 'N',   r[".--"] = 'W',   r["....."] = '5', r["-.-.--"] = '!',  r["-....-"] = '-',
	r["..-."] = 'F', r["---"] = 'O',  r["-..-"] = 'X',  r["-...."] = '6', r["-..-."] = '/',   r["..--.-"] = '_',
	r["--."] = 'G',  r[".--."] = 'P', r["-.--"] = 'Y',  r["--..."] = '7', r["-.--."] = '(',   r[".-..-."] = '\"',
	r["...."] = 'H', r["--.-"] = 'Q', r["--.."] = 'Z',  r["---.."] = '8', r["-.--.-"] = ')',  r[".--.-."] = '@',
	r[".."] = 'I',   r[".-."] = 'R',  r["-----"] = '0', r["----."] = '9', r[".-..."] = '&';
	*/
/*
careful point
ex
.--- --- -... -.. --- -. . ..--.. ..-. .. -. . -.-.--
JOB DONE ? FINE!
->one space between string , two space between word
*/

Morse code is a method for long-distance transmission of textual information without using the usual
symbols. Instead information is represented with a simpler, binary, alphabet composed of short and
long beeps. The short beep is called dih, and the long beep is called dah. For instance, the code for
the letter O is dah dah dah (three long beeps). Actually, because the codication is not prex-free,
there is also a third symbol, which is silence. The code between two letters is a simple silence, the code
between two words is a double silence.
You have been assigned the job to translate a message in Morse code. The signal has already
been digitalized in the following fashion: dih is represented by a dot (.), dah is represented by a dash
(-). Simple and double silences are represented by a single space character and two space characters
respectively.
The following table represents the Morse code of all the characters that your program need to be
able to handle.
Symbol Code Symbol Code Symbol Code Symbol Code Symbol Code Symbol Code
A .- J .--- S ... 1 .---- . .-.-.- : ---...
B -... K -.- T - 2 ..--- , --..-- ; -.-.-.
C -.-. L .-.. U ..- 3 ...-- ? ..--.. = -...-
D -.. M -- V ...- 4 ....- ' .----. + .-.-.
E . N -. W .-- 5 ..... ! -.-.-- - -....-
F ..-. O --- X -..- 6 -.... / -..-. ..--.-
G --. P .--. Y -.-- 7 --... ( -.{. " .-..-.
H .... Q --.- Z --.. 8 ---.. ) -.--.- @ .--.-.
I .. R .-. 0 ----- 9 ----. & .-...



Input
The rst line of input gives the number of cases, T (1  T  10). T test cases follow. Each one is a
sequence of dot, dash and space characters. Two messages are separated by a newline. The maximum
length of a message is 2000.

Output
The output is comprised of one paragraph for each message. The paragraph corresponding to the n-th
message starts with the header `Message #n', on a line on its own. Each decoded sentence of the
message appears then successively on a line of its own. Two paragraphs are separated by a blank line.
The sentences shall be printed in uppercase.



Sample Input
2
... --- ...
.--- --- -... -.. --- -. . ..--.. ..-. .. -. . -.-.--

Sample Output
Message #1
SOS
Message #2
JOB DONE ? FINE!