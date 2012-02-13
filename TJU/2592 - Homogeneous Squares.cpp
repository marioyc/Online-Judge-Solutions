#include <cstdio>

using namespace std;

int M[1000][1000];

int main(){
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&M[i][j]);
        
        bool ok = true;
        
        for(int i = 1;i < n;++i)
            for(int j = 1;j < n;++j)
                if(M[i][j] != M[i][0] + M[0][j] - M[0][0])
                    ok = false;
        
        printf("%s\n",ok? "homogeneous" : "not homogeneous");
    }
    
    return 0;
}
