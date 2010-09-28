#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int N,k,num,n,m,cont,dif;
    int a[500];
    int b[500];
    
    while(1){
        scanf("%d %d",&N,&k);
        if(N==0 && k==0) break;
        
        n=m=0;
        
        for(int i=0;i<N;i++){
            scanf("%d",&num);
            if(num%2==0) a[n++]=num;
            else b[m++]=num;
        }
        
        cont=0;
        sort(a,a+n);
        sort(b,b+m);
        
        for(int i=0,j=0;i<n && j<m;){
            if(a[i]-b[j]>k) j++;
            else if(a[i]-b[j]<-k) i++;
            else{
                cont++;
                i++;
                j++;
                continue;
            }
        }
        
        printf("%d\n",cont);
    }
    
    return 0;
}
