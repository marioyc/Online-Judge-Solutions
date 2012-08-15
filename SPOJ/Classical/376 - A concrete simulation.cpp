#include <cstdio>

using namespace std;

int main(){
    char op;
    int x,y,z,r[1235],c[5679];
    int revr[1235],revc[5679];
    
    for(int i = 1;i <= 1234;++i){
        r[i] = i;
        revr[i] = i;
    }
    
    for(int i = 1;i <= 5678;++i){
        c[i] = i;
        revc[i] = i;
    }
    
    while(~scanf(" %c",&op)){
        if(op == 'R'){
            scanf("%d %d",&x,&y);
            
            int r1 = r[x],r2 = r[y];
            
            r[x] = r2; revr[r2] = x;
            r[y] = r1; revr[r1] = y;
        }else if(op == 'C'){
            scanf("%d %d",&x,&y);
            
            int c1 = c[x],c2 = c[y];
            
            c[x] = c2; revc[c2] = x;
            c[y] = c1; revc[c1] = y;
        }else if(op == 'Q'){
            scanf("%d %d",&x,&y);
            printf("%d\n",(r[x] - 1) * 5678 + c[y]);
        }else{
            scanf("%d",&z);
            --z;
            
            x = z / 5678; y = z % 5678;
            
            printf("%d %d\n",revr[x + 1],revc[y + 1]);
        }
    }
    
    return 0;
}
