#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,m,n;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d",&m,&n);
        
        printf("Scenario #%d:\n",caso);
        if(m%2==0 || n%2==0) printf("%.2f\n\n",(double)m*n);
        else printf("%.2f\n\n",m*n-1+sqrt(2));
    }

    return 0;
}
