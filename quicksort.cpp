#include<cstdlib>
#include<ctime>
#include<vector>
#include<iostream>

using namespace std;

void quicksort(vector<int>&);
void partition(vector<int>&);

void quicksort(vector<int> &arr){

  // if arr.size() == 1, it's a trivial case. already sorted.
  // if arr.size() == 0, it's empty. Therefore, we need not do anything from our side.
  if(arr.size()<=1){
    return;
  }

  else{
    partition(arr);
  }

}

void partition(vector<int> &arr){
  srand((unsigned)time(0));

  int flag=0;
  flag = (int)(((int)rand())%arr.size());

  int temp;
  temp = arr.at(flag);

  vector<int> a, b;

  for(int i=0; i<(int)arr.size(); i++){
    if(arr.at(i)<arr.at(flag)){
      a.push_back(arr.at(i));
    }
    else if((arr.at(i)==arr.at(flag))&&i!=flag){
      a.push_back(arr.at(i));
    }
  }

  for(int i=0; i<(int)arr.size(); i++){
    if(arr.at(i)>arr.at(flag)){
      b.push_back(arr.at(i));
    }
  }

  quicksort(a);
  quicksort(b);

  arr.clear();

  for(int i=0; i<(int)a.size(); i++){
    arr.push_back(a[i]);
  }

  arr.push_back(temp);

  for(int i=0; i<(int)b.size(); i++){
    arr.push_back(b[i]);
  }

  return;
}
