#include <cstdio>
#include <cstring>

using namespace std;

bool done[52];
char card[52][3];

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        for(int i = 0;i < 52;++i)
            scanf("%s",card[i]);
        
        memset(done,false,sizeof(done));
        
        int Y = 0;
        
        for(int i = 0,pos = 26;i < 3;++i){
            int X = (card[pos][0] >= '2' && card[pos][0] <= '9'? card[pos][0] - '0' : 10);
            Y += X;
            
            done[pos] = true;
            --pos;
            
            for(int j = 0;j < 10-X;++j){
                done[pos] = true;
                --pos;
            }
        }
        
        printf("Case %d: ",tc);
        
        for(int i = 0,j = 0;;++i){
            if(!done[i]) ++j;
            
            if(j == Y){
                puts(card[i]);
                break;
            }
        }
    }
    
    return 0;
}
