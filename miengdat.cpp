#include "miengdat.h"

void MiengDat::nhap() {
    cin.ignore();
    cout << "Nhap maso: ";
    getline(cin, this->maso);
    cout << "Nhap don gia: ";
    cin >> this->dongia;
}

void MiengDat::xuat() {
    cout << "Ma so: " << this->maso << " Don gia: " << this->dongia << endl;
    cout << "Dien tich: " << this->tinhDT() << " Tien: " << this->tinhTien() << endl;
}

int MiengDat::tinhTien() {
    return this->dongia * this->tinhDT();
}
