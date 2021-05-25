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
int n,q;
int a[100004];
int tree[400010];

void buildTree(int i,int s,int e){
	if(s==e){ 
		tree[i] = a[s];
		return;
	}
	int m = (s+e)/2;
	buildTree(2*i,s,m);
	buildTree(2*i+1,m+1,e);
	tree[i] = min(tree[2*i+1],tree[2*i]);
	return;
}
int query(int i,int qs,int qe,int ss,int se){
	if(ss == se && (ss>=qs && se<=qe)) return tree[i];
	if((qe<ss)|| (qs>se)) return 100000000000000;
	if((qs<=ss) && (qe>=se)) return tree[i];
	return min(query(2*i,qs,qe,ss,(ss+se)/2),query(2*i+1,qs,qe,(ss+se)/2+1,se));
}

void update(int i,int up,int q,int ss,int se){
	if(ss==se){
		if(ss==q) tree[i] = up;
		return;
	}
	if((q<ss)|| (q>se)) return;
	update(2*i,up,q,ss,(ss+se)/2);
	update(2*i+1,up,q,(ss+se)/2+1,se);
	tree[i] = min(tree[2*i],tree[2*i+1]);
	return; 
}

int32_t main(){
	fast();
	cin>>n>>q;
	fr(i,0,n) cin>>a[i];
	buildTree(1,0,n-1);
	//cout<<query(1,1,n-1,0,n-1)<<endl;
	fr(i,0,q){
		int p,d,c;
		cin>>p>>d>>c;
		if(p==1) cout<<query(1,d-1,c-1,0,n-1)<<endl;
		else update(1,c,d-1,0,n-1);
	}
}