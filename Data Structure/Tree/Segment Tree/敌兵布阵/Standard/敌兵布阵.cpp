#include <cstdio>

const int Maxn = 50000+10;

int Array[Maxn],Sum[2*Maxn];
int T,N;

void Build(int Identifier,int Left,int Right){
    if(Left == Right) Sum[Identifier] = Array[Left];
    else{
        int Middle = (Left+Right)/2;
        Build(Identifier*2,Left,Middle);
        Build(Identifier*2+1,Middle+1,Right);
        Sum[Identifier] = Sum[Identifier*2]+Sum[Identifier*2+1];
    }
}

void Change(int Identifier,int Left,int Right,int Destination,int Value){
    if(Left == Right) Sum[Identifier] += Value;
    else{
        int Middle = (Left+Right)/2;
        Destination <= Middle ? Change(Identifier*2,Left,Middle,Destination,Value) : Change(Identifier*2+1,Middle+1,Right,Destination,Value);
        Sum[Identifier] = Sum[Identifier*2]+Sum[Identifier*2+1];
    }
}

int Get(int Identifier,int Left,int Right,int ObjectiveLeft,int ObjectiveRight){
    if(Left >= ObjectiveLeft && Right <= ObjectiveRight) return Sum[Identifier];
    if(Left > ObjectiveRight || Right < ObjectiveLeft) return 0;
    int Middle = (Left+Right)/2;
    return Get(Identifier*2,Left,Middle,ObjectiveLeft,ObjectiveRight)+Get(Identifier*2+1,Middle+1,Right,ObjectiveLeft,ObjectiveRight);
}

int main(){
    scanf("%d",&T);
    for(int i = 1;i <= T;i++){
        scanf("%d",&N);
        for(int i = 1;i < N;i+=2) scanf("%d%d",&Array[i],&Array[i+1]);
        if(N&1) scanf("%d",&Array[N]);
        Build(1,1,N);
        while(1){
            char Command;
            int Destination,Value;
            scanf("%s%d%d",&Command,&Destination,&Value);
            switch(Command){
                case 'A' : Change(1,1,N,Destination,Value);
                            break;
                case 'S' : Change(1,1,N,Destination,-Value);
                            break;
                case 'Q' : //printf("%d%d",Destination,Value);
                            printf("%d",Get(1,1,N,Destination,Value));
                            break;
                case 'E' : goto Out;
            }
        }
        Out:;
    }
    return 0;
}