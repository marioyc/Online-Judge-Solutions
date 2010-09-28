#include<cstdio>

using namespace std;

int main(){    
    int cont_left,cont_right;
    
    int T,a,b;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%d %d",&a,&b);
        
        cont_left=cont_right=0;
        
        while(a!=1 && b!=1){
            if(a>b){
                cont_left+=a/b;
                a%=b;
            }else{
                cont_right+=b/a;
                b%=a;
            }
        }
        
        if(a==1) cont_right+=b-1;
        else cont_left+=a-1;
        
        printf("Scenario #%d:\n%d %d\n\n",i,cont_left,cont_right);
    }
    
    return 0;
}
