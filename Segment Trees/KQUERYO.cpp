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

vi tree[400010];
int a[200000];
void buildTree(int i,int s,int e){
	if(s==e){ 
		tree[i].pb(a[s]);
		return;
	}
	int m = (s+e)/2;
	buildTree(2*i,s,m);
	buildTree(2*i+1,m+1,e);
	for(auto x:tree[2*i+1]) tree[i].pb(x);
	for(auto x:tree[2*i]) tree[i].pb(x);
	sort(tree[i].begin(),tree[i].end());
	return;
}
int query(int i,int k,int qs,int qe,int ss,int se){
//	if(ss == se && (ss>=qs && se<=qe)) return tree[i][0]>=k;
	if((qe<ss)|| (qs>se)) return 0;
	if((qs<=ss) && (qe>=se)) return (tree[i].size() - ( lower_bound(tree[i].begin(),tree[i].end(),k+1) - tree[i].begin()));
	return query(2*i,k,qs,qe,ss,(ss+se)/2)+query(2*i+1,k,qs,qe,(ss+se)/2+1,se);
}

int32_t main(){
	fast();
	int n;
	cin>>n;
	fr(i,0,n) cin>>a[i];
	int q;
	cin>>q;
	buildTree(1,0,n-1);
	int last = 0;
	fr(i,0,q){
		int l,r,k;
		cin>>l>>r>>k;
		l = l^last;
		r = r^last;
		k = k^last;
		l = max(l,1LL);
		r = min(n,r);
		if(l>r) last = 0;
		else last = query(1,k,l-1,r-1,0,n-1);
		cout<<last<<endl;
	}
}