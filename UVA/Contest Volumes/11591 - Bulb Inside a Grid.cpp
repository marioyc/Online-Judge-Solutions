#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N,M,M2,rmin[200],rmax[200],cmin[200],cmax[200];
set<int> SR,SC;

void add(int r1, int r2, int c1, int c2){
    if(r2 >= N && c2 >= N){
        rmin[M2] = r1; rmax[M2] = N - 1;
        cmin[M2] = c1; cmax[M2] = N - 1;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
        
        rmin[M2] = r1; rmax[M2] = N - 1;
        cmin[M2] = 0; cmax[M2] = c2 - N;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
        
        rmin[M2] = 0; rmax[M2] = r2 - N;
        cmin[M2] = c1; cmax[M2] = N - 1;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
        
        rmin[M2] = 0; rmax[M2] = r2 - N;
        cmin[M2] = 0; cmax[M2] = c2 - N;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
    }else if(r2 >= N){
        rmin[M2] = r1; rmax[M2] = N - 1;
        cmin[M2] = c1; cmax[M2] = c2;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
        
        rmin[M2] = 0; rmax[M2] = r2 - N;
        cmin[M2] = c1; cmax[M2] = c2;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
    }else if(c2 >= N){
        rmin[M2] = r1; rmax[M2] = r2;
        cmin[M2] = c1; cmax[M2] = N - 1;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
        
        rmin[M2] = r1; rmax[M2] = r2;
        cmin[M2] = 0; cmax[M2] = c2 - N;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
    }else{
        rmin[M2] = r1; rmax[M2] = r2;
        cmin[M2] = c1; cmax[M2] = c2;
        SR.insert(rmin[M2]); SR.insert(rmax[M2] + 1);
        SC.insert(cmin[M2]); SC.insert(cmax[M2] + 1);
        ++M2;
    }
}

long long f(int n){
    return (long long)n * (n+1) / 2;
}

long long count(long long r1, long long r2, long long c1, long long c2){
    if(c1 > r2 - 1) return (r2-r1) * (c2-c1);
    if(c2 - 1 <= r1) return 0;
    
    if(r2 - 1 <= c2 - 2){
        if(c1 - 1 >= r1) return f(r2 - c1 + 1) + (c1 - r1 - 1) * (c2 - c1) + (r2 - c1 + 1) * (c2 - r2 - 1);
        return f(r2 - r1) + (r2 - r1) * (c2 - r2 - 1);
    }else{
        if(r1 + 1 >= c1) return f(c2 - r1 - 1);
        return f(c2 - c1) + (c1 - r1 - 1) * (c2 - c1);
    }
    
    return 0;
}

int main(){
    int T;
    char line[100];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d\n",&N,&M);
        
        SR.clear(); SC.clear();
        SR.insert(0); SR.insert(N);
        SC.insert(0); SC.insert(N);
        M2 = 0;
        
        for(int i = 0;i < M;++i){
            fgets(line,100,stdin);
            
            int L = strlen(line);
            
            for(int j = 0;j < L;++j)
                if(line[j] < '0' || line[j] > '9')
                    line[j] = ' ';
            
            istringstream is(line);
            vector<int> param;
            int aux;
            
            while(is >> aux) param.push_back(aux);
            
            int r1 = param[0] - 1;
            int c1 = param[1] - 1;
            int c2 = c1 + param[2] - 1;
            
            if(param.size() == 4 && param[3] % 2 == 1) add(r1,r1 + param[2] - 1,c1,c2);
            if(param.size() == 5 && param[4] % 2 == 1) add(r1,r1 + param[3] - 1,c1,c2);
        }
        
        vector<int> R(SR.begin(),SR.end()),C(SC.begin(),SC.end());
        int nR = R.size(),nC = C.size();
        
        bool change[nR - 1][nC - 1];
        memset(change,0,sizeof(change));
        
        for(int k = 0;k < M2;++k)
            for(int i = 0;i+1 < nR;++i)
                if(rmin[k] <= R[i] && R[i+1]-1 <= rmax[k])
                    for(int j = 0;j+1 < nC;++j)
                        if(cmin[k] <= C[j] && C[j+1]-1 <= cmax[k])
                            change[i][j] ^= 1;
        
        long long ans = 0;
        
        for(int i = 0;i+1 < nR;++i)
            for(int j = 0;j+1 < nC;++j)
                if(!change[i][j])
                    ans += (long long)(R[i+1] - R[i]) * (C[j+1] - C[j]) - count(R[i],R[i+1],C[j],C[j+1]);
                else
                    ans += count(R[i],R[i+1],C[j],C[j+1]);
        
        printf("Case %d: %lld\n",tc,ans);
    }
    
    return 0;
}
