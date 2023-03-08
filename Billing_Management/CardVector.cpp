#include "CardVector.h"
#include "global.h"
#include "tool.h"


CardVector::CardVector(const string &cardPATH) {
    ifstream cardfile(cardPATH, ios::in | ios::binary);
    Card card{};
    if (!cardfile.is_open()) return;
    while (true) {
        cardfile.read((char *) &card, sizeof(Card));
        if (cardfile.eof())break;
        vec.push_back(card);
    }
    cardfile.close();
}

void CardVector::addCard() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        if (isExist(CardName, CardIndex) != nullptr) {
            system("cls");
            cout << "\n\t\t\t\t此卡号已使用，创建卡失败！\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 1)) {
            Card card{};
            strcpy(card.CardName, CardName.c_str());
            strcpy(card.CardPwd, CardPwd.c_str());
            card.Status = UNUSE;
            card.Balance = 100;
            card.Start = card.Last = card.End = time(nullptr);
            vec.push_back(card);
            saveCard(CARDPATH);
            system("cls");
            cout << "\n\t\t\t\t\t创建卡成功！\n\n";
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t密码格式不正确，创建卡失败！\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t输入的卡号格式不正确！\n\n";
        system("pause");
    }
}

void CardVector::delCard() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t卡号不存在！\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 1) && CardPwd == p->CardPwd) {
            vec.erase(vec.begin() + CardIndex);
            saveCard(CARDPATH);
            system("cls");
            cout << "\n\t\t\t\t\t删除卡成功！\n\n";
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t密码错误，删除卡失败！\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t输入的卡号格式不正确！\n\n";
        system("pause");
    }
}

void CardVector::queryCard() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t卡号不存在！\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            system("cls");
            cout << "\n\t\t卡号\t状态\t余额\t上次使用时间\n";
            cout << "\t\t" << CardName << '\t';
            if (p->Status == UNUSE) cout << "未上机\t";
            else cout << "上机\t";
            cout << p->Balance << '\t';
            char LastTime[20] = {0};
            timeToString(p->Last, LastTime);
            cout << LastTime << '\n';
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t密码错误，查询卡失败！\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t输入的卡号格式不正确！\n\n";
        system("pause");
    }
}

void CardVector::resetPwd() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t卡号不存在！\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            if (inputPwd(CardPwd, 2)) {
                strcpy(p->CardPwd, CardPwd.c_str());
                system("cls");
                cout << "\n\t\t\t\t\t重设密码成功！\n\n";
                system("pause");
            } else {
                system("cls");
                cout << "\n\t\t\t\t密码格式不正确，创建卡失败！\n\n";
                system("pause");
            }
        } else {
            system("cls");
            cout << "\n\t\t\t\t密码错误，重设密码失败！\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t输入的卡号格式不正确！\n\n";
        system("pause");
    }
}

void CardVector::logon() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t卡号不存在！\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            if (p->Status == USING) {
                system("cls");
                cout << "\n\t\t\t\t该卡正在使用，不可重复上机！\n\n";
                system("pause");
            } else if (p->Balance <= 0) {
                system("cls");
                cout << "\n\t\t\t\t卡余额不足，上机失败！\n\n";
                system("pause");
            } else {
                p->Status = USING;
                p->Start = p->Last = time(nullptr);
                char StartTime[20];
                timeToString(p->Start, StartTime);
                updateCard(p, CARDPATH, CardIndex);
                system("cls");
                cout << "\n\t\t\t\t\t上机成功！\n\n";
                cout << "\t\t\t\t卡号：" << p->CardName << '\n';
                cout << "\t\t\t\t余额：" << p->Balance << '\n';
                cout << "\t\t\t\t上机时间：" << StartTime << "\n\n";
                system("pause");
            };
        } else {
            system("cls");
            cout << "\n\t\t\t\t密码错误，上机失败！\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t输入的卡号格式不正确！\n\n";
        system("pause");
    }
}

bool CardVector::inputName(string &CardName) {
    while (true) {
        system("cls");
        cout << "\n\t\t\t请输入卡号<长度为1~17>：";
        cin >> CardName;
        if (CardName.size() > 17) {
            system("cls");
            cout << "\n\t\t\t\t卡号长度超过最大值！\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t重新输入吗？<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        } else break;
    }
    return true;
}

bool CardVector::inputPwd(string &CardPwd, int p) {
    while (true) {
        system("cls");
        if (p == 2) cout << "\n\t\t\t请输入新密码<长度为1~7>:";
        else cout << "\n\t\t\t请输入密码<长度为1~7>:";
        cin >> CardPwd;
        if (CardPwd.size() > 7) {
            system("cls");
            cout << "\n\t\t\t\t密码长度超过最大值！\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t重新输入吗？<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        } else if (p) {
            system("cls");
            cout << "\n\t\t\t请再次输入密码<长度为1~7>：";
            string Pwd;
            cin >> Pwd;
            if (Pwd != CardPwd) {
                system("cls");
                cout << "\n\t\t\t\t两次输入的密码不相同！\n\n";
                char ch = 'M';
                while (ch != 'N' && ch != 'Y') {
                    cout << "\t\t\t\t重新输入吗？<y/n>:";
                    cin >> ch;
                    ch = (char) toupper(ch);
                }
                if (ch == 'N') return false;
            } else break;
        } else break;
    }
    return true;
}

Card *CardVector::isExist(string &CardName, int &CardIndex) {
    CardIndex = 0;
    for (auto &it: vec) {
        if (it.CardName == CardName) return &it;
        CardIndex++;
    }
    return nullptr;
}

void CardVector::saveCard(const string &cardPATH) {
    ofstream cardfile(cardPATH, ios::out | ios::binary);
    if (!cardfile.is_open()) return;
    for (auto it: vec) cardfile.write((char *) &it, sizeof(Card));
    cardfile.close();
}

void CardVector::updateCard(const Card *p, const string &cardPATH, int CardIndex) {
    fstream cardfile(cardPATH, ios::in | ios::out);
    if (!cardfile.is_open()) return;
    cardfile.seekp(sizeof(Card) * CardIndex, ios::beg);
    cardfile.write((char *) p, sizeof(Card));
    cardfile.close();
}
