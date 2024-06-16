/*  Quản lý nhập hàng:
-Quản lý việc nhập hàng (viết hàm nhập hàng, thay đổi danh sách liên kết tượng trưng cho số hàng tương ứng)*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct hanghoa{
    long mahanghoa;
    string tenhanghoa;
    int soluong;
    long dongia;
    long tongia;
    int luongmua;
    int luongnhap;
    string nhacungcap;
};

struct NodeNH{
    hanghoa info;
    NodeNH* next;
};
typedef NodeNH* PNodeNH;
typedef NodeNH* LinkedListNH;

void init(LinkedListNH& NH){
    NH = NULL;
}

bool isEmpty(LinkedListNH& NH){
    return (NH == NULL);
}

void themHanghoanhap(LinkedListNH& NH, hanghoa K){
    PNodeNH Q = new NodeNH;
    Q->info = K;
    Q->next = NULL;
    Q->info.luongnhap = Q->info.soluong;
    if(NH == NULL){
        Q->next = NULL;
        NH = Q;
    }else{
        PNodeNH R = NH;
        while(R->next != NULL){
            R = R->next;
        }
        R->next = Q;
    }
}

PNodeNH timkiemMahanghoa(LinkedListNH& NH, long K){
    PNodeNH P = NH;
    while(P != NULL){
        if(P->info.mahanghoa == K){
            return P;
        }else{
            P = P->next;
        }
    }
    return 0;
}

int tonghanghoa(LinkedListNH& NH){
    PNodeNH P = NH;
    int tong = 0;
    if(NH == NULL){
        return 0;
    }
    while(P != NULL){
        tong++;
        P = P->next;
    }
    return tong;
}

void xoahanghoanhap(LinkedListNH& NH, PNodeNH P){
    PNodeNH R = NH;
    if(R == NULL){
        cout << "Danh sach rong hoac khong ton tai san pham." << endl;
    }else{
        while(R->next == P){
            R->next = P->next;
            delete P;

        }
    }
}

void displayQuanlyNhapHang(LinkedListNH NH){
    if(NH == NULL){
        cout << "Chua them san pham nao!" << endl;
    }
    long tongtienNhaphang = 0;
    PNodeNH P = NH;
    while(P != NULL){
        cout <<"Ma san pham: "<< P->info.mahanghoa << "\t\t" << "Ten san pham: "<< P->info.tenhanghoa << "\t\t" << "So luong nhap: " << P->info.luongnhap << "\t" << "Don gia: " << P->info.dongia << "\t\t" << "Tong tien nhap: " << P->info.luongnhap * P->info.dongia << endl;
        cout << endl;
        tongtienNhaphang += (P->info.luongnhap * P->info.dongia);
        cout << "Tong hoa don nhap hang: " << tongtienNhaphang << endl;
        cout << endl;
        P = P->next;
    }
}

void displayNhanhang(PNodeNH P){
    if(P == NULL){
        cout << "Khong ton tai! Hay thu lai." << endl;
    }else{
        cout <<"Ma san pham: "<< P->info.mahanghoa << endl;
        cout <<"Ten san pham: "<< P->info.tenhanghoa << endl;
        cout <<"So luong: " << P->info.soluong << endl;
        cout <<"Don gia: " << P->info.dongia << endl;
        long tongtien = P->info.soluong * P->info.dongia;
        cout <<"Tong tien: " << tongtien << endl;
        cout << endl;
    }
}

void exportQuanlyNhapHangToFile(LinkedListNH NH, fstream &fileout) {
    if(NH == NULL){
        fileout << "Chua them san pham nao!" << endl;
        return;
    }
    PNodeNH P = NH;
    while(P != NULL){
        fileout << P->info.tenhanghoa << ", "
                << P->info.soluong << ", "
                << P->info.dongia << ", "
                << P->info.mahanghoa << ", "
                << P->info.nhacungcap << endl;
        P = P->next;
    }
}

void importHanghoaFromFile(fstream &filein, LinkedListNH &NH) {
    while (!filein.eof()){
        hanghoa K;
        getline(filein, K.tenhanghoa, ',');
        filein >> K.soluong;
        filein.ignore(1);
        filein >> K.dongia;
        filein.ignore(1);
        filein >> K.mahanghoa;
        filein.ignore(1);
        getline(filein, K.nhacungcap);
        themHanghoanhap(NH, K);
    }
}

void menuNhaphang(){
    LinkedListNH NH;
    init(NH);
    int choice = 0;
    while(true){
        cout << endl;
        cout << "-------------------QUAN LY NHAP HANG-------------------" << endl;
        cout << endl;
        cout << "1. Danh sach hang can nhap." << endl;
        cout << "2. Them hang hoa moi." << endl;
        cout << "3. Chinh sua hang hoa moi." << endl;
        cout << "4. Xoa hang hoa moi." << endl;
        cout << "5. Them so luong san pham." << endl;
        cout << "6. Chinh sua so luong san pham nhap."  << endl;
        cout << "7. In hoa don nhap hang." << endl;
        cout << "8. Nhap hang tu file." << endl;
        cout << "9. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch(choice){
        case 1:{
            displayQuanlyNhapHang(NH);
            break;
        }
        case 2:{
            hanghoa K;
            cout << "Nhap ma hang hoa: ";
            cin >> K.mahanghoa;
            cin.ignore(); 

            cout << "Nhap ten hang hoa: ";
            getline(cin, K.tenhanghoa);

            cout << "Nha cung cap: ";
            getline(cin, K.nhacungcap);

            cout << "Nhap so luong: ";
            cin >> K.soluong;
            cin.ignore();
            
            cout << "Nhap don gia: ";
            cin >> K.dongia;


            long tongtien = K.soluong * K.dongia;
            cout << "Tong tien: " << tongtien;
        
            themHanghoanhap(NH,K);
            cout << endl;
            cout << "Nhap thanh cong!" << endl;
            break;
        }

        case 3:{
            long K;
            PNodeNH P;
            bool vonglap = true;// Thoat vong lap do while khi K = 0
            do {
                cout << "Nhap ma hang hoa can chinh sua(Nhan 0 de tro ve menu): ";
                cin >> K;
                P = timkiemMahanghoa(NH,K);
                if(K == 0){
                    vonglap = false;
                    cout << "Thoat thanh cong!";
                    break;
                }
                if(P == NULL){
                    cout << "Khong tim thay hang hoa hoac khong ton tai hang hoa" << endl;
                }
            }while(vonglap && P == NULL);
            
            while (vonglap){
                char chon;
                cout << "Chon muc can chinh sua: " << endl;
                cout << "A. Ten hang hoa." << endl;
                cout << "B. So luong." << endl;
                cout << "C. Don gia" << endl;
                cout << "D. Nha cung cap." << endl;
                cout << "E. Thoat." << endl;
                cout << "Nhap lua chon: ";
                cin >> chon;

                switch(chon){
                case 'a':
                case 'A':{
                    string K;
                    cin.ignore();
                    cout << "Nhap ten hang hoa moi: ";
                    getline(cin, K);
                    P->info.tenhanghoa = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'b':
                case 'B':{
                    int K;
                    cout << "Nhap so luong moi: ";
                    cin >> K;
                    P->info.soluong = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'c':
                case 'C':{
                    long K;
                    cout << "Nhap don gia moi: ";
                    P->info.dongia = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                case 'd':
                case 'D':{
                    string K;
                    cin.ignore();
                    cout << "Nhap nha cung cap moi: ";
                    getline(cin, K);
                    P->info.nhacungcap = K;
                    cout << endl;
                    cout << "Thay doi thanh cong!" << endl;
                    break;
                }
                
                case 'e':
                case 'E':
                    vonglap = false;
                    break;
                default:
                    cout << "Vui long thu lai!" << endl;
                    break;
                }
                cout << "Ket qua sau khi sua: " << endl;
                displayNhanhang(P);
            }
            break;
        }

        case 4:{
            long K;
            PNodeNH P;
            int luongnhap;
            bool vonglap = true;
            bool hienthi = true;
            do{
                cout << "Nhap ma hang hoa(nhap 0 de tro ve menu): ";
                cin >> K;
                if(K == 0){
                    vonglap = false;
                    hienthi = false;
                    cout << "Thoat thanh cong!" << endl;
                    break;
                }
                P = timkiemMahanghoa(NH,K);
                if(P == NULL){
                    cout << "Khong tim thay hang hoa hoac hang hoa khong ton tai." << endl;
                }
            }while(vonglap && P == NULL);
            if(hienthi && P != NULL){
                xoahanghoanhap(NH,P);
                cout << "Da xoa thanh cong!" << endl;
            }
            break;
        }

        case 5:{
            long K;
            PNodeNH P;
            int luongnhap;
            bool vonglap = true;
            bool hienthi = true;
            do{
                cout << "Nhap ma hang hoa(nhap 0 de tro ve menu): ";
                cin >> K;
                if(K == 0){
                    vonglap = false;
                    hienthi = false;
                    cout << "Thoat thanh cong!" << endl;
                    break;
                }
                P = timkiemMahanghoa(NH,K);
                if(P == NULL){
                    cout << "Khong tim thay hang hoa hoac hang hoa khong ton tai." << endl;
                }
            }while(vonglap && P == NULL);
            if(hienthi && P != NULL){
                cout << "Nhap so luong hang nhap: ";
                cin >> luongnhap;
                P->info.soluong += luongnhap;
                P->info.luongnhap = luongnhap;
                cout << "Da nhap hang thanh cong!" << endl;
                cout << "So luong ton kho da cap nhat: " << P->info.soluong << endl;
            }
            break;
        }

        case 6:{
            long K;
            PNodeNH P;
            int luongnhap;
            bool vonglap = true;
            bool hienthi = true;
            do{
                cout << "Nhap ma hang hoa(nhap 0 de tro ve menu): ";
                cin >> K;
                if(K == 0){
                    vonglap = false;
                    hienthi = false;
                    cout << "Thoat thanh cong!" << endl;
                    break;
                }
                P = timkiemMahanghoa(NH,K);
                if(P == NULL){
                    cout << "Khong tim thay hang hoa hoac hang hoa khong ton tai." << endl;
                }
            }while(vonglap && P == NULL);
            if(hienthi && P != NULL){
                cout << "Nhap so luong hang nhap thay doi: ";
                cin >> luongnhap;
                P->info.soluong -= P->info.luongnhap;
                P->info.luongnhap = luongnhap;
                P->info.soluong += luongnhap;
                cout << "Da nhap hang thanh cong!" << endl;
                cout << "So luong ton kho da cap nhat: " << P->info.soluong << endl;
            }
            break;
        }

        case 7:{
            displayQuanlyNhapHang(NH);
            fstream fileout;
            fileout.open("banhang.txt", ios::out);
            if(!fileout){
                cout << "Khong the mo file banhang.txt" << endl;
            }else{
                exportQuanlyNhapHangToFile(NH, fileout);
                cout << "Xuat danh sach nhap hang ra file banhang.txt thanh cong!" << endl;
                fileout.close();
            }
            cout << endl;
            break;
        }
        case 8:{
            fstream filein;
            filein.open("nhaphang.txt", ios::in);
            if(!filein){
                cout << "Khong the mo file nhaphang.txt" << endl;
            }else{
                importHanghoaFromFile(filein, NH);
                cout << "Nhap hang tu file thanh cong!" << endl;
                filein.close();
            }
            break;
        }
        case 9:
            cout << "Da thoat thanh cong!" << endl;
            return;
        default:
            cout << "Vui long nhap lai!" << endl;
            break;
        }
    }
}

int main(){
    menuNhaphang();
    return 0;
}