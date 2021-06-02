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
#define f first
#define s second
void fast(){ 
ios_base::sync_with_stdio(false); cin.tie(NULL); 
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

bool myc(pii a,pii b){
	if(a.s==b.s) return a.f<b.f;
	return a.s<b.s;
}

int32_t main(){
	fast();
	
		int n;
		cin>>n;
		pii v[n+1];
		fr(i,0,n){
			int a,b;
			cin>>a>>b;
			v[i].f = a-b;
			v[i].s = a+b;
		}
		sort(v,v+n,myc);
		int ans = 1;
		int prevE = v[0].s;
		fr(i,1,n){
			if(prevE <= v[i].f){
				ans++;
				prevE = v[i].s;
			}
		}
		cout<<n-ans<<endl;
	
}