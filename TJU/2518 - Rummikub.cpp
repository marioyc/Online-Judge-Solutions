#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int mask[100],memo[100][4][4][4][4];

int solve(int pos, int cont1, int cont2, int cont3, int cont4){
    if(pos == 100) return 0;
    
    int &ret = memo[pos][cont1][cont2][cont3][cont4];
    
    if(ret == -1){
        ret = 0;
        
        int x1 = 0,sc1 = 0,x2 = 0,sc2 = 0,x3 = 0,sc3 = 0,x4 = 0,sc4 = 0;
        
        if(mask[pos] & 1){
            x1 = min(3,cont1 + 1);
            if(cont1 == 3) sc1 = pos + 1;
            if(cont1 == 2) sc1 = 3 * pos;
        }
        
        if(mask[pos] & 2){
            x2 = min(3,cont2 + 1);
            if(cont2 == 3) sc2 = pos + 1;
            if(cont2 == 2) sc2 = 3 * pos;
        }
        
        if(mask[pos] & 4){
            x3 = min(3,cont3 + 1);
            if(cont3 == 3) sc3 = pos + 1;
            if(cont3 == 2) sc3 = 3 * pos;
        }
        
        if(mask[pos] & 8){
            x4 = min(3,cont4 + 1);
            if(cont4 == 3) sc4 = pos + 1;
            if(cont4 == 2) sc4 = 3 * pos;
        }
        
        if((mask[pos] & 7) == 7)
            ret = max(ret,(pos + 1) * 3 + sc4 + solve(pos + 1,0,0,0,x4));
        
        if((mask[pos] & 11) == 11)
            ret = max(ret,(pos + 1) * 3 + sc3 + solve(pos + 1,0,0,x3,0));
        
        if((mask[pos] & 13) == 13)
            ret = max(ret,(pos + 1) * 3 + sc2 + solve(pos + 1,0,x2,0,0));
        
        if((mask[pos] & 14) == 14)
            ret = max(ret,(pos + 1) * 3 + sc1 + solve(pos + 1,x1,0,0,0));
        
        if(mask[pos] == 15) ret = max(ret,(pos + 1) * 4 + solve(pos + 1,0,0,0,0));
        
        ret = max(ret,sc1 + sc2 + sc3 + sc4 + solve(pos + 1,x1,x2,x3,x4));
    }
    
    return ret;
}

int main(){
    int T,N,num;
    char c;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        memset(mask,0,sizeof mask);
        
        for(int i = 0;i < N;++i){
            scanf("%d%c",&num,&c);
            --num;
            
            if(c == 'y') mask[num] |= 1;
            else if(c == 'r') mask[num] |= 2;
            else if(c == 'g') mask[num] |= 4;
            else mask[num] |= 8;
        }
        
        memset(memo,-1,sizeof memo);
        
        printf("%d\n",solve(0,0,0,0,0));
    }
    
    return 0;
}
