#include "Quanlynhadat.h"

void Quanlynhadat ::Nhapds(){
    int chon;
    MiengDat *Md;

    do{
        cout <<"0. Quay lai"<< endl;
        cout <<"1. Mieng dat HCN"<<endl;
        cout <<"2. Mieng dat HT"<<endl;
        cout <<"3. Mieng dat HTG"<<endl;
        cout <<"MOI BAN CHON"<<endl;
        cin >>chon;
        if (chon == 0){
            break;
        }
        else if(chon == 1){
            Md = new MiengDatHCN;
            Md->nhap();
            dat.push_back(Md);
            break;
        }

        else if(chon == 2){
            Md = new MiengDatHT;
            Md->nhap();
            dat.push_back(Md);
            break;
        }

        else if (chon == 3){
            Md = new MiengDatHTG;
            Md->nhap();
            dat.push_back(Md);
            break;
        }

    }
    while(chon != 0);

}

void Quanlynhadat ::Xuatds(){
    for (int i = 0; i< dat.size(); i++){
        dat[i]->xuat();
        cout <<"-----------------------------"<<endl;
    }
}

double Quanlynhadat::TongDT(){
    double tong = 0;
    for (int i = 0; i< dat.size(); i++){
        tong += dat[i]->tinhDT();
    }

    return tong;
}

int Quanlynhadat::TongTien(){
    int tong = 0;
    for (int j = 0; j< dat.size(); j++){
        tong += dat[j]->tinhTien();
    }

    return tong;
}