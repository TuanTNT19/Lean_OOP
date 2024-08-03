#include "miengdatHT.h"

void MiengDatHT::nhap(){
    MiengDat::nhap();
    cout <<"Nhap day: ";
    cin>>this->day;
    cout <<"nhap chieu cao: ";
    cin >> this->chieucao;
}

void MiengDatHT::xuat(){
    cout <<"Mieng dat hinh Thang"<<endl;
    cout <<"Day: "<< this->day<<". Chieu cao: "<<this->chieucao<<endl;
    MiengDat::xuat();
}

double MiengDatHT::tinhDT(){
    return (0.5) * (this->chieucao) * (this->day);
}

int MiengDatHT::tinhTien(){
    return this->dongia * (this->tinhDT()) * 0.9;
}