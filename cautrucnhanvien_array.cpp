#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
using namespace std;

struct nhanvien {
	char ten[50];
	int maNV;
	char sdt[20];
	char chucVu[20];
	float heSoLuong;
} kieuNhanVien;

int main() {
	int n;
	
	cout << "Cau truc nhan vien su dung thu vien vector" << endl;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	
	struct nhanvien *dsNV = (struct nhanvien*) malloc(n * (sizeof(struct nhanvien)));	
	int index;	
	for (index=0;index<n;index++) {		
		cout << "Nhap ten nhan vien: ";
		cin >> dsNV[index].ten;		
		cout << "Nhap ma nhan vien: ";
		cin >> dsNV[index].maNV;
		cout << "Nhap so dien thoai nhan vien: ";
		cin >> dsNV[index].sdt;
		cout << "Nhap chuc vu nhan vien: ";
		cin >> dsNV[index].chucVu;
		cout << "Nhap he so luong nhan vien: ";
		cin >> dsNV[index].heSoLuong;
	}	
	cout << endl;
	cout <<"=======================" << endl << "Danh sach nhan vien" << endl;
	for (index=0;index<n;index++) {
		cout << "Ten nhan vien: ";
		cout << dsNV[index].ten << endl;
		cout << "Ma nhan vien: ";
		cout << dsNV[index].maNV << endl;
		cout << "So dien thoai nhan vien: ";
		cout << dsNV[index].sdt << endl;
		cout << "Chuc vu nhan vien: ";
		cout << dsNV[index].chucVu << endl;
		cout << "He so luong nhan vien: ";
		cout << fixed << setw(2) << setprecision(2) << dsNV[index].heSoLuong << endl;		
	}
	
	char loopCond = 1;
	char action;
	while (loopCond == 1) {
		cout << endl << "=======================" << endl;
		cout << "(T: them; X: xoa; S: sua, D: danh sach NV, K: ket thuc)" << endl;
		cout << "Hay chon hanh dong muon chinh sua: ";		
		cin >> action;
		int ma;
		struct nhanvien *temp;
		switch (action) {
			case 'T':				
				temp = (struct nhanvien*) malloc((n+1) * sizeof(struct nhanvien));
				for (index=0;index<n;index++) {				
					temp[index] = dsNV[index];
				}
				cout << "Nhap ten nhan vien: ";				
				cin >> temp[n].ten;		
				cout << "Nhap ma nhan vien: ";
				cin >> temp[n].maNV;
				cout << "Nhap so dien thoai nhan vien: ";
				cin >> temp[n].sdt;
				cout << "Nhap chuc vu nhan vien: ";
				cin >> temp[n].chucVu;
				cout << "Nhap he so luong nhan vien: ";
				cin >> temp[n].heSoLuong;
				n = n+1;
				dsNV = temp;
				break;
			case 'X':				
				cout << "Nhap ma nhan vien can xoa: ";			
				cin >> ma;
				for (index=0;index<n;index++) {
					if (dsNV[index].maNV == ma) {
						for (index=index;index<n-1;index++) {
							dsNV[index] = dsNV[index+1];
						}
					}
				}
				n--;
				break;
			case 'S':				
				cout << "Nhap ma nhan vien can sua: ";
				cin >> ma;
				for (index=0;index<n;index++) {
					if (dsNV[index].maNV == ma) {
						cout << "Nhap thong tin moi cho nhan vien" << endl;
						cout << "Nhap ten nhan vien: ";
						cin >> dsNV[index].ten;		
						cout << "Nhap ma nhan vien: ";
						cin >> dsNV[index].maNV;
						cout << "Nhap so dien thoai nhan vien: ";
						cin >> dsNV[index].sdt;
						cout << "Nhap chuc vu nhan vien: ";
						cin >> dsNV[index].chucVu;
						cout << "Nhap he so luong nhan vien: ";
						cin >> dsNV[index].heSoLuong;
					}
				}
				break;
			case 'D':
				cout << "Ten cac nhan vien trong danh sach" << endl;
				for (index=0;index<n;index++)
					cout << dsNV[index].ten << " " << endl;
				break;
			case 'K':
			default:
				loopCond = 0;
		}
	}
}
