#pragma once

#include "miengdat.h"

class MiengDatHTG : public MiengDat{
    private:
    double day, chieucao;

    public:
    void nhap();
    void xuat();
    double tinhDT();
    int tinhTien();
};
