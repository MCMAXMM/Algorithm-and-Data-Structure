#ifndef SORT_H_
#define SORT_H_
#endif
#include<vector>
#include<algorithm> 
using namespace std;

void bubble_sort(vector<int> &b){
	int size=b.size();
	for(int i=size-1;i>0;i--){
		bool flag=false;
		for(int j=0;j+1<=i;j++){
			if(b[j]>b[j+1]){
			
			swap(b[j],b[j+1]);
			flag=true;
			}
		}
		if(!flag)
		break;
	}
}
void selective_sort(vector<int> &b){
	int size =b.size();
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++)
		if(b[j]<b[i])
		swap(b[i],b[j]);
	}
	}
void insertion_sort(vector<int> &b){
	int size=b.size();
	for(int i=1;i<size;i++)
	{
		int t=b[i],j;
		for(j=i-1;j>=0;j--)
		{
			if(b[j]>t)
				b[j+1]=b[j];
			else
				break;
		}
		b[j]=t;
	}
}

void merge_sort(vector<int> &q,int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	merge_sort(q,l,mid);
	merge_sort(q,mid+1,r);
	static vector<int> w;
	w.clear();
	//归并部分
	//主要有两个条件一是自底向上还是自上而下， 二是使用链表还是数组，所以总共有四种情况 
	//本模型使用的是递归的自上而下，和数组。 
	int i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(q[i]<=q[j])
			w.push_back(q[i++]);
		else
			w.push_back(q[j++]);
	}
	while(i<=mid)
	w.push_back(q[i++]);
	while(j<=r)
	w.push_back(q[j++]);
	
	for(i=l,j=0;j<w.size();i++,j++)
	q[i]=w[j];	
}

void quick_sort(vector<int> &q,int l,int r){
	if(l>=r)return;
	int i=l-1,j=r+1,x=q[l+r>>1];
	while(i<j){
		do j--;while(q[j]>x);
		do i++;while(q[i]<x);
		if(i<j) swap(q[i],q[j]);
		else
		quick_sort(q,l,j),quick_sort(q,j+1,r);
	}
}
void push_down(vector<int> &heap,int size,int u){
	int t=u,left=u*2,right=u*2+1;
	if(left<=size&&heap[left]>heap[t]) t=left;
	if(right<=size&&heap[right]>heap[t]) t=right;
	if(t!=u){
		swap(heap[u],heap[t]);
		push_down(heap,size,t);
	}
}
//这里的u为index 
void push_up(vector<int> &heap,int u){
	while(u/2&&heap[u/2]<heap[u]){
		swap(heap[u/2],heap[u]);
		u/=2;
	}
}

void remove_top(vector<int> &heap,int &size){
	heap[1]=heap[size];
	size--;
	push_down(heap,size,1);
}
void heap_sort(vector<int> &q,int n){
	int size=n;
	for(int i=1;i<=n;i++)
	push_up(q,i);
	for(int i=1;i<=n;i++){
		swap(q[1],q[size]);
		size--;
		push_down(q,size,1);
	}
}
void counting_sort(vector<int> &q,int n){
	//数据在0-101之间，线性的排序算法 
	vector<int> cnt(101,0);
	for(int i=1;i<=n;i++)
	cnt[q[i]]++;
	for(int i=1,k=1;i<=100;i++){
		while(cnt[i]){
			q[k++]=i;
			cnt[i]--;
		}
	}
}
int get(int x,int i){
	while(i--) x/=10;
	return x%10;
}
void radix_sort(vector<int> &q,int n){
	vector<vector<int>> cnt(10);
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++)
			cnt[j].clear();
		
		for(int j=1;j<=n;j++)
			cnt[get(q[j],i)].push_back(q[j]);
			
		for(int j=0,k=1;j<10;j++){
			for(int x:cnt[j])
				q[k++]=x;
		}
	}
}
