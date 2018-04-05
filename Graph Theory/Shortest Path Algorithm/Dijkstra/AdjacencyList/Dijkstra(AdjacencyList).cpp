#include <cstdio>
#include <cstring>

const int Maxn = 1000;

bool Used[Maxn];

int Large,Lenth;
int Atlas[Maxn][Maxn];
int Dis[Maxn];

void ReadAtlas(){
	for(int i = 1;i <= Large;i++){
		for(int j = 1;j <= Large;j++){
			int Tmp;
			scanf("%d",&Tmp);
			Atlas[i][j] = Tmp ? Tmp : (int)1e9+7;
		}
	}
}

void PrepareDijkstra(int Begin){
	for(int i = 1;i <= Large;i++)
		Dis[i] = Atlas[Begin][i];
	Dis[Begin] = 0;
}

int FindNearest(){
	int Point = 0,MinLenth = 1e9+7;
	for(int i = 1;i <= Large;i++){
		if(Dis[i] < MinLenth && !Used[i]){
			Point = i;
			MinLenth = Dis[i];
 		}
	}
	return Point;
}

int Min(int X,int Y){
	return X <= Y ? X : Y;
}

void UpdateDis(int Begin,int TransferPoint){
	Used[TransferPoint] = 1;
	for(int i = 1;i <= Large;i++)
		Dis[i] = Min(Dis[i],Atlas[Begin][TransferPoint] + Atlas[TransferPoint][i]);
}

void Dijkstra(int Begin){
	PrepareDijkstra(Begin);
	register int TransferPoint;
	for(int i = 1;i <= Large;i++){
		TransferPoint = FindNearest();
		if(!TransferPoint) return ;
		UpdateDis(Begin,TransferPoint);
	}
}

/*void Prepare(){
	memset(Atlas,0x7f,sizeof(Atlas));
	for(int i = 1;i <= Large;i++)
		Atlas[i][i] = 0;
}
*/

int main(){
	int Begin,End;
	scanf("%d",&Large);
	ReadAtlas();
	scanf("%d%d",&Begin,&End);
	Dijkstra(Begin);
	printf("%d",Dis[End]);
	return 0;
}
