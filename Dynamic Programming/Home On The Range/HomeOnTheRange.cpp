#include <algorithm>
#include <cctype>
#include <cstdio>

const int Maxn = 250 + 5;

int N;
int Martix[Maxn][Maxn];
int Equation[Maxn][Maxn];
int Sum[Maxn];

int SpecialRead(){
    char Tmp;
    Tmp = getchar();
    while(!isdigit(Tmp))
        Tmp = getchar();
    return Tmp - '0';
}

void Read(){
    scanf("%d",&N);
    for(int i = 1;i <= N;++ i)
        for(int j = 1;j <= N;++ j)
            Martix[i][j] = SpecialRead();
}

void Prepare(){
    for(int i = 1;i <= N;++ i){
        Equation[1][i] = Martix[1][i];
        Equation[i][1] = Martix[i][1];
    }
}

void Dp(){
    for(int i = 2;i <= N;++ i){
        for(int j = 2;j <= N;++ j){
            if(Martix[i][j]){
                Equation[i][j] = std::min(Equation[i - 1][j],Equation[i][j - 1]);
                Equation[i][j] = std::min(Equation[i][j],Equation[i - 1][j - 1]);
                ++ Equation[i][j];
                ++ Sum[Equation[i][j]];
            }
        }
    }
    for(int i = N;i;-- i)
       Sum[i - 1] += Sum[i];
}

void Print(){
    for(int i = 2;i <= N;++ i)
        if(Sum[i])
            printf("%d %d\n",i,Sum[i]);
}

int main(){
    Read();
    Prepare();
    Dp();
    Print();
    return 0;
}
