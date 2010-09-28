#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){    
    string s;
    int n;
    
    vector<string> v;
    
    while(getline(cin,s)){
        n=s.size();
        
        for(int i=0;i<n;i++)
            if(s[i]==' ') continue;
            else if(isupper(s[i])) s[i]=s[i]-'A'+'a';
            else if(!islower(s[i])) s[i]=' ';
        
        istringstream is(s);
        
        while(is>>s) v.push_back(s);
    }
    
    n=v.size();
    sort(v.begin(),v.end());
    
    bool used[n];
    fill(used,used+n,false);
    
    int cont[n];
    fill(cont,cont+n,1);
    
    for(int i=0;i<n;i++){
        if(used[i]) continue;
        
        for(int j=i+1;j<n;j++){
            if(v[j]!=v[i]) break;
            cont[i]++;
            used[j]=true;
        }
    }
    
    int mx=0;
    
    for(int i=0;i<n;i++) if(!used[i]) mx=max(mx,cont[i]);
    
    cout<<mx<<" occurrences"<<endl;
    
    for(int i=0;i<n;i++) if(cont[i]==mx) cout<<v[i]<<endl;
    
    return 0;
}
