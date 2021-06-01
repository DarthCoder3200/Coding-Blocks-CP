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
map<int,list<int>> m;int n;
int val[1000004];
int bit[1000004];
int a[1000005];

int query(int i){
	int sum = 0;
	while(i>0){
		sum = max(sum,bit[i]);
		i -= (i&-i);
	}
	return sum;
}
int ans = 0;
void update(int i,int v){
	int j = query(i-1);
	ans = max(ans,v+j);
	//cout<<v<<" "<<j<<endl;
	while(i<=n){
		bit[i] = max(bit[i],v+j);
		i += (i&-i);
	}
}

int32_t main(){
	fast();
	test{
		memset(bit,0,sizeof bit);
		ans = 0;
		cin>>n;
	//	int a[n+34];
		int l;
		fr(i,0,n){
			cin>>l;
			m[l].pb(i);
		}
		int j = 1;
		for(auto i:m){
			for(auto k:i.second){
				a[k] = j;
			}
			j++;
		}
		fr(i,0,n) cin>>val[i];
		fr(i,0,n) update(a[i],val[i]);
		cout<<ans<<endl;

		m.clear();
	}
}