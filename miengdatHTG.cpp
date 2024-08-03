#include "miengdatHTG.h"

void MiengDatHTG ::nhap(){
    MiengDat::nhap();
    cout <<"Nhap day: "; cin >>this->day;
    cout <<"Nhap chieu cao: "; cin >>this->chieucao;
}

void MiengDatHTG::xuat(){
    cout <<"Mieng dat hinh tam giac"<<endl;
    cout <<"Chieu cao: "<<this->chieucao<<". Day: "<<this->day <<endl;
    MiengDat::xuat();
}

double MiengDatHTG ::tinhDT(){
    return (0.5) * (this->chieucao) * (this->day);
}

int MiengDatHTG::tinhTien(){
    return (0.75) * (this->tinhDT()) * (this->dongia);
}