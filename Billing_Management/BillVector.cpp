#include "BillVector.h"
#include "global.h"

BillVector::BillVector(const string &pricePATH) {
    ifstream pricefile(pricePATH, ios::in | ios::binary);
    if (!pricefile.is_open()) return;
    pricefile.read((char *) &Price, sizeof(double));
    pricefile.close();
}

void BillVector::checkPrice() const {
    system("cls");
    cout << "\n\t\t\t\t��ǰ�۸�Ϊ��" << setprecision(2) << Price << "/����\n\n";
    system("pause");
}

void BillVector::resetPrice() {
    double NewPrice;
    system("cls");
    cout << "\n\t\t\t\t��ǰ�۸�Ϊ��" << setprecision(2) << Price << "/����\n\n";
    cout << "\t\t\t\t�������µļ۸�</����>��";
    cin >> NewPrice;
    Price = NewPrice;
    savePrice(PRICEPATH);
    system("cls");
    cout << "\n\t\t\t    �۸�����ɹ�����ǰ�۸�Ϊ��" << setprecision(2) << Price << "/����\n\n";
    system("pause");
}

void BillVector::savePrice(const string &pricePATH) {
    ofstream pricefile(pricePATH, ios::out | ios::binary);
    if (!pricefile.is_open()) return;
    pricefile.write((char *) &Price, sizeof(double));
    pricefile.close();
}