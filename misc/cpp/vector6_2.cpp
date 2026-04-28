#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> vec = {5, 2, 8, 1, 3};

   // Sorting the vector
   std::sort(vec.begin(), vec.end());

   // Displaying sorted elements
   std::cout << "Sorted vector: ";
   for (int num : vec) {
      std::cout << num << " ";
   }
   std::cout << std::endl;

   // Finding an element
   auto it = std::find(vec.begin(), vec.end(), 3);
   if (it != vec.end()) {
      std::cout << "Element 3 found at position: " 
         << std::distance(vec.begin(), it) << std::endl;
   } else {
      std::cout << "Element 3 not found" << std::endl;
   }

   return 0;
}
