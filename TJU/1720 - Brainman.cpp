#include<cstdio>

using namespace std;

int c;

void swap(int &a, int &b){
    c=a;
    a=b;
    b=c;
}

int main(){    
    int T,n,cont,ind;
    int a[1000];
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        cont=0;
        
        for(int i=0;i<n-1;i++){
            ind=i;
            
            for(int j=i+1;j<n;j++)
                if(a[j]<a[ind]) ind=j;
            
            while(ind!=i){
                swap(a[ind-1],a[ind]);
                ind--;
                cont++;
            }
        }
        
        printf("Scenario #%d:\n%d\n\n",caso,cont);
    }
    
    return 0;
}
