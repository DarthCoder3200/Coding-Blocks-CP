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
#define mod 1000000007
void fast(){ 
ios_base::sync_with_stdio(false); cin.tie(NULL); 
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}
int pr[2300000]={0};
int tree[8000045] ={0};
int a[2300000]={0};
int lazy[8000045]={0};

void lazyup(int i,int ss,int se){
	if(lazy[i] == 0){
		tree[i] = 0;
		lazy[2*i] = 0;
		lazy[2*i+1] = 0;
		lazy[i] = -1;
	}
	else if(lazy[i] == 1){
		tree[i] = ((pr[se-ss+1]-1)%mod+mod)%mod;
		lazy[2*i] = 1;
		lazy[2*i+1] = 1;
		lazy[i] = -1;
	}
}

int query(int i,int qs,int qe,int ss,int se){
	lazyup(i,ss,se);
	if((qe<ss)|| (qs>se)) return 0;
	if((qs<=ss) && (qe>=se)){
	//	cout << tree[i];
		return tree[i];
	}
	int ans;
	if((se+ss)/2<=qe){
	//	cout<<pr[qe-(se+ss)/2]<<" "<<ss<<" "<<se<<" "<<qs<<" "<<qe<<endl;
		if(qe<=se)ans = ((pr[qe-(se+ss)/2]*query(2*i,qs,qe,ss,(se+ss)/2))%mod + query(2*i+1,qs,qe,(se+ss)/2+1,se))%mod;
		else ans = ans = ((pr[se-(se+ss)/2]*query(2*i,qs,qe,ss,(se+ss)/2))%mod + query(2*i+1,qs,qe,(se+ss)/2+1,se))%mod;
	//	cout<<ans;
		return ans;
	}
	ans = (query(2*i,qs,qe,ss,(se+ss)/2)%mod);
//	cout<<ans<<endl;

	return ans%mod;
}

void update(int i,int up,int qs,int qe,int ss,int se){
	lazyup(i,ss,se);
	if((qs<=ss) && (qe>=se)){
		if(up){
		//	cout<<"up"<<endl;
			tree[i] = ((pr[se-ss+1]-1)%mod+mod)%mod;
			//cout<<tree[i]<<" up "<<endl;
			lazy[2*i] = 1;
			lazy[2*i+1] = 1;
		}
		else{
			tree[i] = 0;
			lazy[2*i] = 0;
			lazy[2*i+1] = 0;
		}
		return;
	}
	if((qe<ss)|| (qs>se)) return;
	update(2*i,up,qs,qe,ss,(ss+se)/2);
	update(2*i+1,up,qs,qe,(ss+se)/2+1,se);
	tree[i] = (((pr[se-(se+ss)/2])*tree[2*i])%mod+tree[2*i+1])%mod;
	//cout<<i<<" "<<tree[i]<<endl;
	return;
}

int32_t main(){
	fast();
	int n;
	cin>>n;
	pr[0] = 1;
	fr(i,1,n+1){
		pr[i] = pr[i-1]*2;
		pr[i] = pr[i]%mod;
	}

	memset(lazy,-1,sizeof lazy);
//	update(1,1,1,n-1,0,n-1);

	//cout<<query(1,0,2,0,n-1)<<" "<<tree[1];
	//cout<<lazy[2]<<endl<<tree[2]<<endl;
	int q;
	cin>>q;
	fr(i,0,q){
		int l,r,k;
		cin>>l>>r>>k;
		if(l==2) cout<<query(1,r,k,0,n-1)<<endl;
		else if(l==1) update(1,1,r,k,0,n-1);
		else update(1,0,r,k,0,n-1);
	}
}