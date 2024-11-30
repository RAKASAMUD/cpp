#include <iostream>
#include <iomanip>
#include <ctime>



int main() {
    // Dapatkan waktu saat ini
    std::time_t waktuSekarang = std::time(nullptr);
    
    // Konversi ke struktur tm (time)
    std::tm* waktuLokal = std::localtime(&waktuSekarang);
    
    // Tampilkan tanggal
    std::cout << "Tanggal saat ini: ";
    std::cout << waktuLokal->tm_mday << "-" 
              << (waktuLokal->tm_mon + 1) << "-" 
              << (waktuLokal->tm_year + 1900) << std::endl;
    
    return 0;
}