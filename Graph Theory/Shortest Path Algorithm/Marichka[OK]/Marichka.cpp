#include <algorithm> 
#include <cstdio>
#include <cstring>

const int MaxnVertex = 1000 + 5;
const int MaxnEdge = 999000 + 5;
const int MaxnLenth = (int)1e9 + 7;

int Cnt;
int Head[MaxnVertex];
struct edge{
    int Vertex;
    int Next;
    int Value;
}Edge[MaxnEdge];

int H,T;
int Queue[MaxnEdge];
bool Visited[MaxnVertex];
int Dis[MaxnVertex];
int Flag;
int Prv[MaxnEdge];
int Cut[MaxnVertex][MaxnVertex];

int N,M;
int Ans = -MaxnLenth;

int Add(int From,int To,int Value){
	Edge[++ Cnt].Next = Head[From];
	Edge[Cnt].Vertex = To;
	Edge[Cnt].Value = Value;
	Head[From] = Cnt;
}

void Read(){
	int Tmp_From,Tmp_To,Tmp_Value;
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= M;++ i){
		scanf("%d%d%d",&Tmp_From,&Tmp_To,&Tmp_Value);
		Add(Tmp_From,Tmp_To,Tmp_Value);
		Add(Tmp_To,Tmp_From,Tmp_Value);
	}
}


void SPFA(){
	H = 0;
	T = 1;
	memset(Queue,0,sizeof(Queue));
	memset(Visited,0,sizeof(Visited));
	for(int i = 1;i <= N;++ i)
		Dis[i] = MaxnLenth;
	Dis[1] = 0;
	Visited[1] = 1;
	Queue[T] = 1;
	while(H < T){
		++ H;
		Visited[Queue[H]] = 0;
		for(int i = Head[Queue[H]];i;i = Edge[i].Next){
			if(!Cut[Queue[H]][Edge[i].Vertex] && Dis[Edge[i].Vertex] > Dis[Queue[H]] + Edge[i].Value){
				if(!Flag)
					Prv[Edge[i].Vertex] = Queue[H];
				Dis[Edge[i].Vertex] = Dis[Queue[H]] + Edge[i].Value;
				if(!Visited[Edge[i].Vertex]){
					Queue[++ T] = Edge[i].Vertex;
					Visited[Edge[i].Vertex] = 1;
				}
			}
		}
	}
}

void Solve(){
	SPFA();
	Flag = 1;
	for(int i = N;i;i = Prv[i]){
		Cut[Prv[i]][i] = 1;
		Cut[i][Prv[i]] = 1;
		SPFA();
		Cut[Prv[i]][i] = 0;
		Cut[i][Prv[i]] = 0;
		Ans = std::max(Ans,Dis[N]);
	}
	printf("%d",Ans);
}

int main(){
	Read();
	Solve();
	return 0;
}
