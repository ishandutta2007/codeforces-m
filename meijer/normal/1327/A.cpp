#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
ll t, n, k;
ll dp[MX];

void program() {
	cin>>t;
	ll mn=0;
	RE(i,MX) {
		dp[i] = mn;
		mn += (i*2)+1;
		if(mn > INF) mn = INF;
	}
	while(t--) {
		bool pos=0;
		cin>>n>>k;
		if((n%2) == (k%2)) pos = 1;
		if(k >= MX) pos=0;
		else if(n < dp[k]) pos = 0;
		cout<<(pos?"YES":"NO")<<endl;
	}
}