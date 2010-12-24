#include <cstdio>
#include <algorithm>

using namespace std;

struct rectangle{
    int x1,y1,x2,y2;
    
    rectangle(){}
    
    bool operator < (rectangle R)const{
        if(x2-x1!=R.x2-R.x1) return x2-x1>R.x2-R.x1;
        return y2-y1>R.y2-R.y1;
    }
}R[20000];

int main(){
    int n;
    
    while(scanf("%d",&n)==1){
        for(int i = 0;i<n;++i)
            scanf("%d %d %d %d",&R[i].x1,&R[i].x2,&R[i].y1,&R[i].y2);
        
        sort(R,R+n);
        int ans = 0;
        
        for(int i = 0;i<n;++i){
            if((i==0 || R[i-1].x1!=R[i].x1 || R[i-1].x2!=R[i].x2 || R[i-1].y1!=R[i].y1 || R[i-1].y2!=R[i].y2)
                && (i+1<n && R[i+1].x1==R[i].x1 && R[i+1].x2==R[i].x2 && R[i+1].y1==R[i].y1 && R[i+1].y2==R[i].y2)){
                    ++ans;
            }else{
                for(int j = i-1;j>=0;--j){
                    if(j!=i && R[j].x1<=R[i].x1 && R[j].x2>=R[i].x2 && R[j].y1<=R[i].y1 && R[j].y2>=R[i].y2){
                        ++ans;
                        break;
                    }
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
