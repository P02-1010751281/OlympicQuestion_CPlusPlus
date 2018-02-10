#include<bits/stdc++.h>

using namespace std;

struct Heap{
	int heap[10010],size;
	Heap(){
		size=0;
	}
	void push(int x){
		heap[++size]=x;
		int i=size,k;
		while(i>1){
			k=i>>1;
			if(heap[k]<=heap[i]) return;
			swap(heap[k],heap[i]);
			i=k;
		}
		return;
	}
	int pop(){
		int ans=heap[1];heap[1]=heap[size--];
		int	i=1,k;
		while(i<<1<=size){
			k=i<<1;
			if(k<size&&heap[k]>heap[k|1]) k|=1;
			if(heap[i]<=heap[k]) return ans;
			swap(heap[i],heap[k]);
			i=k;
		}
		return ans;
	}
};
int main(){
	int n,hj;
	scanf("%d",&n); 
	Heap h;
	for(int i=0;i<n;i++){
		scanf("%d",&hj);
		h.push(hj);
	}
	for(int i=0;i<n;i++)
		printf("%d ",h.pop());
	return 0;
	
}
