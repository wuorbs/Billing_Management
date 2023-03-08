#ifndef BILLING_MANAGEMENT_CARDVECTOR_H
#define BILLING_MANAGEMENT_CARDVECTOR_H


#include <bits/stdc++.h>
using namespace std;

struct Card {
    char CardName[17];
    char CardPwd[7];
    int Status;
    double Balance;
    time_t Start;
    time_t Last;
    time_t End;
};

class CardVector {
public:

    explicit CardVector(const string &cardPATH);

    void addCard();

    void delCard();

    void queryCard();

    void resetPwd();

    void logon();

    static bool inputName(string &CardName);

    static bool inputPwd(string &CardPwd, int p);

    Card *isExist(string &CardName, int &CardIndex);

    void saveCard(const string &cardPATH);

    static void updateCard(const Card *p, const string &cardPATH, int CardIndex);

private:
    vector<Card> vec;
};


#endif //BILLING_MANAGEMENT_CARDVECTOR_H
