
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;
int main()
{

vector <int> v1={3,4,5,6,7};

int v3=6;
auto it = find(v1.begin(), v1.end(), v3);

   if (it != v1.end()) {
      std::cout << "Element 3 found at position: " 
         << std::distance(v1.begin(), it) << std::endl;
   } else {
      std::cout << "Element 3 not found" << std::endl;
   }
   
}
