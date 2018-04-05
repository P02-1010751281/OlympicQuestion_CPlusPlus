#include <cstdio>

bool List[8],ObliqueR[16],ObliqueL[16];
int Map[8],Total;

void Print(){
    printf("%d:\n",++Total);
    for(int i =0 ;i < 8;i++){
        for(int j = 0;j < 7;j++){
            if(j == Map[i]) printf("1 ");
            else printf("0 ");
        }
        if(Map[i] == 7) printf("1\n");
        else printf("0\n");
    }
}

void Dfs(int x){
    for(int i = 0;i < 8;i++){
        if(!List[i] && !ObliqueR[x-i+7] && !ObliqueL[x+i]){
            Map[x] = i;
            List[i] = 1;
            ObliqueR[x-i+7] = 1;
            ObliqueL[x+i] = 1;
            if(x == 7) Print();
            else Dfs(x+1);
            List[i] = 0;
            ObliqueR[x-i+7] = 0;
            ObliqueL[x+i] = 0;
        }
    }
}

int main(){
    Dfs(0);
    return 0;
}
