#include<iostream>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int mul(int a, int b)
{
    return a*b;
}

int div1(int a, int b)
{
    return a/b;
}


int main()
{
	

    int (*funptr[3])(int , int ) = { add, mul, div1};

    cout<<" fun pinter array"<<endl;

     int res = funptr[0](3,4);
    cout<<"res =" <<res <<endl;

    res =funptr[1](4,2);
    cout<<"res =" <<res <<endl;

    res =funptr[2](14,2);
    cout<<"res =" <<res <<endl;

    int **p ;
    
    int arr5[3][4]= { 1,2,3,31,
                41,5,6,61,
                7,8,9,91 };
    *p=(int *)malloc(3*sizeof(int));
  
    for(int i=0; i<3; i++)
    {
        cout<<endl;        

        p[i]=(int *)malloc(4*sizeof(int));
        for (int j=0; j<4; j++)
        {            
            p[i][j] =arr5[i][j];
            cout<<p[i][j] << " ";
        }
    }

return 0;
}

