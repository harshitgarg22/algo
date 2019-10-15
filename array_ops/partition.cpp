#include<vector>
#include "./choosePivot.h"

using namespace std;

unsigned long partition(vector<int> &arr, int method /*= 3*/){

  unsigned long pivot;
  pivot = choosePivot(arr, method);

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
    else if(arr.at(i)>arr.at(pivot)){
      b.push_back(arr.at(i));
    }
  }

  for(unsigned long int i=0; i<arr.size(); i++){
  }

  arr.clear();

  for(unsigned long int i=0; i<a.size(); i++){
    arr.push_back(a[i]);
  }

  arr.push_back(temp);

  for(unsigned long int i=0; i<b.size(); i++){
    arr.push_back(b[i]);
  }

  return a.size();
}
