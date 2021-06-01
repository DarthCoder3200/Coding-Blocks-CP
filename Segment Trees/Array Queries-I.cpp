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
int n,k,q;
int tree[400020];
int a[100045];
int b[100045];
int lazy[400020] = {0};
void lazyup(int i,int ss,int se){
	if(lazy[i]){
		tree[i] += (se-ss+1)*lazy[i];
		if(ss!=se){
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
}
void buildTree(int i,int ss,int se){
	if(ss == se){
		tree[i] = b[ss]; return;
	}
	int m = (ss+se)/2;
	buildTree(2*i,ss,m);
	buildTree(2*i+1,m+1,se);
	tree[i] = tree[2*i] + tree[2*i+1];
	return;
}

int query(int i,int qs,int qe,int ss,int se){
	lazyup(i,ss,se);
	if((qs>se) || (qe<ss)) return 0;
	if(( (qs<=ss)&&(qe>=se))) return tree[i];
	int m = (ss+se)/2;
	int left = query(2*i,qs,qe,ss,m);
	int right = query(2*i+1,qs,qe,m+1,se);
	//cout<<i<<" "<<left<<" "<<right<<endl;
	return left + right; 
}

void update(int i,int up,int qs,int qe,int ss,int se){
	lazyup(i,ss,se);
	if(qs>se || qe<ss) return;
	if(( (qs<=ss)&&(qe>=se))){
		tree[i] += (se-ss+1)*up;
		if(ss!=se){
			lazy[2*i] += up;
			lazy[2*i+1] += up;
		}
		return;
	}
	int m = (ss+se)/2;
	update(2*i,up,qs,qe,ss,m);
	update(2*i+1,up,qs,qe,m+1,se);
	tree[i] = tree[2*i+1] + tree[2*i];
}

int32_t main(){
	fast();
	cin>>n>>k>>q;
	fr(i,0,n) cin>>a[i];
	int s = 0;
	fr(i,n-k+1,n) s+= a[i];
	s+= a[0];
	b[0] = s;

	//cout<<b[0]<<" ";
	int g = n-k+1;
	fr(i,1,n){
		s -= a[g];
		g++;
		g = g%n;
		s += a[i];
		b[i] = s;
	//	cout<<b[i]<<" ";
	}
	buildTree(1,0,n-1);
	//cout<<endl<<tree[7]<<endl;
	fr(i,0,q){
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1){
			int up = z - a[y-1];
			a[y-1] = z;
			if(y+k-2<=n-1) update(1,up,y-1,y+k-2,0,n-1);
			else{
				update(1,up,y-1,n-1,0,n-1);
				update(1,up,0,k-n+y-2,0,n-1);
			}
		}
		else cout<<query(1,y-1,z-1,0,n-1)<<endl;
	}

}