#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define test int t;cin>>t; while(t--)
#define mp make_pair
#define pb push_back
#define pu push
void fast(){ 
ios_base::sync_with_stdio(false); cin.tie(NULL); 
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

int32_t main(){
	fast();
	string a,b;
	getline (cin, a);
	getline (cin, b);
	int n,m;
	n = a.length();
	m = b.length();
	int c[n+1][257];
	memset(c,0,sizeof c);
	c[0][a[0]]++;
	fr(k,1,n) {
		c[k][a[k]]++;
		fr(p,0,256) c[k][p] += c[k-1][p];
	}
	int d[257];
	memset(d,0,sizeof d);
	
	fr(k,0,m){
		
		d[b[k]]++;
	}
	int lol = 0;
	fr(k,0,256) if(d[k] > c[n-1][k]){
		cout<<"No String";
		return 0;
	}
	int ans = n;
	int ia = 0;
	int ib = n-1;
	fr(i,0,n){
		int f = i+1;
		int e = n;
		int r = 0;
		if(i!=0){
			fr(k,0,256) if(d[k] > c[n-1][k]-c[i-1][k]){
				r = 1;
				break;	
			}
			if(!r)
				while(f<=e){
					int m = (f+e)/2;
					fr(k,0,256)
						if(d[k] > c[m-1][k]-c[i-1][k] ){
							r = 1;
							break;
						}
					if(r){r = 0; f = m+1;}
					else {
						e = m-1;
						if(m-i+1 <ans) {
							ia = i;
							ib = m;
							ans = m - i + 1;
						}
					}
				}
			}
			else{
				while(f<=e){
					int m = (f+e)/2;
					fr(k,0,256)
						if(d[k] > c[m-1][k]){
							r = 1;
							break;
						}
					if(r) {r = 0; f = m+1;}
					else {
						e = m-1;
						if(m-i+1 <ans) {
							ia = i;
							ib = m;
							ans = m - i + 1;
						}
					}
				}
		}
	}
	fr(i,ia,ib) cout<<a[i];

	return 0;
}