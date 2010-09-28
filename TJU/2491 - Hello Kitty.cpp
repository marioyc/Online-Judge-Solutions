#include<cstdio>
#include<cstring>

using namespace std;

int main(){    
    int n,m;
    char W[200];
    
    while(1){
        scanf("%s %d",W,&n);
        
        m=strlen(W);
        
        if(m==1 && W[0]=='.') break;
        
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++) printf("%c",W[j]);
            for(int j=0;j<n-1;j++) printf("%s",W);
            for(int j=0;j<i;j++) printf("%c",W[j]);
            printf("\n");
        }
    }
    
    return 0;
}
