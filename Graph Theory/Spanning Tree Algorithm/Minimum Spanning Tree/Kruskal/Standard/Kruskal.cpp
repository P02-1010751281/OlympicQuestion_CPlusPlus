#include <algorithm>
#include <cstdio>

const int MaxnNode = 50000 + 5;
const int MaxnEdge = 2000000 + 5;

struct Point{
	int X;
	int Y;
	int EdgeLenth;
}Node[MaxnEdge];
struct set{
	int Father;
	int SonNumber;
}Set[MaxnNode];
int CntEdge,TreeLenth;

int N,M;

void Read(){
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= M;++ i)
		scanf("%d%d%d",&Node[i].X,&Node[i].Y,&Node[i].EdgeLenth);
}

int GetFather(int X){
	return Set[X].Father != X ? Set[X].Father = GetFather(Set[X].Father) : Set[X].Father;
}

void Union(int X,int Y){
	int XFather = GetFather(X);
	int YFather = GetFather(Y);
	if(Set[XFather].SonNumber >= Set[YFather].SonNumber){
		Set[YFather].Father = XFather;
		Set[XFather].SonNumber += Set[YFather].SonNumber + 1;
	} else {
		Set[XFather].Father = YFather;
		Set[YFather].SonNumber += Set[XFather].SonNumber + 1;
	}
}

bool Comp(Point X,Point Y){
	return X.EdgeLenth < Y.EdgeLenth;
}

void Solve(){
	for(int i = 1;i <= N;++ i)
		Set[i].Father = i;
	std::sort(Node + 1,Node + M + 1,Comp);
	for(int i = 1;i <= M;++ i){
		if(GetFather(Node[i].X) != GetFather(Node[i].Y)){
			Union(Node[i].X,Node[i].Y);
			TreeLenth += Node[i].EdgeLenth;
			++ CntEdge;
		}
		if(CntEdge == N - 1) 
				break;
	}
}

int main(){
	Read();
	Solve();
	printf("%d",TreeLenth);
	return 0;
}
