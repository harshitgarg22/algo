#include<vector>
#include "./choosePivot.h"

using namespace std;

unsigned long int quicksort(vector<int>&, int method=3);
unsigned long int partition(vector<int>&, int method);

unsigned long int quicksort(vector<int> &arr, int method){

  unsigned long int count = 0;
  // if arr.size() == 1, it's a trivial case. already sorted.
  // if arr.size() == 0, it's empty. Therefore, we need not do anything from our side.
  if(arr.size()<=1){
    return count;
  }

  else{
    count += partition(arr, method);
  }

  return count;
}

unsigned long int partition(vector<int> &arr, int method){

  unsigned long int pivot = choosePivot(arr, method);
  unsigned long int count = 0;

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

  count += quicksort(a, method);
  count += quicksort(b, method);

  arr.clear();

  for(unsigned long int i=0; i<a.size(); i++){
    arr.push_back(a[i]);
  }

  arr.push_back(temp);

  for(unsigned long int i=0; i<b.size(); i++){
    arr.push_back(b[i]);
  }

  count += a.size() + b.size();

  return count;
}
