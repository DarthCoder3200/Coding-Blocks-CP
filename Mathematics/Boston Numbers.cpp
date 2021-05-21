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
int SoD(int n){
	int ans = 0;
	while(n){
		ans+= n%10;
		n =  n/10;
	}
	return ans;
}
int primes[100002];
vi getPrimes(){
	memset(primes,1,sizeof primes);
	primes[0] = primes[1] = 0;
	for(int i=4;i<100000;i+=2) primes[i] = 0;
	for(int i=3;i<100000;i+=2){
		if(primes[i]){
			for(int j = i*i;j<100000;j += 2*i){
				primes[j] = 0;
			}
		}
	}
	vi ans;
	for(int i=2;i<100000;i++){
		if(primes[i]) ans.pb(i);
	}
	return ans;
}

int32_t main(){
	fast();
	int n;
	cin>>n;
	int r = SoD(n);
	vi prime = getPrimes();
	vi fact;
	for(auto x:prime){
		//cout<<x<<"  "<<n<<endl;
		if(x*x>n) break;
		if(n%x == 0){
			while(n%x == 0){
				fact.pb(x);
				//cout<<x;
				n = n/x;
			}
		}
	}
	if(n!=1) fact.pb(n);
	int t = 0;
	for(auto x:fact) t+=SoD(x);
	if(r==t) cout<<"1";
	else cout<<"0";
}