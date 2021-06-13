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


int32_t main(){
	fast();
	test{
		map<int,list<pii>> m;
		int n,mj;
		cin>>n>>mj;
		fr(i,0,mj){
			int a,b,c;
			cin>>a>>b>>c;
			m[a].pb(mp(b,c));
			m[b].pb(mp(a,c));
		}
		set<pii> st;
		int d;cin>>d;
		st.insert(mp(0,d));
		map<int,int> dist;
		fr(i,1,n+1) dist[i] = -1;
		dist[d] = 0;
		while(!st.empty()){
			pii a = *(st.begin());
			int ds = a.f;
			int node = a.s;
			st.erase(st.begin());
			for(auto x:m[node]){
				//cout<<x.f<<" : : ";
				if(dist[x.f] == -1){
					dist[x.f] = ds + x.s;
					st.insert(mp(dist[x.f],x.f)); 
				}
				else if(ds + x.s < dist[x.f]){
					st.erase(mp(dist[x.f],x.f));
					dist[x.f] = ds + x.s;
					st.insert(mp(dist[x.f],x.f));
				}
			}
		}
		for(auto x:dist) if(x.second) cout<<x.second<<" ";
		cout<<endl;
	}
}