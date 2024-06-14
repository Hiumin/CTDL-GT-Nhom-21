#include <iostream>
#include <string>
#include <fstream> 

using namespace std;
struct hanghoa{
	string tenhanghoa;
	int soluong;
	int mahanghoa;
	int dongia;
	string nhacungcap;
};
struct Node{
	hanghoa info;
	Node *next;
};
typedef Node* node;
void init (node &h){
	h=NULL;
}
//ham kiem tra danh sach rong
bool isEmpty (node &h){
	return (h==NULL);
}
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
void InsertFirst (node &h, node q){
	if (h == NULL){
		q->next = NULL;
		h = q;
	}else {
		q->next = h;
		h = q;
	}	
}
//them mot phan tu vao cuoi danh sach
void InsertLast (node &h, node q){
	if (h==NULL){
		h=q;
	}
	else{
		node p = h;
		while (p->next != NULL){
			p=p->next;
		}
		p->next = q;
	}
}
//xoa hang hoa
void deletenode(node &h,node p){
	if (h==NULL) cout << "danh sach rong";
	if (h==p&&h->next==NULL){
		h=NULL;
		delete p;
	}else {
		if (h==p){
			p->next = h;
			delete p;
		}else{
		node r = h;
		do{
			r=r->next;
		}while (r!=p);
		r->next = p->next;
		delete p;
	}
}
	
}
//tim mot hang hoa dua tren ma san pham
node searchNode (node h, int x){
	node p = h;
	do{
		if (p->info.mahanghoa==x) return p;
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
void listnhaphang (node p){
	node q = p;
	cout << "cac mat hang sau day can nhap hang\n";
	int count = 0;
	do{
		if (q->info.soluong < 3){
			count++;
			in(q->info);
		}
		q = q->next;
	}while (q!=NULL);
	if (count==0) cout << "khong co mat hang nao can nhap hang!\n";
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
//ham tao node
node createnode (hanghoa a){
	node tmp = new Node();
	tmp ->info = a;
	tmp->next = NULL;
	return tmp;
}
void importlist (fstream &filein, node &h){
	do{
		hanghoa a;
		importFile(filein, a);
		node q = createnode(a);
		InsertLast (h, q);
	}while (!filein.eof());
}
//xuat du lieu hang hoa ra file txt de luu tru
void exportFile(fstream &fileout, node a){
	node q = a;
	do{
		fileout << q->info.tenhanghoa << ", ";
		fileout << q->info.soluong << ", ";
		fileout << q->info.mahanghoa << ", ";
		fileout << q->info.dongia << ", ";
		fileout << q->info.nhacungcap;
		if (q->next!=NULL) fileout << endl;
		q=q->next;
	}while (q!=NULL);
}
//ham hien thi toan bo danh sach hang hoa
void showlist (node a){
	if(isEmpty(a)) cout << "danh sach rong!";
	else {
	for(node q = a; q!=NULL; q= q->next){
		in(q->info);
	}
}
}
void swap (hanghoa &a, hanghoa &b){
	hanghoa tmp = a;
	a = b;
	b = tmp;
}
//ham sap xep hang hoa theo ten
void sortname (node &a){
	for(node p = a; p!=NULL; p=p->next){
		for(node k = p->next; k!=NULL; k=k->next){
			if (p->info.tenhanghoa > k->info.tenhanghoa){
				hanghoa tmp = p->info;
				p->info = k->info;
				k->info = tmp;
			}
		}
	}
	
}
//ham sap xep hang hoa theo gia ca tu thap den cao
void sortprice (node &a){
	for(node q = a; q!=NULL; q=q->next){
		for(node k = q->next; k!=NULL; k=k->next){
			if (q->info.dongia>k->info.dongia) swap (k->info,q->info);
		}
}
	
}
//menu quan ly hang hoa
void menu(node &h){
	bool isExit = false;
    int option;
do
{
   cout <<"Menu quan ly hang hoa:" <<endl
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
   				InsertLast(h, createnode(create()));
				break;
			case 2:
  			fstream filein;
			filein.open("banhang.txt", ios::in);
			importlist(filein, h);
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
			if(!searchNode(h, a)) cout << "Khong co mat hang nao co ma san pham nhu tren" << endl;
			else in(searchNode(h,a)->info);
		}
	case 3:
		sortname(h);
		showlist(h);
		break;
	case 4:
	{
		fstream fileout;
		fileout.open("banhang.txt", ios::out);
		exportFile(fileout, h);
		cout << "Xuat hang hoa ra file thanh cong!" << endl;
		fileout.close();		
		break;
	}
	case 5:
		if(isEmpty(h)) cout << "Khong co hang hoa trong danh sach!" << endl;
		else showlist(h);
		break;
	case 6:
		int b;
		cout << "nhap ma cua san pham ban muon xoa" << endl;
		cin >> b;
		deletenode(h, searchNode(h,b));
		cout << "Xoa thanh cong!" << endl;
	case 7:
		listnhaphang(h);
		break;
	case 8:
		isExit = true;
		break;	   		    				   		
   				}

} while (!isExit);

}
	
int main(){
	node a;
	init(a);
	menu(a);
	return 0;
}




