#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct point{
    int x,y;
    
    point(){}
    
    point(int _x, int _y){
        x = _x; y = _y;
    }
    
    void read(){
        cin>>x>>y;
    }
    
    double dist(point P){
    	return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
    }
}P[1002];

int main(){
    int N,pen[1002],sum[1002];
    double dp[1002];
    
    P[0] = point(0,0);
    pen[0] = 0;
    
    while(true){
    	cin>>N;
    	if(N==0) break;
    	
    	for(int i = 1;i<=N;++i){
    	    P[i].read();
    	    cin>>pen[i];
    	}
    	
    	P[N+1] = point(100,100);
    	pen[N+1] = 0;
    	
    	sum[0] = 0;
    	for(int i = 1;i<=N+1;++i)
    	    sum[i] = sum[i-1]+pen[i];
    	
    	dp[0] = 0;
    	
    	for(int i = 1;i<=N+1;++i){
    	    dp[i] = dp[i-1]+P[i].dist(P[i-1])+1;
    	    
    	    for(int j = 0;j+1<i;++j)
    	    	dp[i] = min(dp[i],dp[j]+P[i].dist(P[j])+sum[i-1]-sum[j]+1);
    	}
    	
    	printf("%.3lf\n",dp[N+1]);
    }
    
    return 0;
}
