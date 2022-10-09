#include <bits/stdc++.h>
using namespace std;

/*
	SOLID
	[S] = Single Responsibility function
	[O] = Open Close principle, i.e open for extension and closed for modification
	[L] = Liksov's substitution principle
	[I] = Interface segregation principle, make another interface for the common virtual functions into a separate derived class
	[D] = Dependency inversion principle
*/

// this is how interface is implemented in c++
class IOperation {
public:
	int a, b;
	void setA(int a) {
		this->a = a;
	}
	void setB(int b) {
		this->b = b;
	}
	virtual int performOperation() = 0; //pure virtual functions
};

class Calculator: public IOperation {
public:
	int performOperation() {return 0;}
};

class Addition: public Calculator {
public:
	int performOperation() {
		return a + b;
	}
};

class Subtraction: public Calculator {
public:
	int performOperation() {
		return a - b;
	}
};

/*************************************************************/

// Example for dependency inversion principle
class Manager {
public:
	void addEmployee(Employee empployee) {

	}
};

class Employee {
public:
	virtual void fun() = 0;
};

class Developer: Employee {
public:

};

class Designer: Employee {
public:

};


int main() {

	Calculator *c1 = new Addition();
	Calculator *c2 = new Subtraction();

	c1->setA(3);
	c1->setB(4);
	int t1 = c1->performOperation();
	cout << "t1 = " << t1 << endl;

	c2->setA(10);
	c2->setB(5);
	int t2 = c2->performOperation();
	cout << "t2 = " << t2 << endl;
	return 0;
}
