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

int ErgodicVertex(int From){
	int Number = 0;
	for(int Vertex = Head[From];Edge[Vertex].Next;Vertex = Edge[Vertex].Next)
		Number++;
	return Number;
}

int Solve{
	int Ans = 0
	for(int i = 1;i <= VertexNumber;i++)
		Ans = std::max(Ans,VertexNumber - ErgodicVertex(i) + 1);
	return Ans;
}

void Read(){
	int TmpFrom,TmpTo;
	scanf("%d",&VertexNumber)
	while(scanf("%d%d",&TmpFrom,&TmpTo) != EOF)
		Add(TmpFrom,TmpTo);
}

int main(){
	Read();
	printf("%d",Sovle());
	return 0;
}
