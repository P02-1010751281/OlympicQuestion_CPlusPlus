#include <cstdio>

struct Free{
	int Line;
	int List;
};

int Map[9][9],Tail = 0;

bool Line[9][10],List[9][10],/*ObliqueR[18][9],ObliqueL[18][9],*/Matrix[3][3][10];

Free Queue[81];

void Read(){
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			scanf("%d",&Map[i][j]);
			if (!Map[i][j]){
				Queue[Tail].Line = i;
				Queue[Tail++].List = j;
			} else {
				Line[i][Map[i][j]] = 1;
				List[j][Map[i][j]] = 1;
				Matrix[i/3][j/3][Map[i][j]] = 1;
			}
		}
	}
	/*for(int i = 0;i < 9;i++){
		for(int j = 0;j < 8;j+=2){
			scanf("%d%d",&Map[i][j],&Map[i][j+1]);
			if (!Map[i][j]){
				Queue[Tail].Line = i;
				Queue[Tail++].List = j;
			} else {
				Line[i][Map[i][j]] = 1;
				List[j][Map[i][j]] = 1;
				Matrix[i/3][j/3][Map[i][j]] = 1;
			}
			if (!Map[i][j+1]){
				Queue[Tail].Line = i;
				Queue[Tail++].List = j+1;
			} else {
				Line[i][Map[i][j+1]] = 1;
				List[j][Map[i][j+1]] = 1;
				Matrix[i/3][(j+1)/3][Map[i][j+1]] = 1;
			}
		}
		scanf("%d",&Map[i][8]);
		if (!Map[i][8]){
			Queue[Tail].Line = i;
			Queue[Tail++].List = 8;
		} else {
			Line[i][Map[i][8]] = 1;
			List[8][Map[i][8]] = 1;
			Matrix[i/3][2][Map[i][8]] = 1;
		}
	}*/
}

void Print(){
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 8;j++)
			printf("%d ",Map[i][j]);
		printf("%d\n",Map[i][8]);
	}
}

void Dfs(int Head){
//	printf("%d\n",Head);
	if(Head < Tail){
		for(int i = 1;i <= 9;i++){
			if ((!Line[Queue[Head].Line][i]) && (!List[Queue[Head].List][i]) && (!Matrix[Queue[Head].Line/3][Queue[Head].List/3][i])){
				Map[Queue[Head].Line][Queue[Head].List] = i;
				Line[Queue[Head].Line][i] = 1;
				List[Queue[Head].List][i] = 1;
				Matrix[Queue[Head].Line/3][Queue[Head].List/3][i] = 1;
				Dfs(Head+1);
				Map[Queue[Head].Line][Queue[Head].List] = 0;
				Line[Queue[Head].Line][i] = 0;
				List[Queue[Head].List][i] = 0;
				Matrix[Queue[Head].Line/3][Queue[Head].List/3][i] = 0;
			}
		}
	}else Print();
}

int main(){
	Read();
//	printf("\n%d\n",Map[0][0]);
	Dfs(0);
//	Print();
//	printf("\n%d",Map[0][0]);
	return 0;
}
