//Wahe Guru ji ka Khalsa Wahe Guru ji ki Fateh
//HARJOT SINGH
//Software Developer and Data Scientist
//Contact me @ harjot3200@gmail.com
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
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

int32_t main(){
	fast();
	int n;
	cin>>n;
	int a=1;
	int b=1;
	int k = n+1;
	int g = n+1;
	if(n==0){
		cout<<"0";
		return 0;
	}
	while(k!=2*n+1){
		a*=k;
		b*=g;
		int p = __gcd(a,b);
		a /= p;
		b /= p;
		k++;
		g--;
		//cout<<a<<" "<<b<<endl;
	}
	cout<<(a/b);
}