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

const int MX = 5e5;
int t, a, b, c, n;

void program() {
	cin>>t;
	while(t--) {
		cin>>a>>b>>c>>n;
		int total = a+b+c+n;
		bool pos = 1;
		if(total % 3) pos = 0;
		total /= 3;
		if(a > total) pos = 0;
		if(b > total) pos = 0;
		if(c > total) pos = 0;
		cout<<(pos ? "YES" : "NO")<<endl;
	}
}