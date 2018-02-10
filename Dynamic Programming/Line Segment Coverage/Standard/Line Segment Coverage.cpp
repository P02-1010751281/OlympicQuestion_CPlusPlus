#include <algorithm>
#include <cstdio>
#include <iostream>

const int Maxn = 10000 + 5;

struct line{
	int LeftPoint;
	int RightPoint;
	int TotalNumber;
}Line[Maxn];

int Number,Sum[Maxn];

bool CompRightPoint(line x,line y){
	return x.RightPoint == y.RightPoint ? x.LeftPoint < y.LeftPoint : x.RightPoint < y.RightPoint;
}

int Dp(){
	int Ans = 0;
	std::sort(Line + 1,Line + Number + 1,CompRightPoint);
	for(int i = 1;i <= Number;i++){
		int Max = 0;
		for(int j = 1;j < i;j++) {
			if(Line[j].RightPoint <= Line[i].LeftPoint)
				Max = std::max(Line[j].TotalNumber,Max);
		}
		Line[i].TotalNumber = Max + 1;
		Ans = std::max(Ans,Line[i].TotalNumber);
	}
	return Ans;
}

void Read(){
	scanf("%d",&Number);
	for(int i = 1;i <= Number;i++){
		int TmpPoint_1,TmpPoint_2;
		scanf("%d%d",&TmpPoint_1,&TmpPoint_2);
		Line[i].LeftPoint = std::min(TmpPoint_1,TmpPoint_2);
		Line[i].RightPoint = std::max(TmpPoint_1,TmpPoint_2);
	}
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}

