#include <iostream>

class SinivelCap // �๰ óġ�� ĸ��
{
public:
	void Take() const { std::cout << "�๰�� ��~ ���ϴ�." << std::endl; }
};

class SneezeCap // ��ä�� óġ�� ĸ��
{
public:
	void Take() const { std::cout << "��ä�Ⱑ �ܽ��ϴ�." << std::endl; }
};

class SnuffleCap // �ڸ��� óġ�� ĸ��
{
public:
	void Take() const { std::cout << "�ڰ� �� �ո��ϴ�." << std::endl; }
};

class ColPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap& cap)const { cap.Take(); }
};

int main(void) {
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}