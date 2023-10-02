#include"Memory.h"
#include"Status.h"
#include<iostream>

using std::cout;
using std::endl;

Memory::Memory(){
    this->id=-1;
    this->address=-1;
    this->status=0;
}
Memory::Memory(int id,int address,int status){
    this->id=id;
    this->address=address;
    this->status=status;
}
void Memory::print(){
    cout<<"Memory "<<this->get_id()<<": the status is "<< this->get_status()<<","<<"the data is "<<this->get_address()<<"."<<endl;
}
bool Memory::visit(int address){
    return true;
}