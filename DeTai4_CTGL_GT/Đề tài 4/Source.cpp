#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<math.h>
using namespace std;
struct NgayThangNam
{
	int ngay;
	int thang;
	int nam;
};
struct ChienDich
{
	string MaCD;
	string TenCD;
	NgayThangNam ngayBD;
	NgayThangNam ngayKT;
};
struct NodeCD
{
	ChienDich infoChienDich;
	NodeCD* next;
};
struct ListChienDich
{
	NodeCD* head;
	NodeCD* tail;
};
struct TNV
{
	string Ma;
	string HoLot;
	string Ten;
	NgayThangNam ngaythangnamsinh;
	string SDT;
	string MaCD;
};
struct NodeTNV
{
	TNV infoTNV;
	NodeTNV* next;
};
struct ListTNV
{
	NodeTNV* head;
	NodeTNV* tail;
};
//============================================================================================

NodeCD* createNodeChienDich(ChienDich x);
void AddTailNodeChienDich(ListChienDich& DSCD, NodeCD* p);
void docFileChienDich(ListChienDich& DSCD);
void duyetDanhSachChienDich(ListChienDich DSCD);

//--------------------------------------------------------------------------------------------

NodeTNV* createNodeTNV(TNV x);
void AddTailNodeTNV(ListTNV& DSTNV, NodeTNV* p);
void docFileTNV(ListTNV& DSTNV);
void duyetDanhSachTNV(ListTNV DSTNV);
//=============================================================================================
//                              DANH SÁCH LIÊN KẾT ĐƠN CHIẾN DỊCH
NodeCD* createNodeChienDich(ChienDich x)
{
    NodeCD* p = new NodeCD;
    if (p == NULL)
    {
        cout << "Khong du bo nho de cap phat.";
        return NULL;
    }
    p->infoChienDich.MaCD;
    p->infoChienDich.TenCD;
    p->infoChienDich.ngayBD.ngay;
    p->infoChienDich.ngayBD.thang;
    p->infoChienDich.ngayBD.nam;
    p->infoChienDich.ngayKT.ngay;
    p->infoChienDich.ngayKT.thang;
    p->infoChienDich.ngayKT.nam;
    p->next = NULL;
    return p;
}
void AddTailNodeChienDich(ListChienDich& DSCD, NodeCD* p)
{

    if (DSCD.head == NULL)
    {
        DSCD.head = DSCD.tail = p;
    }
    else
    {
        DSCD.tail->next = p;
        DSCD.tail = p;
        p->next = NULL;
    }
}
void docFileChienDich(ListChienDich& DSCD)
{
    DSCD.tail = NULL;
    DSCD.head = NULL;
    int i = 0;
    fstream filein;
    filein.open("ChienDich.txt", ios::in);
    if (filein.fail())
    {
        cout << "\nKhong mo duoc file de doc";
        return;
    }
    while (!filein.eof())
    {
        NodeCD* p = new NodeCD;
        filein >> p->infoChienDich.MaCD;
        filein >> p->infoChienDich.TenCD;
        filein >> p->infoChienDich.ngayBD.ngay;
        filein >> p->infoChienDich.ngayBD.thang;
        filein >> p->infoChienDich.ngayBD.nam;
        filein >> p->infoChienDich.ngayKT.ngay;
        filein >> p->infoChienDich.ngayKT.thang;
        filein >> p->infoChienDich.ngayKT.nam;
        p->next == NULL;
        AddTailNodeChienDich(DSCD, p);
        i++;
    }
    filein.close();
}
void duyetDanhSachChienDich(ListChienDich DSCD)
{
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                        --DANH SACH CHIEN DICH TINH NGUYEN--                                           |" << endl;
    cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
    cout << "|" << setw(20)<< "MA CHIEN DICH " << setw(30) << "TEN CHIEN DICH" << setw(30) << "NGAY BAT DAU" << setw(30) << "NGAY KET THUC" << setw(10) << "|" << endl;
    for (NodeCD* p = DSCD.head; p != NULL; p = p->next)
    {
        cout << "|" << setw(15) << p->infoChienDich.MaCD << setw(38) << p->infoChienDich.TenCD << setw(20) << p->infoChienDich.ngayBD.ngay << "/"
            << p->infoChienDich.ngayBD.thang << "/" << p->infoChienDich.ngayBD.nam << setw(23) << p->infoChienDich.ngayKT.ngay 
            << "/" << p->infoChienDich.ngayKT.thang << "/" << p->infoChienDich.ngayKT.nam << setw(10) << "|" << endl;
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    __END__                                                            |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
}
//=============================================================================================
//                                 DANH SÁCH LIÊN KẾT ĐƠN TÌNH NGUYỆN VIÊN
NodeTNV* createNodeTNV(TNV x)
{
    NodeTNV* p = new NodeTNV;
    if (p == NULL)
    {
        cout << "\nkhong du bo nho de cap phat.";
        return NULL;
    }
    p->infoTNV.Ma;
    p->infoTNV.HoLot;
    p->infoTNV.Ten;
    p->infoTNV.ngaythangnamsinh.ngay;
    p->infoTNV.ngaythangnamsinh.thang;
    p->infoTNV.ngaythangnamsinh.nam;
    p->infoTNV.SDT ;
    p->infoTNV.MaCD;
    p->next = NULL;
    return p;
}
void AddTailNodeTNV(ListTNV& DSTNV, NodeTNV* p)
{
    if (DSTNV.head == NULL)
    {
        DSTNV.head = DSTNV.tail = p;
    }
    else
    {
        DSTNV.tail->next = p;
        DSTNV.tail = p;
        p->next = NULL;
    }

}
void docFileTNV(ListTNV& DSTNV)
{
    DSTNV.tail = NULL;
    DSTNV.head = NULL;
    int i = 0;
    fstream filein;
    filein.open("TinhNguyenVien.txt", ios::in);
    if (filein.fail())
    {
        cout << "Khong mo duoc file de doc.";
        return;
    }
    while (!filein.eof())
    {
        NodeTNV* p = new NodeTNV;
        filein >> p->infoTNV.Ma;
        filein >> p->infoTNV.HoLot;
        filein >> p->infoTNV.Ten;
        filein >> p->infoTNV.ngaythangnamsinh.ngay;
        filein >> p->infoTNV.ngaythangnamsinh.thang;
        filein >> p->infoTNV.ngaythangnamsinh.nam;
        filein >> p->infoTNV.SDT;
        filein >> p->infoTNV.MaCD;
        p->next == NULL;
        AddTailNodeTNV(DSTNV, p);
        i++;
    }
    filein.close();
}
void duyetDanhSachTNV(ListTNV DSTNV)
{
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                        --DANH SACH TINH NGUYEN VIEN--                                                 |" << endl;
    cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
    cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20) 
        << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten <<setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/" 
            << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23)<< p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    __END__                                                            |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
}
//======================================================================================================================
//                                                  THÊM THÔNG TIN TÌNH NGUYỆN VIÊN VÀO DANH SÁCH TÌNH NGUYỆN VIÊN
void ThemTinhNguyenVien(ListTNV& DSTNV)
{

    NodeTNV* p = new NodeTNV;
    cout << "\nVui long nhap thong tin tinh nguyen vien.";
    cin.ignore();
    cout << "\nNhap ma tinh nguyen vien: ";
    getline(std::cin,p->infoTNV.Ma);
    if(p->infoTNV.Ma.length() > 10)
    {
        cout << "\nMa tinh nguyen vien chi gom 10 ky tu.";
        cin.ignore();
        cout << "\nNhap lai ma tinh nguyen vien:";
        getline(std::cin, p->infoTNV.Ma);
    }
    cout << "Nhap ho lot tinh nguyen vien: ";
    getline(std::cin, p->infoTNV.HoLot);
    cout << "Nhap ten tinh nguyen vien: ";
    getline(std::cin, p->infoTNV.Ten);
    cout << "Nhap ngay/thang/nam sinh: ";
    cin >> p->infoTNV.ngaythangnamsinh.ngay >> p->infoTNV.ngaythangnamsinh.thang >> p->infoTNV.ngaythangnamsinh.nam;
    cin.ignore();
    cout << "Nhap so dien thoai: ";
    getline(std::cin, p->infoTNV.SDT);
    if(p->infoTNV.SDT.length() > 10 || p->infoTNV.SDT.length() < 10)
    {
        cout << "\nSo dien thoai phai gom 10 ky tu";
        cout << "\nNhap lai so dien thoai: ";
        getline(std::cin, p->infoTNV.SDT);
    }
    cout << "Nhap ma chien dich: ";
    getline(std::cin, p->infoTNV.MaCD);
    if (p->infoTNV.MaCD.length() > 6 || p->infoTNV.MaCD.length() < 6)
    {
        cout << "\nMa Chien Dich phai gom 6 ky tu";
        printf("\nNhap lai ma chien dich: ");
        getline(std::cin, p->infoTNV.MaCD);
    }
    p->next = NULL;
    AddTailNodeTNV(DSTNV, p);
}
//=============================================================================================================
//                                            TÌM KIẾM THEO TIÊU CHÍ
NodeCD* SearchCD_Name(ListChienDich DSCD, string ten) {
    if (!DSCD.head)return NULL;
    for (NodeCD* p = DSCD.head; p; p = p->next)
        if (p->infoChienDich.TenCD == ten)
            return p;
    return NULL;
}
void PrintTNV_TenCD(ListTNV DSTNV, ListChienDich DSCD, string tenCD) {
    NodeCD* p = SearchCD_Name(DSCD, tenCD);
    if (p)
    {
        string maCD = p->infoChienDich.MaCD;
        cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                          --DANH SACH TINH NGUYEN VIEN THEO TEN CHIEN DICH CAN TIM--                                   |" << endl;
        cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
        cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
            << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
        for (NodeTNV* i = DSTNV.head; i; i = i->next) {
            if (i->infoTNV.MaCD == maCD)
                cout << "|" << setw(15) << i->infoTNV.Ma << setw(19) << i->infoTNV.HoLot << setw(15) << i->infoTNV.Ten << setw(14) << i->infoTNV.ngaythangnamsinh.ngay << "/"
                << i->infoTNV.ngaythangnamsinh.thang << "/" << i->infoTNV.ngaythangnamsinh.nam << setw(23) << i->infoTNV.SDT << setw(18) << i->infoTNV.MaCD << setw(9) << "|" << endl;
        }
        cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                                    __END__                                                            |" << endl;
        cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    }
    else cout << "\n Khong co tinh nguyen vien can tim trong chien dich nay!";
}
void TimkiemtheomaTNV(ListTNV& DSTNV)
{
    int flag = 0;
    string maTNV;
    cin.ignore();
    cout << "\nNhap ma tinh nguyen vien can tim: ";
    getline(std::cin, maTNV);
    if (maTNV.length() > 10 && maTNV.length() < 0)
    {
        cout << "\nMa tinh nguyen can tim nhap khong hop le.Ma tinh nguyen vien yeu cau 10 ki tu.";
        cout << "\nNhap lai ma tinh nguyen vien can tim: ";
        getline(std::cin, maTNV);
    }
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.Ma == maTNV)
        {
            flag = 1;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                --TINH NGUYEN VIEN CO MA TINH NGUYEN VIEN CAN TIM--                                    |" << endl;
            cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
            cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
                << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
                cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                    << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                                    __END__                                                            |" << endl;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
        }
    }
    if (flag == 0)
        cout << "\nMa tinh nguyen vien can tim khong co trong danh sach!" << endl;
}
void TimkiemtheoSDT(ListTNV DSTNV)
{
    int flag = 0;
    string SDT;
    cin.ignore();
    cout << "\nNhap so dien thoai can tim: ";
    getline(std::cin, SDT);
    if (SDT.length() > 10 && SDT.length() < 0)
    {
        cout << "\nSo dien thoai can tim khong hop le.So dien thoai yeu cau 10 ki tu.";
        cout << "\nNhap lai so dien thoai can tim: ";
        getline(std::cin, SDT);
    }
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.SDT == SDT)
        {
            flag = 1;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                  --TINH NGUYEN VIEN CO SO DIEN THOAI CAN TIM--                                        |" << endl;
            cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
            cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
                << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
            cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                                    __END__                                                            |" << endl;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
        }
    }
    if (flag == 0)
        cout << "\nMa tinh nguyen vien can tim khong co trong danh sach!" << endl;
}
//=======================================================================================================================
//                                                IN DANH SÁCH TÌNH NGUYÊN VIÊN THEO MÃ CHIẾN DỊCH
void Intheomacd(ListTNV& DSTNV)
{
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.MaCD == "126484")
        {
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                       --DANH SACH TINH NGUYEN VIEN CO CHIEN DICH CHUNG CU XANH NEP SONG DEP--                         |" << endl;
            cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
            cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
                << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
            cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
            p = p->next;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                                    __END__                                                            |" << endl;
            cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
        }
    }
    cout << "\n\n";
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                       --DANH SACH TINH NGUYEN VIEN CO CHIEN DICH TRAO TANG NHA TINH THUONG--                          |" << endl;
    cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
    cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
         << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.MaCD == "153464")
        {
            cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
        }
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    __END__                                                            |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\n\n";
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                   --DANH SACH TINH NGUYEN VIEN CO CHIEN DICH KHANH THANH SAN CHOI RAC TAI CHE--                       |" << endl;
    cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
    cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
        << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.MaCD == "159304")
        {
            cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
        }
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    __END__                                                            |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\n\n";
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                           --DANH SACH TINH NGUYEN VIEN CO CHIEN DICH GIA SU AO XANH--                                 |" << endl;
    cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
    cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
        << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.MaCD == "169032")
        {
            cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
        }
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    __END__                                                            |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\n\n";
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                   --DANH SACH TINH NGUYEN VIEN CO CHIEN DICH HO TRO PHONG CHONG DICH COVID 19--                       |" << endl;
    cout << "|--------------------------------------------------**********-----------------------------------------------------------|" << endl;
    cout << "|" << setw(15) << "MA TINH NGUYEN VIEN" << setw(15) << "HO LOT" << setw(15) << "TEN" << setw(25) << "NGAY THANG NAM SINH" << setw(20)
        << "SO DIEN THOAI" << setw(20) << "MA CHIEN DICH" << setw(6) << "|" << endl;
    for (NodeTNV* p = DSTNV.head; p != NULL; p = p->next)
    {
        if (p->infoTNV.MaCD == "143208")
        {
            cout << "|" << setw(15) << p->infoTNV.Ma << setw(19) << p->infoTNV.HoLot << setw(15) << p->infoTNV.Ten << setw(14) << p->infoTNV.ngaythangnamsinh.ngay << "/"
                << p->infoTNV.ngaythangnamsinh.thang << "/" << p->infoTNV.ngaythangnamsinh.nam << setw(23) << p->infoTNV.SDT << setw(18) << p->infoTNV.MaCD << setw(9) << "|" << endl;
        }
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    __END__                                                            |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
}
void menutimkiem(ListChienDich DSCD,ListTNV &DSTNV)
{
    int choice = 1;
    while (choice)
    {
        cout << "+----------------------------------************************************----------------------------+" << endl;
        cout << "|                                  | CHUC NANG TIM KIEM THEO TIEU CHI |                            |" << endl;
        cout << "+----------------------------------************************************----------------------------|" << endl;
        cout << "|                  1. Tim kiem tinh nguyen vien theo ten chien dich.                               |" << endl;
        cout << "|                  2. Tim kiem tinh nguyen vien theo ma tinh nguyen vien.                          |" << endl;
        cout << "|                  3. Tim kiem tinh nguyen vien theo so dien thoai.                                |" << endl;
        cout << "|                  0. Thoat khoi chuc nang tim kiem.                                               |" << endl;
        cout << "+--------------------------------------------------------------------------------------------------+" << endl;
        cout << "\n";
        cout << "------------------->Su lua chon tim kiem cua ban: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            string tenCD;
            cout << "\n Nhap ten chien dich can tim: ";
            cin >> tenCD;
            PrintTNV_TenCD(DSTNV, DSCD, tenCD);
            break;
        }
        case 2:
            TimkiemtheomaTNV(DSTNV);
            break;
        case 3:
            TimkiemtheoSDT(DSTNV);
            break;
        default:
            return;
        }
    }
    
}
void menu()
{
    int luachon;
    ListChienDich DSCD;
    ListTNV DSTNV;
    do
    {
        Home:
        cout << "\n\n" << endl;
        cout << "+------------------------***********************************---------------------------------------+" << endl;
        cout << "|                        | QUAN LY CHIEN DICH TINH NGUYEN  |                                       |" << endl;
        cout << "+------------------------***********************************---------------------------------------+" << endl;
        cout << "|         1. Doc file chiendich.txt va tinh nguyen.txt vao chuong trinh quan ly.                   |" << endl;
        cout << "|         2. Xuat danh sach chien dich va tinh nguyen vien.                                        |" << endl;
        cout << "|         3. Them mot tinh nguyen vien vao danh sach tinh nguyen vien.                             |" << endl;
        cout << "|         4. Tim kiem tinh nguyen vien theo cac tieu chi.                                          |" << endl;
        cout << "|         5. Xuat danh sach cac tinh nguyen theo ten chien dich.                                   |" << endl;
        cout << "|         0. Thoat khoi chuong trinh.                                                              |" << endl;
        cout << "+--------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                      --END MENU--                                                |" << endl;
        cout << "+--------------------------------------------------------------------------------------------------+" << endl;
        cout << "\n";
        cout << "--------->Su lua chon cua ban la: ";
        cin >> luachon;
        system("cls");
        switch (luachon)
        {
        case 1: docFileChienDich(DSCD);
                docFileTNV(DSTNV);
                break;
        case 2: duyetDanhSachChienDich(DSCD);
                duyetDanhSachTNV(DSTNV);
                break;
        case 3: ThemTinhNguyenVien(DSTNV);
                duyetDanhSachChienDich(DSCD);
                duyetDanhSachTNV(DSTNV);
                break;
        case 4: 
                menutimkiem(DSCD, DSTNV);
                break;
        case 5: Intheomacd(DSTNV);
                break;
        case 0: exit(1);
        default:
        {
            cout << "\nLua chon khong hop le";
            break;
        }
        }
    } while (luachon != 0);
}
int main()
{
    menu();
    system("pause");
    return 0;
}