// Finds the ith order statistic in an integer array

#include<vector>
#include "./partition.h"

using namespace std;


int rselect(vector<int> arr, unsigned long i){

  if(arr.size()==1) return arr.at(0);

  i--;
  unsigned long j = partition(arr, 3);

  if(j==i) return arr.at(j);

  else if(i>j){
    vector<int> rightPart;

    for(unsigned long k=j+1; k<=arr.size()-1; ++k){
      rightPart.push_back(arr.at(k));
    }

    return rselect(rightPart, i-j);
  }

  else {
    vector<int> leftPart;

    for(unsigned long k=0; k<=j-1; ++k){
      leftPart.push_back(arr.at(k));
    }

    return rselect(leftPart, i+1);
  }

}
