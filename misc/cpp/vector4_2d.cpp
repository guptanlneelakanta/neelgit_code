#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    // Declares an empty vector
    vector<vector<int>>  vec1 = {{2,3,4}, {4} ,{66,7,8}};
    
    cout<<"\n vector size vec1.size() = "<<vec1.size()<<endl;
    
    for(int i=0; i<vec1.size(); i++)
    {
        for(int j=0; j<vec1[i].size(); j++)
            cout<<"  "<<vec1[i][j] ;
        cout<<endl;
    }

    return 0;
}