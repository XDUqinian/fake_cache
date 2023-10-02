#include"Device.h"
#include"Memory.h"
#include"Cache.h"
#include"Status.h"
#include"Controll.h"
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    // Device a(1,2,3);
    // a.print();
    // Memory m(0,2,3);
    // m.print();
    // cout<<m.visit(1)<<endl;
    // Cache c(3,2,2);
    // c.print();
    // cout<<c.visit(1)<<endl;
    Controll ice;
    while(true) ice.run();
    return 0;
}