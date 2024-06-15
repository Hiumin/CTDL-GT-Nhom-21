/*  Quản lý nhân viên:
-Ghi nhận thông tin về nhân viên như tên, chức vụ, thông tin liên lạc.(danh sách liên kết)*/

#include<iostream>
#include<string>
#include<cmath>
#include<chrono>
#include<ctime>
#include<limits>
using namespace std;

#define GIOVAO 7
#define PHUTVA0 30
#define GIORA 17
#define PHUTRA 0

//cham cong
struct Chamcong{
    int giovao;
    int phutvao;
    int giora;
    int phutra;
    int ngaycc;
    int thangcc;
    int namcc;
    int phutphat;//thoi gian phat di muon / tan som so voi gio quy dinh
    int phutlamthem;
};

//danh sach luong theo ngay cua tung nhan vien
struct luongtheongay{
    Chamcong chamcong;
    double tienthuong;
    double tienphat;
};

struct NodeNVLuong{
    luongtheongay data;
    NodeNVLuong* next;
};

//danh sach nhan vien
struct nhanvien{
    long id;
    string hoten;
    string chucvu;
    string sodienthoai;
    string email;
    double luongcoban;
    NodeNVLuong* Luong;
};

struct NoveNV{
    nhanvien info;
    NoveNV* next;
};
typedef NoveNV* PNodeNV;
typedef NoveNV* LinkedListNV;

void init (LinkedListNV& NV){
    NV = NULL;
}

bool isEmpty(LinkedListNV& NV){
    return (NV == NULL);
}

//them nhan vien
void themNhanvien(LinkedListNV& NV, nhanvien K){
    PNodeNV Q = new NoveNV;
    Q->info = K;
    Q->info.Luong = NULL;
    Q->next = NULL;
    if(NV == NULL){
        Q->next = NULL;
        NV = Q;
    }else{
        PNodeNV R = NV;
        while(R->next != NULL){
            R = R->next;
        }
        R->next = Q;
    }
}

void themLuongNgay(PNodeNV P, luongtheongay K) {
    if (P == NULL) {
        cout << "Chua co thong tin nhan vien." << endl;
        return;
    }

    NodeNVLuong** R = &P->info.Luong;
    while (*R != NULL && !((*R)->data.chamcong.ngaycc == K.chamcong.ngaycc && (*R)->data.chamcong.thangcc == K.chamcong.thangcc && (*R)->data.chamcong.namcc == K.chamcong.namcc)) {
        R = &(*R)->next;
    }

    if (*R != NULL) {
        // Cập nhật thông tin chấm công vào và ra nếu ngày có
        (*R)->data.chamcong.giovao = K.chamcong.giovao;
        (*R)->data.chamcong.phutvao = K.chamcong.phutvao;
        (*R)->data.chamcong.giora = K.chamcong.giora;
        (*R)->data.chamcong.phutra = K.chamcong.phutra;
        (*R)->data.chamcong.phutphat = K.chamcong.phutphat;
        (*R)->data.chamcong.phutlamthem = K.chamcong.phutlamthem;
        cout << "Da cap nhat thong tin luong cho ngay: " << K.chamcong.ngaycc << "/" << K.chamcong.thangcc << "/" << K.chamcong.namcc << endl;
    } else {
        // Nếu không có ngày đó trong danh sách, tạo node mới
        NodeNVLuong* Q = new NodeNVLuong;
        Q->data = K;
        Q->next = NULL;
        *R = Q;
        cout << "Da them thong tin luong moi cho ngay: " << K.chamcong.ngaycc << "/" << K.chamcong.thangcc << "/" << K.chamcong.namcc << endl;
    }
}

//tính lương theo ngày xác định của 1 nhân viên
void tinhLuongtheoNgay(PNodeNV P, int ngaycc, int thangcc, int namcc){
    if(P == NULL){
        cout <<"Khong có thông tin cua nhan vien." << endl;
        return;
    }
    double luongNgay = 0.0;
    NodeNVLuong* R = P->info.Luong;
    bool tim = false; // xác định xem nhân viên đã có bảng lương chưa.
    while(R != NULL){
        if(R->data.chamcong.ngaycc == ngaycc && R->data.chamcong.thangcc == thangcc && R->data.chamcong.namcc == namcc){
            R->data.tienphat = (R->data.chamcong.phutphat/60.0) * P->info.luongcoban;
            R->data.tienthuong = (R->data.chamcong.phutlamthem/60.0) * P->info.luongcoban;
            luongNgay = P->info.luongcoban*((GIORA - GIOVAO) + (PHUTRA - PHUTVA0)/60.0) - R->data.tienphat + R->data.tienthuong;
            cout << "Luong ngay " << ngaycc << "/" << thangcc << "/" << namcc << " : " << luongNgay << " VND." << endl;
            cout << "thoi gian tang ca: " << R->data.chamcong.phutlamthem << " phút." << endl;
            cout << "Tien thuong: " << R->data.tienthuong << " VND." << endl;
            cout << "thoi gian di muon va tan som: " << R->data.chamcong.phutphat << " phút." << endl;
            cout << "Tien phat: " << R->data.tienphat << " VND." << endl;
            tim = true;
            break;
        }
        R = R->next;
    }
    if(tim == false){
        cout << "Khong thay luong cua nhan vien ngay " << ngaycc << "/" << thangcc << "/" << namcc << endl;
    }
}

// tính lương theo tháng xác định của 1 nhân viên
void tinhLuongtheoThang(PNodeNV P, int thangcc , int namcc){
    if(P == NULL){
        cout << "Khong co thong tin cua nhan vien." << endl;
        return;
    }
    double luongThang = 0.0;
    double phutlamthemThang = 0;
    double tienthuongThang = 0.0;
    double phutphatThang = 0;
    double tienphatThang = 0.0;
    NodeNVLuong* R = P->info.Luong;
    bool tim = false;
    while(R != NULL){
        if(R->data.chamcong.thangcc == thangcc && R->data.chamcong.namcc == namcc){
            R->data.tienphat = (R->data.chamcong.phutphat/60.0) * P->info.luongcoban;
            R->data.tienthuong = (R->data.chamcong.phutlamthem/60.0) * P->info.luongcoban;
            double luongNgay = P->info.luongcoban*((GIORA - GIOVAO) + (PHUTRA - PHUTVA0)/60.0) - R->data.tienphat + R->data.tienthuong;
            luongThang += luongNgay;
            phutlamthemThang += R->data.chamcong.phutlamthem;
            tienthuongThang += R->data.tienthuong;
            phutphatThang += R->data.chamcong.phutphat;
            tienphatThang += R->data.tienphat;
            tim = true;
        }
        R = R->next;
    }
    if(tim == true){
        cout << "Luong thang " << thangcc << "/" << namcc << " : " << luongThang << " VND." << endl;
        cout << "thoi gian tang ca: " << phutlamthemThang << " phút." << endl;
        cout << "Tien thuong: " << tienthuongThang << " VND." << endl;
        cout << "thoi gian di muon va tan som: " << phutphatThang << " phút." << endl;
        cout << "Tien phat: " << tienphatThang << " VND." << endl;
    }else{
        cout << "Khong thay luong cua nhan vien thang " << thangcc << "/" << namcc << endl;
    }
} 

//tính lương theo năm xác định của 1 nhân viên
void tinhLuongtheoNam(PNodeNV P, int namcc){
    if(P == NULL){
        cout << "Khong co thong tin cua nhan vien." << endl;
        return;
    }
    double luongNam = 0.0;
    double phutlamthemNam = 0;
    double tienthuongNam = 0.0;
    double phutphatNam = 0;
    double tienphatNam = 0.0;
    NodeNVLuong* R = P->info.Luong;
    bool tim = false;
    while(R != NULL){
        if(R->data.chamcong.namcc == namcc){
            R->data.tienphat = (R->data.chamcong.phutphat/60.0) * P->info.luongcoban;
            R->data.tienthuong = (R->data.chamcong.phutlamthem/60.0) * P->info.luongcoban;
            double luongNgay = P->info.luongcoban*((GIORA - GIOVAO) + (PHUTRA - PHUTVA0)/60.0) - R->data.tienphat + R->data.tienthuong;

            luongNam += luongNgay;
            phutlamthemNam += R->data.chamcong.phutlamthem;
            tienthuongNam += R->data.tienthuong;
            phutphatNam += R->data.chamcong.phutphat;
            tienphatNam += R->data.tienphat;
            tim = true;
        }
        R = R->next;
    }
    if(tim == true){
        cout << "Luong nam " << namcc << " : " << luongNam << " VND." << endl;
        cout << "thoi gian tang ca: " << phutlamthemNam << " phút." << endl;
        cout << "Tien thuong: " << tienthuongNam << " VND." << endl;
        cout << "thoi gian di muon va tan som: " << phutphatNam << " phút." << endl;
        cout << "Tien phat: " << tienphatNam << " VND." << endl;
    }else{
        cout << "Khong thay luong cua nhan vien thang " << namcc << endl;
    }
}

//tim kiem nhan vien bang ID
PNodeNV timkiemID(LinkedListNV& NV, long K){
    PNodeNV P = NV;
    while(P != NULL){
        if(P->info.id == K){
            return P;
        }else{
            P = P->next;
        }
    }
    return NULL;
}

//tong so nhan vien
int tongNhanvien(LinkedListNV& NV){
    PNodeNV P = NV;
    int tong = 0;
    while(P != NULL){
        tong++;
        P = P->next;
    }
    return tong;
}

//xoa nhan vien
void xoaNhanvien(LinkedListNV& NV, PNodeNV P){
   if (NV == NULL || P == NULL) {
        cout << "Danh sach rong hoac nhan vien khong ton tai." << endl;
        return;
    }
    if (NV == P) {
        NV = NV->next;
        delete P;
        return;
    }
    PNodeNV R = NV;
    while (R->next != NULL && R->next != P) {
        R = R->next;
    }
    if (R->next == NULL) {
        cout << "Khong tim thay nhan vien." << endl;
    } else {
        R->next = P->next;
        delete P;
    }
}

//sap xep nhan vien theo chieu tang dan hoac giam dan ID
//sap xep theo phuong phap bubble sort
void sapxepNhanVien(LinkedListNV& NV, bool thutu = true) {
    if (NV == NULL || NV->next == NULL) {
        cout << "Danh sach rong. Vui long thu lai!" << endl;
        return;
    }

    bool sorted;
    do {
        sorted = false;
        PNodeNV R = NV;
        while (R->next != NULL) {
            if (thutu ? R->info.id > R->next->info.id : R->info.id < R->next->info.id) {
                swap(R->info, R->next->info);
                sorted = true;
            }
            R = R->next;
        }
    } while (sorted);
}

//tìm lương max min cho cả danh sách
void timLuongMaxMinThang(LinkedListNV NV, int thang, int nam) {
    PNodeNV P = NV;
    while (P != NULL) {
        NodeNVLuong* R = P->info.Luong;
        double luongMax = 0.0;
        double luongMin = numeric_limits<double>::max(); // Khởi tạo với giá trị lớn nhất

        while (R != NULL) {
            if (R->data.chamcong.thangcc == thang && R->data.chamcong.namcc == nam) {
                double tienPhat = (R->data.chamcong.phutphat / 60.0) * P->info.luongcoban;
                double tienThuong = (R->data.chamcong.phutlamthem / 60.0) * P->info.luongcoban;
                double luongNgay = P->info.luongcoban * ((GIORA - GIOVAO) + (PHUTRA - PHUTVA0) / 60.0) - tienPhat + tienThuong;
                if (luongNgay > luongMax) {
                    luongMax = luongNgay;
                }
                if (luongNgay < luongMin) {
                    luongMin = luongNgay;
                }
            }
            R = R->next;
        }

        if (luongMin == numeric_limits<double>::max()){ // Kiểm tra xem có lương min không
            luongMin = 0.0;
        }
        cout << "Nhan vien: " << P->info.id << " - " << P->info.hoten << endl;
        cout << "Luong Max thang " << thang << "/" << nam << ": " << luongMax << " VND" << endl;
        cout << "Luong Min thang " << thang << "/" << nam << ": " << luongMin << " VND" << endl;
        P = P->next;
    }
}

void timLuongMaxMinThangMotNhanVien(PNodeNV P, int thang, int nam) {
    if (P == NULL) {
        cout << "Khong tim thay nhan vien!" << endl;
        return;
    }

    NodeNVLuong* R = P->info.Luong;
    double luongMax = 0.0;
    double luongMin = numeric_limits<double>::max(); // Khởi tạo với giá trị lớn nhất

    while (R != NULL) {
        if (R->data.chamcong.thangcc == thang && R->data.chamcong.namcc == nam) {
            double tienPhat = (R->data.chamcong.phutphat / 60.0) * P->info.luongcoban;
            double tienThuong = (R->data.chamcong.phutlamthem / 60.0) * P->info.luongcoban;
            double luongNgay = P->info.luongcoban * ((GIORA - GIOVAO) + (PHUTRA - PHUTVA0) / 60.0) - tienPhat + tienThuong;
            if (luongNgay > luongMax) {
                luongMax = luongNgay;
            }
            if (luongNgay < luongMin) {
                luongMin = luongNgay;
            }
        }
        R = R->next;
    }

    if (luongMin == numeric_limits<double>::max()){ // Kiểm tra xem có lương min không
        luongMin = 0.0;
    }
    cout << "Nhan vien: " << P->info.id << " - " << P->info.hoten << endl;
    cout << "Luong Max thang " << thang << "/" << nam << ": " << luongMax << " VND" << endl;
    cout << "Luong Min thang " << thang << "/" << nam << ": " << luongMin << " VND" << endl;
}


//in ra danh sach nhan vien
void displayQuanlynhanvien(LinkedListNV NV){
    if(NV == NULL){
        cout << "Chua co thong tin cua bat cu nhan vien nao!" << endl;
        return;
    }
    PNodeNV P = NV;
    while(P != NULL){
        cout <<"ID: "<< P->info.id << endl;
        cout <<"Ho ten: "<< P->info.hoten << endl;
        cout <<"So dien thoai: " << P->info.sodienthoai << endl;
        cout << "Email: " << P->info.email << endl;
        cout << "Chuc vu: " << P->info.chucvu << endl;
        cout << "Luong co ban(VND/1h): " << P->info.luongcoban << endl;
        cout << endl;
        P = P->next;
    }
}
//in ra 1 nhan vien xac dinh
void displaynhanvien(PNodeNV P){
    if(P == NULL){
        cout << "Khong tim thay! Hay thu lai." << endl;
    }else{
        cout <<"ID: "<< P->info.id << endl;
        cout <<"Ho ten: "<< P->info.hoten << endl;
        cout <<"So dien thoai: " << P->info.sodienthoai << endl;
        cout << "Email: " << P->info.email << endl;
        cout << "Chuc vu: " << P->info.chucvu << endl;
        cout << "Luong co ban(VND/1h): " << P->info.luongcoban << endl;
        cout << endl;
    }
}
//menu quan ly nhan vien
void menuNhanvien(){
    LinkedListNV NV;
    init(NV);
    int choice = 0;

    while(true){
        cout << endl;
        cout << "-------------------QUAN LY NHAN VIEN-------------------" << endl;
        cout << endl;
        cout << "1. Thong tin nhan vien." << endl;
        cout << "2. Them nhan vien." << endl;
        cout << "3. Tim kiem nhan vien." << endl;
        cout << "4. Chinh sua thong tin nhan vien." << endl;
        cout << "5. Xoa nhan vien." << endl;
        cout << "6. Cham cong." << endl;
        cout << "7. Kiem tra luong nhan vien." << endl;
        cout << "8. In hoa don luong." << endl;
        cout << "9. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice){
        case 1:{
            displayQuanlynhanvien(NV);
            cout << endl;
            cout << "Tong nhan vien hien tai: " << tongNhanvien(NV) << endl;
            break;
        }

        case 2:{
            nhanvien K;
            PNodeNV P;
            bool vonglap = true;
            do{
                cout << "Nhap ID: ";
                cin >> K.id;
                cin.ignore();
                P = NV;
                while(P != NULL){
                    if(P->info.id == K.id){
                        cout << "ID da bi trung! Xin nhap lai ID khac." << endl;
                        vonglap = false;
                        break;
                    }
                    P = P->next;
                }
            }while(vonglap == false);

            cout << "Nhap ho ten: ";
            getline(cin, K.hoten);

            cout << "Nhap so dien thoai: ";
            getline(cin, K.sodienthoai);

            cout << "Nhap email: ";
            getline(cin, K.email);

            cout << "Nhap chuc vu: ";
            getline(cin, K.chucvu);

            cout << "Nhap luong co ban(VND/1h): ";
            cin >> K.luongcoban;
            cin.ignore();

            themNhanvien(NV,K);
            cout << endl;
            cout << "Nhap thanh cong!" << endl;
            break;
        }

        case 3:{
            long K;
            PNodeNV P;
            bool vonglap = true; // Thoat vong lap do while khi K = 0
            bool hienthi = true; // ngan ham displaynhanvien chay khi K = 0
            do {
                cout << "Nhap ID cua nhan vien can tim kiem(Nhan 0 de tro ve menu): ";
                cin >> K;
                if(K == 0){
                    vonglap = false;
                    hienthi = false;
                    cout << "Thoat thanh cong!";
                    break;
                }
                P = timkiemID(NV,K);
                if(P == NULL){
                    cout << "Khong tim thay nhan vien. Vui long thu lai!" << endl;
                }
            }while( vonglap && P == NULL);
            if(hienthi && P != NULL){
                displaynhanvien(P);
            }
            break;
        }

        case 4:{
            long K;
            PNodeNV P;
            bool vonglap = true;// Thoat vong lap do while khi K = 0
            do {
                cout << "Nhap ID cua nhan vien can chinh sua(Nhan 0 de tro ve menu): ";
                cin >> K;
                P = timkiemID(NV,K);
                if(K == 0){
                    vonglap = false;
                    cout << "Thoat thanh cong!";
                    break;
                }
                if(P == NULL){
                    cout << "Khong tim thay nhan vien. Vui long thu lai!" << endl;
                }
            }while(vonglap && P == NULL);
            
            while (vonglap){
                char chon;
                cout << "Chon muc can chinh sua: " << endl;
                cout << "A. Ho ten." << endl;
                cout << "B. So dien thoai." << endl;
                cout << "C. Email." << endl;
                cout << "D. Chuc vu." << endl;
                cout << "E. Luong co ban(VND/1h)." << endl;
                cout << "F. Thoat." << endl;
                cout << "Nhap lua chon: ";
                cin >> chon;

                switch(chon){
                case 'a':
                case 'A':{
                    string K;
                    cin.ignore();
                    cout << "Nhap ho ten moi: ";
                    getline(cin, K);
                    P->info.hoten = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'b':
                case 'B':{
                    string K;
                    cin.ignore();
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, K);
                    P->info.sodienthoai = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'c':
                case 'C':{
                    string K;
                    cin.ignore();
                    cout << "Nhap email moi: ";
                    getline(cin, K);
                    P->info.email = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'd':
                case 'D':{
                    string K;
                    cin.ignore();
                    cout << "Nhap chuc vu moi: ";
                    getline(cin, K);
                    P->info.chucvu = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'e':
                case 'E':{
                    long K;
                    cout << "Nhap luong co ban(VND/1h) moi: ";
                    cin >> K;
                    P->info.luongcoban = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'f':
                case 'F':
                    vonglap = false;
                    break;
                default:
                    cout << "Vui long thu lai!" << endl;
                    break;
                }
                cout << "Ket qua sau khi sua: " << endl;
                displaynhanvien(P);
            }
            break;
        }

        case 5:{
            long K;
            PNodeNV P;
            bool vonglap = true; // Thoat vong lap do while khi K = 0
            bool hienthi = true; // ngan ham displaynhanvien chay khi K = 0
            do {
                cout << "Nhap ID cua nhan vien can xoa(Nhan 0 de tro ve menu): ";
                cin >> K;
                if(K == 0){
                    vonglap = false;
                    hienthi = false;
                    cout << "Thoat thanh cong!";
                    break;
                }
                P = timkiemID(NV,K);
                if(P == NULL){
                    cout << "Khong tim thay nhan vien. Vui long thu lai!" << endl;
                }
            }while( vonglap && P == NULL);
            if(hienthi && P != NULL){
                xoaNhanvien(NV,P);
            }
            break;
        }


        case 6:{
            luongtheongay K;
            long ID;
            PNodeNV P = NULL;
            bool vonglap = true;// Thoat vong lap do while khi ID = 0
            char chon;
            do{
                cout << "Nhap ID cua nhan vien can chinh sua(Nhan 0 de tro ve menu): ";
                cin >> ID;
                if(ID == 0){
                    cout << "Thoat thanh cong!";
                    vonglap = false;
                    break;
                }
                P = timkiemID(NV,ID);
                if(P == NULL){
                    cout << "Khong tim thay nhan vien. Vui long thu lai!" << endl;
                    continue;
                }
                auto now = chrono::system_clock::now();
                time_t now_time = chrono::system_clock::to_time_t(now);// Chuyển đổi thời gian hiện tại sang time_t
                struct tm *timeinfo = localtime(&now_time);// Chuyển đổi time_t sang struct tm để truy xuất các thành phần thời gian
                K.chamcong.ngaycc = timeinfo->tm_mday; // Ngày
                K.chamcong.thangcc = timeinfo->tm_mon + 1; // Tháng (tm_mon bắt đầu từ 0)
                K.chamcong.namcc = timeinfo->tm_year + 1900; // Năm
                
                    cout << "Gio cham cong: " << endl;
                    cout << "A. Vao." << endl;
                    cout << "B. Ra." << endl;
                    cout << "C. Thoat." << endl;
                    cout << "Nhap lua chon: ";
                    cin >> chon;

                    switch (chon){
                    case 'a':
                    case 'A':{
                        K.chamcong.giovao = timeinfo->tm_hour;
                        K.chamcong.phutvao = timeinfo->tm_min;
                        cout << "Thoi gian vao: " << K.chamcong.giovao << ":" << K.chamcong.phutvao << " " << K.chamcong.ngaycc << "/" << K.chamcong.thangcc << "/" << K.chamcong.namcc << endl;
                        K.chamcong.phutphat = (K.chamcong.giovao - GIOVAO)*60 + ( K.chamcong.phutvao - PHUTVA0);
                        if(K.chamcong.phutphat <= 0){
                            K.chamcong.phutphat = 0;
                            cout << "Ban da cham cong thanh cong!" << endl;
                        }else{
                            cout << "Ban da di muon " << K.chamcong.phutphat << " phut." << endl;
                        }
                        break;
                    }
                    case 'b': 
                    case 'B':{
                        K.chamcong.giora = timeinfo->tm_hour;
                        K.chamcong.phutra = timeinfo->tm_min;
                        cout << "Thoi gian ra: " << K.chamcong.giora << ":" << K.chamcong.phutra << " " << K.chamcong.ngaycc << "/" << K.chamcong.thangcc << "/" << K.chamcong.namcc << endl;
                        int tg = (K.chamcong.giora - GIORA)*60 + (K.chamcong.phutra - PHUTRA);
                        if(tg == 0){
                            cout << "Ban da cham cong thanh cong!" << endl;
                        }else if(tg < 0){
                            K.chamcong.phutphat = K.chamcong.phutphat + abs(tg);
                            cout << "Ban da tan lam som " << abs(tg) << " phut." << endl;
                        }else{
                            K.chamcong.phutlamthem = tg;
                            cout << "Ban da lam them duoc " << tg << " phut." << endl;
                        }
                        break;
                    }
                    case 'c':
                    case 'C':
                        cout << "Thoat thanh cong." << endl;
                        break;
                    default:
                        cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
                        continue;
                    }
                    themLuongNgay(P,K);
                    vonglap = false;
            }while(vonglap);
            break;
        }

        case 7:{
            long K;
            int ngaycc;
            int thangcc;
            int namcc;
            PNodeNV P;
            bool vonglap = true;
            do {
                cout << "Nhap ID cua nhan vien can tim kiem(Nhan 0 de tro ve menu): ";
                cin >> K;
                P = timkiemID(NV,K);
                if(K == 0){
                    vonglap = false;
                    cout << "Thoat thanh cong!";
                    break;
                }
                if(P == NULL){
                    cout << "Khong tim thay nhan vien. Vui long thu lai!" << endl;
                }
            }while(vonglap && P == NULL);
            while(vonglap){
                char chon;
                cout << "Tinh luong theo: " << endl;
                cout << "A. Ngay." << endl;
                cout << "B. Thang." << endl;
                cout << "C. Nam." << endl;
                cout << "D. Thoat." << endl;
                cout << "Nhap lua chon: ";
                cin >> chon;
                switch(chon){
                    case 'A':
                    case 'a':{
                        cout << "Nhap ngay: ";
                        cin >> ngaycc;
                        cout << "Nhap thang: ";
                        cin >> thangcc;
                        cout << "Nhap nam: ";
                        cin >> namcc;
                        cout << endl;
                        tinhLuongtheoNgay(P,ngaycc,thangcc,namcc);
                        break;
                    }
                    case 'B':
                    case 'b':{
                        cout << "Nhap thang: ";
                        cin >> thangcc;
                        cout << "Nhap nam: ";
                        cin >> namcc;
                        cout << endl;
                        tinhLuongtheoThang(P,thangcc,namcc);
                        break;
                    }
                    case 'C':
                    case 'c':{
                        cout << "Nhap nam: ";
                        cin >> namcc;
                        cout << endl;
                        tinhLuongtheoNam(P,namcc);
                        break;
                    }
                    case 'D':
                    case 'd':
                        vonglap = false;
                        break;
                    default:
                        cout << "Vui long thu lai!" << endl;
                        break;
                }
            }
            break;
        }
       
        case 8:{
            double tongtienluongThang = 0.0;
            PNodeNV P = NV;
            int thangcc;
            int namcc;
            cout << "Nhap thang: ";
            cin >> thangcc;
            cout << "Nhap nam: ";
            cin >> namcc;
            cin.ignore();
            if(NV == NULL){
                cout << "Khong co nhan vien nao trong danh sach." << endl;
                break;
            }
            while(P != NULL){
                double luongThang = 0.0;
                NodeNVLuong* Q = P->info.Luong;
                while(Q != NULL){
                    if (Q->data.chamcong.thangcc == thangcc && Q->data.chamcong.namcc == namcc) {
                        Q->data.tienphat = (Q->data.chamcong.phutphat / 60.0) * P->info.luongcoban;
                        Q->data.tienthuong = (Q->data.chamcong.phutlamthem / 60.0) * P->info.luongcoban;
                        double luongNgay = P->info.luongcoban * ((GIORA - GIOVAO) + (PHUTRA - PHUTVA0) / 60.0) - Q->data.tienphat + Q->data.tienthuong;
                        luongThang += luongNgay;
                    }
                    Q = Q->next;
                }
                tongtienluongThang += luongThang;
                P = P->next;

            }
            cout << "Tong tien luong thang " << thangcc << "/" << namcc << " : " << tongtienluongThang << endl;
            break;

        }
        case 9:
            cout << "Da thoat thanh cong!" << endl;
            return;
        
        default:
            cout << "Vui long thu lai!" << endl;
            break;
        }
    }      
}

int main(){
    menuNhanvien();
    return 0;
}
