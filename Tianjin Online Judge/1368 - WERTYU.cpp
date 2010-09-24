#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){    
    string aux="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    
    int n=aux.size();
    map<char, char> M;
    
    for(int i=1;i<n;i++)
        if(aux[i]!='Q' && aux[i]!='A' && aux[i]!='Z') M[aux[i]]=aux[i-1];
    
    string s;
    
    map<char,char> :: iterator it;
    
    while(getline(cin,s)){
        n=s.size();
        
        for(int i=0;i<n;i++){
            it=M.find(s[i]);
            
            if(it!=M.end()) cout<<it->second;
            else cout<<s[i];
        }
        
        cout<<endl;
    }
    
    return 0;
}
