/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Majk
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
constexpr int MOD = 1000000007;

typedef std::pair<int,int> pii;
typedef long long ll;

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

// #include "../l/mod.h"

class TaskA {
public:
	void solve(istream& cin, ostream& cout) {
		char c, d;
		cin >> c >> d;
		vector<char> R{'+'};
		int plus=1,minus=0;
		while (d != '=') {
			R.push_back(d);
			if (d=='-') ++minus; else ++plus;
			cin >> c >> d;
		}
		int n; cin >> n;
		if (plus * n < minus + n || (minus * n < plus - n)) {
			cout << "Impossible" << endl;
		} else {
			cout << "Possible" << endl;
			int cur = -n;
			for (int i = 0; i < R.size(); ++i) {
				if (i!=0) cout << ' ' << R[i] << ' ';
				cerr << R[i] << ' ' << cur << ' ' << plus << ' ' << minus << ' ' << n << ' ' << i << endl;
				if (i == R.size()-1) {
					cout << abs(cur);
				} else if (R[i]=='+') {
					--plus;
					if (cur + 1 + plus * n < minus) { cout << n; cur += n; }
					else { cout << 1; cur += 1; }
				} else {
					--minus;
					if (cur - 1 - minus * n > -plus) { cout << n; cur -= n; }
					else { cout << 1; cur -= 1; }
				}
			}
			cout << " = " << n << endl;
		}
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}