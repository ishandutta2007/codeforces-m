//#include <bits/stdc++.h>
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
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
template<class T>
inline T read(T &x) {
	x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	if(fu)x=-x;
}
inline int read(){
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}
int n,a[100002],tot;
struct s{
	int v,pos;
}qwq[100002];
inline bool cmp(s a,s b){
	return a.v<b.v;
}
int main(){
    cin>>n;
    F(i,1,n)a[i]=read();
    if(n%2==0){
    	F(i,1,n)tot^=a[i];
    	if(tot==0){
    		cout<<"YES"<<endl;
    		cout<<n-2<<endl;
    		for(ri i=1;i<n-2;i+=2){
    			cout<<i<<' '<<i+1<<' '<<i+2<<'\n';
    			cout<<i<<' '<<i+1<<' '<<n<<'\n';
			}
		}else{
			cout<<"NO";
		}return 0;
	}else{
		cout<<"YES"<<endl;cout<<n-1<<endl;
		for(ri i=1;i<=n-2;i+=2){
			cout<<i<<' '<<i+1<<' '<<i+2<<'\n';
		}for(ri i=1;i<=n-2;i+=2){
			cout<<i<<' '<<i+1<<' '<<n<<'\n';
		}return 0;
	}cout<<"NO";
    return 0;
}