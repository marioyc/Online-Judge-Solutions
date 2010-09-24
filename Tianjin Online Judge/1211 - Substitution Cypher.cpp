#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s1,s2;
    
    getline(cin,s1);
    getline(cin,s2);
    cout<<s2<<endl;
    cout<<s1<<endl;
    
    map<char,char> M;
    
    for(int i=0;i<s1.size();i++) M[s1[i]]=s2[i];
    
    while(getline(cin,s1)){
        for(int i=0;i<s1.size();i++){
            if(M[s1[i]]==0) cout<<s1[i];
            else cout<<M[s1[i]];
        }
        
        cout<<endl;
    }

    return 0;
}
