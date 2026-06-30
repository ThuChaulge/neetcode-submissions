class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Khởi tạo map với CustomHash để đạt O(1) thuần túy, an toàn tuyệt đối
        unordered_map<string, vector<int>> mp;
        mp.reserve(strs.size()); // Tối ưu hằng số cấp phát bộ nhớ

        // Mảng đếm tần suất cố định dùng chung, tránh cấp phát lại trong vòng lặp
        int count[26]; 

        for (int i = 0; i < strs.size(); ++i) {
            // Bước 1: Đếm tần suất ký tự - O(K)
            for (int j = 0; j < 26; ++j) count[j] = 0;
            for (char c : strs[i]) {
                count[c - 'a']++;
            }

            // Bước 2: Dựng lại chuỗi đại diện (Key) đã sắp xếp - O(K)
            string key = "";
            key.reserve(strs[i].length()); // Tối ưu bộ nhớ cho chuỗi key
            for (int j = 0; j < 26; ++j) {
                if (count[j] > 0) {
                    key.append(count[j], (char)('a' + j));
                }
            }

            // Bước 3: Đẩy chỉ số vào map
            mp[key].push_back(i);
        }

        // Bước 4: Gom kết quả tối ưu bộ nhớ
        vector<vector<string>> result;
        result.reserve(mp.size()); // Cấp phát sức chứa trước cho kết quả

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            vector<string> group;
            group.reserve(it->second.size()); // Tối ưu kích thước từng nhóm
            
            for (int idx : it->second) {
                // Sử dụng std::move nếu đề bài cho phép hoán vị/tiêu thụ mảng strs gốc, 
                // hoặc sao chép thông thường nếu cần giữ nguyên strs. Ở đây ta sao chép an toàn:
                group.push_back(strs[idx]);
            }
            // Đẩy group vào result bằng std::move để triệt tiêu chi phí copy vector
            result.push_back(move(group));
        }

        return result;
    }
};