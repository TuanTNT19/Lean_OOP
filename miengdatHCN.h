#pragma once

#include "miengdat.h"

class MiengDatHCN : public MiengDat {
private:
    double cd, cr;

public:
    void nhap();
    void xuat();
    double tinhDT();
};
