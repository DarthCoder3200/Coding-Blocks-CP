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

class box{
public:
	int f,s,f2,s2;
	box(int a,int b,int c,int d){
		f = a; s = b; f2 = c; s2 = d;
	}
	box(){
		f = s = f2 = s2 = 0; 
	}
};

box id(1,0,0,1);

box tree[400045];
box a[200004];
int n,q,r;

box multi(box A,box B){
	box C;
	C.f = ((A.f*B.f)%r + (A.s*B.f2)%r)%r;
	C.s = ((A.f*B.s)%r + (A.s*B.s2)%r)%r;
	C.f2 = ((A.f2*B.f)%r + (A.s2*B.f2)%r)%r;
	C.s2 = ((A.f2*B.s)%r + (A.s2*B.s2)%r)%r;
	return C;
}

void buildTree(int i,int ss,int se){
	if(ss==se){
		tree[i].f = a[ss].f;
		tree[i].s = a[ss].s;
		tree[i].f2 = a[ss].f2;
		tree[i].s2 = a[ss].s2;
		return;
	}
	int m = (ss+se)/2;
	buildTree(2*i,ss,m);
	buildTree(2*i+1,m+1,se);
	tree[i] = multi(tree[2*i],tree[2*i+1]);
	return;
}
box query(int i,int qs,int qe,int ss,int se){
	if(ss>qe || se<qs) return id;
	if((ss>=qs) && (se<=qe)) return tree[i];
	return multi(query(2*i,qs,qe,ss,(ss+se)/2), query(2*i+1,qs,qe,(ss+se)/2+1,se));
}

int32_t main(){
	fast();
	cin>>r>>n>>q;
	fr(i,0,n) cin>>a[i].f>>a[i].s>>a[i].f2>>a[i].s2;
	buildTree(1,0,n-1);
	fr(i,0,q){
		int o,p;
		cin>>o>>p;
		box ans = query(1,o-1,p-1,0,n-1);
		cout<<ans.f<<" "<<ans.s<<endl<<ans.f2<<" "<<ans.s2<<endl<<endl;
	}
}