#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N,P,w[100],v[100],adol,vol;
char name_adol[1000][80],name_vol[1000][80],cat[12],name[80];
int A[1000][100],V[1000][100],sum;

struct person{
    int ind,sc;
    
    person(){
    }
    
    person(const int _ind, const int _sc){
        ind=_ind; sc=_sc;
    }
    
    bool operator < (const person & X) const{
        return sc<X.sc;
    }
}f[1000];

#define SZ 1000

int n,pref_men[SZ][SZ],pref_women[SZ][SZ],inv[SZ][SZ],cont[SZ],wife[SZ],husband[SZ];
int Q[SZ+1],head,tail;

void Stable_Marriage(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            inv[i][pref_women[i][j]]=j;
    
    head=0; tail=n;
    for(int i=0;i<n;i++) Q[i]=i;;
    fill(cont,cont+n,0);
    fill(wife,wife+n,-1);
    fill(husband,husband+n,-1);
    
    int m,w;
    
    while(head!=tail){
        m=Q[head];
        w=pref_men[m][cont[m]];
        
        if(husband[w]==-1){
            wife[m]=w;
            husband[w]=m;
            head++;
        }else{
            if(inv[w][m]<inv[w][husband[w]]){
                wife[m]=w;
                wife[husband[w]]=-1;
                head++;
                Q[tail++]=husband[w];
                husband[w]=m;
            }
        }
        
        cont[m]++;
    }
}

struct adolescent{
    string s;
    int ind;
    
    adolescent(){
    }
    
    bool operator < (adolescent X) const{
        return s<X.s;
    }
}aux[1000];

int main(){
    int tc=1;
    string s;
    
    while(1){
        scanf("%d %d",&N,&P);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&w[i]);
        for(int i=0;i<N;i++) scanf("%d",&v[i]);
        
        adol=vol=0;
        
        for(int i=2*P-1,j=0;i>=0;i--,j++){
            scanf("%s",cat);
            
            if(cat[0]=='A'){
                scanf("%s",name_adol[adol]);
                for(int k=0;k<N;k++) scanf("%d",&A[adol][k]);
                adol++;
            }else{
                scanf("%s",name_vol[vol]);
                for(int k=0;k<N;k++) scanf("%d",&V[vol][k]);
                vol++;
            }
        }
        
        for(int i=0;i<P;i++){
            for(int j=0;j<P;j++){
                sum=0;
                for(int k=0;k<N;k++) sum+=w[k]*(A[i][k]-V[j][k])*(A[i][k]-V[j][k]);
                f[j]=person(j,sum);
            }
            sort(f,f+P);
            for(int j=0;j<P;j++) pref_men[i][j]=f[j].ind;
        }
        
        for(int i=0;i<P;i++){
            for(int j=0;j<P;j++){
                sum=0;
                for(int k=0;k<N;k++) sum+=v[k]*(A[j][k]-V[i][k])*(A[j][k]-V[i][k]);
                f[j]=person(j,sum);
            }
            sort(f,f+P);
            for(int j=0;j<P;j++) pref_women[i][j]=f[j].ind;
        }
        
        n=P;
        Stable_Marriage();
        
        for(int i=0;i<P;i++){
            aux[i].s=string(name_adol[i],name_adol[i]+strlen(name_adol[i]));
            aux[i].ind=i;
        }
        sort(aux,aux+P);
        
        printf("Situation %d:\n",tc++);
        for(int i=0;i<P;i++) printf("Adolescent %s Volunteer %s\n",name_adol[aux[i].ind],name_vol[wife[aux[i].ind]]);
    }
    
    return 0;
}
