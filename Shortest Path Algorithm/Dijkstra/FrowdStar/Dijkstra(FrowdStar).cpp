#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxnNode = 10000 + 5;
const int MaxnEdge = 500000 + 5;

int Cnt;
int Head[MaxnNode];
struct edge{
	int Next;
	int Node;
	int Lenth;
}Edge[MaxnEdge];

bool Visited[MaxnNode];
int Dis[MaxnNode];

int N,M,S;

void Add(int From,int To,int Lenth){
	Edge[++ Cnt].Next = Head[From];
	Edge[Cnt].Node = To;
	Edge[Cnt].Lenth = Lenth;
	Head[From] = Cnt; 
}

int FindNearest(){
	int Point = 0,MinLenth = 1e9+7;
	for(int i = 1;i <= N;i++){
		if(Dis[i] < MinLenth && !Visited[i]){
			Point = i;
			MinLenth = Dis[i];
 		}
	}
	return Point;
}

void UpDataDis(int Begin,int TranslateNode){
	int To;
	for(int Vertex = Head[TranslateNode];Vertex;Vertex = Edge[Vertex].Next){
		To = Edge[Vertex].Node;
		if(Dis[To] > Dis[TranslateNode] + Edge[Vertex].Lenth)
			Dis[To] = Dis[TranslateNode] + Edge[Vertex].Lenth;
	}
}

void Dijkstra(int Begin){
//	memset(Dis,0x7f,sizeof(Dis));
	for(int i = 1;i <= N;++ i)
		Dis[i] = (int)1e9 + 7;
	Dis[Begin] = 0;
	int TranslateNode;
	for(int i = 1;i <= N;++ i){
		TranslateNode = FindNearest();
		if(!TranslateNode) return ;
		Visited[TranslateNode] = 1;
		UpDataDis(Begin,TranslateNode);
	}
}


void Read(){
	scanf("%d%d%d",&N,&M,&S);
	int From,To,Lenth;
	for(int i = 1;i <= M;++ i){
		scanf("%d%d%d",&From,&To,&Lenth);
		Add(From,To,Lenth);
	}
}

void Print(){
	for(int i = 1;i <= N;++ i)
		if(Dis[i] == (int)1e9 + 7) printf("2147483647 ");
		else printf("%d ",Dis[i]);
}

int main(){
	Read();
	Dijkstra(S);
	Print();
	return 0;
}
