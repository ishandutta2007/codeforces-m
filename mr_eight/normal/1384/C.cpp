//#include <bits/c++config.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
using namespace __gnu_pbds;
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10+ch-48),ch=getchar();
	return fu?-x:x;
}
int T,n,mmin,ans;
string a,b;
bool check(){
	F(i,0,n-1){
    		if(a[i]>b[i]){
    			return 1;
			}
		}return 0;
}
int main(){
    cin>>T;
    while(T--){ans=0;
    	cin>>n;
    	cin>>a>>b;
    	if(check()){
    		cout<<-1<<endl;
    		continue;
		}for(re char c='a';c<='t';c++){
			mmin=1000000000;
			F(i,0,n-1){
				if(a[i]==c){
					if(b[i]==c)continue;
					else mmin=min(mmin,int(b[i]));
				}
			}if(mmin<100000000){
				
			
			F(i,0,n-1){
				if(a[i]==c){
					if(b[i]==c)continue;
					else a[i]=mmin;
				}
			}ans++;}
		}cout<<ans<<endl;
	}
    return 0;
}