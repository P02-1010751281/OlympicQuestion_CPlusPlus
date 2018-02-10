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
	return x.RightPoint == y.RightPoint ? x.LeftPoint > y.LeftPoint : x.RightPoint < y.RightPoint;
}

int Greedy(){
	int Ans = 0,MaxRightPoint = -1e9+7;
	std::sort(Line + 1,Line + Number + 1,CompRightPoint);
	for(int i = 1;i <= Number;i++){
		if(Line[i].LeftPoint >= MaxRightPoint){
			Ans++;
			MaxRightPoint = Line[i].RightPoint;
		}
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
	printf("%d",Greedy());
	return 0;
}
