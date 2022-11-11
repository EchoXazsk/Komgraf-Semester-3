#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class BasicTicket
{
    public:
    string Nama;
    string KotaBrgkt;
    string KotaDtg;
    int NoTerbang;
    int Harga;

    BasicTicket(string x, string y, string z, int a, int b);
    {
        Nama = x;
    KotaBrgkt = y;
    KotaDtg = z;
    NoTerbang = a;
    Harga = b;
    }
};

BasicTicket::BasicTicket(string x, string y, string z, int a, int b)
{
    Nama = x;
    KotaBrgkt = y;
    KotaDtg = z;
    NoTerbang = a;
    Harga = b;
}

class PremiumTicket : public BasicTicket
{
    int PremiumPrice;

    public:
    void set_PremiumPrice()
        {
            PremiumPrice = Harga / 10;
            PremiumPrice += Harga;
            cout<<"Harga Premium Tiket adalah: ";
            cin>> PremiumPrice;
        }

        void display_PremiumPrice()
        {
            display_PremiumPrice();
            cout<<PremiumPrice<<endl;
        }
};

int main()
{
    BasicTicket BasicTicketObj1("satrio, Surabaya, Sidoarjo, 1299, 12000");
    cout << BasicTicketObj1.Nama<<endl<< " " << BasicTicketObj1.KotaBrgkt<<endl<< " " << BasicTicketObj1.KotaDtg<<end<< BasicTicketObj1.NoTerbang<<end<< BasicTicketObj1.Harga<<end<< "\n";
    PremiumTicket s;
    s.set_PremiumPrice;
    s.display_PremiumPrice;
    return 0;
}
