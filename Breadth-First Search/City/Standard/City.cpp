#include <cstdio>

struct queue{
	int Front;
	int Mine;
}Queue[64];

bool Used[8];

int Map[8][8];

void Print(int Now){
	printf("%c ",Queue[Now].Mine + 'A');
	while(Queue[Now = Queue[Now].Front].Front != -1) printf("%c ",Queue[Now].Mine + 'A');
	printf("%c",Queue[Now].Mine + 'A');
}

void Bfs(int Start,int End){
	int Head = 0,Tail = 1;
	Queue[Tail].Front = -1;
	Queue[Tail].Mine = Start;
	Used[Start] = 1;
	do{
		Head++;
		for(int i = 0;i < 8;i++){
			if(!Map[Queue[Head].Mine][i] && !Used[i]){
				Queue[++Tail].Mine = i;
				Queue[Tail].Front = Head;
				Used[i] = 1;
				if(i == End){
					Print(Tail);
					Head = Tail;
					break;
				}
			}
		}
	}while(Head < Tail);
}

int main(){
	freopen("in.txt","r",stdin);
	int Strat,End;
	scanf("%d%d",&Strat,&End);
	for(int i = 0;i < 8;i++) for(int j = 0;j < 8;j++) scanf("%d",&Map[i][j]);
	Bfs(Strat,End);
	return 0;
}
