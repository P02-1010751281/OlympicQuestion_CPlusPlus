#include <cstdio>

const int Maxn = 50005;

int L,N,M;
int Where[Maxn],Times[Maxn];
int Left,Right,Midium;

bool Check(){
    int Sum = 0,Ans = 0;
    for(int i = 1;i <= N;i++){
    	if(Where[i] - Sum < Midium) Ans++;
		else Sum = Where[i];
	}
    return Ans <= M;
}

int main(){
    scanf("%d%d%d",&L,&N,&M);
    for(int i = 1;i <= N;i++) scanf("%d",&Where[i]);
	Right = Where[++N] = L;
    while(Left <= Right){
        Midium = (Left + Right) / 2;
        if(Check()){
        	Left = Midium + 1;
			Times[Left]++;
		} else Right = Midium-1;
    }
    printf("%d",Left-1);
    return 0;
}
