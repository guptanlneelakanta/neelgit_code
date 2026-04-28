#include<iostream>
#include<ctime>

using namespace std;

int main()
{

    time_t now = time(0);

    char *dt = ctime(&now);

    cout<<"\n dt = "<<dt<<endl;

    //convert time to struct UTC
    tm *gmtm = gmtime(&now);
    cout<<"\n gmtm = "<<gmtm<<endl;

    dt = asctime(gmtm);
    cout<<"\n gmtm = "<<dt<<endl;
}