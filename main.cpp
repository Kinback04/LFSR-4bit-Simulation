#include <iostream>
#include <bitset> // Thư viện để in số nhị phân (0110) cho dễ nhìn

using namespace std;

int main() {
    // --- 1. KHỞI TẠO TRẠNG THÁI (INITIAL STATE) ---
    // Chọn seed là 6 (nhị phân 0110) giống hệt Table 1 của bạn
    // uint8_t là kiểu số nguyên 8-bit (nhưng ta chỉ dùng 4 bit)
    uint8_t lfsr = 0b0110; 
    
    cout << "--- MO PHONG LFSR 4-BIT (Da thuc: x^4 + x + 1) ---" << endl;
    cout << "Buoc(t)\tNhi Phan\tThap Phan" << endl;
    cout << "---------------------------------" << endl;

    // --- 2. VÒNG LẶP MÔ PHỎNG (Chạy 20 bước) ---
    for (int t = 0; t <= 16; t++) {
        
        // In ra trạng thái hiện tại
        // bitset<4> giúp in ra dạng 0110 thay vì số 6
        cout << t << "\t" << bitset<4>(lfsr) << "\t\t" << (int)lfsr << endl;

        // --- 3. TÍNH TOÁN LOGIC (Fibonacci) ---
        
        // A. Lấy bit ở vị trí Tap (Hồi tiếp)
        // Đa thức x^4 + x + 1 nghĩa là lấy bit thứ 4 và bit thứ 1
        // Trong C++, chỉ số tính từ 0 (bên phải nhất).
        // - Bit 1 (x^1) nằm ở vị trí index 0.
        // - Bit 4 (x^4) nằm ở vị trí index 3.
        
        unsigned int bit_x1 = (lfsr >> 0) & 1; // Lấy bit cuối cùng (bên phải)
        unsigned int bit_x4 = (lfsr >> 3) & 1; // Lấy bit đầu tiên (bên trái)

        // B. Tính Bit mới (Feedback) bằng phép XOR (^)
        // Quy tắc: Giống nhau ra 0, Khác nhau ra 1
        unsigned int feedback = bit_x1 ^ bit_x4;

        // C. Dịch chuyển thanh ghi sang phải 1 bước (Shift Right)
        lfsr = lfsr >> 1;

        // D. Đưa bit Feedback vào vị trí đầu hàng (vị trí index 3)
        // Dịch bit feedback sang trái 3 bước rồi dùng phép OR (|) để chèn vào
        lfsr = lfsr | (feedback << 3);
    }

    return 0;
}
