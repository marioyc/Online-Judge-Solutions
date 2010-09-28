#include<iostream>
#include<string>

#define all(v) (v).begin(),(v).end()

using namespace std;

string s;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin>>s;
    if(next_permutation(all(s))) cout<<s<<endl;
    else cout<<0<<endl;
}
