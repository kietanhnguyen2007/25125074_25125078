#pragma once
#include "uuid_v4.h"
using namespace std;
using namespace UUIDv4;
// static: Đảm bảo biến này chỉ khởi tạo cục bộ trong mỗi file .cpp, tránh lỗi Linker
static UUIDGenerator<mt19937_64> myUUIDGen;

// inline: Cho phép hàm này được include ở nhiều file .cpp mà không bị lỗi trùng lặp
inline string generateUUID() {
    UUID uuid = myUUIDGen.getUUID();
    return uuid.str();
}
/*template <typename T>
std::string getUniqueId(T* list, int currentSize) {
    std::string candidateId;
    bool isDuplicate;
    do {
        candidateId = generateUUID();
        isDuplicate = false;
        for (int i = 0; i < currentSize; i++) {
            if (list[i].ID == candidateId) {
                isDuplicate = true;
                break;
            }
        }
    } while (isDuplicate);
    return candidateId;
}*/
inline int inputInt() {
    int n;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return n;
}
inline double inputDouble() {
    double n;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return n;
}
