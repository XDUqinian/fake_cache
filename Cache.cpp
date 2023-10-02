#include"Cache.h"
#include"Status.h"
#include<iostream>

using std::cout;
using std::endl;
Cache::Cache(){
    this->id=-1;
    this->address=-1;
    this->status=0;
}
Cache::Cache(int id,int address,int status){
    this->id=id;
    this->address=address;
    this->status=status;
}
void Cache::print(){
    cout<<"Cache "<<this->get_id()<<": the status is "<< this->get_status()<<","<<"the address is "<<this->get_address()<<"."<<endl;
}
void Cache::l_r(){
    char s=this->get_status();
    if(s=='M') return;
    else if(s=='S') return;
    else if(s=='I') this->toS();
}
void Cache::l_w(){
    char s=this->get_status();
    if(s=='M') return;
    else if(s=='S') this->toM();
    else if(s=='I') this->toM();
}
void Cache::r_r(){
    char s=this->get_status();
    if(s=='M') this->toS();
    else if(s=='S') return;
    else if(s=='I') return;
}
void Cache::r_w(){
    char s=this->get_status();
    if(s=='M') this->toI();
    else if(s=='S') this->toI();
    else if(s=='I') return;
}
void Cache::set_address(int address){
    this->address=address;
}
bool Cache::visit(int address){
    return (this->address==address);
}