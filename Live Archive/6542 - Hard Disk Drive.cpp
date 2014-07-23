#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char aux[] = "BKMGTPEZY";

int main(){
    int T,x;
    char s[3];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d%s",&x,s);
        int k;
        
        for(int i = 0;i < 9;++i)
            if(s[1] == aux[i])
                k = i;
        
        printf("Case #%d: %.2f%c\n",tc,(1 - pow(1000.0/1024,k)) * 100 + 1e-8,'%');
    }
    
    return 0;
}
