#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    char s1[1001],s2[1001];
    int L1,L2;
    
    while(scanf("%s %s",s1,s2)==2){
        L1 = strlen(s1);
        L2 = strlen(s2);
        
        int best = 0;
        
        for(int i = 0;i<L1;++i){
            int aux = 0;
            
            for(int j = 0;j<L2 && i+j<L1;++j)
                if(s1[i+j]==s2[j]) ++aux;
            
            if(aux>best) best = aux;
        }
        
        for(int i = 0;i<L2;++i){
            int aux = 0;
            
            for(int j = 0;j<L1 && i+j<L2;++j)
                if(s2[i+j]==s1[j]) ++aux;
            
            if(aux>best) best = aux;
        }
        
        printf("appx(%s,%s) = ",s1,s2);
        
        int num = best*2,dem = L1+L2;
        int g = __gcd(num,dem);
        
        num /= g; dem /= g;
        
        if(num==0) printf("0");
        else if(dem==1) printf("%d",num);
        else printf("%d/%d",num,dem);
        
        putchar('\n');
    }
    
    return 0;
}
