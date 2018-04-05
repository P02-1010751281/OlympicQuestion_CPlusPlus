#include <cstdio>

bool Used[8];
int Way[64],Queue[64];

int Map[8][8];

void Print(int Start,int End){
//	for(int i = 0;i < 8;i++) printf("%c ",Way[i]+'A');
	printf("%c ",Queue[End] + 'A');
	while(Queue[End = Way[End]] != 0) printf("%c ",Queue[End] + 'A');
	printf("%c",Queue[End]);
}

void Bfs(int Start,int End){
	int Head = 0,Tail = 1;
	Queue[Tail] = Start;
	Way[Tail] = 0;
	Used[Tail] = 1;
	do{
		Head++;
		for(int i = 0;i < 8;i++){
			if(!Map[Queue[Head]][i] && !Used[i]){
				Queue[++Tail] = i;
				Way[Tail] = Head;
				Used[i] = 1;
				if(i == End) {
					Print(Start,End);
					Tail = 0;
					break;
				}
			}
		}
	}while(Head < Tail);
}

int main(){
	int Start,End;
	freopen("in.txt","r",stdin);
	scanf("%d%d",&Start,&End);
	for(int i = 0;i < 8;i++) for(int j = 0;j < 7;j+=2) scanf("%d%d",&Map[i][j],&Map[i][j+1]);
	Bfs(Start,End);
	return 0;
}
