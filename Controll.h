//
// Created by 七年 on 2023/10/2.
//

#ifndef CONTROLL_H
#define CONTROLL_H

#include"Status.h"
#include"Cache.h"
#include"Memory.h"
#include<queue>

class Controll{
    public:
        Cache c[4];
        Memory m[10];
        int share[10];

        Controll();
        void run();
        void read(int id,int address);
        void write(int id,int address);
        void change(int id,int cache_adr,int mem_adr);
};
#endif