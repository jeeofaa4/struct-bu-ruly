#include <iostream>
using namespace std;

//Prosedur menampilkan biodata mahasiswa 
void tampilbiodataMahasiswa(const string &nama, int umur, const string &jurusan,
int hari,int bulan,int tahun) {
    cout << "\n[Prosedur tampilbiodataMahasiswa()]" << endl;
    cout << "Nama: " << nama << endl;
    cout << "Umur: " << umur << endl;
    cout << "Jurusan: " << jurusan << endl;
    cout << "Tanggal Lahir: " << hari << " / " << bulan << " / " << tahun << endl;
    
}

//Function menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (uts + uas + tugas) / 3;
}

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
};
struct Tanggal{ 
    int hari;
    int bulan;
    int tahun;
};
struct Nilai {
    float uts;
    float uas;
    float tugas;
};

int main() {
    Mahasiswa m1;
    m1.nama;
    m1.umur;
    m1.jurusan;
    Tanggal h1;
    h1.hari;
    h1.bulan;
    h1.tahun;
    Nilai s1;
    s1.uts;
    s1.uas;
    s1.tugas;
    
    Mahasiswa m2;
    m2.nama;
    m2.umur;
    m2.jurusan;
    Tanggal h2;
    h2.hari;
    h2.bulan;
    h2.tahun;
    Nilai s2;
    s2.uts;
    s2.uas;
    s2.tugas;
    
    int jumlah;
    cout << "Masukkan jumlah mahasiswa :" << endl;
    cin >> jumlah;
    for(int i=0; i<jumlah; i++) {
    cout << "Masukkan biodata mahasiswa ke-" << i+1 << endl;
    
    cout << "masukkan nama        : ";
    cin >> m1.nama;
    cout << endl;
   
    cout << "masukkan umur        : "; 
    cin >> m1.umur;
    cout << endl;
    
    cout << "masukkan jurusan     : ";
    cin >> m1.jurusan;
    cout << endl;
   
    cout << "masukkan hari        : ";
    cin >> h1.hari;
    cout << endl;
   
    cout << "masukkan bulan lahir : ";
    cin >> h1.bulan;
    cout << endl;
   
    cout << "masukkan tahun lahir : ";
    cin >> h1.tahun;
    cout << endl;
   
    cout << "masukkan nilai uts   : ";
    cin >> s1.uts;
    cout << endl;
   
    cout << "masukkan nilai uas   : ";
    cin >> s1.uas;
    cout << endl;
   
    cout << "masukkan nilai tugas : "; 
    cin >> s1.tugas;
    cout << endl;
   
    cout << "nama    = " << m1.nama << endl;
    cout << "umur    = " << m1.umur << endl;
    cout << "jurusan = " << m1.jurusan << endl;
    
    cout << "Tanggal lahir : "
     << h1.hari  << " / " 
     << h1.bulan << " / " 
     << h1.tahun << endl;
     
    cout << "nilai anda :"<< endl;
    cout << "nilai uts   = " << s1.uts<< endl;
    cout << "nilai uas   = " << s1.uas<< endl;
    cout << "nilai tugas = " << s1.tugas<< endl;
   
    tampilbiodataMahasiswa(m1.nama, m1.umur, m1.jurusan, h1.hari, h1.bulan, h1.tahun);
    float nilaiAkhir = hitungNilaiAkhir(s1.uts, s1.uas, s1.tugas);
    cout << "\nNilai akhir: " << nilaiAkhir << endl;
    
    for(int i=1; i<jumlah; i++) 
    cout << "Masukkan biodata mahasiswa ke-" << i+1 << endl;
    
    cout << "masukkan nama        : ";
    cin >> m2.nama;
    cout << endl;
   
    cout << "masukkan umur        : "; 
    cin >> m2.umur;
    cout << endl;
    
    cout << "masukkan jurusan     : ";
    cin >> m2.jurusan;
    cout << endl;
   
    cout << "masukkan hari        : ";
    cin >> h2.hari;
    cout << endl;
   
    cout << "masukkan bulan lahir : ";
    cin >> h2.bulan;
    cout << endl;
   
    cout << "masukkan tahun lahir : ";
    cin >> h2.tahun;
    cout << endl;
   
    cout << "masukkan nilai uts   : ";
    cin >> s2.uts;
    cout << endl;
   
    cout << "masukkan nilai uas   : ";
    cin >> s2.uas;
    cout << endl;
   
    cout << "masukkan nilai tugas : "; 
    cin >> s2.tugas;
    cout << endl;
    
    cout << "nama    = " << m2.nama << endl;
    cout << "umur    = " << m2.umur << endl;
    cout << "jurusan = " << m2.jurusan << endl;
    
    cout << "Tanggal lahir : "
     << h2.hari  << " / " 
     << h2.bulan << " / " 
     << h2.tahun << endl;
     
    cout << "nilai anda :"<< endl;
    cout << "nilai uts   = " << s2.uts<< endl;
    cout << "nilai uas   = " << s2.uas<< endl;
    cout << "nilai tugas = " << s2.tugas<< endl;

    tampilbiodataMahasiswa(m2.nama, m2.umur, m2.jurusan, h2.hari, h2.bulan, h2.tahun);
    nilaiAkhir = hitungNilaiAkhir(s2.uts, s2.uas, s2.tugas);
    cout << "\nNilai akhir: " << nilaiAkhir << endl;
}
}
