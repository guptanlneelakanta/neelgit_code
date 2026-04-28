#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Iterable{

    public:
        Iterable(const vector<int>& v2) : value(v2){}
        auto begin() const ->vector<int>::const_iterator{ return value.begin();}
        auto end() const ->vector<int>::const_iterator{ return value.end();}

    private:
        vector <int> value;
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for(const auto& i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

