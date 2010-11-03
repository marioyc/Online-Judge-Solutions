#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void getPermutation(int n, int inv){
    vector<int> ans;
	for(int i=1;i<=n;++i) ans.push_back(i);
	
	for(int i=1;i<=n;++i){
		if(inv<=i*(i-1)/2){
			int I = i*(i-1)/2;
			reverse(ans.begin()+(n-i),ans.end());
			
			for(int j=0;I>inv;++j){
				int diff = I-inv;
				
				if(diff>=n-j-1){
					rotate(ans.begin()+(n-i+j),ans.begin()+(n-j-1),ans.begin()+(n-j));
					I -= n-j-1;
				}else{
					rotate(ans.begin()+(n-i+j),ans.begin()+(n-i+j+diff),ans.begin()+(n-i+j+diff+1));
					I = inv;
				}
			}
			
			break;
		}
	}
	
	printf("%d",ans[0]);
	for(int i=1;i<n;++i) printf(" %d",ans[i]);
	printf("\n");
}


int main(){
    int n,m;
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n==-1) break;
        
        getPermutation(n,m);
    }
    
    return 0;
}
