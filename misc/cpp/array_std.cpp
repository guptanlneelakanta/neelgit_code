
#include<iostream>
#include<array>

using namespace std;

void printarr(array<int, 5> arr)
{
    for(auto i : arr)
    cout<<i <<" ";

}

int main()
{
    array<int , 5> stdarr ={33,4,5,6,7};

    printarr(stdarr);

    cout<<"\n stdarr.size() = "<<stdarr.size()<<endl;

     int arr[] = {10, 20, 30, 40, 50};
  int arr_length = sizeof(arr) / sizeof(arr[0]);

  cout << "Array's Length : " << arr_length<<endl;
  cout << "Array's Length sizeof(arr) : " << sizeof(arr)<<endl;

  int b[2][3][4] = {0, 1, 2, 3, 
  4, 5, 6, 7, 
  8, 9, 10, 11, 
  12, 13, 14, 15, 
  16, 17, 18, 19};

  cout<<b[1][1][3]<<endl;
  cout<<b[1][2][3]<<endl;
  cout<<b[1][2][0]<<endl;
  cout<<b[1][1][0]<<endl;


}