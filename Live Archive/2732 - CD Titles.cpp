#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N = 0,len[50];
    char title[51][105];
    
    while(true){
        fgets(title[N],105,stdin);
        int L = strlen(title[N]);
        
        if(L==2 && title[N][0]=='#') break;
        
        len[N] = L-1;
        ++N;
    }
    
    for(int i = 2*N;i>=0;--i) putchar('-');
    putchar('\n');
    
    for(int i = 0;i<36;++i){
        putchar('|');
        
        for(int j = 0;j<N;++j){
            if(i<len[j]) putchar(title[j][i]);
            else putchar(' ');
            
            putchar('|');
        }
        
        putchar('\n');
    }
    
    for(int i = 2*N;i>=0;--i) putchar('-');
    putchar('\n');
    
    return 0;
}
