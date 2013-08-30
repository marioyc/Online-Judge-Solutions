#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N;
    char s[2];
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > Q;
    
    scanf("%d",&N);
    
    for(int i = 1,a,cont = 0,sum = 0;i < N;++i){
        scanf("%s %d",s,&a);
        
        if(s[0] == 'd'){
            ++cont; sum += a;
            Q.push(make_pair(a,i + 1));
        }else{
            if(i < N - 1){
                while(cont >= a){
                    pair<int,int> cur = Q.top();
                    --cont; sum -= cur.first;
                    Q.pop();
                }
            }else{
                if(cont >= a){
                    printf("%d\n%d\n",sum,cont);
                    vector<int> ans;
                    
                    while(!Q.empty()){
                        pair<int,int> cur = Q.top();
                        ans.push_back(cur.second);
                        Q.pop();
                    }
                    
                    sort(ans.begin(),ans.end());
                    
                    for(int i = 0;i < cont;++i){
                        printf("%d",ans[i]);
                        if(i < cont - 1) printf(" ");
                        else printf("\n");
                    }
                }else printf("-1\n");
            }
        }
    }
    
    return 0;
}
