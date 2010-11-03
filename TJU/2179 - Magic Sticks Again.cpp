#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct stick{
	int a,b;
	
	stick(){}
		
	bool operator < (const stick &X) const{
		return a<X.a;
	}
};

int main(){
    int N;
	scanf("%d",&N);
	
	stick S[N];
	for(int i=0;i<N;i++) scanf("%d %d",&S[i].a,&S[i].b);
	sort(S,S+N);
    
    priority_queue<int> Q; Q.push(-S[0].b);
    int ans = 1,aux;
    
    for(int i=1;i<N;++i){
        aux = Q.top();
        
        if(-aux<=S[i].a) Q.pop();
        else ++ans;
        
        Q.push(-S[i].b);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
