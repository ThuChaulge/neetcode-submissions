#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

// Cấu trúc tùy biến Hàm băm (Custom Hash) chống lại các test case Anti-hash (Ép O(N^2))
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Tối ưu hóa I/O nếu chạy trong hàm main, tuy nhiên ở đây là nộp theo dạng hàm/class
        // Khởi tạo map với custom_hash và cấp phát sức chứa ban đầu để tránh rehash liên tục
        unordered_map<int, int, custom_hash> mp;
        mp.reserve(nums.size()); 
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int other = target - nums[i];
            
            // Sử dụng find() để kiểm tra sự tồn tại (chỉ mất 1 lần lookup)
            auto it = mp.find(other);
            if (it != mp.end()) {
                // Do i chạy từ 0 đến n-1, nên chỉ số cũ chắc chắn luôn nhỏ hơn i
                return {it->second, i};
            }
            
            // Nếu không tìm thấy, lưu chỉ số hiện tại của nums[i]
            // Đề bài cam kết chỉ có 1 đáp án duy nhất, nên nếu ghi đè các số trùng nhau cũng không ảnh hưởng kết quả cuối
            mp[nums[i]] = i; 
        }
        
        return {}; // Trả về mảng rỗng mặc định nếu hệ thống yêu cầu cấu trúc chặt chẽ
    }
};