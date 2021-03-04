
#include<iostream>
using namespace std;
class Student
{
private:    // private data member
	int rollno;

public:     // public accessor and mutator functions
	int getRollno()
	{
		return rollno;
	}

	void setRollno(int i)
	{
		rollno = i;
	}

};

int main()
{
	Student A;
	//A.rollno = 1;  //Compile time error
	//cout << A.rollno; //Compile time error

	A.setRollno(1);  //Rollno initialized to 1
	cout << A.getRollno(); //Output will be 1
}