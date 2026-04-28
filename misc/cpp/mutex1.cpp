#include<bits/stdc++.h>
#include<iostream>
//#include<memory>
#include <mutex>

using namespace std;

mutex m;
int i=0;
int f()
{
 i++;
 return i;
}
int everything_ok=0;

void bad()
{
m.lock();
everything_ok = f();
if(!everything_ok)
{
    return;
}
m.unlock();

}

void good()
{
    lock_guard<mutex> lk(m);
    everything_ok = f();
    if(!everything_ok)
    {
        return;
    }   
}

int main()
{
    
bad();
good();

}