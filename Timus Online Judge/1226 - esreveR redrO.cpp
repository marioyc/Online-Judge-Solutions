#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool alpha(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main(){
    char line[300];
    
    while(fgets(line,300,stdin) != NULL){
        int L = strlen(line);
        
        for(int i = 0;i < L;){
            if(alpha(line[i])){
                int s = i,e = i;
                
                while(alpha(line[e])) ++e;
                i = e--;
                
                while(s < e){
                    swap(line[s],line[e]);
                    ++s; --e;
                }
            }else ++i;
        }
        
        printf("%s",line);
    }
    
    return 0;
}
