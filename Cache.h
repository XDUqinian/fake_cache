#ifndef CACHE_H
#define CACHE_H

#include"Device.h"

class Cache:public Device{
    public:
        Cache();
        Cache(int id,int address,int status);
        void print();
        void l_r();
        void l_w();
        void r_r();
        void r_w();
        void set_address(int address);
        bool visit(int address);
};

#endif