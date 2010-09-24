#include<iostream>
#include<string>

using namespace std;

int main(){
    int T,max;
    string s;
    int cont[26];
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>s;
        
        memset(cont,0,sizeof(cont));
        
        for(int j=0;j<s.size();j++) cont[s[j]-'a']++;
        
        max=-1;
        
        for(int j=0;j<26;j++)
            if(cont[j]>max) max=cont[j];
        
        for(char c='a';c<='z';c++)
            if(cont[c-'a']==max) cout<<c;
        
        cout<<endl;
    }
    
    return 0;
}
