#include<vector>
#include "./choosePivot.h"

using namespace std;

void quicksort(vector<int>&, int method = 2);
void partition(vector<int>&, int method);

void quicksort(vector<int> &arr, int method){

  // if arr.size() == 1, it's a trivial case. already sorted.
  // if arr.size() == 0, it's empty. Therefore, we need not do anything from our side.
  if(arr.size()<=1){
    return;
  }

  else{
    partition(arr, method);
  }

}

void partition(vector<int> &arr, int method){

  unsigned long int pivot = choosePivot(arr.size(), method);

  int temp;
  temp = arr.at(pivot);

  vector<int> a, b;

  for(unsigned long int i=0; i<arr.size(); i++){
    if(arr.at(i)<arr.at(pivot)){
      a.push_back(arr.at(i));
    }
    else if((arr.at(i)==arr.at(pivot))&&i!=pivot){
      a.push_back(arr.at(i));
    }
  }

  for(unsigned long int i=0; i<arr.size(); i++){
    if(arr.at(i)>arr.at(pivot)){
      b.push_back(arr.at(i));
    }
  }

  quicksort(a);
  quicksort(b);

  arr.clear();

  for(unsigned long int i=0; i<a.size(); i++){
    arr.push_back(a[i]);
  }

  arr.push_back(temp);

  for(unsigned long int i=0; i<b.size(); i++){
    arr.push_back(b[i]);
  }

  return;
}
