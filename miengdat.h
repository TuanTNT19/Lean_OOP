#pragma once

#include <iostream>
#include <string>

using namespace std;

class MiengDat {
protected:
    string maso;
    int dongia;

public:
    virtual void nhap();
    virtual void xuat();
    virtual double tinhDT() = 0;
    virtual int tinhTien();
};
