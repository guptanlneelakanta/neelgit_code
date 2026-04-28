#include <iostream>
#include <cstring>
#include <locale>

int main() {
   const char* str1 = "hello";
   const char* str2 = "Tutorialspoint Learner";

   // Set the locale (optional, depends on your environment)
   std::setlocale(LC_COLLATE, "en_US.UTF-8");

   int result = strcoll(str1, str2);

   if (result < 0) {
      std::cout << "str1 is less than str2\n";
   } else if (result > 0) {
      std::cout << "str1 is greater than str2\n";
   } else {
      std::cout << "str1 is equal to str2\n";
   }

   return 0;
}