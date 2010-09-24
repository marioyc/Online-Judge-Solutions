/*
ID: zion_ba1
LANG: C++
TASK: palsquare
*/

#include <cstdio>

using namespace std;

int main(){
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    
    int B;
    
    scanf("%d",&B);
    
    int a[20],d,aux,b[20],D;
    bool palindrome;
    
    for(int i=1;i<=300;i++){
        d=0;
        aux=i*i;
        
        while(aux!=0){
            a[d]=aux%B;
            aux/=B;
            d++;
        }
        
        palindrome=true;
        
        for(int j=0;j<d/2;j++)
            if(a[j]!=a[d-1-j])
                palindrome=false;
        
        if(!palindrome) continue;
        
        aux=i;
        D=0;
        while(aux!=0){
            b[D++]=aux%B;
            aux/=B;
        }
        
        for(int j=D-1;j>=0;j--)
            if(b[j]>=10) printf("%c",b[j]-10+'A');
            else printf("%d",b[j]);
        printf(" ");
        
        for(int j=d-1;j>=0;j--)
            if(a[j]>=10) printf("%c",a[j]-10+'A');
            else printf("%d",a[j]);
        printf("\n");
    }
    
    return 0;
}
