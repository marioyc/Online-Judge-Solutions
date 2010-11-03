#include <iostream>

using namespace std;

int k,num[100],L[100][100],res[100];

bool test(int c, int w){
    int wl,wr;
    
    for(int i=0;i<k;++i){
        wl = wr = 0;
        for(int j=0;j<num[i];++j) if(L[i][j]==c) wl += w;
        for(int j=0;j<num[i];++j) if(L[i][j+num[i]]==c) wr += w;
        if(res[i]==0 && wl<=wr) return false;
        if(res[i]==1 && wl!=wr) return false;
        if(res[i]==2 && wl>=wr) return false;
    }
    
    return true;
}

int solve(int &N){
    int cont = 0, ans = -1;
    
    for(int c=1;c<=N;++c){
        for(int w=-1;w<=1;w+=2){
            if(!test(c,w)) continue;
            ans = c;
            ++cont;
            break;
        }
    }
    
    if(ans==-1 || cont>1) return 0;
    return ans;
}

int main(){
    int n;
    cin>>n>>k;
    char sym;
    
    for(int i=0;i<k;++i){
        cin>>num[i];
        for(int j=0;j<2*num[i];++j) cin>>L[i][j];
        cin>>sym;
        if(sym=='>') res[i] = 0;
        else if(sym=='=') res[i] = 1;
        else res[i] = 2;
    }
    
    cout<<solve(n)<<endl;   
    
    return  0;
}

