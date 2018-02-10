#include <cstdio>

struct Queue{
	int x;
	int y;
};

const int Maxn = 10;
const int Dx[4] = {0,0,-1,1};
const int Dy[4] = {-1,1,0,0};

int Map[Maxn][Maxn];

void BFS(int x,int y){
	int Head = 0,Tail = 1;
	Queue queue[Maxn*Maxn];
	queue[Tail].x = x;
	queue[Tail].y = y;
	do{
		Head++;
		if(Map[queue[Head].x][queue[Head].y] == 0){
			Map[queue[Head].x][queue[Head].y] = 1;
			for(int i = 0;i < 4;i++){
				int Tx = queue[Head].x + Dx[i];
				int Ty = queue[Head].y + Dy[i];
				if(Map[Tx][Ty] == 0 && Tx >= 0 && Tx < 10 && Ty >= 0 && Ty < 10){
					queue[++Tail].x = Tx;
					queue[Tail].y = Ty;
				}
			}
		}
	}while(Head < Tail);
}

int main(){
	int Sum = 0;
	for(int i = 0;i < Maxn;i++) for(int j = 0;j < Maxn;j += 2) scanf("%d%d",&Map[i][j],&Map[i][j+1]);
	BFS(0,0);
	BFS(0,Maxn-1);
	BFS(Maxn-1,0);
	BFS(Maxn-1,Maxn-1);
	for(int i = 0;i < Maxn;i++) for(int j = 0;j < Maxn;j++) if(Map[i][j] == 0) Sum++;
	printf("%d",Sum);
	return 0;
}
