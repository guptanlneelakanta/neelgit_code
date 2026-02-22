#include<iostream>
#include <memory>
#include <string>

using namespace std;

class Box
{
    public:
        Box(int l, int b, int h ):len(l), breadth(b), height(h){}
        int volume(void);

    private:
        int len, breadth, height;
};

int Box :: volume(void)
{
    return len*breadth*height;
}

int main()
{
    Box Box1(3,4,6);
    Box *Box2 =new Box(3,4,6);

    cout<<Box2->volume()<<endl;

}