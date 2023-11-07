//
// Created by 七年 on 2023/10/2.
//
#include"Controll.h"
#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::cin;

std::ifstream fin[4];

int main(){
    for(int i=0;i<4;i++)
        fin[i].open("./trace/trace"+std::to_string(i)+".txt");

    Controll ice;
    
    for(int i=0;i<16;i++){
        int id=i%4,address;
        char op;
        fin[id]>>op>>address;
        ice.run(op,id,address);
    }
    return 0;
}