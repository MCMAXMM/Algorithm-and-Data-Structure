#include<vector>
#include<iostream>
#include<algorithm>
#include"sort.h"
using namespace  std;


int main(){
//	vector<int> a ;
//	int number;
//	cin>>number;
//	for(int i=0;i<number;i++)
//		{
//			int tmp;
//			cin>>tmp;
//			a.push_back(tmp);
//		}
//	//bubble_sort(a);
//	//selective_sort(a);
//	//insertion_sort(a);
//	//merge_sort(a,0,a.size()-1);
//	quick_sort(a,0,a.size()-1);
//	for(int i:a){
//		cout<<i<<" ";}


	vector<int> q;
	int n;
	cin>>n;
	q.resize(n+1);
	for(int i=1;i<=n;i++)cin>>q[i];
	//counting_sort(q,n);
	radix_sort(q,n);
	for(int i=1;i<q.size();i++)
	cout<<q[i]<<" "; 
	return 0;
return 0;
}
