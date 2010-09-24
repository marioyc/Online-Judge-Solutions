#include <cstdio>

using namespace std;

struct Node{
	Node* links[2];
	int ind;
	
	Node(){
		ind = -1;
		links[0] = NULL;
		links[1] = NULL;
	}
};

class Tree{
	public :
	
	Node* root;	
	
	Tree(){
		root = new Node();
	}
	
	void insert(int ind, int num){
		Node *t = root;
		
		for(int i = 21;i>=0;--i){
			int aux = ((num & (1<<i))==0? 0 : 1);
			
			if(t->links[aux]==NULL) t->links[aux] = new Node();
			t = t->links[aux];
			t->ind = ind;
		}
	}
	
	int findBest(int num){
		Node *t = root;
		
		for(int i = 21;i>=0;--i){
			int aux = ((num & (1<<i))==0? 1 : 0);
			
			if(t->links[aux]!=NULL) t = t->links[aux];
			else t = t->links[aux ^ 1];
		}
		
		return t->ind;
	}
};

int main(){
	freopen("xormax.in","r",stdin);
	freopen("xormax.out","w",stdout);	
	
	int N;
	scanf("%d",&N);
	
	int a[N];
	for(int i = 0;i<N;++i) scanf("%d",&a[i]);
	
	int c[N+1];
	c[0] = 0;
	for(int i = 0;i<N;++i) c[i+1] = (c[i] ^ a[i]);
	
	int ans = a[0],s = 1,e = 1;
	Tree* myTree;
	myTree = new Tree();
	myTree->insert(0,0);
	
	for(int i = 1;i<=N;++i){
		int ret = myTree->findBest(c[i]);
		
		if((c[i] ^ c[ret])>ans){
			ans = (c[i] ^ c[ret]);
			s = ret+1;
			e = i;
		}
		
		myTree->insert(i,c[i]);
	}
	
	delete myTree;
	
	printf("%d %d %d\n",ans,s,e);
	
	return 0;
}
