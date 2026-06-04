#include <iostream>
#include <iomanip>
using namespace std;

// ==============================================
// PROSEDUR: Menampilkan daftar barang yang dijual
// ==============================================
void tampilkanDaftarBarang() {
    cout << "\n===== DAFTAR BARANG =====" << endl;
    cout << "1. Sarden  : Rp 15.000" << endl;
    cout << "2. Sabun   : Rp  5.000" << endl;
    cout << "3. Minyak  : Rp 20.000" << endl;
    cout << "4. Gula    : Rp 18.000" << endl;
    cout << "=========================" << endl;
}

// ==============================================
// FUNGSI: Menghitung subtotal = harga satuan × jumlah
// ==============================================
double hitungSubtotal(double harga, int jumlah) {
    return harga * jumlah;
}

// ==============================================
// FUNGSI: Menghitung diskon 10% jika belanja ≥ Rp100.000
// ==============================================
double hitungDiskon(double subtotal) {
    if (subtotal >= 100000) {
        return subtotal * 0.10; // Potongan 10%
    } else {
        return 0; // Tidak ada diskon
    }
}

// ==============================================
// FUNGSI: Menghitung pajak 10% dari subtotal
// ==============================================
double hitungPajak(double subtotal) {
    return subtotal * 0.10;
}

// ==============================================
// PROSEDUR: Mencetak struk pembelian lengkap
// ==============================================
void cetakStruk(double subtotal, double diskon, double pajak, double totalAkhir) {
    cout << fixed << setprecision(2); // Format angka 2 desimal
    cout << "\n===== STRUK PEMBELIAN =====" << endl;
    cout << "Subtotal  : Rp " << subtotal << endl;
    cout << "Diskon    : Rp " << diskon << endl;
    cout << "Pajak 10% : Rp " << pajak << endl;
    cout << "---------------------------" << endl;
    cout << "TOTAL BAYAR: Rp " << totalAkhir << endl;
    cout << "===========================" << endl;
    cout << "Terima Kasih Berbelanja!" << endl;
}

// ==============================================
// Fungsi Utama Program Kasir
// ==============================================
int main() {
    char ulang;
    int pilihan, jumlah;
    double hargaBarang, subtotal, diskon, pajak, total;

    // Perulangan agar bisa belanja berulang kali
    do {
        tampilkanDaftarBarang();

        // Input pilihan barang
        cout << "\nPilih nomor barang: ";
        cin >> pilihan;

        // Tentukan harga sesuai pilihan
        switch(pilihan) {
            case 1: hargaBarang = 15000; break;
            case 2: hargaBarang = 5000; break;
            case 3: hargaBarang = 20000; break;
            case 4: hargaBarang = 18000; break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                continue; // Kembali ke awal perulangan
        }

        // Input jumlah barang
        cout << "Masukkan jumlah barang: ";
        cin >> jumlah;

        // Proses perhitungan
        subtotal = hitungSubtotal(hargaBarang, jumlah);
        diskon = hitungDiskon(subtotal);
        pajak = hitungPajak(subtotal);
        total = subtotal - diskon + pajak;

        // Tampilkan struk
        cetakStruk(subtotal, diskon, pajak, total);

        // Tanya apakah ingin belanja lagi
        cout << "\nIngin belanja lagi? (y/t): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai." << endl;
    return 0;
}
