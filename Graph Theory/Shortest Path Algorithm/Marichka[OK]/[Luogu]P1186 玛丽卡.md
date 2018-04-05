# [[Luogu]P1186 玛丽卡](https://www.luogu.org/problemnew/show/P1186)

## 题目描述

麦克找了个新女朋友，玛丽卡对他非常恼火并伺机报复。

因为她和他们不住在同一个城市，因此她开始准备她的长途旅行。

在这个国家中每两个城市之间最多只有一条路相通，并且我们知道从一个城市到另一个城市路上所需花费的时间。

麦克在车中无意中听到有一条路正在维修，并且那儿正堵车，但没听清楚到底是哪一条路。无论哪一条路正在维修，从玛丽卡所在的城市都能到达麦克所在的城市。

玛丽卡将只从不堵车的路上通过，并且她将按最短路线行车。麦克希望知道在最糟糕的情况下玛丽卡到达他所在的城市需要多长时间，这样他就能保证他的女朋友离开该城市足够远。

编写程序，帮助麦克找出玛丽卡按最短路线通过不堵车道路到达他所在城市所需的最长时间(用分钟表示)。

## 输入输出格式

输入格式：

第一行有两个用空格隔开的数N和M，分别表示城市的数量以及城市间道路的数量。1≤N≤1000，1≤M≤N*(N-1)/2。城市用数字1至N标识，麦克在城市1中，玛丽卡在城市N中。

接下来的M行中每行包含三个用空格隔开的数A，B和V。其中1≤A，B≤N，1≤V≤1000。这些数字表示在A和城市B中间有一条双行道，并且在V分钟内是就能通过。

输出格式：

输出文件的第一行中写出用分钟表示的最长时间，在这段时间中，无论哪条路在堵车，玛丽卡应该能够到达麦克处，如果少于这个时间的话，则必定存在一条路，该条路一旦堵车，玛丽卡就不能够赶到麦克处。

## 输入输出样例

输入样例#1：

```
5 7
1 2 8
1 4 10
2 3 9
2 4 10
2 5 1
3 4 7
3 5 10

```

输出样例#1：

```
27
```
## 题解

- 因为**她将按最短路线行车。**，所以很容易看出这是让我们求单源最短路，但是**玛丽卡将只从不堵车的路上通过**······

- 也就说在图内有一条边不能走，但是**当这条边不在最短路的路径上时，这条边显然对答案无影响**，所以我们要求的是在最短路的路径上任意一条边不能走时都能通过的时间，即任意一条边不能走后所用时间小于等于的时间

- 让我们换一种描述方法，存在一张图，求1到N的最短路，但是这条最短路上有一条边不能走，求任意一条边不能走后所用时间小于等于的时间

- 我们可以暴力枚举删去每一条边，在不停的跑最短路，但是我们已经知道**不在最短路的路径上的条边对答案无影响**，所以我们可以先跑一遍最短路，再枚删去举**最短路的路径**上的每一条边，再跑一边最短路，取最大的即可

- 顺便注意一下**双向边**


## 代码

```c++
#include <algorithm> 
#include <cstdio>
#include <cstring>

const int MaxnVertex = 1000 + 5;
const int MaxnEdge = 999000 + 5;
const int MaxnLenth = (int)1e9 + 7;

int Cnt;
int Head[MaxnVertex];
struct edge{
    int Vertex;
    int Next;
    int Value;
}Edge[MaxnEdge];

int H,T;
int Queue[MaxnEdge];
bool Visited[MaxnVertex];
int Dis[MaxnVertex];
int Flag;
int Prv[MaxnEdge];
int Cut[MaxnVertex][MaxnVertex];

int N,M;
int Ans = -MaxnLenth;

int Add(int From,int To,int Value){
	Edge[++ Cnt].Next = Head[From];
	Edge[Cnt].Vertex = To;
	Edge[Cnt].Value = Value;
	Head[From] = Cnt;
}

void Read(){
	int Tmp_From,Tmp_To,Tmp_Value;
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= M;++ i){
		scanf("%d%d%d",&Tmp_From,&Tmp_To,&Tmp_Value);
		Add(Tmp_From,Tmp_To,Tmp_Value);
		Add(Tmp_To,Tmp_From,Tmp_Value);
	}
}


void SPFA(){
	H = 0;
	T = 1;
	memset(Queue,0,sizeof(Queue));
	memset(Visited,0,sizeof(Visited));
	for(int i = 1;i <= N;++ i)
		Dis[i] = MaxnLenth;
	Dis[1] = 0;
	Visited[1] = 1;
	Queue[T] = 1;
	while(H < T){
		++ H;
		Visited[Queue[H]] = 0;
		for(int i = Head[Queue[H]];i;i = Edge[i].Next){
			if(!Cut[Queue[H]][Edge[i].Vertex] && Dis[Edge[i].Vertex] > Dis[Queue[H]] + Edge[i].Value){
				if(!Flag)
					Prv[Edge[i].Vertex] = Queue[H];
				Dis[Edge[i].Vertex] = Dis[Queue[H]] + Edge[i].Value;
				if(!Visited[Edge[i].Vertex]){
					Queue[++ T] = Edge[i].Vertex;
					Visited[Edge[i].Vertex] = 1;
				}
			}
		}
	}
}

void Solve(){
	SPFA();
	Flag = 1;
	for(int i = N;i;i = Prv[i]){
		Cut[Prv[i]][i] = 1;
		Cut[i][Prv[i]] = 1;
		SPFA();
		Cut[Prv[i]][i] = 0;
		Cut[i][Prv[i]] = 0;
		Ans = std::max(Ans,Dis[N]);
	}
	printf("%d",Ans);
}

int main(){
	Read();
	Solve();
	return 0;
}
```

