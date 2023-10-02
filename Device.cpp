#include"Device.h"
#include"Status.h"
#include<iostream>

using std::cout;
using std::endl;

Device::Device(){}
Device::Device(int id,int address,int status){
    this->id=id;
    this->address=address;
    this->status=status;
}
int Device::get_id(){
    return this->id;
}
int Device::get_address(){
    return this->address;
}
char Device::get_status(){
    Status ss;
    return ss.mp[this->status];
}
void Device::toS(){
    this->status=Status::S;
}
void Device::toI(){
    this->status=Status::I;
}
void Device::toM(){
    this->status=Status::M;
}
void Device::print(){
    cout<<"Device "<<this->get_id()<<": the status is "<< this->get_status()<<"."<<endl;
    // cout<<"the status of this device "<< Status::mp[1]<<endl;
}