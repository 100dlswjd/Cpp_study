class PermanentWorker
{
private:
	char name[100];
	int salary;
public:
	PermanentWorker(char* name, int money) : salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		std::cout << "name : " << name << std::endl;
		std::cout << "salary : " << GeyPay() << std::endl << std::endl;
	}
};