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

class aD{
public:
	int pr,su,maxi,tot;
	aD(int a,int b,int c,int d){
		pr = a; su = b; maxi = c; tot = d;
	}
	aD(){
		pr = su = maxi = tot = 0; 
	}
};

aD id(1,0,0,1);

aD tree[400045];
int a[200004];
int n,q;


aD getThat(aD left , aD right){
	aD c;
	c.tot = left.tot+right.tot;
	c.pr = max(left.tot+right.pr, left.pr);
	c.su = max(right.tot+left.su, right.su);
	c.maxi = max(c.tot,max(c.pr,max(c.su,max(left.su+right.pr,max(left.maxi,right.maxi)))));
	return c;
}

void buildTree(int i,int ss,int se){
	if(ss==se){
		tree[i] = aD(a[ss],a[ss],a[ss],a[ss]);
		return;
	}
	int m = (ss+se)/2;
	buildTree(2*i,ss,m);
	buildTree(2*i+1,m+1,se);
	aD left = tree[2*i];
	aD right = tree[2*i+1];
	aD c = getThat(left,right);
	tree[i] = c;
	return;
}
aD query(int i,int qs,int qe,int ss,int se){
	if(ss>qe || se<qs) return aD(-100000000000,-10000000000,-10000000000,-100000000000);
	if((ss>=qs) && (se<=qe)) return tree[i];
	aD left = query(2*i,qs,qe,ss,(ss+se)/2);
	aD right = query(2*i+1,qs,qe,(ss+se)/2+1,se);
	aD c = getThat(left,right);
	return c;
}

int32_t main(){
	fast();
	cin>>n;
	fr(i,0,n) cin>>a[i];
	buildTree(1,0,n-1);
	cin>>q;
	fr(i,0,q){
		int o,p;
		cin>>o>>p;
		aD ans = query(1,o-1,p-1,0,n-1);
		cout<<ans.maxi<<endl;
	}
}