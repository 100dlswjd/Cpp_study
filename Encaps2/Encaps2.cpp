#include<iostream>

class SinivelCap  // Äà¹° Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { std::cout << "Äà¹°ÀÌ ½Ï ~ ³³´Ï´Ù." << std::endl; }
};

class SneezeCap
{
public:
	void Take() const { std::cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << std::endl; }
};

class SnuffleCap
{
public:
	void Take() const { std::cout << "ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù." << std::endl; }
};

class CONTAC600
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}