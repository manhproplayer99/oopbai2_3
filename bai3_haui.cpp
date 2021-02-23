#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

class Nguoi{
	private:
		string HoTen;
		string NgaySinh;
		string QueQuan;
	public:
		void nhap();
		void xuat();

};
void Nguoi::nhap(){
	cout<<"Nhap ho ten:";
	fflush(stdin);
	getline(cin,this->HoTen);
	cout<<"Nhap ngay sinh:";
	fflush(stdin);
	getline(cin,this->NgaySinh);
	cout<<"Nhap que quan:";
	fflush(stdin);
	getline(cin,this->QueQuan);

}
void Nguoi::xuat(){
	cout<<setw(15)<<this->HoTen<<setw(15)<<this->NgaySinh<<setw(15)<<this->QueQuan;
}
class SinhVien : public Nguoi{
	private:
		string Masv;
		string Nganh;
		int KhoaHoc;
	public:
		void nhap();
		void xuat();
		friend class LopHoc;
};
void SinhVien::nhap(){
	Nguoi::nhap();
	cout<<"Nhap ma sv:";
	fflush(stdin);
	getline(cin,this->Masv);
	cout<<"Nhap nganh:";
	fflush(stdin);
	getline(cin,this->Nganh);
	cout<<"Nhap khoa hoc:";
	cin>>this->KhoaHoc;
}
void SinhVien::xuat(){
	Nguoi::xuat();
	cout<<setw(15)<<this->Masv<<setw(15)<<this->Nganh<<setw(15)<<this->KhoaHoc<<endl;
}
class LopHoc{
	private:
		string MaLH;
		string TenLH;
		string NgayMo;
		SinhVien *x;
		int n;
		string GiaoVien;
	public:
		void nhap();
		void xuat();
};
void LopHoc::nhap(){
    cout<<"Nhap ma lop hoc:";
    fflush(stdin);
    getline(cin,this->MaLH);
    cout<<"Nhap ten lop hoc:";
    fflush(stdin);
    getline(cin,this->TenLH);
    cout<<"Nhap ngay mo:";
    fflush(stdin);
    getline(cin,this->NgayMo);
    cout<<"Nhap giao vien:";
    fflush(stdin);
    getline(cin,this->GiaoVien);
    cout<<"Nhap so sinh vien:";
    cin>>this->n;
    x=new SinhVien[n];
    for(int i=0;i<n;i++){
        x[i].nhap();
    }

}
void LopHoc::xuat(){
    cout<<setw(18)<<"Ma LH:"<<this->MaLH<<setw(25)<<"Ten LH:"<<this->TenLH<<endl;
    cout<<setw(20)<<"Ngay Mo:"<<this->NgayMo<<setw(20)<<"Giao Vien:"<<this->GiaoVien<<endl;
    cout<<setw(15)<<"Ho Ten"<<setw(15)<<"Ngay Sinh"<<setw(15)<<"Que Quan"<<setw(15)<<"Ma SV"<<setw(15)<<"Nganh"<<setw(15)<<"Khoa Hoc"<<endl;
    for(int i=0;i<n;i++){
        x[i].xuat();
    }
    int dem=0;
    for(int i=0;i<n;i++){
        if(x[i].KhoaHoc == 11){
            dem++;
        }
    }
    cout<<"\nSo sinh vien khoa 11 cua lop hoc la:"<<dem<<endl;

    cout<<"\nSap Xep:"<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(x[i].KhoaHoc>x[j].KhoaHoc){
                swap(x[i],x[j]);
            }
        }
    }

    cout<<setw(15)<<"Ho Ten"<<setw(15)<<"Ngay Sinh"<<setw(15)<<"Que Quan"<<setw(15)<<"Ma SV"<<setw(15)<<"Nganh"<<setw(15)<<"Khoa Hoc"<<endl;
    for(int i=0;i<n;i++){
        x[i].xuat();
    }


}

int main(){
    LopHoc l1;
    l1.nhap();
    l1.xuat();
    return 0;
}
