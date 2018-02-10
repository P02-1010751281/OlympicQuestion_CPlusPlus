#include <cstdio>

const int Maxn = 9 + 5;

struct alphabet{
	int Identifier[2];
	int Number;
};

alphabet Map[26 + 5];
char AMap[Maxn];
alphabet Matrix[Maxn][Maxn];
int Total;

bool Used[9 + 5],Print;
int NumberOfFound;

bool Check(){
	for(int i = 1;i < Total;++ i){
		for(int j = 1;j <= i;++ j){
			int Tmp_0 = (Map[AMap[i] - 'A'].Number + Map[AMap[j] - 'A'].Number) % (Total - 1);
			int Tmp_1 = (Map[AMap[i] - 'A'].Number + Map[AMap[j] - 'A'].Number) / (Total - 1);
			if(Matrix[i][j].Identifier[1]){
				if(!Tmp_1) 
					return false;
				if(Tmp_1 != Map[AMap[Matrix[i][j].Identifier[1]] - 'A'].Number || Tmp_0 != Map[AMap[Matrix[i][j].Identifier[0]] - 'A'].Number)
					return false;
			} else {
				if(Tmp_0 != Map[AMap[Matrix[i][j].Identifier[0]] - 'A'].Number)
					return false;
				if(Tmp_1)
					return false;
			}
		}
	}
	return true;
}

bool DFS(int x){
	if(x == Total)	{
		if(Check()){
			for(int i = 1;i < Total - 1;++ i){
				printf("%c=%d ",AMap[i],Map[AMap[i] - 'A'].Number);
			}
			printf("%c=%d\n",AMap[Total - 1],Map[AMap[Total - 1] - 'A'].Number);
			printf("%d",Total - 1);
			return true;
		}
	} else {
		for(int i = 0;i < Total;++ i){
			if(!Used[i]){			
				Used[i] = 1;
				Map[AMap[x] - 'A'].Number = i;
				if(DFS(x + 1)) 
					return true;
				Used[i] = 0;
				Map[AMap[x] - 'A'].Number = 0;
			}
		}
	}
	
	return false;
}

void Read(){
	scanf("%d",&Total);
	char Tmp;
	scanf("%c",&Tmp);
	for(int i = 1;i < Total;++ i){
		scanf("%c",&Tmp);
		while(Tmp < 'A' || Tmp > 'Z')
			scanf("%c",&Tmp);
		Map[Tmp - 'A'].Identifier[0] = i;
		AMap[i] = Tmp;
		Matrix[0][i].Identifier[0] = i;
	}
	for(int i = 1;i < Total;++ i){
		for(int j = 0;j < Total;++ j){
			scanf("%c",&Tmp);
			while(Tmp < 'A' || Tmp > 'Z')
				scanf("%c",&Tmp);
			char Next;
			scanf("%c",&Next);
			if(Next != ' ' && Next != '\n' && Next != '\r'){
				Matrix[i][j].Identifier[1] = Map[Tmp - 'A'].Identifier[0];
				Matrix[i][j].Identifier[0] = Map[Next - 'A'].Identifier[0];
			} else Matrix[i][j].Identifier[0] = Map[Tmp - 'A'].Identifier[0];
		}
	}
}

int main(){
	Read();
	if(!DFS(1)) 
		printf("ERROR!\n");
	return 0;
}
