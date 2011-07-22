#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,cont[3];
    char s[10];
    
    cont[0] = cont[1] = cont[2] = 0;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        
        if(s[0] == 'E') ++cont[0];
        if(s[0] == 'L') ++cont[1];
        if(s[0] == 'M') ++cont[2];
        
        scanf("%s",s);
    }
    
    int best = max(cont[0],max(cont[1],cont[2]));
    
    if(cont[0] == best) puts("Emperor Penguin");
    if(cont[1] == best) puts("Little Penguin");
    if(cont[2] == best) puts("Macaroni Penguin");
    
    return 0;
}
