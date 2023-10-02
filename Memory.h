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