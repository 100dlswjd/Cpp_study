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

	// 정규직등록
	handler.AddEmployee(new PermanentWorker("KIN", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// 영업직 등록	
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	
	return 0;
}