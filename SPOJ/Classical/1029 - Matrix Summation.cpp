#include<cstdio>
#include<algorithm>

using namespace std;

long long tree[1026][1026];

long long F(int idx, int idy){
    long long sum=0;
    for(;idx>0;idx-=(idx & -idx))
        for(int y=idy;y>0;y-=(y&-y)) sum+=tree[idx][y];
    return sum;
}

long long f(int x1, int y1, int x2, int y2){
    return F(x2,y2)-F(x1-1,y2)-F(x2,y1-1)+F(x1-1,y1-1);
}

long long f(int idx, int idy){
    return f(idx,idy,idx,idy);
}

void set(int idx, int idy, int val){
    long long a=val-f(idx,idy);
    
    for(;idx<1026;idx+=(idx & -idx))
        for(int y=idy;y<1026;y+=(y & -y)) tree[idx][y]+=a;
}

int main(){    
    int t,N,x1,x2,y1,y2,num;
    char s[4];
    
    scanf("%d",&t);
    
    for(int tc=0;tc<t;tc++){
        scanf("%d",&N);
        
        for(int i=0;i<=N;i++) fill(tree[i],tree[i]+N+1,0);
        
        while(1){
            scanf("%s",s);
            if(s[0]=='E') break;
            
            if(s[1]=='E'){
                scanf("%d %d %d",&x1,&y1,&num);
                x1++; y1++;
                set(x1,y1,num);
            }else{
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1++; y1++; x2++; y2++;
                printf("%lld\n",f(x1,y1,x2,y2));
            }
        }
    }
    
    return 0;
}
