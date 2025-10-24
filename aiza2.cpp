#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct nilai_Nilai {
    float uts;
    float uas;
    float tugas;
};

struct Nilai_Mapel {
    float Mtk;
    float BIn;
    float Big;
    float IPA;
};

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    string NISN;
    nilai_Nilai Nilai;
    Nilai_Mapel Mapel;
    Tanggal lahir;
};

//Function menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (uts + uas + tugas) / 3;
}

// Fuction menghitung nilai mapel
float hitungNilaiMapel(float Mtk, float BIn, float Big, float IPA) {
    return (Mtk * 0.4) + (IPA * 0.3) + (BIn * 0.2) + (Big * 0.1);
}

void input(int total, Mahasiswa m1[]) {
    for (int i = 0; i < total; i++) {
        cout << "\nMasukkan biodata mahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, m1[i].nama);

        cout << "Umur: ";
        cin >> m1[i].umur;
        cin.ignore(100, '\n');

        cout << "Jurusan: ";
        getline(cin, m1[i].jurusan);

        cout << "NISN: ";
        getline(cin, m1[i].NISN);

        cout << "Tanggal lahir (hari bulan tahun): ";
        cin >> m1[i].lahir.hari >> m1[i].lahir.bulan >> m1[i].lahir.tahun;

        cout << "Nilai UTS, UAS, Tugas: ";
        cin >> m1[i].Nilai.uts >> m1[i].Nilai.uas >> m1[i].Nilai.tugas;

        cout << "Nilai Mtk, B.Indo, B.Ing, IPA: ";
        cin >> m1[i].Mapel.Mtk >> m1[i].Mapel.BIn >> m1[i].Mapel.Big >> m1[i].Mapel.IPA;
        cin.ignore(100, '\n');
    }
}

void output(int total, Mahasiswa m1[]) {
    ofstream file("mahasiswa.txt", ios::app);

    for (int i = 0; i < total; i++) {
        float nilaiAkhir = hitungNilaiAkhir(
            m1[i].Nilai.uts, m1[i].Nilai.uas, m1[i].Nilai.tugas
        );
        float nilaiMapel = hitungNilaiMapel(
            m1[i].Mapel.Mtk, m1[i].Mapel.BIn, m1[i].Mapel.Big, m1[i].Mapel.IPA
        );

        file << m1[i].nama << "|"
             << m1[i].NISN << "|"
             << m1[i].jurusan << "|"
             << m1[i].umur << "|"
             << m1[i].lahir.hari << "-" << m1[i].lahir.bulan << "-" << m1[i].lahir.tahun << "|"
             << m1[i].Mapel.Mtk << "|" << m1[i].Mapel.BIn << "|" << m1[i].Mapel.Big << "|" << m1[i].Mapel.IPA << "|"
             << nilaiAkhir << "|" << nilaiMapel << endl;
    }

    cout << "\nData berhasil disimpan ke file mahasiswa.txt\n";
    file.close();
}

void tampilDataDariFile() {
    ifstream file("mahasiswa.txt");
    if (!file.is_open()) {
        cout << "File belum ada atau gagal dibuka.\n";
        return;
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    string nama, NISN, jurusan, tglLahir;
    float Mtk, BIn, Big, IPA, nilaiAkhir, nilaiMapel;
    int umur;
    char pemisah;

    while (getline(file, nama, '|')) {
           getline(file, NISN, '|');
           getline(file, jurusan, '|');
           file >> umur >> pemisah;
           getline(file, tglLahir, '|');
           file >> Mtk >> pemisah >> BIn >> pemisah >> Big >> pemisah >> IPA >> pemisah >> nilaiAkhir >> pemisah >> nilaiMapel;
           file.ignore();

        cout << "Nama: " << nama << endl;
        cout << "NISN: " << NISN << endl;
        cout << "Jurusan: " << jurusan << endl;
        cout << "Umur: " << umur << endl;
        cout << "Tanggal Lahir: " << tglLahir << endl;
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        cout << "Nilai Mapel: " << nilaiMapel << endl;
        cout << "----------------------------------------\n";
    }

    file.close();
}

// ===================== PENCARIAN NISN =====================
void cariSiswa(string cariNISN) {
    ifstream file("mahasiswa.txt");
    if (!file.is_open()) {
        cout << "File belum ada.\n";
        return;
    }

    string nama, NISN, jurusan, tglLahir;
    float Mtk, BIn, Big, IPA, nilaiAkhir, nilaiMapel;
    int umur;
    char pemisah;
    bool ditemukan = false;

    while (getline(file, nama, '|')) {
        getline(file, NISN, '|');
        getline(file, jurusan, '|');
        file >> umur >> pemisah;
        getline(file, tglLahir, '|');
        file >> Mtk >> pemisah >> BIn >> pemisah >> Big >> pemisah >> IPA >> pemisah >> nilaiAkhir >> pemisah >> nilaiMapel;
        file.ignore();

        if (NISN == cariNISN) {
            cout << "\n=== DATA DITEMUKAN ===\n";
            cout << "Nama: " << nama << endl;
            cout << "NISN: " << NISN << endl;
            cout << "Jurusan: " << jurusan << endl;
            cout << "Nilai Mapel: " << nilaiMapel << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) cout << "Data dengan NISN tersebut tidak ditemukan.\n";
    file.close();
}

// ===================== RANKING MAHASISWA =====================
void peringkat_mahasiswa(int total, Mahasiswa m1[]) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            float nilaiA = hitungNilaiMapel(
                m1[j].Mapel.Mtk, m1[j].Mapel.BIn, m1[j].Mapel.Big, m1[j].Mapel.IPA);
            float nilaiB = hitungNilaiMapel(
                m1[j + 1].Mapel.Mtk, m1[j + 1].Mapel.BIn, m1[j + 1].Mapel.Big, m1[j + 1].Mapel.IPA);
            if (nilaiA < nilaiB) {
                Mahasiswa temp = m1[j];
                m1[j] = m1[j + 1];
                m1[j + 1] = temp;
            }
        }
    }

    cout << "\n=== RANGKING MAHASISWA ===\n";
    for (int i = 0; i < total; i++) {
        float nilaiMapel = hitungNilaiMapel(
            m1[i].Mapel.Mtk, m1[i].Mapel.BIn, m1[i].Mapel.Big, m1[i].Mapel.IPA);
        cout << i + 1 << ". " << m1[i].nama << " | NISN: " << m1[i].NISN
             << " | Total Nilai: " << nilaiMapel << endl;
    }
}

int main() {
    int total;
    cout << "Masukkan total mahasiswa: ";
    cin >> total;
    Mahasiswa m1[100];
    input(total, m1);
    output(total, m1);
    peringkat_mahasiswa(total, m1);

    cout << "\nApakah ingin menampilkan data dari file? (1 = Ya, 0 = Tidak): ";
    int pilih;
    cin >> pilih;
    if (pilih == 1) tampilDataDariFile();

    cout << "\nCari siswa berdasarkan NISN? (1 = Ya, 0 = Tidak): ";
    cin >> pilih;
    if (pilih == 1) {
        string cariNISN;
        cout << "Masukkan NISN yang ingin dicari: ";
        cin.ignore();
        getline(cin, cariNISN);
        cariSiswa(cariNISN);
    }

    return 0;
}