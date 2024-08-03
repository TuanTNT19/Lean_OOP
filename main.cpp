#include "Quanlynhadat.h"

int main(){
    Quanlynhadat qlnd;
    int chon;
    do{
        cout <<"0. Thoat"<<endl;
        cout <<"1. Nhap ds"<<endl;
        cout <<"2. Xuat danh sach"<<endl;
        cout <<"3. Xuat Tong Dien Tich"<<endl;
        cout <<"4. Xuat Tong Tien"<<endl;
        cin >> chon;

        if (chon == 0){
            break;
        }

        else if (chon == 1){
            qlnd.Nhapds();
        }

        else if(chon == 2){
            qlnd.Xuatds();
        }

        else if (chon == 3){
            cout <<"Tong dien tich dat la: "<< qlnd.TongDT()<<endl;
        }

        else if (chon == 4){
            cout <<"Tong tien bo ra la: "<< qlnd.TongTien()<<endl;
        }

    }while(chon != 0);

    return 0;


}