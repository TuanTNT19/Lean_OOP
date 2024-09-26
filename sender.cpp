#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <cstring>


using namespace std;

#define FIFO1 "./f1"
int fd1;

void charToBinary(char c, char binaryStr[9]) {
    // Chuyển từng bit của ký tự thành chuỗi nhị phân và lưu vào mảng
    for (int i = 7; i >= 0; --i) {
        binaryStr[7 - i] = (c & (1 << i)) ? '1' : '0';
    }
    binaryStr[8] = '\0';  // Đảm bảo chuỗi kết thúc bằng null
}

int main() {

    mkfifo(FIFO1, 0666);
    fd1 = open(FIFO1, O_WRONLY);  

    char input_char;
    char binaryStr[9];  // Mảng để lưu chuỗi nhị phân, kích thước 9 bao gồm ký tự null

    while(1)
    {
        cout << "Enter a character: ";
        cin >> input_char;

    // Gọi hàm để chuyển ký tự thành chuỗi nhị phân và lưu vào binaryStr
        charToBinary(input_char, binaryStr);

        write(fd1, binaryStr, strlen(binaryStr));
    }

    close(fd1);

    return 0;
}
