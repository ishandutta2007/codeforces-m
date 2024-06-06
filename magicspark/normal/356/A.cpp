#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:16000000")
//#define map gp_hash_table
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
namespace fastio{
	char in[100000];
	int itr=0,llen=0;
	char get(){
		if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
		if(llen==0)return EOF;
		return in[itr++];
	}
	char out[100000];
	int itr2=0;
	void put(char c){
		out[itr2++]=c;
		if(itr2==100000){
			fwrite(out,1,100000,stdout);
			itr2=0;
		}
	}
	int clear(){
		fwrite(out,1,itr2,stdout);
		itr2=0;
		return 0;
	}
	int getint(){
    	int r=0; bool ng=0; char c; c=get();
    	while (c!='-'&&(c<'0'||c>'9')) c=get();
   		if (c=='-') ng=1, c=get();
    	while (c>='0'&&c<='9') r=r*10+c-'0', c=get();
    	return ng?-r:r;
	}
	string getstr(){
		string ret="";
		char ch=get();
		while(ch==' '||ch=='\n')ch=get();
		while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
		return ret;
	}
	void putstr(string s){
		for(int i=0;i<s.size();i++)put(s[i]);
	}
	void putint(int x){
		if(x<0){
			put('-');
			x=-x;
		}
		if(x==0){
			put('0');
			return;
		}
		char c[20];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
	}
	void getarr(int arrname[],int size){
		 for(int i=0;i<size;i++)arrname[i]=getint();
	}
}
using namespace fastio;
#define fastio
const int MAX_N=3e5;
struct BIT{
	int bit[MAX_N+1],BITN;
	//sum a[1,i]
	void init(vector<int> v){
		for(int i=0;i<v.size();i++)add(i+1,v[i]);
	}
	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i=(i)&(i-1);
		}
		return s;
	}
	//a[i]+=x
	void add(int i,int x){
		while(i<=BITN){
			bit[i]+=x;
			i+=(i)&(-i);
		}
	}
}bit;
int n,m;
int ans[MAX_N+1];
int main(){
    cerr<<"sjcakioi!\nsjc is dalao!\n";
	n=getint();m=getint();
	bit.BITN=n;
	for(int i=1;i<=n;i++)bit.add(i,1);
	while(m--){
		int l=getint(),r=getint(),x=getint();
		int lower=bit.sum(l-1);
		int dif=bit.sum(r)-lower;
		while(dif--){
			int ll=l-1,rr=r;
			while(rr-ll>1){
				int mid=ll+rr>>1;
				if(bit.sum(mid)==lower)ll=mid;
				else rr=mid;
			}
			ans[rr]=x;
			bit.add(rr,-1);
		}
		bit.add(x,1);
		ans[x]=0;
	}
	for(int i=1;i<=n;i++)putint(ans[i]),put(' ');
	#ifdef fastio
		clear();
	#endif
	return 0;
}