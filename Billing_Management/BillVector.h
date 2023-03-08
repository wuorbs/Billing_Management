#ifndef BILLING_MANAGEMENT_BILLVECTOR_H
#define BILLING_MANAGEMENT_BILLVECTOR_H


#include <bits/stdc++.h>
using namespace std;

struct Bill {
    char CardName[17];
    time_t Start;
    time_t End;
    double Balance;
};

class BillVector {
public:
    explicit BillVector(const string &pricePATH);

    void checkPrice() const;

    void resetPrice();

    void savePrice(const string &pricePATH);

private:
    vector<Bill> vec;

    double Price{} {};
};


#endif //BILLING_MANAGEMENT_BILLVECTOR_H
