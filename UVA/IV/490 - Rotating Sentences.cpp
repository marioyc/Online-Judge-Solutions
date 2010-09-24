#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    vector<string> v;    
    int n=-1;
    
    while(getline(cin,s)){
        v.push_back(s);
        n=max(n,(int)s.size());
    }
    
    vector<string> u(n,"");
    
    for(int i=v.size()-1;i>=0;i--){
        for(int j=0;j<v[i].size();j++) u[j]+=v[i][j];
        for(int j=v[i].size();j<n;j++) u[j]+=" ";
    }
    
    for(int i=0;i<n;i++) cout<<u[i]<<endl;

    return 0;
}
