#include <algorithm>
#include <cstdio>

const int Maxn = 10000;

int Volume,Number;
int Weight[Maxn];

int Greedy(){
	std::sort(Weight+1,Weight+Number);
	int Left = 1,Right = Number+1,Ans = 0;
	while(Weight[1] + Weight[--Right] > Volume) Ans++;
//	int Middle = (Left + Right)/2;
//	if(Middle & 1) Ans++,Middle--;
//	int Isolated,UnIsolated;
	while(Left < Right){
		Ans++;
		if(Weight[Left] + Weight[Right] > Volume){
			Right--;
//			Isolated++;
		}else{
			Left++;
//			UnIsolated++;
		}
	}
	return Ans;
}

int main(){
	scanf("%d%d",&Volume,&Number);
	for(int i = 1;i <= Number;i++)
		scanf("%d",&Weight[i]);
    printf("%d",Greedy());
    return 0;
}
