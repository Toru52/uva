//check lcm
int gcd(int a, int b){return b == 0 ? a : gcd(b, a%b);}
int lcm(int a, int b){return a*(b / gcd(a, b));}
bool check(int a, int b, int n){return lcm(a, b) == n ? 1 : 0;}