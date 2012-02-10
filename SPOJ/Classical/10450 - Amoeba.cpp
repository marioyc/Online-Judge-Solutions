#include <cstdio>
#include <cstring>

using namespace std;

int tam[] = {1,4,4,20,100,500,5000,50000,500000,5000000};

int pow(long long a, int b, int c){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    char s[10];
    int K,y,ans;
    bool found;
    
    while(scanf("%s",s) == 1){
        K = strlen(s);
        sscanf(s,"%d",&y);
        
        found = true;
        
        for(int i = 1,pow10 = 10,x = 0;i <= K && found;++i,pow10 *= 10){
            found = false;
            
            for(int j = 0;j <= tam[i] / tam[i - 1];++j){
                if(pow(7,x,pow10) == y % pow10){
                    found = true;
                    ans = x;
                    break;
                }else{
                    x += tam[i - 1];
                }
            }
            
            if(!found) ans = -2;
        }
        
        printf("%d\n",ans + 1);
    }
    
    return 0;   
}
