#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_VAL 128

int N,T[MAX_VAL+1][MAX_VAL+1][MAX_VAL+1];

void update(int idx, int idy, int idz, int val){
    for(int x = idx;x<=MAX_VAL;x += (x & -x))
        for(int y = idy;y<=MAX_VAL;y += (y & -y))
            for(int z = idz;z<=MAX_VAL;z += (z & -z))
                T[x][y][z] += val;
}

int F(int idx, int idy, int idz){
    int sum = 0;
    
    for(int x = idx;x>0;x -= (x & -x))
        for(int y = idy;y>0;y -= (y & -y))
            for(int z = idz;z>0;z -= (z & -z))
                sum += T[x][y][z];
    
    return sum;
}

int main(){
    scanf("%d",&N);
    memset(T,0,sizeof(T));
    
    int M,x1,x2,y1,y2,z1,z2,K;
    
    while(true){
        scanf("%d",&M);
        if(M==3) break;
        
        if(M==1){
            scanf("%d %d %d %d",&x1,&y1,&z1,&K);
            ++x1; ++y1; ++z1;
            update(x1,y1,z1,K);
        }else{
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            ++x1; ++y1; ++z1;
            ++x2; ++y2; ++z2;
            printf("%d\n",F(x2,y2,z2)-F(x2,y2,z1-1)-F(x2,y1-1,z2)-F(x1-1,y2,z2)
                            +F(x1-1,y1-1,z2)+F(x1-1,y2,z1-1)+F(x2,y1-1,z1-1)-F(x1-1,y1-1,z1-1));
        } 
    }
    
    return 0;
}
