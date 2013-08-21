#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    char s[201];
    
    scanf("%s",s);
    
    int L = strlen(s);
    
    if(s[0] == '@' || s[L - 1] == '@' || count(s,s + L,'@') == 0) printf("No solution\n");
    else{
        vector<string> token;
        int n = 0;
        bool ok = true;
        
        for(int i = 0;i + 1 < L;++i)
            if(s[i] == '@' && s[i + 1] == '@')
                ok = false;
        
        for(int i = 0;i < L;){
            if(s[i] == '@') ++i;
            else{
                string aux;
                int e = i;
                
                while(e < L && s[e] != '@'){
                    aux += s[e];
                    ++e;
                }
                
                token.push_back(aux);
                ++n;
                i = e;
            }
        }
        
        if(n > 2){
            for(int i = 1;i + 1 < n;++i)
                if(token[i].size() == 1)
                    ok = false;
        }
        
        if(!ok){
            printf("No solution\n");
            return 0;
        }
        
        for(int i = 0;i < n - 1;++i){
            string A,B;
            
            if(i == 0) A = token[i];
            else A = token[i].substr(1,token[i].size() - 1);
            
            if(i == n - 2) B = token[i + 1];
            else B = token[i + 1][0];
            
            if(i) printf(",");
            printf("%s@%s",A.c_str(),B.c_str());
        }
        
        printf("\n");
    }
    
    return 0;
}
