#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(a,b) for(int i=a;i<b;i++)
#define frn(a,b) for(int i=a;i>=b;i--)
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
	int n;
	cin>>n;
	int a[2*n+1];
	for(int i=0;i<2*n;i++) cin>>a[i];
	sort(a,a+2*n);
	cout<<a[n-1];
}