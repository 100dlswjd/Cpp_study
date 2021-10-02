#include <iostream>

class SinivelCap // Äà¹° Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { std::cout << "Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù." << std::endl; }
};

class SneezeCap // ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { std::cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << std::endl; }
};

class SnuffleCap // ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { std::cout << "ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù." << std::endl; }
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