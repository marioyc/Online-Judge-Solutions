#include <cstdio>
#include <cstring>

using namespace std;

const int LIM = (1<<15);

int main(){
    int cont[LIM];
    memset(cont,0,sizeof(cont));
    
    for(int x = 0;x<=181;++x)
        for(int y = x;x*x+y*y<LIM;++y)
            for(int z = y;x*x+y*y+z*z<LIM;++z)
                for(int w = z;x*x+y*y+z*z+w*w<LIM;++w)
                    ++cont[x*x+y*y+z*z+w*w];
    
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",cont[n]);
    }
    
    return 0;
}
