#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <sstream>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
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
#define MSI std::multiset<int>
#define MSS std::multiset<std::string>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MSIII std::multiset<int>::iterator
#define MSSI std::multiset<std::string>::iterator
#define MAPII std::map<int, int>
#define MAPSS std::map<std::string, std::string>
#define MAPIS std::map<int, std::string>
#define MAPSI std::map<std::string, int>

int n, m;

int main() {
	in >> n >> m;
	int ans = -1;
	for(int i = ceil(1.0 * n / 2); i <= n; i++) {
		if(i % m == 0) {
			ans = i;
			break;
		}
	}
	out << ans;
}