 #include <iostream>
 #include <stdlib.h>
 #include <string.h>
using namespace std;
#define MAX 100
struct hanghoa{
    string tenhanghoa;
    long soluong;
    long mahanghoa, dongia, tonggia;
    long luongmua;
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
void matkhau(billlist &J, Listbill &L, Listbill &temp, long &doanhthu, listnv* &K, Linkedlist &H);
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
    system("cls");
    if(choice == 1) menumua(temp,H,L,J,K,doanhthu);
    if(choice == 2) matkhau(J,L,temp,doanhthu,K,H);
} 
void inserthoadon(billlist &J, Listbill &L) {
    billnode Q = new stackhoadon;
    QNode P = L;
    
    Listbill O = NULL;
    while (P != NULL) {
        QNode newNode = new Node;
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
        Q->bill = currentBill;
        Q->mahoadon = 1;
        J = Q;
    } else {
        Q->billnext = J;
        Q->bill = currentBill;
        Q->mahoadon = J->mahoadon + 1;
        J = Q;
    }
     while (L != NULL) {
        QNode T = L;
        L = L->next;
        delete T;
    }
}
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
} // GPT
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
void matkhau(billlist &J, Listbill &L, Listbill &temp, long &doanhthu, listnv* &K, Linkedlist &H){
    long pass;
    bool found = false;
    char escape;
    
    if (K == NULL) {
        cout << "Khong co nhan vien nao" << endl;
        cout << "Nhap 1 ky tu bat ky de thoat ra:";
        cin >> escape;
        menu(temp, H, L, K, J, doanhthu);
        return;
    }
    
    while (true) {
        cout << "Nhap mat khau(ID)(Nhap 0 de ve menu):";
        cin >> pass;
        if (pass == 0) {
            system("cls");
            menu(temp, H, L, K, J, doanhthu);
            return;
        }
        listnv* Q = K;
        found = false;
        while (Q != NULL) {
            if (pass == Q->id) {
                found = true;
                break;
            }
            Q = Q->Knext;
        }
        if (found) {
            menunv(temp, L, doanhthu, K, J, H);
            return;
        } else {
            cout << "Chua dung. Nhap lai!)" << endl;
        }
    }
}

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

void Clear(Listbill &temp,Listbill &L, Linkedlist &H,listnv* &K, billlist &J, long &doanhthu){
    tongtien = 0;
    temp = NULL;
    cout << "Done";
    system("cls");
    menu(temp,H,L,K,J,doanhthu);
}


void display(Listbill &temp) {
    QNode Q = temp;
    while (Q != NULL) {
        cout << Q->h.tenhanghoa << "," << Q->h.luongmua << "," << Q->h.dongia << "," << Q->h.tonggia << endl;
        Q = Q->next;
    }
}

PNode searchlast(Linkedlist &H){
    if(H == NULL){
        cout <<"H rong"<< endl;
        return NULL;
    }
    PNode P = H;
    while(P->next != NULL){
        P = P->next;
    }
    return P;
}
QNode searchlasttemp(Listbill &temp){
    if(temp == NULL){
        cout <<"temp rong"<< endl;
        return NULL;
    }
    QNode T = temp;
    while(T->next != NULL){
        T = T->next;
    }
    return T;
}
void insertafter(Linkedlist &H, PNode P){
    PNode Q = new Node;
    cout <<"Nhap ten hang:";
        cin >> Q->h.tenhanghoa;
        cout <<"Nhap so luong:";
        cin >> Q->h.soluong;
        cout <<"Nhap ma hang hoa;";
        cin >> Q->h.mahanghoa;
        cout <<"Nhap don gia:";
        cin >> Q->h.dongia;
        cout << "Nhap nha cung cap;";
        cin >> Q->h.nhacungcap;
        cout <<"Nhap thanh cong!" << endl;
    if(H == NULL){
        Q->next = NULL;
        H = Q;
    } else{
        if(P == NULL) return;
        Q->next = P->next;
        P->next = Q;
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

