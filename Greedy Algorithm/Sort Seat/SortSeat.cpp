#include <algorithm>
#include <cstdio>

const int MaxnM = 1000 + 5;
const int MaxnN = 2000 + 5;

int M,N,K,L,D;
struct Ans{
	int Position;
	int Sum;
}Line[MaxnM],List[MaxnN];

bool CompSum(Ans X,Ans Y){
	return X.Sum > Y.Sum;
}

bool CompPosition(Ans X,Ans Y){
	return X.Position < Y.Position;
	
}

int main(){
	scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);
	int TmpX_1,TmpY_1,TmpX_2,TmpY_2,TmpP;
	for(int i = 1;i <= D;++ i){
		scanf("%d%d%d%d",&TmpX_1,&TmpY_1,&TmpX_2,&TmpY_2);
		if(TmpX_1 == TmpX_2){
			TmpP = std::min(TmpY_1,TmpY_2);
			++ List[TmpP].Sum;
			List[TmpP].Position = TmpP;
		} else {
			TmpP = std::min(TmpX_1,TmpX_2);
			++ Line[TmpP].Sum;
			Line[TmpP].Position = TmpP;
		}
	}
	std::sort(Line + 1,Line + M + 1,CompSum);
	std::sort(List + 1,List + N + 1,CompSum);
	std::sort(Line + 1,Line + K + 1,CompPosition);
	std::sort(List + 1,List + L + 1,CompPosition);
	//for(int i = 1;i <= K;++ i)
	//	printf("%d ",List[i].Position);
	//printf("\n");
	//for(int i = 1;i <= L;++ i)
	//	printf("%d",Line[i].Position);
	//printf("\n");
	for(int i = 1;i <= K;++ i){
		printf("%d",Line[i].Position);
		if(i == K)
			printf("\n");
		else printf(" ");
	}
	for(int i = 1;i <= L;++ i){
		printf("%d",List[i].Position);
		if(i == L)
			printf("\n");
		else printf(" ");
	}
	return 0;
}
