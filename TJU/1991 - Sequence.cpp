#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int ax1,ax2;

int conv(string s, int b){
    ax1=0;ax2=1;
    
    for(int i=s.size()-1;i>=0;i--){
        ax1+=(s[i]-'0')*ax2;
        ax2*=b;
    }
    return ax1;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector<string> v;
    vector<int> u;
    
    short n;
    string s;
    int mn;
    bool ok,solved;
    
    while(true){
        cin>>n;
        if(n==0) break;
        v.clear();
        
        for(int i=0;i<n;i++){
            cin>>s;
            v.push_back(s);
        }
        
        mn=-1;
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++) mn=max(mn,v[i][j]-'0');
        }
        mn++;
        
        solved=false;
        for(int i=mn;i<11 && !solved;i++){
            u.clear();
            for(int j=0;j<v.size();j++) u.push_back(conv(v[j],i));
            ok=true;
            for(int j=0;j<u.size()-2 && ok;j++){
                if(u[j+1]-u[j]!=u[j+2]-u[j+1]) ok=false;
            }
            if(ok){
                solved=true;
                mn=i;
            }
        }
        if(!solved) cout<<"No base <= 10 can be found."<<endl;
        else cout<<"Minimum base = "<<mn<<"."<<endl;
    }

    return 0;
}
