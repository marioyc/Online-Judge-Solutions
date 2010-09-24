#include<cstdio>

using namespace std;

int main(){    
    int N,a[3];
    char s[9];
    
    scanf("%d\n",&N);
    
    for(int i=1;i<=N;i++){
        scanf("%s",s);
        sscanf(s,"%d:%d:%d",&a[0],&a[1],&a[2]);
        
        printf("%d ",i);
        
        for(int j=5;j>=0;j--)
            for(int k=0;k<3;k++)
                if(a[k] & (1<<j)) printf("1");
                else printf("0");
        
        printf(" ");
        
        for(int j=0;j<3;j++)
            for(int k=5;k>=0;k--)
                if(a[j] & (1<<k)) printf("1");
                else printf("0");
        
        printf("\n");
    }
    
    return 0;
}
