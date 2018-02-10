#include <algorithm>
#include <cstdio>

const int Maxn = 100000;

int Kinds;

struct Activity{
	int Strat;
	int End;
}Activities[Maxn];

bool Comp(Activity A,Activity B){
	return A.End < B.End;
}

int Greedy(){
	std::sort(Activities+1,Activities+Kinds,Comp);
	int EndTime = Activities[1].End,Ans = 1;
	for(int i = 1;i <= Kinds;i++)
		if(EndTime <= Activities[i].Strat){
			Ans++;
			EndTime = Activities[i].End;
		}
	return Ans;
}

int main(){
	scanf("%d",&Kinds);
	for(int i = 1;i <= Kinds;i++) scanf("%d%d",&Activities[i].Strat,&Activities[i].End);
	printf("%d",Greedy());
	return 0;
}
