#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool myc(string a,string b){
    if(a.length() > b.length()){
        int n = b.length();
        int d = 0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) {
                break;
                d = 1;
            }
        }
        if(!d) return a.length() > b.length();
    }
    else if(a.length() > b.length()){
        int n = a.length();
        int d = 0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) {
                break;
                d = 1;
            }
        }
        if(!d) return b.length() > a.length();
    }
    return a<b;
}

int main(){
    vector<string> v;
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),myc);
    for(auto x : v) cout<<x<<endl;
}