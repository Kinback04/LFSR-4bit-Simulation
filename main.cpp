#include <iostream>
#include <bitset>
#include <cstdint> // <--- Đã thêm thư viện này để sửa lỗi

using namespace std;

int main() {
    // --- 1. KHỞI TẠO TRẠNG THÁI (INITIAL STATE) ---
    // Chọn seed là 6 (nhị phân 0110)
    // Đổi sang 'unsigned int' cho dễ chạy, không lo thiếu thư viện
    unsigned int lfsr = 0b0110; 
    
    cout << "--- MO PHONG LFSR 4-BIT (Da thuc: x^4 + x + 1) ---" << endl;
    cout << "Buoc(t)\tNhi Phan\tThap Phan" << endl;
    cout << "---------------------------------" << endl;

    // --- 2. VÒNG LẶP MÔ PHỎNG (Chạy 20 bước) ---
    for (int t = 0; t <= 16; t++) {
        
        // In ra trạng thái hiện tại
        // bitset<4> giúp in ra dạng 0110
        cout << t << "\t" << bitset<4>(lfsr) << "\t\t" << (int)lfsr << endl;

        // --- 3. TÍNH TOÁN LOGIC (Fibonacci) ---
        
        // A. Lấy bit ở vị trí Tap (Hồi tiếp)
        // Bit 1 (vị trí 0) và Bit 4 (vị trí 3)
        unsigned int bit_x1 = (lfsr >> 0) & 1; 
        unsigned int bit_x4 = (lfsr >> 3) & 1; 

        // B. Tính Bit mới (Feedback) bằng phép XOR (^)
        unsigned int feedback = bit_x1 ^ bit_x4;

        // C. Dịch chuyển thanh ghi sang phải 1 bước
        lfsr = lfsr >> 1;

        // D. Đưa bit Feedback vào vị trí đầu hàng (vị trí index 3)
        // Vì lfsr bây giờ dùng int nên ta phải đảm bảo chỉ thao tác trên 4 bit
        // (feedback << 3) đưa bit về đầu
        lfsr = lfsr | (feedback << 3);
        
        // Quan trọng: Vì dùng int (32 bit) nên ta cần xóa sạch các bit thừa phía trên
        // Chỉ giữ lại 4 bit cuối cùng (Mask 0b1111 = 15)
        lfsr = lfsr & 0xF; 
    }

    return 0;
}
