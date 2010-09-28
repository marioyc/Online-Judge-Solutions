#include<cstdio>

using namespace std;

int main(){    
    int n,A,B;
    int a[20];
    int b[20];
    bool start=true;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        if(!start) printf("\n");
        start=false;
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        
        A=B=0;
        
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(a[i]>b[i]){
                    if(a[i]-b[i]==1){
                        if(a[i]==2) B+=6;
                        else B+=(a[i]+b[i]);
                    }else A+=a[i];
                }else{
                    if(b[i]-a[i]==1){
                        if(b[i]==2) A+=6;
                        else A+=(a[i]+b[i]);
                    }else B+=b[i];
                }
            }
        }
        
        printf("A has %d points. B has %d points.\n",A,B);
    }
    
    return 0;
}
