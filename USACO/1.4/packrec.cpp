/*
ID:zion_ba1
LANG:C++
TASK:packrec
*/

#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    
    int L[4][2],ind[4],ans=(1<<30),h,w;
    set< pair<int, int> > S;
    
    for(int i=0;i<4;i++) scanf("%d %d",&L[i][0],&L[i][1]);
    
    ind[0]=0; ind[1]=1; ind[2]=2; ind[3]=3;
    
    do{
        for(int a=0;a<2;a++){
            for(int b=0;b<2;b++){
                for(int c=0;c<2;c++){
                    for(int d=0;d<2;d++){
                        h=max(max(L[ind[0]][a],L[ind[1]][b]),max(L[ind[2]][c],L[ind[3]][d]));
                        w=L[ind[0]][1-a]+L[ind[1]][1-b]+L[ind[2]][1-c]+L[ind[3]][1-d];
                        
                        if(h*w<ans){
                            ans=h*w;
                            S.clear();
                            S.insert(make_pair(min(h,w),max(h,w)));
                        }else if(h*w==ans) S.insert(make_pair(min(h,w),max(h,w)));
                        
                        h=max(max(L[ind[0]][a],L[ind[1]][b]),L[ind[2]][c])+L[ind[3]][d];
                        w=max(L[ind[0]][1-a]+L[ind[1]][1-b]+L[ind[2]][1-c],L[ind[3]][1-d]);
                        
                        if(h*w<ans){
                            ans=h*w;
                            S.clear();
                            S.insert(make_pair(min(h,w),max(h,w)));
                        }else if(h*w==ans) S.insert(make_pair(min(h,w),max(h,w)));
                        
                        h=max(max(L[ind[0]][a],L[ind[1]][b])+L[ind[2]][c],L[ind[3]][d]);
                        w=max(L[ind[0]][1-a]+L[ind[1]][1-b],L[ind[2]][1-c])+L[ind[3]][1-d];
                        
                        if(h*w<ans){
                            ans=h*w;
                            S.clear();
                            S.insert(make_pair(min(h,w),max(h,w)));
                        }else if(h*w==ans) S.insert(make_pair(min(h,w),max(h,w)));
                        
                        h=max(L[ind[0]][a],max(L[ind[1]][b]+L[ind[2]][c],L[ind[3]][d]));
                        w=L[ind[0]][1-a]+max(L[ind[1]][1-b],L[ind[2]][1-c])+L[ind[3]][1-d];
                        
                        if(h*w<ans){
                            ans=h*w;
                            S.clear();
                            S.insert(make_pair(min(h,w),max(h,w)));
                        }else if(h*w==ans) S.insert(make_pair(min(h,w),max(h,w)));
                        
                        h=max(L[ind[0]][a]+L[ind[1]][b],L[ind[2]][c]+L[ind[3]][d]);
                        w=max(L[ind[0]][1-a]+L[ind[2]][1-c],L[ind[1]][1-b]+L[ind[3]][1-d]);
                        if((L[ind[0]][1-a]>w-L[ind[3]][1-d] && L[ind[0]][a]>h-L[ind[3]][d]) || (L[ind[1]][1-b]>w-L[ind[2]][1-c] && L[ind[1]][b]>h-L[ind[2]][c])){
                            w=max(w,L[ind[0]][1-a]+L[ind[3]][1-d]);
                            w=max(w,L[ind[2]][1-c]+L[ind[1]][1-b]);
                        }
                        
                        if(h*w<ans){
                            ans=h*w;
                            S.clear();
                            S.insert(make_pair(min(h,w),max(h,w)));
                        }else if(h*w==ans) S.insert(make_pair(min(h,w),max(h,w)));
                    }
                }
            }
        }
    }while(next_permutation(ind,ind+4));
    
    printf("%d\n",ans);
    
    set< pair<int, int> > :: iterator it;
    
    for(it=S.begin();it!=S.end();it++) printf("%d %d\n",(*it).first,(*it).second);
    
    return 0;
}
