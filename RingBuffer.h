#include <iostream>
#include <variant>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename... Types>
class RingBuffer{
private:
    uint16_t buffer_size;
    uint16_t current_size;
    uint16_t head;  
    uint16_t tail;
    vector<variant<Types...>> buffer;

public:
    // Hàm khởi tạo
    RingBuffer(uint16_t size) : buffer_size(size), current_size(0), head(0), tail(0) {
        buffer.resize(size); 
    };

    void push(const variant<Types...> &c){ 
        buffer[head] = c;  // Ghi đè lên vị trí hiện tại
        head = (head + 1) % buffer_size;  // Cập nhật chỉ số, quay vòng nếu cần
        
        if (current_size < buffer_size) {
            current_size++;  // Tăng kích thước hiện tại
        }
    }

    variant<Types...> get() {
        if (is_empty()) {
            throw runtime_error("Buffer is empty!");
        }

        variant<Types...> ret = buffer[tail];
        tail = (tail + 1) % buffer_size;

    return ret;
}

    // variant<Types...> get_out(){
    //     if (is_empty()) {
    //         throw runtime_error("Buffer is empty!");
    //     }

    //     variant<Types...> ret = buffer.front();
    //     buffer.erase(buffer.begin()); 
    //     current_size--;

    //     return ret;
    // }

    bool is_empty(){
        return buffer.empty();
    }

    bool is_full(){
        return buffer.size() == buffer_size;
    }

    uint16_t get_size(){
        return current_size;
    }
};
