#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 10007

int main(){
    int T,B,S,pow;
    char m[1001];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %s",&B,m);
        
        S=0; pow=1;
        
        for(int i=strlen(m)-1;i>=0;i--){
            S=(S+(m[i]-'0')*pow)%MOD;
            pow=(pow*B)%MOD;
        }
        
        printf("%d\n",S);
    }
    
    return 0;
}
