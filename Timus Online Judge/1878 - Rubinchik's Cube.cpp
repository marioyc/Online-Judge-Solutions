#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int M2[4][4][2] = {
    {{0,0}, {0,3}, {3,3}, {3,0}},
    {{0,1}, {1,3}, {3,2}, {2,0}},
    {{1,0}, {0,2}, {2,3}, {3,1}},
    {{1,1}, {1,2}, {2,2}, {2,1}},
};

int main(){
    int M[4][4];
    
    for(int i = 0;i < 4;++i)
        for(int j = 0;j < 4;++j)
            scanf("%d",&M[i][j]);
    
    int cost[4];
    memset(cost,0,sizeof cost);
    
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 4;++j){
            if(M[ M2[i][j][0] ][ M2[i][j][1] ] == 1){
                ++cost[(j + 1) % 4];
                cost[(j + 2) % 4] += 2;
                ++cost[(j + 3) % 4];
            }
        }
    }
    
    printf("%d\n",min(min(cost[0],cost[1]),min(cost[2],cost[3])));
    
    return 0;
}
