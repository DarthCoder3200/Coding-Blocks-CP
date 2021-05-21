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
int l,r;
int tot(int n){
	if(n==0 || n==1) return 1;
	int x = tot(n/2);
	return 2*x+1;
}
int ans = 0;
void getA(int n,int left,int right){
	//int ans = 0;
	if(n==0) return;
	else if(n==1){
		ans++;
		return;
	}
	int x = (right-left)/2;
	if(!((l>left+x-1)||(r<left))){
        getA(n/2,left,left+x-1);
    }
    if(!((l>right)||(r<left+x+1))){
        getA(n/2,left+x+1,right);
    }
	if((left+x>=l)&&(left+x<=r)&&(n%2==1)) ans++;
}

int32_t main(){
	fast();
	int n;
	cin>>n>>l>>r;
	getA(n,1,tot(n));
	//cout<<tot(n)<<endl;
	cout<<ans;
}