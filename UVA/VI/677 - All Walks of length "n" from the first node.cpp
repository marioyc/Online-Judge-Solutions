#include <cstdio>

using namespace std;

int n,len,path[11];
int M[10][10];
bool found;

void search(int pos, int mask, int m){
    if(m == 0){
        putchar('(');
        
        for(int i = len;i >= 0;--i){
            printf("%d",path[i]);
            if(i > 0) putchar(',');
        }
        
        putchar(')');
        putchar('\n');
        
        found = true;
        
        return;
    }
    
    for(int i = 0;i < n;++i){
        if(M[pos][i] == 1 && (mask & (1 << i)) == 0){
            path[m - 1] = i + 1;
            search(i,mask | (1 << i),m - 1);
        }
    }
}

int main(){
    int aux;
    bool first = true;
    
    do{
        scanf("%d %d",&n,&len);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&M[i][j]);
        
        if(!first) putchar('\n');
        first = false;
        found = false;
        
        path[len] = 1;
        search(0,1,len);
        
        if(!found) printf("no walk of length %d\n",len);
    }while(scanf("%d",&aux) == 1 && aux == -9999);
    
    return 0;
}
