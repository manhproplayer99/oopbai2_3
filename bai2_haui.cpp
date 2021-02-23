#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

class NCC{
	private:
		string mancc;
		string tenncc;
		string diachi;
		string sdt;
	public:
		void nhap();
		void xuat();
};
void NCC::nhap(){
	cout<<"Nhap ma ncc:";
	fflush(stdin);
	getline(cin,this->mancc);
	cout<<"Nhap ten ncc:";
	fflush(stdin);
	getline(cin,this->tenncc);
	cout<<"Nhap dia chi:";
	fflush(stdin);
	getline(cin,this->diachi);
	cout<<"Nhap sdt:";
	fflush(stdin);
	getline(cin,this->sdt);
}
void NCC::xuat(){
	cout<<setw(15)<<"Ma NCC:"<<this->mancc<<setw(30)<<"Ten NCC:"<<this->tenncc<<endl;
	cout<<setw(15)<<"Dia Chi:"<<this->diachi<<setw(25)<<"SDT:"<<this->sdt<<endl;
}
class SanPham{
	private:
		string masp;
		string tensp;
		int soluong;
		int dongia;

	public:
		void nhap();
		void xuat();
		friend class Phieu;

};
void SanPham::nhap(){
	cout<<"Nhap masp:";
	fflush(stdin);
	getline(cin,this->masp);
	cout<<"Nhap ten sp:";
	fflush(stdin);
	getline(cin,this->tensp);
	cout<<"Nhap so luong:";
	cin>>this->soluong;
	cout<<"Nhap don gia:";
	cin>>this->dongia;
}
void SanPham::xuat(){
	cout<<setw(10)<<this->masp<<setw(10)<<this->tensp<<setw(10)<<this->soluong<<setw(10)<<this->dongia<<setw(10)<<this->soluong*this->dongia<<endl;
}

class Phieu{
	private:
		string maPhieu;
		string ngayLap;
		NCC x;
		SanPham *a;
		int n;
	public:
		void nhap();
		void xuat();


};
void Phieu::nhap(){
	cout<<"Nhap ma phieu:";
	fflush(stdin);
	getline(cin,this->maPhieu);
	cout<<"Nhap ngay lap:";
	fflush(stdin);
	getline(cin,this->ngayLap);
	x.nhap();
	cout<<"Nhap so san pham:";
	cin>>this->n;
	a=new SanPham[n];
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
}
void Phieu::xuat(){
	cout<<setw(18)<<"Ma Phieu:"<<this->maPhieu<<setw(30)<<"Ngay Lap:"<<this->ngayLap<<endl;
	x.xuat();
	cout<<setw(10)<<"Ma SP"<<setw(10)<<"Ten SP"<<setw(10)<<"So Luong"<<setw(10)<<"Don Gia"<<setw(15)<<"Thanh Tien"<<endl;
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
	int T=0;
	for(int i=0;i<n;i++){
		T+=a[i].soluong*a[i].dongia;
	}
	cout<<"Tong:"<<T;
	int dem=0;
	for(int i=0;i<n;i++){
		if(a[i].soluong<80){
			dem++;
		}
	}
	cout<<"\nso san pham co so luong nhap nho hon 80 la:"<<dem;

	cout<<"\nSap xep:"<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].dongia<a[j].dongia){
				swap(a[i],a[j]);
			}
		}
	}

	cout<<setw(10)<<"Ma SP"<<setw(10)<<"Ten SP"<<setw(10)<<"So Luong"<<setw(10)<<"Don Gia"<<setw(15)<<"Thanh Tien"<<endl;
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
int main(){

	Phieu p1;
	p1.nhap();
	p1.xuat();
    return 0;
}
