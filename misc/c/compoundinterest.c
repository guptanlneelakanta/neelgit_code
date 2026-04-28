#include<stdio.h>
#include<math.h>

int main()
{
    int p=2000;
    float r=7;
    int t=2;

    float i=0;

    i = p *r*t /100;
    printf("i = %f ", i);

    float pp = pow((1+r/100), t);
    float amount = p * pp;

    float ci= amount - p;
    printf("ci = %f ", ci);

}