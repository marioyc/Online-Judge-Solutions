#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

int n,a[100000],cont[100000];

int main(){
    char c;
    bool num;
    
    while(true){
        n = 0;
        a[0] = 0;
        num = false;
        
        while(true){
            c = getchar();
            
            if(c >= '0' && c <= '9'){
                a[n] = a[n] * 10 + c - '0';
                num = true;
            }else{
                if(num) ++n, a[n] = 0;
                num = false;
                if(c == '\n') break;
            }
        }
        
        if(n == 1 && a[0] == 0) break;
        
        bool valid = true;
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i < n;++i){
            if(a[i] >= n) valid = false;
            else ++cont[a[i]];
        }
        
        if(!valid) puts("Message hacked by the Martians!!!");
        else{
            memset(a,-1,sizeof(a));
            
            for(int i = 0;i < n;++i){
                if(cont[i] > 0){
                    a[i] = i;
                    --cont[i];
                }
            }
            
            for(int i = 0,j = 0;i < n;++i){
                if(a[i] == -1){
                    while(cont[j] == 0) ++j;
                    --cont[j];
                    a[i] = j;
                }
            }
            
            printf("%d",a[0]);
            for(int i = 1;i < n;++i) printf(" %d",a[i]);
            printf("\n");
        }
    }
    
    return 0;
}
