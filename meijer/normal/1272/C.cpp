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
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 1e6;
int n, k;
string s;
bitset<256> used;

void program() {
	cin>>n>>k>>s;
	used.reset();
	RE(i,k) {
		char c; cin>>c;
		used[c] = 1;
	}
	ll cnt=0;
	ll ans=0;
	RE(i,n) {
		if(used[s[i]]) {
			cnt++;
		} else {
			ans += (cnt*(cnt+1))/2;
			cnt = 0;
		}
	}
	ans += (cnt*(cnt+1))/2;
	cout<<ans<<endl;
}