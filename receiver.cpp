#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include "RingBuffer.h"
#include <bitset>

using namespace std;

#define FIFO1 "./f1"
int fd1;
RingBuffer<char> rb(8);

char binaryToChar(const char binaryArr[9]) {  // Nhận vào mảng char với độ dài 8 bit + 1 ký tự '\0'
    // Kiểm tra độ dài mảng nhị phân phải đúng 8 bit
    for (int i = 0; i < 8; ++i) {
        if (binaryArr[i] != '0' && binaryArr[i] != '1') {
            throw invalid_argument("Chuỗi nhị phân chỉ được chứa '0' và '1'.");
        }
    }

    // Chuyển đổi chuỗi nhị phân thành số nguyên
    bitset<8> bits(binaryArr); // Sử dụng bitset để chuyển chuỗi thành số nguyên
    
    unsigned long decimalValue = bits.to_ulong(); // Chuyển bitset thành số thập phân

    // Chuyển từ thập phân thành ký tự
    char character = static_cast<char>(decimalValue);
    return character;
}

int main() {
    mkfifo(FIFO1, 0666);
    fd1 = open(FIFO1, O_RDONLY);  

    char binaryRead[9];  // Mảng để lưu chuỗi nhị phân, kích thước 9 bao gồm ký tự null
    char binary[9];
    int r = 0;

    while (1) {
        r = read(fd1, binaryRead, 8);
        binaryRead[r] = '\0';  // Đảm bảo kết thúc chuỗi nhị phân bằng ký tự null
        cout << "Da doc " << r << " bit data" << endl;
        cout << "Read : " << binaryRead << endl;

        for (int i = 0; i < 8; i++) {
            rb.push(binaryRead[i]);
        }

        cout << "Push ok " << endl;

        // Đảm bảo lấy dữ liệu từ ring buffer với kiểm tra
        for (int j = 0; j < 8; j++) {
                binary[j] = std::get<char>(rb.get());
        }

        // Kết thúc chuỗi nhị phân bằng ký tự null
        binary[8] = '\0'; 

        cout << "Ky tu doc duoc: " << binaryToChar(binary) << endl;
    }

    close(fd1);

    return 0;
}
