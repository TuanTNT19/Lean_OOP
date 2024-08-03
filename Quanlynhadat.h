// main.cpp
#include "miengdat.h"
#include "miengdatHCN.h"
#include "miengdatHT.h"
#include "miengdatHTG.h"
#include <vector>

class Quanlynhadat{
    private:
    vector<MiengDat *> dat;

    public:
    void Nhapds();
    void Xuatds();
    double TongDT();
    int TongTien();
};

