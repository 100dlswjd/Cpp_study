#include<iostream>
#include<string>
class Book
{
private:
	char title[_MAX_PATH];
	char isbn[_MAX_PATH];
	int price;
public:
	Book(std::string ftitle, std::string fisbn, int fprice)
	{

		std::size_t title_length = ftitle.copy(title, sizeof(ftitle), 0);
		title[title_length] = '\0';

		std::size_t isbn_length = fisbn.copy(isbn, sizeof(fisbn), 0);
		isbn[isbn_length] = '\0';

		price = fprice;
	}
	void ShowBookInfo()
	{

		std::cout << "제목 : " << title << std::endl;
		std::cout << "ISBN : " << isbn << std::endl;
		std::cout << "가격 : " << price << std::endl;
	}
};

class EBook : public Book
{
private:
	char DRMKey[_MAX_PATH];
public:
	EBook(std::string ftitle, std::string fisbn, int fprice, std::string fDRMKey) :
		Book(ftitle, fisbn, fprice)
	{
		std::size_t DRMKey_length = fDRMKey.copy(DRMKey, sizeof(fDRMKey), 0);
		DRMKey[DRMKey_length] = '\0';
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		std::cout << "인증키 : " << DRMKey << std::endl;
	}
};

int main()
{
	Book b1("도서관 모험", "555-12345-890-0", 20000);
	EBook b2("도서관 모험(E-book)", "555-12345-890-1", 10000, "fdx9w0i8kiw");

	b1.ShowBookInfo();
	std::cout<<std::endl;
	b2.ShowEBookInfo();
	std::cout << std::endl;

	int* intp;
	char* charp;
	float* floatp;
	double* doublep;
	char* c1, c2, c3;

	std::cout << "intp *p size : " << sizeof(intp) << std::endl;
	std::cout << "char *p size : " << sizeof(charp) << std::endl;
	std::cout << "floatp *p size : " << sizeof(floatp) << std::endl;
	std::cout << "doublep *p size : " << sizeof(doublep) << std::endl;
	std::cout << std::endl;

	std::cout << "c1 size : " << sizeof(c1) << std::endl;
	std::cout << "c2 size : " << sizeof(c2) << std::endl;
	std::cout << "c3 size : " << sizeof(c3) << std::endl;

	return 0;
}