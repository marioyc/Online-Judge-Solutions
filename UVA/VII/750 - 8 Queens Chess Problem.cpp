#include <cstdio>

using namespace std;

bool R[8],D1[15],D2[15];
int C,pos[8],cont;

void search(int c){
    if(c==8){
        printf("%2d      ",++cont);
        
        for(int i=0;i<8;i++){
            if(i!=0) printf(" ");
            printf("%d",pos[i]+1);
        }
        
        printf("\n");
    }
    
    if(c==C) search(c+1);
    else{
        for(int i=0;i<8;i++){
            if(R[i] || D1[c-i+7] || D2[c+i]) continue;
            R[i]=D1[c-i+7]=D2[c+i]=true;
            pos[c]=i;
            search(c+1);
            R[i]=D1[c-i+7]=D2[c+i]=false;
        }
    }
}

int main(){
    int T,r;
    
    scanf("%d",&T);
    
    for(int tc=0;tc<T;tc++){
        scanf("%d %d",&r,&C);
        r--; C--;
        
        for(int i=0;i<8;i++) R[i]=false;
        for(int i=0;i<15;i++) D1[i]=D2[i]=false;
        
        R[r]=D1[C-r+7]=D2[C+r]=true;
        pos[C]=r;
        cont=0;
        
        if(tc!=0) printf("\n");
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        search(0);
    }
    
    return 0;
}
