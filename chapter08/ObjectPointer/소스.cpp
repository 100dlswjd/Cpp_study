#include<iostream>
#include<string>

class Employee
{
private:
	char name[100];
public:
	Employee(std::string fname)
	{
		std::size_t fname_length = fname.copy(name, sizeof(fname), 0);
		name[fname_length] = '\0';
	}
	void ShowYourName()const
	{
		std::cout << this->name << std::endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(std::string fname, int fmoney)
		: Employee(fname), salary(fmoney)
	{ }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << GetPay() << std::endl << std::endl;
	}

};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(std::string fname, int fpay)
		: Employee(fname), workTime(0), payPerHour(fpay)
	{ }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << GetPay() << std::endl << std::endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(std::string fname, int fmoney, double fratio)
		: PermanentWorker(fname, fmoney), salesResult(0), bonusRatio(fratio)
	{ }
	void AddSalesResult(int value)
	{
		this->salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay();
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << GetPay() << std::endl << std::endl;
	}
};

class EmployeeHandler 
{
private:
	Employee * emplist[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		this->emplist[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for(int i = 0 ; i < empNum; i++)
		{
			emplist[i]->ShowSalaryInfo();
		}
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
		{
			sum += emplist[i]->GetPay();
		}
		*/
		std::cout << "Salary sum : " << sum << std::endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete emplist[i];
	}
};

int main()
{
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIN", 10000));
	handler.AddEmployee(new PermanentWorker("IN", 50000));
	handler.AddEmployee(new PermanentWorker("JUN", 17000));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();

	
	return 0;
}