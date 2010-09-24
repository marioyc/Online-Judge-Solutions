#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s1="VWXYZABCDEFGHIJKLMNOPQRSTU",s;
    
    char M[26];
    
    for(int i=0;i<26;i++) M[i]=s1[i];
    
    while(1){
        getline(cin,s);
        if(s=="START") continue;
        if(s=="END"){
            cout<<endl;
            continue;
        }
        if(s=="ENDOFINPUT") break;
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z') cout<<M[s[i]-'A'];
            else cout<<s[i];
        }
    }
    
    return 0;
}
