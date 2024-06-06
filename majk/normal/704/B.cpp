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

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

// #include "../l/mod.h"

ll dp[5000][5000];

class TaskB {
public:
	void solve(istream& cin, ostream& cout) {
		int N, S, E; cin >> N >> S >> E;
		vector<int> X(N), A(N), B(N), C(N), D(N);
		cin >> X >> A >> B >> C >> D;
		--S; --E;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dp[i][j] = 1e17;
			}
		}
		if (S == 0) {
			dp[0][0] = D[0] + X[1] - X[0];
		} else if (E == 0) {
			dp[0][0] = B[0] + X[1] - X[0];
		} else {
			dp[0][1] = B[0] + D[0] + 2*(X[1] - X[0]);
		}

		for (int i = 1; i < N-1; ++i) {
			for (int j = 0; j < N; ++j) {
				int ein = j + (E <= i);
				int eout = j + (S <= i);
				if (i == S) {
					if (j < N-1)
						dp[i][j] = min(dp[i][j], dp[i-1][j+1] + C[i]); // out small
					if (ein)
						dp[i][j] = min(dp[i][j], dp[i-1][j] + D[i]); // out large
				} else if (i == E) {
					if (eout)
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + B[i]); // in small
					if (j < N-1)
						dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + A[i]); // in large
				} else {
					if (j > 0)
						dp[i][j] = min(dp[i][j], dp[i - 1][j-1] + B[i] + D[i]); // in small, out large
					if (eout)
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i] + D[i]); // in large, out large
					if (ein)
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + B[i] + C[i]); // in small, out small
					if (j < N-1 && (j > 0 || S < i || E < i))
						dp[i][j] = min(dp[i][j], dp[i - 1][j+1] + A[i] + C[i]); // in large, out small
				}

				dp[i][j] += (ll)(ein + eout) * (X[i+1] - X[i]);
			}
		}

		ll ans = dp[N-2][0];
		ans += (S == N-1 ? 0 : A[N-1]) + (E == N-1 ? 0 : C[N-1]);
		cout << ans << endl;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}