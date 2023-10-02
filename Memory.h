//
// Created by 七年 on 2023/10/2.
//
#ifndef MEMORY_H
#define MEMORY_H

#include"Device.h"

class Memory:public Device{
    public:
        Memory();
        Memory(int id,int address,int status);
        void print();
        bool visit(int address);
};

#endif