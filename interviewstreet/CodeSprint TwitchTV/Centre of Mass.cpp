#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int parent[100];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    parent[x] = y;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    int a[N];
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    char M[N][N + 1];
    
    for(int i = 0;i < N;++i){
        scanf("%s",M[i]);
        parent[i] = i;
    }
    
    for(int i = 0;i < N;++i)
        for(int j = 0;j < N;++j)
            if(M[i][j] == 'Y')
                Union(i,j);
    
    for(int i = 0;i < N;++i){
        if(parent[i] == i){
            vector<int> x,y;
            
            for(int j = 0;j < N;++j){
                if(Find(j) == i){
                    x.push_back(j);
                    y.push_back(a[j]);
                }
            }
            
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            
            for(int i = 0;i < x.size();++i)
                a[ x[i] ] = y[i];
        }
    }
    
    for(int i = 0;i < N;++i)
        printf("%d%c",a[i],i == N - 1? '\n' : ' ');
    
    return 0;
}
