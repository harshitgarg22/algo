#include<cstdlib>
#include<ctime>
#include<vector>

/* The following methods can be used (based on the value of the `method` variable):-

   1. Always first element
   2. Always last element
   3. Random based on time and srand
   4. "median-of-three" pivot rule

*/

using namespace std;

unsigned long int choosePivot(vector<int> arr, int method){

  if(method==1){
    return 0;
  }

  else if(method==2){
    return arr.size()-1;
  }

  else if(method==3){
    srand((unsigned)time(0));

    unsigned long int pivot=0;
    pivot = (rand()%arr.size());

    return pivot;
  }

  else if(method==4){
    unsigned long int mid = (arr.size()-1)/2;
    unsigned long int end = arr.size()-1;

    if(arr[0]>arr[mid]){
      if(arr[0]>arr[end]){
        if(arr[mid]>arr[end]){
          return mid;
        }
        else{
          return end;
        }
      }
      else{
        return 0;
      }
    }
    else{
      if(arr[0]>arr[end]){
        return 0;
      }
      else if(arr[end]>arr[mid]){
        return mid;
      }
      else{
        return end;
      }
    }
  }

  return 0;
}
