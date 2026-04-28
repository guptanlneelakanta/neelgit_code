#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    // Declares an empty vector
    vector<char> ch1 = {'a', 'g', 'k'};
    
    ch1.push_back('m');
ch1.insert(ch1.begin()+1, 'h');

    
    // Print items of v3
    for (char x : ch1) {
        cout << x << " ";
    }
    cout<<endl;

    cout<<"\n element using the [] ch1[2] = "<<ch1[2]<<endl;
    cout<<"\n element using the at() ch1.at(2) = "<<ch1.at(2)<<endl;

    ch1[2] = 'y';
    cout<<"\n element using the at() ch1.at(2) = "<<ch1.at(2)<<endl;

    cout<<"\n vector size ch1.size() = "<<ch1.size()<<endl;
    for(int i=0; i<ch1.size(); i++)
    cout<<"  "<<ch1[i] <<endl;
    
    ch1.pop_back();

    
    //ch1.erase(ch1.begin(), find(ch1.begin(), ch1.end(), 'f'));

    cout<<"\n after erase "<<endl;
    for(int i=0; i<ch1.size(); i++)
    cout<<"  "<<ch1[i] <<endl;

       vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Deleting last element 'z'
  	v.pop_back();
  
  	// Deleting element 'f'
  	v.erase(v.begin()+2);
  	
  	for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    std::vector<int> vec = {10, 20, 30, 40, 50};

    std::vector<int> vec2 = vec;
    for(auto vi : vec2)
        cout<<"  "<<vi << endl;

    return 0;
}