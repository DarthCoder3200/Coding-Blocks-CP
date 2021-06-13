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

class dsu{
	vi v;
public:
	void init(int n){
		v.resize(n+1);
		fr(i,0,n+1) v[i] = i;
	}
	int Parent(int i){
		if(i==v[i]) return i;
		return v[i] = Parent(v[i]);
	}
	void uni(int x,int y){
		int Px = Parent(x);
		int Py = Parent(y);

		v[Px] = Py; 
	}
};
bool myc(pair<pii,int> a, pair<pii,int> b){
	return a.s<b.s;
}
int32_t main(){
	fast();
	int n,m;
	cin>>n>>m;
	dsu g;
	g.init(n);
	pair<pii,int> ed[m+1];
	fr(i,0,m)cin>>ed[i].f.f>>ed[i].f.s>>ed[i].s;
	sort(ed,ed+m,myc);
	int ans = 0;
	fr(i,0,m){
		int x = ed[i].f.f;
		int y = ed[i].f.s;
		int w = ed[i].s;
		if(g.Parent(x) != g.Parent(y)){
			ans+= w;
			g.uni(x,y);
		}
	}
	cout<<ans;
}