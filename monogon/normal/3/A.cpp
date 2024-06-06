#include <bits/stdc++.h>

#define in std::cin
#define out std::cout
#define endl std::endl
#define Max(a, b) (b > a ? b:a)
#define Max3(a, b, c) Max(a, Max(b, c))
#define Min(a, b) (b < a ? b:a)
#define Min3(a, b, c) Min(a, Min(b, c))
#define MaxE(a, b) a = Max(a, b)
#define MinE(a, b) a = Min(a, b)
#define Getbit(a, n) ((a >> n) & 1)
#define Bitcount(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
#define VPII std::vector<std::pair<int, int> >
#define VPSI std::vector<std::pair<std::string, int> >
#define VPIS std::vector<std::pair<int, std:;string> >
#define VPSS std::vector<std::pair<std::string, std::string> >
#define Mp(a, b) std::make_pair(a, b)
#define PII std::pair<int, int>
#define PSI std::pair<std::string, int>
#define PIS std::pair<int, std::string>
#define PSS std::pair<std::string, std::string>
#define SI std::set<int>
#define SS std::set<std::string>
#define SPII std::set<std::pair<int, int> >
#define SPSI std::set<std::pair<std::string, int> >
#define SPIS std::set<std::pair<int, std::string> >
#define SPSS std::set<std::pair<std::string, std::string> >
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define VPIII std::vector<std::pair<int, int> >::iterator
#define VPISI std::vector<std::pair<int, std::string> >::iterator
#define VPSII std::vector<std::pair<std::string, int> >::iterator
#define VPSSI std::vector<std::pair<std::string, std::string> >::iterator
#define MsI std::multiset<int>
#define MsS std::multiset<std::string>
#define MsPII std::multiset<std::pair<int, int> >
#define MsPSI std::multiset<std::pair<std::string, int> >
#define MsPIS std::multiset<std::pair<int, std::string> >
#define MsPSS std::multiset<std::pair<std::string, std::string> >
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MsII std::multiset<int>::iterator
#define MsSI std::multiset<std::string>::iterator
#define MsPIII std::multiset<std::pair<int, int> >::iterator
#define MsPSII std::multiset<std::pair<std::string, int> >::iterator
#define MsPISI std::multiset<std::pair<int, std::string> >::iterator
#define MsPSSI std::multiset<std::pair<std::string, std::string> >::iterator
#define MapII std::map<int, int>
#define MapSS std::map<std::string, std::string>
#define MapIS std::map<int, std::string>
#define MapSI std::map<std::string, int>

S s1, s2;
int x, y, x2, y2;

int main() {
	in >> s1 >> s2;
	x = s1[0] - 'a';
	y = s1[1] - '1';
	x2 = s2[0] - 'a';
	y2 = s2[1] - '1';
	out << Max(abs(x2 - x), abs(y2 - y)) << endl;
	while(x < x2 && y < y2) {out << "RU\n"; x++; y++;}
	while(x > x2 && y < y2) {out << "LU\n"; x--; y++;}
	while(x < x2 && y > y2) {out << "RD\n"; x++; y--;}
	while(x > x2 && y > y2) {out << "LD\n"; x--; y--;}
	while(x < x2) {out << "R\n"; x++;}
	while(x > x2) {out << "L\n"; x--;}
	while(y < y2) {out << "U\n"; y++;}
	while(y > y2) {out << "D\n"; y--;}
}