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
int n;
int a[100005];

pair<pair<int,int>,pair<int,int>> mx(int l,int r){
	int m = (r+l)/2;
	if(l == r) return mp(mp(a[l],a[l]),mp(a[l],a[l]));
	pair<pii,pii> mL = mx(l,m);
	pair<pii,pii> mR = mx(m+1,r);
	pair<pii,pii> ans;
	ans.f.f = mL.f.f + mR.f.f;
	ans.f.s = max(mL.f.s,max(ans.f.f,mR.f.s + mL.f.f)); // from left
	ans.s.f = max(mR.s.f,max(ans.f.f,mL.s.f + mR.f.f)); // from right

	ans.s.s = max(max(ans.f.f,ans.f.s),max(ans.s.f,max(mR.f.s+mL.s.f, max(mL.s.s,mR.s.s)))); // ans bitch
	return ans;
}

int32_t main(){
	fast();
	test{
		cin>>n;
		fr(i,0,n) cin>>a[i];
		cout<<mx(0,n-1).s.s<<endl;
	}
}