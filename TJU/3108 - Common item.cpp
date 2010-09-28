#include<cstdio>
#include<map>

using namespace std;

int main(){    
    int N,n,m,aux;
    map<int,bool> a1;
    map<int,bool> a2;
    map<int,bool> :: iterator it;
    bool esp;
    
    scanf("%d",&N);
    
    for(int caso=0;caso<N;caso++){
        scanf("%d %d",&n,&m);
        
        a1.clear();
        a2.clear();
        
        for(int i=0;i<n;i++){
            scanf("%d",&aux);
            a1[aux]=true;
        }
        
        for(int i=0;i<m;i++){
            scanf("%d",&aux);
            a2[aux]=true;
        }
        
        esp=false;
        
        for(it=a1.begin();it!=a1.end();it++)
            if(a2[it->first]){
                if(esp) printf(" ");
                esp=true;
                
                printf("%d",it->first);
            }
            
        printf("\n");
    }
    
    return 0;
}
