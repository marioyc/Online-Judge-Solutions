#include <cstdio>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct node{
	int s1,s2;
	string n;
	
	node(){
	}
	
	node(int _s1, int _s2, string _n){
		s1=_s1; s2=_s2; n=_n;
	}
}aux;

bool done[901][8101];
string ans[901][8101];

void solve(){
	queue<node> Q1,Q2;
	
	Q1.push(node(0,0,""));
	
	int s1,s2;
	
	for(int i=0;i<100;i++){
		while(!Q1.empty()){
			aux=Q1.front();
			Q1.pop();
			
			for(int j=1;j<=9;j++){
				s1=aux.s1+j;
				s2=aux.s2+j*j;
				
				if(!done[s1][s2]){
					done[s1][s2]=true;
					ans[s1][s2]=aux.n+string(1,'0'+j);
					Q2.push(node(s1,s2,ans[s1][s2]));
				}
			}
		}
		
		swap(Q1,Q2);
	}
	
	return;
}

int main(){
	memset(done,false,sizeof(done));
	solve();
	
	int T,s1,s2;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d %d",&s1,&s2);
		if(s1>900 || s2>8100 || !done[s1][s2]) printf("No solution\n");
		else printf("%s\n",ans[s1][s2].c_str());
	}
	
	return 0;
}
