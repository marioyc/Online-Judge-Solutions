#include <cstdio>
#include <algorithm>

using namespace std;

char M[1000][1000];

int main(){
    int n,m,Q,K,P,Qr[100],Qc[100],Kr[100],Kc[100],Pr,Pc,r,c,tc=1,cont;
    int dr1[]={-1,-1,-1,1,1,1,0,0},dc1[]={-1,1,0,-1,1,0,-1,1};
    int dr2[]={-2,-2,2,2,-1,-1,1,1},dc2[]={-1,1,-1,1,-2,2,-2,2};
    
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i=0;i<n;i++) fill(M[i],M[i]+m,'E');
        cont=m*n;
        
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d %d",&Qr[i],&Qc[i]);
            Qr[i]--; Qc[i]--;
            if(M[Qr[i]][Qc[i]]=='E'){
                M[Qr[i]][Qc[i]]='Q';
                cont--;
            }
        }
        
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d %d",&Kr[i],&Kc[i]);
            Kr[i]--; Kc[i]--;
            if(M[Kr[i]][Kc[i]]=='E'){
                M[Kr[i]][Kc[i]]='K';
                cont--;
            }
        }
        
        scanf("%d",&P);
        for(int i=0;i<P;i++){
            scanf("%d %d",&Pr,&Pc);
            Pr--; Pc--;
            if(M[Pr][Pc]=='E'){
                M[Pr][Pc]='P';
                cont--;
            }
        }
        
        for(int i=0;i<Q;i++){
            for(int j=0;j<8;j++){
                for(r=Qr[i]+dr1[j],c=Qc[i]+dc1[j];r>=0 && r<n && c>=0 && c<m && (M[r][c]=='X' || M[r][c]=='E');r+=dr1[j],c+=dc1[j])
                    if(M[r][c]=='E'){
                        M[r][c]='X';
                        cont--;
                    }
            }
        }
        
        for(int i=0;i<K;i++){
            for(int j=0;j<8;j++){
                r=Kr[i]+dr2[j];c=Kc[i]+dc2[j];
                if(r>=0 && r<n && c>=0 && c<m && M[r][c]=='E'){
                    M[r][c]='X';
                    cont--;
                }
            }
        }
        
        printf("Board %d has %d safe squares.\n",tc++,cont);
    }
    
    return 0;
}
