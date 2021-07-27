#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE =1,DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct {
	int accID;  // 계좌번호
	int balance; // 잔액
	char cusName[NAME_LEN]; // 고객 이름
}Account;

Account accArr[100];  // Account 저장을 위한 배열
int accNum = 0; // 저장된 Account 수

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney;
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void) {
	int money;
	int id;

	cout << "[입   금]" << endl;
	cout << "계좌ID"; cin >> id;
}