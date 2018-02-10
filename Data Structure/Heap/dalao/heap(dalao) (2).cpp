#include<bits/stdc++.h>


struct Heap{
	int *heap,size;
	Heap (int num){
		heap=new int [num+1];
		size=0;
		}
	
	void push(int x){
		heap[++size]=x;
		int i=size,k;
		while(i>1){
			k=i>>1;
			if(heap[k]<=heap[i])	return;
			std::swap(heap[k],heap[i]);
			i=k;
		}
		return;
	}
	
	int pop(){
		int ans=heap[1];heap[1]=heap[size--];
		int i=1,k;
		while(i<<1<=size){
			k=i<<1;
			if(k<size&&heap[k]>heap[k|1])	k|=1;
			if(heap[i]<=heap[k])	return ans;
			std::swap(heap[i],heap[k]);
			i=k;
		}
		return ans;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	Heap H(n);
	for(int i=0;i<n;i++){
		int hj;
		 scanf("%d",&hj);
		H.push(hj);
	}
	for(int i=0;i<n;i++)
		printf("%d ",H.pop());
	return 0;
	
}
