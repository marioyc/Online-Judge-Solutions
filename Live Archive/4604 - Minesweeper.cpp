#include <iostream>
#include <string>

using namespace std;

int main(){
    int R,C,ans[100][100];
    int dr[] = {-1,-1,-1,1,1,1,0,0};
    int dc[] = {-1,0,1,-1,0,1,-1,1};
    string M[100];
    
    while(true){
    	cin>>R>>C;
    	if(R==0 || C==0) break;
    	
    	for(int i = 0;i<R;++i) cin>>M[i];
    	
    	for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
    	    ans[i][j] = 0;
    	    
    	    for(int k = 0;k<8;++k){
    	    	int r2 = i+dr[k];
    	    	int c2 = j+dc[k];
    	    	
    	    	if(r2>=0 && r2<R && c2>=0 && c2<C && M[r2][c2]=='*')
    	    	    ++ans[i][j];
    	    }
    	}
    	
    	for(int i = 0;i<R;++i){
    	    for(int j = 0;j<C;++j)
    	    	if(M[i][j]=='*') cout<<"*";
    	    	else cout<<ans[i][j];
    	    cout<<endl;
    	}
    }
    
    return 0;
}