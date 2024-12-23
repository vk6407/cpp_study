#include "classes.h"
#include <iostream>
#include <string>
//#include <ctime>
#include <conio.h>
using namespace  std;

const string code = { "123" }; //��� ��� ����� � ��������� ����

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    string vcode = { "000" };
    char oper = '0';

    //��������� ������������� ��������
    VendingMachine* machine = new VendingMachine();
    CashRegister* cash = new CashRegister();
    Snack* bounty = new Snack("������", 250, 300, 10);
    Snack* snickers = new Snack("�������", 235, 340, 11);
    Snack* mars = new Snack("����", 220, 315, 12);
    SnackSlot* slot1 = new SnackSlot();
    SnackSlot* slot2 = new SnackSlot();
    SnackSlot* slot3 = new SnackSlot();
    for (int i = 0; i < slot1->getMaxSnackCount(); i++) slot1->addSnack(bounty);
    for (int i = 0; i < slot2->getMaxSnackCount(); i++) slot2->addSnack(snickers);
    for (int i = 0; i < slot3->getMaxSnackCount(); i++) slot3->addSnack(mars);
    machine->addSlot(slot1);
    machine->addSlot(slot2);
    machine->addSlot(slot3);

    while (true)
    {
        if (code != vcode)
        {
            cout << endl << "� �������:" << endl;
            if (slot1->getSnackCount() != 0) bounty->showSnackInfo();
            if (slot2->getSnackCount() != 0) snickers->showSnackInfo();
            if (slot3->getSnackCount() != 0) mars->showSnackInfo();
            cout << endl << "������� '1' ��� ������� ������, '2' ��� ������� ��������, '3' ��� ������� �����, " << endl;
            cout << "        's' ��� ����� � ��������� ����: ";
            oper = _getch();
        }
        else if (code == vcode)
        {
            cout << "�������: " << cash->getCurrentBalance() << endl;
            cout << "���������� ������: " << machine->getSlotCount() << endl;
            cout << "���������� ������ ������: " << machine->getEmptySlotsCount() << endl;
            cout << "���������� ������ " << bounty->getName() << ": " << slot1->getSnackCount() << endl;
            cout << "���������� ������ " << snickers->getName() << ": " << slot2->getSnackCount() << endl;
            cout << "���������� ������ " << mars->getName() << ": " << slot3->getSnackCount() << endl;
            //slot1->slotInfo();
            //slot2->slotInfo();
            //slot3->slotInfo();
            cout << endl << "������� 'i' ��� ���������� �������� �������, ";
            cout << endl << "'b' ��� �������� � ���������������� ����, 'q' ��� ������: ";
            oper = _getch();
        }
        if (oper == 's')
        {
            cout << endl << "������� ���: ";
            cin >> vcode;
            system("cls");
        }
        if (oper == 'q' && code == vcode)
        {
            cout << "���������� ������.\n";
            break;
        }
        switch (oper) //
        {
        case '1': // ������� ������
            cash->acceptAmount(slot1->buySnack());
            break;
        case '2': //������� ��������
            cash->acceptAmount(slot2->buySnack());
            break;
        case '3': //������� �����
            cash->acceptAmount(slot3->buySnack());
            break;
        case 'i': // �������� ������������ ������
            slot1->initSlot(bounty);
            slot2->initSlot(snickers);
            slot3->initSlot(mars);
            system("cls");
            break;
        case 'b': //������� � ���������������� ����
            vcode = { "000" };
            system("cls");
            break;
        default:
            system("cls");
            if (vcode != code) cout << endl << "�� ����� ������������ ������." << endl;
            break;
        }
    }

    delete bounty;
    delete snickers;
    delete mars;
    delete slot1;
    delete slot2;
    delete slot3;
    delete cash;
    delete machine;

    return 0;
}
