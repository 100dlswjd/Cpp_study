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
	void ShowYourName() const
	{
		std::cout << "name : " << this->name << std::endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
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
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << GetPay() << std::endl;
	}
};

namespace RISK_LEVEL
{
	enum {RISK_A = 30, RISK_B = 20, RISK_C = 10};
}


class ForeignSalesWorker : public SalesWorker
{
private:
	int risk_level;
public:
	ForeignSalesWorker(std::string fname, int fmoney, double fratio, int frisk_level)
		: SalesWorker(fname, fmoney, fratio), risk_level(frisk_level)
	{ }
	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * (risk_level / 100.0));
	}
	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << SalesWorker::GetPay() << std::endl;
		std::cout << "risk pay : " << GetRiskPay() << std::endl;
		std::cout << "sum : " << GetPay() << std::endl << std::endl;
	}
};

class EmployeeHandler
{
private:
	Employee* emplist[50];
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
		for (int i = 0; i < empNum; i++)
		{
			emplist[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
		{
			sum += emplist[i]->GetPay();
		}

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

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);
	
	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);
	
	handler.ShowAllSalaryInfo();
	return 0;
}