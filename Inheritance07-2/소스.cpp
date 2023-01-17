#include<iostream>
#include<string>

class MyFriendInfo
{
private:
	char name[_MAX_PATH];
	int age;
public:
	MyFriendInfo(std::string fname, int fage) : age(fage)
	{
		std::size_t length = fname.copy(name, sizeof(fname), 0);
		name[length] = '\0';
	}

	void ShowMyFriendInfo()
	{
		std::cout << "�̸� : " << name << std::endl;
		std::cout << "���� : " << age << std::endl;
	}
	~MyFriendInfo()
	{
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char addr[_MAX_PATH];
	char phone[_MAX_PATH];
public:
	MyFriendDetailInfo(std::string fname, int fage, std::string adr, std::string pnum)
		: MyFriendInfo(fname, fage)
	{
		std::size_t length_addr = adr.copy(addr, sizeof(adr), 0);
		addr[length_addr] = '\0';

		std::size_t length_pnum = pnum.copy(phone, sizeof(pnum), 0);
		phone[length_pnum] = '\0';
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		std::cout << "�ּ� : " << addr << std::endl;
		std::cout << "��ȭ : " << phone << std::endl;
	}
	~MyFriendDetailInfo()
	{
	}
};



int main()
{
	MyFriendDetailInfo fren1("�̸���", 56, "��", "010-1234-5678");
	fren1.ShowMyFriendDetailInfo();
	return 0;
}