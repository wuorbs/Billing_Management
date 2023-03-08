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
    cout << "\n\t\t\t\t当前价格为：" << setprecision(2) << Price << "/分钟\n\n";
    system("pause");
}

void BillVector::resetPrice() {
    double NewPrice;
    system("cls");
    cout << "\n\t\t\t\t当前价格为：" << setprecision(2) << Price << "/分钟\n\n";
    cout << "\t\t\t\t请输入新的价格</分钟>：";
    cin >> NewPrice;
    Price = NewPrice;
    savePrice(PRICEPATH);
    system("cls");
    cout << "\n\t\t\t    价格调整成功，当前价格为：" << setprecision(2) << Price << "/分钟\n\n";
    system("pause");
}

void BillVector::savePrice(const string &pricePATH) {
    ofstream pricefile(pricePATH, ios::out | ios::binary);
    if (!pricefile.is_open()) return;
    pricefile.write((char *) &Price, sizeof(double));
    pricefile.close();
}