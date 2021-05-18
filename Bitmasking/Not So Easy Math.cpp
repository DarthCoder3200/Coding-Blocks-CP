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

void get(int n){
	int a[10] = {2,3,5,7,11,13,17,19};
	int ans =0;
	fr(i,1,(1<<8)){
		int k = __builtin_popcountll(i);
		int r = 1;
		int p = i;
		int j = 0;
		while(p){
			if(p%2==1) r *= a[j];
			j++;
			p = p/2;
		}
		if(k%2==1) ans += (n/r);
		else ans -= (n/r); 
	}
	cout<<ans<<endl;
}

int32_t main(){
	fast();
	test{
		int n;
		cin>>n;
		get(n);
	}
}