#include<cstdio>

using namespace std;

int main(){    
    int T,n,cont1,cont2;
    char c1,c2;
    
    scanf("%d\n",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d\n",&n);
        
        cont1=cont2=0;
        
        for(int i=0;i<n;i++){
            scanf("%c %c\n",&c1,&c2);
            
            if(c1==c2) continue;
            
            if(c1=='R'){
                if(c2=='S') cont1++;
                else cont2++; 
            }else if(c1=='P'){
                if(c2=='R') cont1++;
                else cont2++;
            }else{
                if(c2=='P') cont1++;
                else cont2++;
            }
        }
        
        if(cont1>cont2) printf("Player 1\n");
        else if(cont1<cont2) printf("Player 2\n");
        else printf("TIE\n");
    }
    
    return 0;
}
