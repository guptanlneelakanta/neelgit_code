#include<iostream>
#include<csignal>

using namespace std;

void signalhandler(int signum)
{
    cout<<"\n interrupt sig number "<<signum<<endl;
    exit(signum);
}
int main()
{

    signal(SIGINT, signalhandler);

    while(1)
    {
        cout << "Going to sleep...." << endl;
      sleep(1);
    }
    return 0;
}



