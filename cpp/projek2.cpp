#include <bits/stdc++.h>
using namespace std;

class Pasien;
class Dokter;
class Pendaftaran;
class Penyakit;
class Pembayaran;
class Spesialisasi;
class Kefokusan;

class MainApp
{
private:
    vector<shared_ptr<Pasien>> dataPasien;
    vector<shared_ptr<Pendaftaran>> Daftar;
    vector<shared_ptr<Penyakit>> dataPenyakit;
    vector<shared_ptr<Pembayaran>> Payment;
    vector<shared_ptr<Dokter>> dataDokter;
    time_t tanggalDaftar;

public:
    MainApp();
    void addPasien(const string &name, int age, const string tempatTinggal, const string gender);
    void addTanggalDaftar(time_t TglDaftar);
    void addPendaftaran(const string &keperluan, string const &tanggalDatang);
    void addDokter(const string &nama, const string &jabatan, int NIP);
    void addPenyakit(const string &penyakit);
    void addPembayaran(const string &payment, const string &bank, int noRek, const string &namaPemilik, int noBPJS);
    void inputPasien();
    void inputTanggalDaftar();
    void inputPendaftaran();
    void inputDokter();
    void inputPenyakit();
    void inputPembayaran();
    void displayPasien() const;
    void displayTanggalDaftar();
    void displayPendaftaran() const;
    void displayDokter() const;
    void displayPenyakit() const;
    void displayPembayaran() const;
};

MainApp::MainApp() : dataPasien(), tanggalDaftar(), Daftar(), dataDokter(), dataPenyakit(), Payment() {}

/*========== CLASS PASIEN ==========*/
class Pasien
{
private:
    string Nama;
    int Umur;
    string TempatTinggal;
    string Kelamin;

public:
    Pasien(const string name, int age, const string tempatTinggal, const string gender);

    void displayPasien() const;
};

/*========== MAIN PASIEN ==========*/

void MainApp::addPasien(const string &name, int age, const string tempatTinggal, const string gender)
{
    dataPasien.push_back(make_shared<Pasien>(name, age, tempatTinggal, gender));
}

void MainApp::inputPasien()
{
    string name, tempatTinggal, gender;
    int age;

    cout << "Masukkan nama pasien: ";
    getline(cin, name);
    cout << "Masukkan umur pasien: ";
    cin >> age;
    cin.ignore();
    cout << "Masukkan tempat tinggal pasien: ";
    getline(cin, tempatTinggal);
    cout << "Masukkan jenis kelamin pasien: ";
    getline(cin, gender);

    addPasien(name, age, tempatTinggal, gender);
}

void MainApp::displayPasien() const
{
    cout << "\nCurrent Patient: " << endl;
    for (const auto &pasien : dataPasien)
    {
        pasien->displayPasien();
    }
}

Pasien::Pasien(const string name, int age, const string tempatTinggal, const string gender)
    : Nama(name), Umur(age), TempatTinggal(tempatTinggal), Kelamin(gender) {}

void Pasien::displayPasien() const
{
    cout << "Nama\t\t: " << Nama << endl;
    cout << "Umur\t\t: " << Umur << endl;
    cout << "Tempat tinggal\t: " << TempatTinggal << endl;
    cout << "Kelamin\t\t: " << Kelamin << endl;
}

/*========== CLASS TANGGAL ==========*/
class TanggalDaftar
{
private:
    time_t TglDaftar;

public:
    TanggalDaftar(time_t tglDaftar);

    void displayTanggalDaftar() ;
};

/*=========== MAIN TANGGAL SKRG ===========*/

void MainApp::addTanggalDaftar(time_t TglDaftar){
}

void MainApp::inputTanggalDaftar(){
    time_t Tgldaftar = time(nullptr);

    tm* waktuLokal =localtime(&Tgldaftar);
    
    // Tampilkan tanggal
    cout << "Tanggal Daftar\t: ";
    cout << waktuLokal->tm_mday << "-" 
              << (waktuLokal->tm_mon + 1) << "-" 
              << (waktuLokal->tm_year + 1900) << endl;

    addTanggalDaftar(Tgldaftar);
}

void MainApp::displayTanggalDaftar(){
    time_t Tgldaftar = time(nullptr);
    
    // Konversi ke struktur tm (time)
    tm* waktuLokal =localtime(&Tgldaftar);
    
    // Tampilkan tanggal
    cout << "Tanggal Daftar\t: ";
    cout << waktuLokal->tm_mday << "-" 
              << (waktuLokal->tm_mon + 1) << "-" 
              << (waktuLokal->tm_year + 1900) << endl;
    

}

TanggalDaftar::TanggalDaftar(time_t Tgldaftar) 
: TglDaftar(Tgldaftar) {}

void TanggalDaftar::displayTanggalDaftar() {
    cout << "Tanggal Sekarang : "<< endl;
}


/*========== CLASS PENDAFTARAN ==========*/
class Pendaftaran
{
private:
    string Keperluan;
    string TanggalDatang;

public:
    Pendaftaran(const string &keperluan, string const &tanggalDatang);
    void displayPendaftaran() const;
};



/*========== MAIN PENDAFTARAN ==========*/

void MainApp::addPendaftaran(const string &keperluan, string const &tanggalDatang){
    Daftar.push_back(make_shared<Pendaftaran>(keperluan, tanggalDatang));
}

void MainApp::inputPendaftaran(){
    string keperluan, tglDatang;

    cout<<"\n=> Kontrol" << endl;
    cout << "=> Periksa " << endl;
    cin >> keperluan;
    cin.ignore();
     if (keperluan != "Kontrol" && keperluan != "kontrol" && keperluan != "Periksa" && keperluan != "periksa")
    {
        cout << "\nKeperluan tidak ditemukan" << endl;
        terminate();
    }
    else
    {
    }

    addPendaftaran(keperluan, tglDatang);
}

void MainApp::displayPendaftaran() const
{
    for (const auto &keperluan : Daftar)
    {
        keperluan->displayPendaftaran();
    }
}
Pendaftaran::Pendaftaran(const string &keperluan, string const &tanggalDatang)
    : Keperluan(keperluan), TanggalDatang(tanggalDatang) {}

void Pendaftaran::displayPendaftaran() const
{
    cout << "keperluan\t: " << Keperluan << endl;
}

/*========== CLASS PENYAKIT ==========*/
class Penyakit
{
private:
    string penyakit;

public:
    Penyakit(const string &disease);

    void displayPenyakit() const;
};

/*========== MAIN PENYAKIT ==========*/

void MainApp::addPenyakit(const string &penyakit)
{
    dataPenyakit.push_back(make_shared<Penyakit>(penyakit));
}

void MainApp::inputPenyakit()
{
    string penyakit;

    cout << "\n=> Umum" << endl;
    cout << "=> Internis" << endl;
    cout << "Pilih penyakit anda: ";
    cin >> penyakit;
    cin.ignore();

    if (penyakit != "Umum" && penyakit != "umum" && penyakit != "Internis" && penyakit != "internis")
    {
        cout << "\nPenyakit tidak ditemukan" << endl;
        terminate();
    }
    else
    {
    }

    addPenyakit(penyakit);
}

void MainApp::displayPenyakit() const
{

    for (const auto &penyakit : dataPenyakit)
    {
        penyakit->displayPenyakit();
    }
}

Penyakit::Penyakit(const string &disease)
    : penyakit(disease) {}

void Penyakit::displayPenyakit() const
{
    cout << "Penyakit\t: " << penyakit << endl;
}

/*========== CLASS PEMBAYARAN ==========*/
class Pembayaran
{
private:
    string jenisPembayaran;
    string bank;
    int NoRek;
    string NamaPemilik;
    int NoBPJS;

public:
    Pembayaran(const string &payment, const string &bank, int noRek, const string &namaPemilik, int noBPJS);

    void displayPembayaran() const;
};

/*========== MAIN PEMBAYARAN ==========*/

void MainApp::addPembayaran(const string &pembayaran, const string &bank, int noRek, const string &namaPemilik, int noBPJS)
{
    Payment.push_back(make_shared<Pembayaran>(pembayaran, bank, noRek, namaPemilik, noBPJS));
}

void MainApp::inputPembayaran()
{
    string payment, Bank, namaPemilik;
    int noRek, noBPJS;
    int test;

    cout << "\n=> Pribadi" << endl;
    cout << "=> Asuransi" << endl;
    cout << "Pilih jenis pembayaran anda: ";
    cin >> payment;
    cin.ignore();

    if (payment == "Pribadi" || payment == "pribadi")
    {
        cout << "Masukkan Bank: ";
        getline(cin, Bank);
        cout << "Masukkan Nomor Rekening: ";
        cin >> noRek;
        cin.ignore();
        cout << "Masukkan Nama Pemilik Rekening: ";
        getline(cin, namaPemilik);
    }
    else if (payment == "Asuransi" || payment == "asuransi")
    {
        cout << "Masukkan Nomor BPJS: ";
        cin >> noBPJS;
        cin.ignore();
    }
    else
    {
        cout << "Opsi pembayaran tidak tersedia";
    }
    addPembayaran(payment, Bank, noRek, namaPemilik, noBPJS);
}

void MainApp::displayPembayaran() const
{
    for (const auto &pembayaran : Payment)
    {
        pembayaran->displayPembayaran();
    }
}

Pembayaran::Pembayaran(const string &payment, const string &Bank, int noRek, const string &namaPemilik, int noBPJS)
    : jenisPembayaran(payment), bank(Bank), NoRek(noRek), NamaPemilik(namaPemilik), NoBPJS(noBPJS) {}

void Pembayaran::displayPembayaran() const
{
    cout << "Pembayaran\t: " << jenisPembayaran << endl;
    cout << "Bank\t\t: " << bank << endl;
    cout << "Nomor Rekening\t: " << NoRek << endl;
    cout << "Nama Pemilik\t: " << NamaPemilik << endl;
    cout << "Nomor BPJS\t: " << NoBPJS << endl;
}

/*========== CLASS DOKTER ==========*/
class Dokter
{
private:
    string Nama;
    string Pangkat;
    int NIP;

public:
    Dokter(const string nama, const string jabatan, int NIP);

    void displayDokter() const;
};

/*========== MAIN DOKTER ==========*/

void MainApp::addDokter(const string &nama, const string &jabatan, int NIP)
{
    dataDokter.push_back(make_shared<Dokter>(nama, jabatan, NIP));
}

void MainApp::inputDokter()
{
    string Nama, Jabatan;
    int NIP;

    cout << "Masukkan nama Dokter: ";
    getline(cin, Nama);
    cout << "Masukkan pangkat Dokter: ";
    getline(cin, Jabatan);
    cout << "Masukkan NIP Dokter: ";
    cin >> NIP;

    addDokter(Nama, Jabatan, NIP);
}

void MainApp::displayDokter() const
{
    cout << "\nCurrent Doctors: " << endl;
    for (const auto &dokter : dataDokter)
    {
        dokter->displayDokter();
    }
}

Dokter::Dokter(const string nama, const string jabatan, int NIP)
    : Nama(nama), Pangkat(jabatan), NIP(NIP) {}

void Dokter::displayDokter() const
{
    cout << "Nama\t\t: " << Nama << endl;
    cout << "Pangkat\t\t: " << Pangkat << endl;
    cout << "NIP\t\t: " << NIP << endl
         << endl;
}

int main(int argc, char const *argv[])
{
    MainApp klinik;
    char pilut, pildok;
    string passwordAdmin, passwordDokter;
    passwordAdmin = "KlinikSehat24%";

    cout << "=========== SELAMAT DATANG =========" << endl;
    cout << "===== DI APLIKASI KLINIK SEHAT =====" << endl;
    cout << "\nA. Pasien" << endl;
    cout << "B. Dokter" << endl;
    cout << "Anda sebagai: ";
    cin >> pilut;
    cin.ignore();

    if (pilut == 'A')
    {   klinik.inputPendaftaran();
        klinik.inputTanggalDaftar();
        klinik.inputPasien();
        klinik.inputPenyakit();
        klinik.inputPembayaran();
        klinik.displayPasien();
        klinik.displayTanggalDaftar();
        klinik.displayPendaftaran();
        klinik.displayPenyakit();
        klinik.displayPembayaran();
    }
    else if (pilut == 'B')
    {
        cout << "Masukkan Password: ";
        cin >> passwordDokter;
        cin.ignore();
        if (passwordDokter == passwordAdmin)
        {
            do
            {
                klinik.inputDokter();
                cout << "\nApakah ingin menambahkan Dokter lagi? (Y/N): ";
                cin >> pildok;
                cin.ignore();
            } while (pildok == 'Y');

            klinik.displayDokter();
        }
        else
        {
            cout << "Password anda salah!" << endl;
        }
    }

    return 0;
}
