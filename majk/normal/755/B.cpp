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
#include <set>
#include <functional>
#include <fstream>
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
typedef unsigned int ui;

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

// #include "../l/mod.h"

class TaskB {
public:
	void solve(istream& cin, ostream& cout) {
		int N, M; cin >> N >> M;
		vector<string> P(N), E(M); cin >> P >> E;
		sort(P.begin(), P.end());
		sort(E.begin(), E.end());
		int p=0, e=0, c=0, i=0, j=0;
		while (i<N || j<M) {
			if (i < N && (j == M || P[i] < E[j])) {
				++p; ++i;
			} else if (j < M && (i == N || P[i] > E[j])) {
				++e; ++j;
			} else {
				++i; ++j; ++c;
			}
		}

		p += c/2 + c%2;
		e += c/2;
		cout << (p > e ? "YES" : "NO") << endl;
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}