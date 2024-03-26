#include <iostream>
#include <vector>

void printData() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Tambah Data\n";
    std::cout << "2. Lihat Data\n";
    std::cout << "3. Ubah Data\n";
    std::cout << "4. Hapus Data\n";
    std::cout << "5. Keluar\n";
    std::cout << "Pilih menu (1-5): ";
}

void menu(std::vector<std::pair<std::string, int>>& dataList) {
    int pilih;
    std::cin >> pilih;

    switch (pilih) {
        case 1: {
            std::pair<std::string, int> newData;
            std::string name;
            int nomorIDPajak;
            std::cout << "Nama: ";
            std::cin >> name;
            newData.first = name;
            std::cout << "Nomor ID Pajak: ";
            std::cin >> nomorIDPajak;
            newData.second = nomorIDPajak;
            dataList.push_back(newData);
            break;
        }
        case 2: {
            if (dataList.empty()) {
                std::cout << "Data kosong.\n";
            } else {
                std::cout << "\nData Pajak:\n";
                for (const auto& data : dataList) {
                    std::cout << "Nama: " << data.first << ", Nomor ID Pajak: " << data.second << "\n";
                }
            }
            break;
        }
        case 3: {
            int index;
            std::cout << "Masukkan indeks data yang ingin diubah: ";
            std::cin >> index;
            if (index >= 0 && index < dataList.size()) {
                std::string name;
                int nomorIDPajak;
                std::cout << "Nama baru: ";
                std::cin >> name;
                dataList[index].first = name;
                std::cout << "Nomor ID Pajak baru: ";
                std::cin >> nomorIDPajak;
                dataList[index].second = nomorIDPajak;
            } else {
                std::cout << "Indeks tidak valid.\n";
            }
            break;
        }
        case 4: {
            int index;
            std::cout << "Masukkan indeks data yang ingin dihapus: ";
            std::cin >> index;
            if (index >= 0 && index < dataList.size()) {
                dataList.erase(dataList.begin() + index);
            } else {
                std::cout << "Indeks tidak valid.\n";
            }
            break;
        }
        case 5:
            std::cout << "Program berhenti.\n";
            return; // Exit the recursive function
        default:
            std::cout << "Menu tidak valid.\n";
            break;
    }

    printData(); // Print the menu again
    menu(dataList); // Recursive call
}

int main() {
    std::vector<std::pair<std::string, int>> dataList;
    std::string username, password;
    int attempts = 0;

    do {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (username != "nelsi" || password != "2309106120") {
            attempts++;
            std::cout << "Username atau password salah. Coba lagi.\n";
        }
        if (attempts == 3) {
            std::cout << "Anda telah melebihi batas percobaan. Program berhenti.\n";
            return 0;
        }
    } while (username != "nelsi" || password != "2309106120");

    printData();
    menu(dataList);

    return 0;
}
