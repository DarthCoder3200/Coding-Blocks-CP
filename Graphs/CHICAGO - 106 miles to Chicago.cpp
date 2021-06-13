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
class Graph{
	map<int,list<pair<int,double>>> m;
public:
	void addEdge(int a,int b,double w){
		m[a].pb(mp(b,w));
		m[b].pb(mp(a,w));
	}
	void dijsktraSSSP(int src,int l) {
		map<int, double> dist;

		for (auto i : m) dist[i.first] = 0;
		set<pair<double , int>> s;
		dist[src] = 100;
		s.insert(make_pair(100, src));
		while (!s.empty()) {
			auto p = *(s.begin());
			int node = p.second;
			double nodeDist = p.first;
			//cout<<nodeDist<<endl;
			s.erase(s.begin());
			for (auto i : m[node]) {
				if (((nodeDist * i.second)/100 > dist[i.first])) {
					int dest = i.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end()) s.erase(f);
					dist[dest] = (nodeDist * i.second)/100;
					s.insert(make_pair(dist[dest], dest));
				}
			}
		}
		cout<<fixed<<setprecision(6)<<dist[l]<<" percent"<<endl;
	}
};

int32_t main(){
	fast();
	int a;int b;
	while(true){
		cin>>a;
		if(a==0) break;
		cin>>b;
		Graph g;
		int x,y;
		double w;
		fr(0,b){
			cin>>x>>y>>w;
			g.addEdge(x,y,w);
		}
		g.dijsktraSSSP(1,a);
	}
}