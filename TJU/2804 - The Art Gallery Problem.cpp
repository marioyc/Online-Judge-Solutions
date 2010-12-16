#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char n[1002];    
    
    while(scanf("%s",n)==1){
        bool start = true;
        int L = strlen(n);
        
        for(int i = 0,x = 0,y;i<L;++i){
            x = x*10+n[i]-'0';
            y = x/3;
            x %= 3;
            
            if(y!=0 || (y==0 && !start)){
                start = false;
                putchar('0'+y);
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
