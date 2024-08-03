#include "miengdatHCN.h"

void MiengDatHCN::nhap() {
    MiengDat::nhap();
    cout << "Nhap chieu dai: "; cin >> this->cd;
    cout << "Nhap chieu rong: "; cin >> this->cr;
  

}

void MiengDatHCN::xuat() {
    cout <<"Mieng dat hinh chu nhat: "<<endl;
    cout << "Chieu dai: " << this->cd << ". Chieu rong: " << this->cr << endl;
    MiengDat::xuat();
}

double MiengDatHCN::tinhDT() {
    return this->cd * this->cr;
}
