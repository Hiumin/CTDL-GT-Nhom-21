//KHAI BAO THU VIEN
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<string>
#include<cmath>
#include<chrono>
#include<ctime>
#include<fstream>  

using namespace std;

#define MAX 100
#define GIOVAO 7
#define PHUTVA0 30
#define GIORA 17
#define PHUTRA 0

// KHAI BAO DANH SACH HANG HOA
struct hanghoa{
    string tenhanghoa;
    long soluong;
    long mahanghoa, dongia, tonggia, luongmua;
    int luongnhap;
    string nhacungcap;
};
struct Node{
    hanghoa h;
    Node* next;
};
typedef Node* PNode;
typedef Node* Linkedlist; //H
typedef Node* QNode;
typedef Node* Listbill; //L
struct stackhoadon{
    Listbill bill;
    int mahoadon;
    stackhoadon* billnext;
};
typedef stackhoadon* billnode;
typedef stackhoadon* billlist;

long doanhthu = 0, tongtien = 0;
int mua = 0;
struct listnv{
    long id;
    listnv* Knext;
};

void InitH(Linkedlist &H){
    H = NULL;
}
void InitL(Listbill &L){
    L = NULL;
}
void InitK(listnv* &K){
    K = NULL;
}
void InitJ(billlist &J){
    J = NULL;
}
void InitTemp(Listbill &temp){
    temp = NULL;
}
bool isEmpty (PNode &H){
	return (H==NULL);
}

// KHAI BAO DANH SACH NHAP HANG
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

//KHAI BAO DANH SACH CHAM CONG
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

//KHAI BAO DANH SACH NHAN VIEN
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
// DANG.
void menu(Listbill &temp,Linkedlist &H, Listbill &L, listnv* &K, billlist &J, long &doanhthu);
void menumua(Listbill &temp,Linkedlist &H, Listbill &L, billlist &J,listnv* &K, long &doanhthu);
void menunv(Listbill &temp,Listbill &L, long &doanhthu,listnv* &K, billlist &J, Linkedlist &H);
void giohang(Linkedlist &H, Listbill &L, Listbill &temp, billlist &J,listnv* &K, long &doanhthu,long tongtien);
void inserthoadon(billlist &J, Listbill &L);
void deletehoadon(billlist &J);
void deleteallhoadon(billlist &J);
void Clear(Listbill &temp, Listbill &L, Linkedlist &H,listnv* &K, billlist &J,long &doanhthu);
void muahang(Linkedlist &H, long choice, Listbill &L, Listbill &temp, listnv* &K, billlist &J, int mua,long &doanhthu);
void insertgiohang(Linkedlist &H, Listbill &L,billlist &J, listnv* &K, Listbill &temp,long choice, int mua);
void deletegiohang(Listbill &temp,Linkedlist &H, Listbill &L, billlist &J,listnv* &K, long &doanhthu);
void displayhoadon(Listbill &L, Listbill &temp, long tongtien,billlist &J,Linkedlist &H, listnv* &K, long &doanhthu);
void display(Listbill &temp);
void swap(Listbill &L, Listbill &temp);
void tinhhangton(Linkedlist &H, long maso, long mua);
//DUNG.
void InsertFirst (Linkedlist &H, PNode q);
void InsertLast (Linkedlist &H, PNode q);
void deletenode(Linkedlist &H,PNode p);
PNode searchNode (Linkedlist H, int x);
void in(hanghoa h);
void listnhaphang (PNode p);
void importFile(fstream &filein, hanghoa &a);
PNode createnode (hanghoa a);
void importlist (fstream &filein, Linkedlist &H);
void exportFile(fstream &fileout, PNode a);
void showlist (PNode a);
void swaphanghoa (hanghoa &a, hanghoa &b);
void sortname (PNode &a);
void sortprice (PNode &a);
void listnhaphangToFile(PNode p, fstream &fileout);//xuat file cho Hieu
void menunhaphang(Linkedlist &H);
hanghoa create();
//HIEU.
void themHanghoanhap(LinkedListNH& NH, hanghoa K);
PNodeNH timkiemMahanghoa(LinkedListNH& NH, long K);
int tonghanghoa(LinkedListNH& NH);
void xoahanghoanhap(LinkedListNH& NH, PNodeNH P);
void displayQuanlyNhapHang(LinkedListNH NH);
void displayNhanhang(PNodeNH P);
void exportQuanlyNhapHangToFile(LinkedListNH NH, fstream &fileout);
void importHanghoaFromFile(fstream &filein, LinkedListNH &NH);
void menuNhaphang();

void themNhanvien(LinkedListNV& NV, nhanvien K);
void themLuongNgay(PNodeNV P, luongtheongay K);
void tinhLuongtheoNgay(PNodeNV P, int ngaycc, int thangcc, int namcc);
void tinhLuongtheoThang(PNodeNV P, int thangcc , int namcc);
void tinhLuongtheoNam(PNodeNV P, int namcc);
PNodeNV timkiemID(LinkedListNV& NV, long K);
int tongNhanvien(LinkedListNV& NV);
void xoaNhanvien(LinkedListNV& NV, PNodeNV P);
void displayQuanlynhanvien(LinkedListNV NV);
void displaynhanvien(PNodeNV P);
void menuNhanvien(Listbill &temp,Linkedlist &H, Listbill &L, listnv* &K, billlist &J, long &doanhthu);

//Quan ly nhap hang cua HIEU
//them hang nhap
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
//Tim kiem theo ma hang hoa
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
//Tong so hang nhap
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
//Xoa hang nhap
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
//In ra danh sach nhap hang  
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
//In ra 1 hang nhap xac dinh 
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
//Xuat tu danh sach nhap hang ra file
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
//Nhap tu file vao danh sach
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
//Menu quan ly nhap hang 
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
        cout << "---------------------------------\n";
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


// QUAN LY HANG HOA CUA DUNG.
//tao mot node hang hoa moi (nhap tu ban phim)
hanghoa create(){
	hanghoa a;
	cout << "nhap thong tin cua hang hoa:\n";
	cout << "nhap ten hang hoa: ";
	cin.ignore();
	getline (cin, a.tenhanghoa);
	cout << "nhap so luong cua hang hoa:";
	cin >> a.soluong;
	cout << "nhap ma hang hoa: ";
	cin >> a.mahanghoa;
	cout << "nhap don gia: ";
	cin >> a.dongia;
	cout << "nhap ten cua nha cung cap: ";
	cin.ignore();
	getline (cin, a.nhacungcap);
	return a;
}

//them mot phan tu vao dau danh sach
void InsertFirst (Linkedlist &H, PNode q){
	if (H == NULL){
		q->next = NULL;
		H = q;
	}else {
		q->next = H;
		H = q;
	}	
}
//them mot phan tu vao cuoi danh sach
void InsertLast (Linkedlist &H, PNode q){
	if (H==NULL){
		H=q;
	}
	else{
		PNode p = H;
		while (p->next != NULL){
			p=p->next;
		}
		p->next = q;
	}
}
//xoa hang hoa
void deletenode(Linkedlist &H,PNode p){
	if (H==NULL) cout << "danh sach rong";
	if (H==p&&H->next==NULL){
		H=NULL;
		delete p;
	}else {
		if (H==p){
			p->next = H;
			delete p;
		}else{
		PNode r = H;
		do{
			r=r->next;
		}while (r!=p);
		r->next = p->next;
		delete p;
	}
}
}
//tim mot hang hoa dua tren ma san pham
PNode searchNode (Linkedlist H, int x){
	PNode p = H;
	do{
		if (p->h.mahanghoa==x) return p;
		else p = p->next;
	} while (p!=NULL);
	return 0;
} 
//ham in ra hang hoa
void in(hanghoa h){
	cout << "---------------------------------\n";
	cout << "ten hang hoa: " << h.tenhanghoa << endl;
	cout << "so luong: " << h.soluong << endl;
	cout << "don gia: " << h.dongia << endl;
	cout << "ma hang hoa: " << h.mahanghoa << endl;
	cout << "nha cung cap: " << h.nhacungcap << endl;
	cout << "---------------------------------\n";
}
//ham dua ra danh sach cac mat hang can nhap hang
void listnhaphang (PNode p){
	PNode q = p;
	cout << "cac mat hang sau day can nhap hang\n";
	int count = 0;
	do{
		if (q->h.soluong < 3){
			count++;
			in(q->h);
		}
		q = q->next;
	}while (q!=NULL);
	if (count==0) cout << "khong co mat hang nao can nhap hang!\n";
}
//ham xuat ra file nhap hang cua Hieu
void listnhaphangToFile(PNode p, fstream &fileout){
    PNode q = p;
    int count = 0;
    while (q != NULL){
        if (q->h.soluong < 3){
            count++;
            fileout << q->h.tenhanghoa << ", ";
            fileout << q->h.soluong << ", ";
            fileout << q->h.dongia << ", ";
            fileout << q->h.mahanghoa << ", ";
            fileout << q->h.nhacungcap;
			if (q->next!=NULL) fileout << endl;
        }
        q = q->next;
    }
    if (count == 0) fileout << "Khong co mat hang nao can nhap hang!\n";
}
//nhap hang tu du lieu file (txt)
void importFile(fstream &filein, hanghoa &a){
	getline (filein, a.tenhanghoa, ',');
	filein.seekg(1, ios::cur);
	filein >> a.soluong;
	filein.seekg(1, ios::cur);
	filein >> a.mahanghoa;
	filein.seekg(1, ios::cur);
	filein >> a.dongia;
	filein.seekg(1, ios::cur);
	getline (filein, a.nhacungcap);
}
//ham tao PNode
PNode createnode (hanghoa a){
	PNode tmp = new Node();
	tmp->h = a;
	tmp->next = NULL;
	return tmp;
} 
void importlist (fstream &filein, Linkedlist &H){
	do{
		hanghoa a;
		importFile(filein, a);
		PNode q = createnode(a);
		InsertLast (H, q);
	}while (!filein.eof());
}
//xuat du lieu hang hoa ra file txt de luu tru
void exportFile(fstream &fileout, PNode a){
	PNode q = a;
	do{
		fileout << q->h.tenhanghoa << ", ";
		fileout << q->h.soluong << ", ";
		fileout << q->h.mahanghoa << ", ";
		fileout << q->h.dongia << ", ";
		fileout << q->h.nhacungcap;
		if (q->next!=NULL) fileout << endl;
		q=q->next;
	}while (q!=NULL);
}
//ham hien thi toan bo danh sach hang hoa
void showlist (PNode a){
	if(isEmpty(a)) cout << "danh sach rong!";
	else {
	for(PNode q = a; q!=NULL; q= q->next){
		in(q->h);
	}
}
}
void swaphanghoa (hanghoa &a, hanghoa &b){
	hanghoa tmp = a;
	a = b;
	b = tmp;
}
void sortname (PNode &a){
	for(PNode p = a; p!=NULL; p=p->next){
		for(PNode k = p->next; k!=NULL; k=k->next){
			if (p->h.tenhanghoa > k->h.tenhanghoa){
				hanghoa tmp = p->h;
				p->h = k->h;
				k->h = tmp;
			}
		}
	}
}
//ham sap xep hang hoa theo gia ca tu thap den cao
void sortprice (PNode &a){
	for(PNode q = a; q!=NULL; q=q->next){
		for(PNode k = q->next; k!=NULL; k=k->next){
			if (q->h.dongia>k->h.dongia) swaphanghoa(k->h,q->h);
		}
}
}
//menu quan ly hang hoa
void menunhaphang(Linkedlist &H){
	bool isExit = false;
    int option;
do
{
   cout <<"----------------QUAN LY HANG HOA----------------" <<endl
        <<"1. Nhap hang" <<endl
        <<"2. Tim kiem hang hoa" <<endl
        <<"3. Sap xep hang hoa" <<endl
        <<"4. Xuat du lieu hang hoa ra file" <<endl
        <<"5. Hien thi toan bo danh sach hang hoa" << endl
        <<"6. Xoa hang hoa" << endl
        <<"7. Hien thi cac mat hang can nhap hang" <<endl
        <<"8. Thoat" <<endl
        <<"---------------------------------------------"<<endl
        <<"Nhap lua chon cua ban: ";
   cin >> option;
   switch (option){
   	case 1:
   		int choice;
   		cout << "Nhap lua chon" << endl;
   		cout << "1. Nhap hang tu ban phim" << endl;
   		cout << "2. Nhap tu file" << endl;
   		cin >> choice;
   		switch (choice){
   			case 1:
   				InsertLast(H, createnode(create()));
				break;
			case 2:
  			fstream filein;
			filein.open("banhang.txt", ios::in);
			importlist(filein, H);
			cout << "Nhap hang tu file thanh cong!" << endl;
			filein.close();
			break;	  			
		   }
		   break;
	case 2:
		{
			int a;
			cout << "nhap ma hang hoa" << endl;
			cin >> a;
			if(searchNode(H, a)==0) cout << "Khong co mat hang nao co ma san pham nhu tren" << endl;
			else in(searchNode(H,a)->h);
			break;
		}
	case 3:
		sortname(H);
		showlist(H);
		break;
	case 4:
	{
		fstream fileout;
		fileout.open("banhang.txt", ios::out);
		exportFile(fileout, H);
		cout << "Xuat hang hoa ra file thanh cong!" << endl;
		fileout.close();		
		break;
	}
	case 5:
		if(isEmpty(H)) cout << "Khong co hang hoa trong danh sach!" << endl;
		else showlist(H);
		break;
	case 6:
		int b;
		cout << "nhap ma cua san pham ban muon xoa" << endl;
		cin >> b;
		deletenode(H, searchNode(H,b));
		cout << "Xoa thanh cong!" << endl;
	case 7:{
		listnhaphang(H);
        fstream fileout;
        fileout.open("nhaphang.txt", ios::out);
        listnhaphangToFile(H, fileout);
        fileout.close();
        cout << "Xuat danh sach mat hang can nhap ra file thanh cong!\n";
		break;
    }
	case 8:
		isExit = true;
		break;	   		    				   		
        }

} while (!isExit);


// DANG
// Ham chuyen danh sach temp sang danh sach L de luu vao danh sach cac hoa don
}
void swap(Listbill &L, Listbill &temp) {
    if (temp == NULL) return;
    QNode Q = temp;
    while (Q != NULL) {
        QNode T = new Node;
        T->h.tenhanghoa = Q->h.tenhanghoa;
        T->h.soluong = Q->h.soluong;
        T->h.mahanghoa = Q->h.mahanghoa;
        T->h.dongia = Q->h.dongia;
        T->h.tonggia = Q->h.tonggia;
        T->h.luongmua = Q->h.luongmua;
        T->h.nhacungcap = Q->h.nhacungcap;
        T->next = L;
        L = T;
        Q = Q->next;
    }
}
// ham menu chinh
void menu(Listbill &temp,Linkedlist &H, Listbill &L, listnv* &K, billlist &J, long &doanhthu){ 
    int choice;
    cout <<"VAN PHONG PHAM BACH KHOA"<< endl;
    cout <<"1. Danh cho Khach Hang" << endl;
    cout <<"2. Danh cho Nhan Vien va Quan Li" << endl;
    cout <<"Nhap lua chon:";
    cin >> choice;
    while(choice != 1 && choice != 2){
        cout << "Khong hop le, de nghi nhap lai!" << endl;
        cout << "Nhap lua chon cua ban:";
        cin >> choice;
    }
    if(choice == 1) menumua(temp,H,L,J,K,doanhthu);
    if(choice == 2){
        menuNhanvien(temp,H,L,K,J,doanhthu);
    }

} 
//ham insert hoa don moi vao danh sach hoa don
void inserthoadon(billlist &J, Listbill &L) {
    billnode Q = new stackhoadon;
    QNode P = L;
    
    Listbill O = NULL;
    while (P != NULL) {
        QNode T = new Node;
        T->h.tenhanghoa = P->h.tenhanghoa;
        T->h.soluong = P->h.soluong;
        T->h.mahanghoa = P->h.mahanghoa;
        T->h.dongia = P->h.dongia;
        T->h.tonggia = P->h.tonggia;
        T->h.luongmua = P->h.luongmua;
        T->h.nhacungcap = P->h.nhacungcap;
        T->next = O;
        O = T;
        P = P->next;
    }
    
    if (J == NULL) {
        Q->billnext = NULL;
        Q->bill = O;
        Q->mahoadon = 1;
        J = Q;
    } else {
        Q->billnext = J;
        Q->bill = O;
        Q->mahoadon = J->mahoadon + 1;
        J = Q;
    }
     while (L != NULL) {
        QNode T = L;
        L = L->next;
        delete T;
    }
}
// ham xoa hoa don
void deletehoadon(billlist &J) {
    char escape;
    if (J == NULL) return;
    int maso;
    cout << "Nhap ma so hoa don ban muon xoa:";
    cin >> maso;
    billnode prev = NULL, curr = J;
    while (curr != NULL && curr->mahoadon != maso) {
        prev = curr;
        curr = curr->billnext;
    }
    if (curr == NULL) {
        cout << "Khong tim thay hoa don nay." << endl;
    } else {
        if (prev == NULL) {
            J = J->billnext;
        } else {
            prev->billnext = curr->billnext;
        }
        delete curr;
        cout << "Xoa hoa don thanh cong." << endl;
    }
    J->mahoadon --;
    billnode P = J;
    while (P != NULL) {
        cout << "Hoa don so: " << P->mahoadon << endl;
        QNode billItem = P->bill;
        while (billItem != NULL) {
            cout << billItem->h.tenhanghoa << "," << billItem->h.luongmua << "," << billItem->h.tonggia << endl;
            billItem = billItem->next;
        }
        P = P->billnext;
    }
    cout << "Nhan 1 de tiep tuc xoa, nhan phim bat ky de tro lai menu nhan vien:";
    cin >> escape;
    if(escape == '1') deletehoadon(J);
    return;
} 
// ham xoa tat ca hoa don
void deleteallhoadon(billlist &J){
    char escape;
    if(J == NULL) return;
    billnode Q = new stackhoadon;
    while(J != NULL){
        Q = J;
        J = J->billnext;
       delete Q;
    }
    J = NULL;
    cout << "Da xoa toan bo hoa don cua cua hang!" << endl;
    cout << "Nhap 1 ky tu bat ky de thoat ve menu nhan vien:" ;
    cin >> escape;
    system("cls");
    return;
}
// ham hien thi hoa don cho khach hang
void displayhoadon(Listbill &L, Listbill &temp, long tongtien,billlist &J,Linkedlist &H, listnv* &K, long &doanhthu){
    char escape;
    QNode Q = new Node;
    Q = temp;
    if(Q == NULL){
        cout << "Nhan ky tu bat ky de tro ve man hinh chinh:";
        cin >> escape;
        Clear(temp,L,H,K,J,doanhthu);
        return;
    }
    cout << "HOA DON" <<endl;
    cout << "Ten mat hang"<< "\t" << "So luong" << "\t" << "Don gia" << "\t" <<"\t" <<"Tong gia" << endl;  
    while(Q != NULL){
        cout << Q->h.tenhanghoa << "\t" << "\t" << Q->h.luongmua << "\t" <<"\t" << Q->h.dongia <<"\t" <<"\t" << Q->h.tonggia << endl; // TEMP
        tongtien += Q->h.tonggia;
        Q = Q->next;
    }
    doanhthu += tongtien;
    cout << "\n";
    cout << "Tong: " << tongtien << "VND" << endl;
    cout << "Nhan 1 ky tu bat ky de quay lai man hinh chinh." << endl;
    cin >> escape;
    inserthoadon(J,L);
    Clear(temp,L,H,K,J,doanhthu); 
}
// ham chinh sua gio hang 
void deletegiohang(Listbill &temp, Linkedlist &H, Listbill &L, billlist &J, listnv* &K, long &doanhthu) {
    long maso;
    char escape;
    cout << "Nhap ma so mat hang:";
    cin >> maso;
    QNode prev = NULL;
    QNode curr = temp;
    bool found = false;

    while (curr != NULL) {
        if (curr->h.mahanghoa == maso) {
            found = true;
            if (prev == NULL) {
                temp = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Xoa mat hang thanh cong" << endl;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (!found) {
        cout << "Khong tim thay mat hang nay trong gio hang" << endl;
    }

    cout << "Hien tai gio hang cua ban bao gom" << endl;
    display(temp);

    cout << "Nhan 1 de quay ve phan quan ly gio hang, nhan ky tu bat ky de tiep tuc chinh sua:";
    cin >> escape;
    system("cls");

    if (escape == '1') {
        giohang(H, L, temp, J, K, doanhthu, tongtien);
    } else {
        deletegiohang(temp, H, L, J, K, doanhthu);
    }
}
// ham menu mua hang 
void menumua(Listbill &temp,Linkedlist &H, Listbill &L, billlist &J,listnv* &K, long &doanhthu){
    long choice;
    char random;
    if(H == NULL){
        cout << "Khong co hang hoa" << endl;
        cout << "Nhap 1 so bat ky de quay lai menu chinh";
        cin >> random;
        system("cls");
        menu(temp,H,L,K,J,doanhthu);
        return;
    }
    PNode Q = new Node;
    Q = H;  
    cout << " \t\t    XIN MUA HANG" << endl; 
    cout << "----------------------------------------------------" << endl; 
    cout << "Ma san pham" << "\t" << "Ten san pham" << "\t" << "Don gia " << "\t" << "Nha cung cap"<< endl; // can sua lai trinh bay thanh 1 cot 
    while(Q != NULL){
        cout << Q->h.mahanghoa << "\t" << "\t" <<  Q->h.tenhanghoa << "\t" << "\t" << Q->h.dongia << "\t" << "\t" << Q->h.nhacungcap << endl;
        Q = Q->next;
    }
    cout << "Nhap ma mat hang ban muon mua(Nhap 0 neu ban khong muon mua):";
    cin >> choice;
    if(choice == 0){
        displayhoadon(L,temp,tongtien,J,H,K,doanhthu);
    }
    muahang(H,choice,L,temp,K,J,mua,doanhthu);
}
// ham ghi nhan va quan ly so luong hang hoa khach mua
void muahang(Linkedlist &H, long choice, Listbill &L, Listbill &temp, listnv* &K, billlist &J, int mua, long &doanhthu) {
    PNode Q = H;
    bool found = false;

    while (Q != NULL) {
        if (choice == Q->h.mahanghoa) {
            found = true;
            if (Q->h.soluong == 0) {
                cout << "Het hang" << endl;
                menumua(temp, H, L, J, K, doanhthu);
                return;
            } else {
                do {
                    cout << "Nhap so luong ban muon mua (Nhap 0 neu ban khong muon mua):";
                    cin >> mua;
                    if (mua == 0) {
                        displayhoadon(L, temp, tongtien, J, H, K, doanhthu);
                    }
                    if (mua > Q->h.soluong || mua < 0) {
                        cout << "Khong hop le. De nghi nhap lai" << endl;
                    }
                } while (mua > Q->h.soluong || mua < 0);
                cout << "Hoan thanh!" << endl;
                tinhhangton(H,choice,mua);
                insertgiohang(H, L, J, K, temp, choice, mua);
                return;
            }
        }
        Q = Q->next;
    }

    if (!found) {
        cout << "Khong tim thay mat hang ban dang tim, xin lam lai thao tac." << endl;
        cout << "Nhan 1 ky tu bat ky de quay lai thao tac mua" << endl;
        char random;
        cin >> random;
        menumua(temp, H, L, J, K, doanhthu);
    }
}
// ham khoi tao gio hang moi cho khach hang
void insertgiohang(Linkedlist &H, Listbill &L, billlist &J, listnv* &K, Listbill &temp, long choice, int mua) {
    PNode P = H;
    QNode T = temp;

    while (P != NULL) {
        if (choice == P->h.mahanghoa) {
            bool found = false;

            while (T != NULL) {
                if (T->h.mahanghoa == choice) {
                    T->h.luongmua += mua;
                    T->h.tonggia = T->h.luongmua * T->h.dongia;
                    found = true;
                    break;
                }
                T = T->next;
            }

            if (!found) {
                QNode Q = new Node;
                Q->h.dongia = P->h.dongia;
                Q->h.luongmua = mua;
                Q->h.tenhanghoa = P->h.tenhanghoa;
                Q->h.tonggia = mua * P->h.dongia;
                Q->h.mahanghoa = P->h.mahanghoa;
                Q->next = NULL;

                if (temp == NULL) {
                    temp = Q;
                } else {
                    QNode last = temp;
                    while (last->next != NULL) {
                        last = last->next;
                    }
                    last->next = Q;
                }
            }

            giohang(H, L, temp, J, K, doanhthu, tongtien);
            return;
        }
        P = P->next;
    }

    cout << "Khong tim thay mat hang" << endl;
    cout << "Nhap ky tu bat ky de thoat ve menu mua hang:";
    char escape;
    cin >> escape;
    menumua(temp, H, L, J, K, doanhthu);
}
// ham tinh so luong hang hoa sau moi lan mua
void tinhhangton(Linkedlist &H, long maso, long mua) {
    long tonkho = 0;
    char escape;
    PNode Q = H;
    while (Q != NULL) {
        if (Q->h.mahanghoa == maso) {
            tonkho = Q->h.soluong - mua;
            if (tonkho < 0) {
                tonkho = 0;
                cout << "Cua hang khong du!" << endl;
                cout << "Vui long mua lai duoi so luong ton kho" << endl;
                cout << "Nhap 1 ky tu bat ky de ve lai menu mua hang:";
                cin >> escape;
                system("cls");
                return;
            } else {
                Q->h.soluong = tonkho;
            }
        }
        Q = Q->next;
    }
}
// ham hien thi gio hang cua khach hang
void giohang(Linkedlist &H, Listbill &L, Listbill &temp, billlist &J, listnv* &K, long &doanhthu, long tongtien) {
    int flag;
    char escape;
    QNode Q = temp;
    if (Q == NULL) {
        cout << "Gio hang cua ban khong co gi \n Nhan 1 de thoat, nhan 1 phan tu bat ky de quay ve mua hang:";
        cin >> escape;
        system("cls");
        if (escape == '1') menu(temp, H, L, K, J, doanhthu);
        else menumua(temp, H, L, J, K, doanhthu);
        return;
    }
    cout << "Gio hang cua ban hien tai bao gom:" << endl;
    while (Q != NULL) {
        cout << Q->h.tenhanghoa << ": " << Q->h.luongmua << " cai \t" << Q->h.dongia << "/1chiec  =>" << "Tong gia:" << Q->h.tonggia << endl;
        Q = Q->next;
    }
    do {
        cout << "Nhan 1 de thanh toan, nhan 0 de tiep tuc mua hang, nhan 2 de sua mot mat hang: ";
        cin >> flag;
        system("cls");
    } while (flag != 1 && flag != 0 && flag != 2);
    if (flag == 1) {
        swap(L, temp);
        displayhoadon(L, temp, tongtien, J, H, K, doanhthu);
    }
    if (flag == 0) menumua(temp, H, L, J, K, doanhthu);
    if (flag == 2) deletegiohang(temp, H, L, J, K, doanhthu);
}
// ham hien thi doanh thu va danh sach hoa don cho nhan vien
void menunv(Listbill &temp, Listbill &L, long &doanhthu, listnv* &K, billlist &J, Linkedlist &H) {
    long pass;
    int choice;
    char escape;
    listnv* Q;
    billnode P;

    cout << "DANH CHO NHAN VIEN" << endl;
    cout << "Doanh thu hien tai: " << doanhthu << endl;
    cout << "Quan li hoa don:" << endl;

    if (J == NULL) {
        cout << "Khong ton tai hoa don nao" << endl;
        cout << "Nhap 1 ky tu bat ky de thoat ra:";
        cin >> escape;
        system("cls");
        menu(temp, H, L, K, J, doanhthu);
        return;
    }

    P = J;
    while (P != NULL) {
        cout << "Hoa don so: " << P->mahoadon << endl;
        QNode billItem = P->bill;
        while (billItem != NULL) {
            cout << billItem->h.tenhanghoa << " - " << billItem->h.luongmua << " chiec -" << billItem->h.tonggia << "VND" << endl;
            billItem = billItem->next;
        }
        P = P->billnext;
    }

    do {
        cout << "Nhan 0 de xoa mot hoa don, nhan 1 de xoa toan bo hoa don:";
        cin >> choice;
    } while (choice != 0 && choice != 1);

    if (choice == 0) {
        deletehoadon(J);
        system("cls");
        menunv(temp,L,doanhthu,K,J,H);
    } else if (choice == 1) {
        deleteallhoadon(J);
        system("cls");
        menunv(temp,L,doanhthu,K,J,H);

    }
}
// ham clear gio hang cu cua khach hang khi thanh toan
void Clear(Listbill &temp,Listbill &L, Linkedlist &H,listnv* &K, billlist &J, long &doanhthu){
    tongtien = 0;
    temp = NULL;
    cout << "Done";
    system("cls");
    menu(temp,H,L,K,J,doanhthu);
}
// ham hien thi gio hang cua khach hang
void display(Listbill &temp) {
    QNode Q = temp;
    while (Q != NULL) {
        cout << Q->h.tenhanghoa << "," << Q->h.luongmua << "," << Q->h.dongia << "," << Q->h.tonggia << endl;
        Q = Q->next;
    }
}

//Quan ly nhan vien HIEU
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
            if (R->data.chamcong.phutlamthem <= 0) R->data.tienthuong = 0;  // Đảm bảo giá trị không âm
            if (R->data.chamcong.phutphat <= 0) R->data.tienphat = 0;
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
            if (R->data.chamcong.phutlamthem <= 0) R->data.tienthuong = 0;  // Đảm bảo giá trị không âm
            if (R->data.chamcong.phutphat <= 0) R->data.tienphat = 0;
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
            if (R->data.chamcong.phutlamthem <= 0) R->data.tienthuong = 0;  // Đảm bảo giá trị không âm
            if (R->data.chamcong.phutphat <= 0) R->data.tienphat = 0;
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
void menuNhanvien(Listbill &temp,Linkedlist &H, Listbill &L, listnv* &K, billlist &J, long &doanhthu){
    LinkedListNV NV;
    init(NV);
    int choice = 0;

    while(true){
        cout << endl;
        cout << "-----------QUAN LY NHAN VIEN & HANG HOA--------------" << endl;
        cout << endl;
        cout << "1. Thong tin nhan vien." << endl;
        cout << "2. Them nhan vien." << endl;
        cout << "3. Tim kiem nhan vien." << endl;
        cout << "4. Chinh sua thong tin nhan vien." << endl;
        cout << "5. Xoa nhan vien." << endl;
        cout << "6. Cham cong." << endl;
        cout << "7. Kiem tra luong nhan vien." << endl;
        cout << "8. In hoa don luong." << endl;
        cout << "9. QUAN LY HANG HOA" << endl;
        cout << "10.QUAN LY NHAP HANG" << endl;
        cout << "11. Thoat." << endl;
        cout << "-----------------------------------------------------" << endl;
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
                    else vonglap = true;
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
                        K.chamcong.giora = timeinfo->tm_hour;//18
                        K.chamcong.phutra = timeinfo->tm_min;//30
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
            menunhaphang(H);
            break;
        case 10:
            menuNhaphang();
            break;
        case 11:
            cout << "Da thoat thanh cong!" << endl;
            menu(temp,H,L,K,J,doanhthu);
            break;
        
        default:
            cout << "Vui long thu lai!" << endl;
            break;
        }
    }      
}

int main(){
    Linkedlist H;
    Listbill L;
    Listbill temp;
    billlist J;
    listnv* K;
    InitH(H);
    InitJ(J);
    InitK(K); 
    InitL(L);
    InitTemp(temp);
    menu(temp,H,L,K,J,doanhthu);
	
    return 0;
}