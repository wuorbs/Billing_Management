#include "Menu.h"

Menu::Menu() = default;

Menu::~Menu() = default;

void Menu::openMenu(CardVector &card, BillVector &bill) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t◎欢迎进入计费管理系统◎\n\n";
        cout << "\t\t\t    -------计费管理系统菜单-------\n";
        cout << "\t\t\t\t    1. 消费功能\n";
        cout << "\t\t\t\t    2. 账户功能\n";
        cout << "\t\t\t\t    3. 管理员功能\n";
        cout << "\t\t\t\t    0. 退出系统\n\n";
        cout << "\t\t\t\t请选择菜单项编号<0~3>:";
        cin >> op;
        switch (op) {
            case 1:
                subMenu1(card, bill);
                break;
            case 2:
                subMenu2(card);
                break;
            case 3:
                subMenu3(card, bill);
                break;
            case 0:
                system("cls");
                cout << "\n\t\t\t\t感谢你使用本系统！\n\n";
                system("pause");
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t输入的菜单项编号错误！\n\n";
                system("pause");
        }
    } while (op != 0);
}

void Menu::subMenu1(CardVector &card, BillVector &bill) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------消费功能-------\n";
        cout << "\t\t\t\t    1. 查询价格\n";
        cout << "\t\t\t\t    2. 上机\n";
        cout << "\t\t\t\t    3. 下机\n";
        cout << "\t\t\t\t    4. 充值\n";
        cout << "\t\t\t\t    5. 退费\n";
        cout << "\t\t\t\t    6. 查询账单\n";
        cout << "\t\t\t\t    0. 返回上级菜单\n\n";
        cout << "\t\t\t请选择菜单项编号<0~6>:";
        cin >> op;
        switch (op) {
            case 1:
                bill.checkPrice();
                break;
            case 2:
                card.logon();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t输入的菜单项编号错误！\n\n";
                system("pause");
        }

    } while (op != 0);
}

void Menu::subMenu2(CardVector &card) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------账户功能-------\n";
        cout << "\t\t\t\t    1. 创建卡\n";
        cout << "\t\t\t\t    2. 注销卡\n";
        cout << "\t\t\t\t    3. 查询卡\n";
        cout << "\t\t\t\t    4. 重设密码\n";
        cout << "\t\t\t\t    0. 返回上级菜单\n\n";
        cout << "\t\t\t\t请选择菜单项编号<0~4>:";
        cin >> op;
        switch (op) {
            case 1:
                card.addCard();
                break;
            case 2:
                card.delCard();
                break;
            case 3:
                card.queryCard();
                break;
            case 4:
                card.resetPwd();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t输入的菜单项编号错误！\n\n";
                system("pause");
        }
    } while (op != 0);
}

void Menu::subMenu3(CardVector &card, BillVector &bill) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------账户功能-------\n";
        cout << "\t\t\t\t    1. 查询卡\n";
        cout << "\t\t\t\t    2. 查看收益\n";
        cout << "\t\t\t\t    3. 价格调整\n";
        cout << "\t\t\t\t    0. 返回上级菜单\n\n";
        cout << "\t\t\t\t请选择菜单项编号<0~3>:";
        cin >> op;
        switch (op) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                bill.resetPrice();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t输入的菜单项编号错误！\n\n";
                system("pause");
        }
    } while (op != 0);
}