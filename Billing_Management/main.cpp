#include "Menu.h"
#include "global.h"

int main() {
    CardVector card(CARDPATH);
    BillVector bill(PRICEPATH);
    Menu::openMenu(card, bill);
}