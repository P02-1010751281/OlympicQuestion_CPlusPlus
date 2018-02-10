#include <cstdio>

struct Point{
	int X;
	int Y;
	int Step;
	int S;
};

bool Atlas[7][7];
const int Dx[4] = {0,0,1,-1};
const int Dy[4] = {1,-1,0,0};

int Head = 0,Tail = 1;
int SX,SY,FX,FY,N,M,T;
int Sum,RoadLen;
Point Queue[1000000];

int d(int x, int y){
	return (x - 1) * N + y;
}

void Bfs(){
	do{
		if(Queue[Head].X == FX && Queue[Head].Y == FY) Sum++;
		else{
			for(int i = 0;i < 4;i++){
				int NX = Queue[Head].X + Dx[i],NY = Queue[Head].Y + Dy[i];
				if(NX < 1 || NX > N || NY < 1 || NY > M) continue;
				if(Atlas[NX][NY]) continue;
				if(Queue[Head].S & (1 << d(NX, NY))) continue;
				Queue[Tail].X = NX;
				Queue[Tail].Y = NY;
				Queue[Tail++].S = Queue[Head].S + (1 << d(NX, NY));
			}
		}
		Head++;
	}while(Head < Tail);
}

int main(){
	scanf("%d%d%d",&N,&M,&T);
	scanf("%d%d%d%d",&SX,&SY,&FX,&FY);
	for(int i = 1;i <= T;i++){
		int TX,TY;
		scanf("%d%d",&TX,&TY);
		Atlas[TX][TY] = 1;
	}
	Queue[Head].X = SX;
	Queue[Head].Y = SY;
	Queue[Head].S = 1 << d(SX, SY);
	Bfs();
	for(int i = 0; i < Tail; i++) printf("%d ", Queue[i].S);
	//printf("%d",Sum);
	return 0;
}
