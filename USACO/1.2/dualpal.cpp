/*
ID: zion_ba1
LANG: C++
TASK: dualpal
*/

#include <cstdio>

using namespace std;

int main(){
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    
    int N,S;
    scanf("%d %d",&N,&S);
    
    int a[20],d,aux,cont,cont_palin;
    bool palindrome;
    
    for(int i=S+1,cont=0;cont!=N;i++){
        cont_palin=0;
        for(int B=2;B<=10;B++){
            d=0;
            aux=i;
            
            while(aux!=0){
                a[d]=aux%B;
                d++;
                aux/=B;
            }
            
            palindrome=true;
            
            for(int j=0;j<d/2;j++)
                if(a[j]!=a[d-1-j])
                    palindrome=false;
            
            if(palindrome) cont_palin++;
            
            if(cont_palin==2){
                printf("%d\n",i);
                cont++;
                break;
            }
        }
    }
    
    return 0;
}
