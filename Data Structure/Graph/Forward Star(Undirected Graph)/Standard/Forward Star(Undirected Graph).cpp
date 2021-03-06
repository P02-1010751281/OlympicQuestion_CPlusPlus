#include <cstdio>

const int Maxn = 10000 + 5;

struct edge{
	int Next;
	int Node;
}Edge[(Maxn * Maxn - 2 * Maxn + 1) + 5];

int Head[Maxn],Cnt;
int VertexNumber;

void Add(int From,int To){
	Edge[++ Cnt].Next = Head[From];
	Head[From] = Cnt;
	Edge[Cnt].Node = To;
	Edge[++ Cnt].Next = Head[To];
	Head[To] = Cnt;
	Edge[Cnt].Node = From;
}

void ErgodicVertex(int From){
	for(int Vertex = Head[From];Vertex;Vertex = Edge[Vertex].Next){
		if(Edge[Vertex].Next) 
			printf("%d ",Edge[Vertex].Node);
		else
			printf("%d\n",Edge[Vertex].Node);
	}
}

void ErgodicAll(){
	for(int i = 1;i <= VertexNumber;i++){
		ErgodicVertex(i);
	}
}

void Read(){
	int TmpFrom,TmpTo;
	scanf("%d",&VertexNumber)
	while(scanf("%d%d",&TmpFrom,&TmpTo) != EOF)
		Add(TmpFrom,TmpTo);
}

int main(){
	Read();
	ErgodicAll();
	return 0;
}
