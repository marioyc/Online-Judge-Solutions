#include <cstdio>

using namespace std;

int end(int m, int y){
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
    else if(m==4 || m==6 || m==9 || m==11) return 30;
    else{
        if(y%400==0 || (y%4==0 && y%100!=0)) return 29;
        else return 28;
    }
}

bool consecutive(int &d1, int &m1, int &y1, int &d2, int &m2, int &y2){
    if(y1==y2 && ((m1==m2 && d2==d1+1) || (m2==m1+1 && d1==end(m1,y1) && d2==1))) return true;
    else if(y2==y1+1 && m1==12 && m2==1 && d1==end(12,y1) && d2==1) return true;
    
    return false;
}

int main(){
    int N,d,m,y,c,cont,ans,d1,m1,y1,c1,d2,m2,y2,c2;
    char line[19];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        gets(line);
        scanf("%d %d %d %d",&d1,&m1,&y1,&c1);
        
        cont=ans=0;
        
        for(int i=1;i<N;i++){
            scanf("%d %d %d %d",&d2,&m2,&y2,&c2);
            if(consecutive(d1,m1,y1,d2,m2,y2)){
                cont++;
                ans+=c2-c1;
            }
            d1=d2; m1=m2; y1=y2; c1=c2;
        }
        
        printf("%d %d\n",cont,ans);
    }
    
    return 0;
}
