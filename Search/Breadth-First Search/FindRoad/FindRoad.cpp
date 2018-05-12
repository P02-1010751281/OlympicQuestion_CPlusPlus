#include <cctype>
#include <cstdio>
#include <cstring>

const int MaxnNode = 100000 + 5;
const int MaxnEdge = 2000000 + 5;

int Cnt,FCnt;
int Head[MaxnNode],FHead[MaxnNode];
struct edge{
    int Vertex;
    int Next;
}Edge[MaxnEdge],FEdge[MaxnEdge];

int H,T;
int Queue[MaxnNode];
int Ans[MaxnNode];

bool Visited[MaxnNode],Used[MaxnNode],Can[MaxnNode];

int N,M,Begin,End;

void Add(int From,int To){
    Edge[++ Cnt].Vertex = To;
    Edge[Cnt].Next = Head[From];
    Head[From] = Cnt;
}

void FAdd(int From,int To){
    FEdge[++ FCnt].Vertex = To;
    FEdge[FCnt].Next = FHead[From];
    FHead[From] = FCnt;
}

void Read(){
    scanf("%d%d",&N,&M);
    int Tmp_1,Tmp_2;
    for(int i = 1;i <= M;++ i){
        scanf("%d%d",&Tmp_1,&Tmp_2);
        Add(Tmp_1,Tmp_2);
        FAdd(Tmp_2,Tmp_1);
    }
    scanf("%d%d",&Begin,&End);
}

void BFS(int Vertex){
    Queue[++ T] = Vertex;
    Visited[End] = 1;
    while(H < T){
        ++ H;
        for(int i = FHead[Queue[H]];i;i = FEdge[i].Next){
            if(!Visited[FEdge[i].Vertex]){
                Queue[++ T] = FEdge[i].Vertex;
                Visited[FEdge[i].Vertex] = 1;
            }
        }
    }
}

void Delete(){
    for(int i = 1;i <= N;++ i)
        if(!Visited[i])
            for(int j = FHead[i];j;j = FEdge[j].Next)
                Can[FEdge[j].Vertex] = 1;
}

bool Solve(){
    BFS(End);
    if(!Visited[Begin])
        return 0;
    Delete();
    memset(Queue,0,sizeof(Queue));
    H = 0;
    T = 1;
    Queue[T] = Begin;
    Visited[Begin] = 1;
    Used[Begin] = 1;
    while(H < T){
        ++ H;
        for(int i = Head[Queue[H]];i;i = Edge[i].Next){
            if(Visited[Edge[i].Vertex] && !Used[Edge[i].Vertex] && !Can[Edge[i].Vertex]){
                Queue[++ T] = Edge[i].Vertex;
                Ans[Edge[i].Vertex] = Ans[Queue[H]] + 1;
                Used[Edge[i].Vertex] = 1;
            }
        }
    }
    return 1;
}

int main(){
    Read();
    if(Solve())
        printf("%d",Ans[End]);
    else printf("-1");
    return 0;
}
