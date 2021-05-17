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
//ios_base::sync_with_stdio(false); cin.tie(NULL); 
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

int nob(int n){
	n++;
	int a = 2;
	int ans = 0;
	while(a<=n){
		int g = (((n/a)*a)/2);
		ans += g;
		ans = ans;
		if((n/a)%2==1){
			ans += (((n - (n/a)*a))%a);
		}
		a *= 2;
	}

	return ans;
}

int32_t main(){
	fast();
	test{
		int a,b;
		cin>>a>>b;
		cout<<nob(b) - nob(a-1)<<endl;
	}
}