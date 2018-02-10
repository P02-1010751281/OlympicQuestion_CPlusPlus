#include <cstdio>

const int Maxn = 10000;

int N;
int Map[Maxn][Maxn],Ans[Maxn][Maxn];

int Max(int x,int y){
    return x >= y ? x : y;
}

int RememberDfs(int x,int y){
    if(!Ans[x][y]) return (x == N ? Map[x][y] : Ans[x][y] += Max(RememberDfs(x+1,y),RememberDfs(x+1,y+1))+Map[x][y]);
    return Map[x][y];
}

int Dp(int x,int y){
    for(int i = N-1;i >= x;i--)
        for(int j = 1;j <= i;j++)
            Map[i][j] += Max(Map[i+1][j],Map[i+1][j+1]);
    return Map[x][y];
}

int main(){
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= i;j++)
            scanf("%d",&Map[i][j]);
    printf("%d",RememberDfs(1,1));
    printf("%d",Dp(1,1));
    return 0;
}