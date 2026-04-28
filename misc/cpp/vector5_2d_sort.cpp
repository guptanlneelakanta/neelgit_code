#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool sizecom(const vector<int>&v1, const vector<int>&v2 )
{
    return v1 <v2;
}

int main() {
    
    // Declares an empty vector
    vector<vector<int>>  vec1 = {{2,3,4}, {4} ,{66,7}};
 
    cout<<"\n before sort"<< endl;
    cout<<"\n vector size vec1.size() = "<< vec1.size() << endl;
    
    for(int i=0; i<vec1.size(); i++)
    {
        for(int j=0; j<vec1[i].size(); j++)
            cout<<"  "<<vec1[i][j] ;
        cout<<endl;
    }

    sort(vec1.begin(), vec1.end(), sizecom);

    cout<<"\n after sort"<< endl;    
    
    for(int i=0; i<vec1.size(); i++)
    {
        for(int j=0; j<vec1[i].size(); j++)
            cout<<"  "<<vec1[i][j] ;
        cout<<endl;
    }

    return 0;
}
#endif


#include<iostream>
#include<vector> // for 2D vector
#include<algorithm>// for sort()
using namespace std;

// Driver function to sort the 2D vector
// on basis of a no. of columns in 
// ascending order
bool sizecom(const vector<int>&v1, const vector<int>& v2)
{
    return v1.size() < v2.size();
}

int main()
{
    // Initializing 2D vector &quot;vect&quot; with
    // values
    vector< vector<int>> vect{{21, 2},
                               {8, 24, 5},
                               {26}};

    // Displaying the 2D vector before sorting
    cout <<"\n The Matrix before sorting is:\n";
    for (int i=0; i<vect.size(); i++)
    {
        //loop till the size of particular
        //row
        for (int j=0; j<vect[i].size() ;j++)
            cout <<vect[i][j] << " ";
        cout << endl;
    }

    //Use of &quot;sort()&quot; for sorting on
    //basis of no. of columns in
    //ascending order.
    sort(vect.begin(), vect.end());

    // Displaying the 2D vector after sorting
    cout <<"The Matrix after sorting is:\n";
    for (int i=0; i<vect.size(); i++)
    {
        //loop till the size of particular
        //row
        for (int j=0; j<vect[i].size() ;j++)
            cout << vect[i][j] <<" ";
                    cout << endl;
    }
    



    return 0;

}