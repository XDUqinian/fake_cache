#include"Controll.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

Controll::Controll(){
    for(int i=0;i<4;i++){
        this->c[i].id=i;
        this->c[i].status=3;
    }
    for(int i=0;i<10;i++){
        this->m[i].id=i;
        this->m[i].address=i;
        this->m[i].status=3;
        this->share[i]=0;
    }
}
void Controll::read(int id,int address){
    Cache *now_c=&(this->c[id]);
    Cache *r_c[3];
    int cnt=0;
    for(int i=0;i<4;i++){
        if(i==id) continue;
        r_c[cnt++]=&(this->c[i]);
    }

    if(!now_c->visit(address)){
        cout<<"not hit!"<<endl;
        change(now_c->id,now_c->address,address);
    }

    if(now_c->get_status()=='I') this->share[address]++;
    now_c->l_r();
    if(this->m[address].get_status()=='I'){
        this->m[address].toS();
        this->share[address]++;
    }

    for(int i=0;i<3;i++){
        if(!r_c[i]->visit(address)) continue;
        r_c[i]->r_r();
    }
    
    return;
}
void Controll::write(int id,int address){
    Cache *now_c=&(this->c[id]);
    Cache *r_c[3];
    int cnt=0;
    for(int i=0;i<4;i++){
        if(i==id) continue;
        r_c[cnt++]=&(this->c[i]);
    }

    if(!now_c->visit(address)){
        cout<<"not hit!"<<endl;
        change(now_c->id,now_c->address,address);
    }
    now_c->l_w();
    this->share[address]=1;
    this->m[address].toI();

    for(int i=0;i<3;i++){
        if(!r_c[i]->visit(address)) continue;
        r_c[i]->r_w();
    }

    return;
}
void Controll::change(int id,int cache_adr,int mem_adr){
    char cache_status=this->c[id].get_status();
    char mem_status=this->m[mem_adr].get_status();
    
    if(cache_status=='M') this->m[cache_adr].toM();
    else if(cache_status=='S'){
        this->share[cache_adr]--;
        if(this->share[cache_adr]==1) this->m[cache_adr].toM();
    }

    if(mem_status=='M'){
        this->c[id].toS();
        this->m[mem_adr].toS();
        this->share[mem_adr]++;
    }else if(mem_status=='S'){
        this->c[id].toS();
        this->share[mem_adr]++;
    }else if(mem_status=='I') this->c[id].toI();

    this->c[id].set_address(mem_adr);
    return;
}
void Controll::run(){
    int id,address;
    char op;
    cin>>op>>id>>address;
    if(op=='r'){
        this->read(id,address);
    }else if(op=='w'){
        this->write(id,address);
    }

    for(int i=0;i<4;i++) this->c[i].print();
    cout<<"Memory ";
    for(int i=0;i<10;i++) cout<<this->m[i].id<<"  ";
    cout<<endl;
    cout<<"Status ";
    for(int i=0;i<10;i++) cout<<this->m[i].get_status()<<"  ";
    cout<<endl;
    cout<<"Share  ";
    for(int i=0;i<10;i++) cout<<this->share[i]<<"  ";
    cout<<endl;

    return;
}