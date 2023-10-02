//
// Created by 七年 on 2023/10/2.
//
#ifndef DEVICE_H
#define DEVICE_H

class Device{
    public:
        int id;
        int address;
        int status;

        Device();
        Device(int id,int address,int status);
        int get_id();
        int get_address();
        char get_status();
        void toS();
        void toI();
        void toM();
        virtual void print();
};

#endif