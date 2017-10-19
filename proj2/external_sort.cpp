#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ref{ 
int ID;
int current;
int value; 
	bool operator<(ref other) const{
		return value > other.value;
	}
};
//struct for holding the ID of the sub array, Where current holds the current value from the sub array that we are using.

void partition(vector<int>& list, int l, int r) {
	//** The pivot should be the median of the
	//** first, middle, and last element.
	int middle = (l+r)/2;
	int left = list[l];
	int right = list[r];
	int tmp = 0;
		tmp = list[middle];
		list[middle] = list[l];
		list[l] = tmp;
	 tmp = list[middle];
	cout << "middle is "<< tmp << endl;
	list[middle] = list[l];
	list[l] = tmp;
	for (int i = 0; i <= list.size()+1; ++i){
		if (list[i] >= list[middle]){
		tmp = list[middle];
		list[middle] = list[i];
		list[i] = tmp;
		}
	}
}

void quicksort(vector<int>& list, int l, int r) {
	//cout << "in the quicksort" <<endl;	
	if ( l <= r){
		//cout << "out of partition" <<endl;		
		partition(list,l,r);
		//cout << "piviot set to:" << piviot << endl;
		quicksort(list, l, r-1);
		//cout << "out of quicksort with right set to piviot-1" << endl;
		quicksort(list, l+1, r);
		//cout << "quicksort done" <<endl;
	}
}

void kway_merge(vector<vector<int> >& k_lists, vector<int>& s_list) {
  //** There exists quite a few ways to perform a k-way merge. 
  //** I suggest using the heap approach as explained in the
  //** project handout. Do NOT just move every element to s_list
  //** and then sort s_list. s_list should be filled one integer
  //** at a time in ascending order.	 
	for(int k = 0; k < k_lists.size(); ++k){
		cout << "list " << k <<endl;		
		for(int j = 0; j < k_lists[k].size(); ++j){
			cout << k_lists[k][j] << endl;
		}
	}
	vector<ref> heap;			//declare our heap
	for(int i = 0; i < k_lists.size(); ++i){
	struct ref t ={i,0,0};
	t.value = k_lists[t.ID][t.current];
	heap.push_back(t);
	}
	make_heap(heap.begin(),heap.end());
		for(int x = 0; x < s_list.size(); x++){
			if(heap.empty() == true)break;			
			pop_heap(heap.begin(),heap.end());
			int v = heap.back().value;
			s_list[x] = v;
			struct ref z = heap.back();
			int temp = z.current;
			heap.pop_back();
			if (temp++ < k_lists[z.ID].size()-1){
				z.current = z.current +1;
				z.value = k_lists[z.ID][z.current];
				heap.push_back(z);
				push_heap(heap.begin(),heap.end());
			}
			
		}	
} 

//** You may change main to replace input and output redirection
//** with fstream file reading. With this exception,
//** main should be left alone.
int main(int argc, char** argv) {

	
  //** Input
  int k;
  int k_size;
  cin >> k >> k_size;

  vector<vector<int> > k_lists(k);
  for (int i = 0; i < k; ++i)
    k_lists[i].resize(k_size);

  for (int i = 0; i < k_lists.size(); ++i) {
    for (int j = 0; j < k_lists[i].size(); ++j) {
      cin >> k_lists[i][j];
    }
  }
  //**

  //** Quicksort k chunks
  for (int i = 0; i < k_lists.size(); ++i)
    quicksort(k_lists[i], 0, k_lists[i].size()-1);
  //**

  //** Merge k chunks into sorted list
  vector<int> s_list(k * k_size); //** Sorted list
  kway_merge(k_lists, s_list);
  //**

  //** Output
  for (int i = 0; i < s_list.size(); ++i)
    cout << s_list[i] << " ";
  cout << endl;
  //**
}
