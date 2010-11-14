#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in2.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,m,n;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%d %d",&m,&n);
        
        printf("Scenario #%d:\n",i);
        
        if(m%2==0 || n%2==0) printf("%.2f\n\n",(float)m*n);
        else printf("%d.41\n\n",m*n);
    }
    
    return 0;
}
