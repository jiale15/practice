#include <iostream>
using namespace std;
class A {
public:
    virtual void x(){cout << "A X!" << endl;}
    virtual void y()=0;
};

class B : public A
{
private:
    
public:
    virtual void x(){cout << "B X!" << endl;}
    // B();
    // ~B();
};
int main()
{
    A* b = new B();
    b->x();
    return 0;
}