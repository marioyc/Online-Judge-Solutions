#include <cstdio>
#include <algorithm>

using namespace std;

struct nodo{
    int n;
    nodo *next;
    
    nodo(){        
    }
};

int main(){    
    int a[3000];
    
    nodo *L,*p;
    L=NULL;
    
    for(int i=33810;i>=2;i--){
        p=new nodo;
        (*p).next=L;
        (*p).n=i;
        L=p;
    }
    
    int n;    
    
    nodo *p2;
    
    for(int i=0;i<3000;i++){
        n=(*L).n;        
        p=L;
        a[i]=n;
        
        while(1){
            for(int j=0;j<n;j++){
                if(p==NULL) break;
                p2=p;
                p=(*p).next;
            }
            
            if(p==NULL) break;
            
            (*p2).next=(*p).next;
        }
        
        L=(*L).next;
    }
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("%d\n",a[n-1]);
    }
    
    return 0;
}
