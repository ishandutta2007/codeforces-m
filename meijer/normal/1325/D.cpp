#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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

const int MX = 5e5;
ll u, v;

void program() {
	cin>>u>>v;
	if(u > v || ((v - u)%2 == 1)) {
		cout<<-1<<endl;
		return;
	}
	if(v == 0) {
		cout<<0<<endl;
		return;
	}
	if(u == v) {
		cout<<1<<endl;
		cout<<u<<endl;
		return;
	}
	ll div = v-u;
	div /= 2;
	if((div&u) == 0) {
		cout<<2<<endl;
		cout<<(u|div)<<" "<<div<<endl;
		return;
	}
	cout<<3<<endl;
	cout<<u<<" "<<div<<" "<<div<<endl;
}