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
int bit[100010][27];
string s;
int n;int q;

void update(int i,int j,int up){
	while(i<=n){
		bit[i][j] += up;
		i += (i&-i);
	}
}
vi query(int i){
	vi a(27);
	fr(j,0,26) a[j] = 0;
	while(i>0){
		fr(j,0,26) a[j] += bit[i][j];
		i -= (i&-i);
	}
	return a;
}

bool check(vi a,vi b){
	int o = 0;
	fr(i,0,26) if((a[i]-b[i])%2==1) o++;
	//cout<<o<<endl;
	return o<=1;
}

int32_t main(){
	fast();
	cin>>n>>q;
	cin>>s;
	fr(i,0,n) update(i+1,s[i]-'a',1);
	fr(i,0,q){
		int x;
		cin>>x;
		if(x==1){
			int y;
			char b;
			cin>>y>>b;
			update(y,s[y-1]-'a',-1);
			s[y-1] = b;
			update(y,b-'a',1);
		}
		else{
			int y,z;
			cin>>y>>z;
			vi a = query(z);
			vi b = query(y-1);
			if(check(a,b)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
}