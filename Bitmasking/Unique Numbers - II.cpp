//Wahe Guru ji ka Khalsa Wahe Guru ji ki Fateh
//HARJOT SINGH
//Software Developer and Data Scientist
//Contact me @ harjot3200@gmail.com
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
	int n;
	cin>>n;
	int a[n+1];
	fr(i,0,n) cin>>a[i];
	int k = 0;
	fr(i,0,n) k = k^a[i];
	int d = 1;
	while(true){
		if(d&k) break;
		d= d<<1;
	}
	int r = 0;
	fr(i,0,n) if(d&a[i]) r = r^a[i];
	int q = r;
	fr(i,0,n) r = r^a[i];
	if(r>q){
		int t = r;
		r = q;
		q = r;
	}
	cout<<r<<" "<<q;
}