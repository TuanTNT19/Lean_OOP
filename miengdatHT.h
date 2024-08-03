#pragma once

#include "miengdat.h"

class MiengDatHT : public MiengDat{
    private:
    double day, chieucao;

    public:
    void nhap();
    void xuat();
    double tinhDT();
    int tinhTien();
};
