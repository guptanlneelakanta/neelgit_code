#include<iostream>
using namespace std;

	class shape{

		protected :
			int len=0;
			int bredth=0;

		public:
			shape(int l, int b ): len(l), bredth(b){}		
			
			virtual int area() { 
				cout<<"parent class called"<<endl;
				return len * bredth;
			}
			
			virtual void print();		
	};

	void shape::print()
	{
		cout<<"\n shape is a parent class"<<endl;
	}

	class rectangle : public shape{

	public:
		rectangle(int l, int b):shape(l,b){}
		int area();
		virtual void print();		
	};
	
	void rectangle::print()
	{
		cout<<"\n shape is a rectangle class"<<endl;
	}


	int rectangle::area()
	{
		return len * bredth;	
	}


	class triangle final : public shape{

	public:
		triangle(int l, int b):shape(l,b){}
		int area();
		virtual void print();		
	};

	int triangle::area()
	{
		return len * bredth/2;	
	}
	
	void triangle::print()
	{
		cout<<"\n shape is a triangle class"<<endl;
	}

	int main()
	{
		shape *sp;
		rectangle rec(34,2);
		sp = &rec;
		cout<<sp->area()<<endl;
		sp->print();
		
		triangle tri(6,7);
		sp = &tri;
		cout<<sp->area()<<endl;
		sp->print();
	}




