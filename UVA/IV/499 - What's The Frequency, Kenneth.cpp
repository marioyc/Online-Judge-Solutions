#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int cont[52];
    int x;
    string s;
    
    while(getline(cin,s)){
        memset(cont,0,sizeof(cont));
        
        for(int i=0;i<s.size();i++)
            if(s[i]>='a' && s[i]<='z') cont[s[i]-'a'+26]++;
            else if(s[i]>='A' && s[i]<='Z') cont[s[i]-'A']++;
        
        x=-1;
        
        for(int i=0;i<52;i++) x=max(x,cont[i]);
        
        for(int i=0;i<52;i++)
            if(cont[i]==x){
                if(i<26) printf("%c",'A'+i);
                else printf("%c",'a'+i-26);
            }
        
        printf(" %d\n",x);
    }
    
    return 0;
}
