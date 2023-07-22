12015 - Google is Feeling Lucky
https://sites.google.com/site/pcshic/solutions/100-1-zi-xun-she-qi-mo-kao-can-kao-jie-da



#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
	int i, mxv, v[10], t, tc = 1;
	string u[10];                           //u(rl)--網址
	cin >> t;
	while (t--) {
		mxv = 0;                            //max v--最大相關度
		for (i = 0; i<10; i++) {
			cin >> u[i] >> v[i];
			mxv = max(mxv, v[i]);          //求v[i] 最大值
		}
		cout << "Case #" << tc++ << ":\n";
		for (i = 0; i<10; i++)
			if (v[i] == mxv)                //若相關度最高
				cout << u[i] << endl;
	}
}



#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n,v[10],cnt=1;
	string url[10];

	cin >> n;
	while (n--) {
		int mxv = 0;
		for (int i = 0; i < 10; i++) {
			cin >> url[i] >> v[i];
			mxv = max(mxv, v[i]);
		}
		printf("Case #%d:\n", cnt++);
		for (int i = 0; i < 10; i++) 
			if (mxv == v[i])
				cout << url[i] << endl;
	}
	return 0;
}


Google is one of the most famous Internet search engines which hosts 
and develops a number of Internet-based services and products. 
On its search engine website, an interesting button 
`I'm feeling lucky' attracts our eyes. 
This feature could allow the user skip the search result page and 
goes directly to the rst ranked page. 
Amazing! It saves a lot of time.
The question is, when one types some keywords and presses 
`I'm feeling lucky' button, which web page will appear? 
Google does a lot and comes up with excellent approaches to deal 
with it. In this simpli ed problem, let us just consider that 
Google assigns every web page an integer-valued relevance.
The most related page will be chosen. If there is a tie, 
all the pages with the highest relevance are possible to be chosen.
Your task is simple, given 10 web pages and their relevance. 
Just pick out all the possible candidates
which will be served to the user when `I'm feeling lucky'.



Input
The input contains multiple test cases. The number of test cases
T
is in the  rst line of the input  le.
For each test case, there are 10 lines, describing the web page and 
the relevance. Each line contains a character string without any 
blank characters denoting the URL of this web page and an integer
V
i
denoting the relevance of this web page. The length of the URL is 
between 1 and 100 inclusively.
(1

V
i

100)
Output
For each test case, output several lines which are the URLs of the 
web pages which are possible to be
chosen. The order of the URLs is the same as the input. 
Please look at the sample output for further
information of output format.



SampleInput
2
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 10
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
www.university.edu.cn 9
acm.university.edu.cn 10
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 11
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
acm.university.edu.cn 9
acm.university.edu.cn 10

SampleOutput
Case #1:
www.alibaba.com
www.bad.com
acm.university.edu.cn
Case #2:
www.alibaba.com