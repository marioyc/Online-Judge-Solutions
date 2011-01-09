#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main(){
    char s[50000];
    string word,ans;
    int L,mx,aux;
    map<string, int> :: iterator it;
    
    while(!feof(stdin)){
        map<string,int> freq;
        mx = 0;
        
        while(true){
            fgets(s,50000,stdin);
            L = strlen(s);
            
            if(L==2 && s[0]=='#') break;
            
            for(int i = 0;i<L;++i){
                if(!(s[i]>='a' && s[i]<='z') && !(s[i]>='A' && s[i]<='Z')) s[i] = ' ';
                else if(s[i]>='A' && s[i]<='Z') s[i] = 'a'+s[i]-'A';
            }
            
            istringstream is(s);
            
            while(is>>word){
                aux = ++freq[word];
                
                if(aux>mx){
                    mx = aux;
                    ans = word;
                }
            }
        }
        
        if(mx==0) break;
        printf("%4d %s\n",mx,ans.c_str());
    }
    
    return 0;
}
