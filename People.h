#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class People  //基类
{
public:
	string name;//姓名
	string ID;//账号
	People(string name1 = "null",string id = "null") :name(name1), ID(id) {}
	string changeName()//修改名字
	{
		string nam;
		cout << "请输入修改后的名字：";
		cin >> nam;
		name = nam;
		return name;
	}
	string getname() { return name; }//获得修改后的名字
	virtual void display() 
	{
		cout << "姓名：" << name << " 账号：" << ID << endl;
	}
};
class Student :public People//继承基类的派生类Student
{
public:
	char gender;
	string classname;
	int studentnum;//学生总数
	double score[4];//四门学科的成绩
	double totalScore;//总分（静态数据）
	double averageScore;//平均分（静态数据）
	Student* next;//链表指针
	//构造函数初始化
	Student(string name1 = "null", string id = "null", char g = 'M', string c = "null", double s[4] = { 0 }) :People(name1, id), gender(g), classname(c), next(nullptr)
	{
		for (int i = 0; i < 4; i++)
		{
			if (s)
			{
				score[i] = s[i];
			}
			else
			{
				score[i] = 0;
			}
		}
		calScore();
	}
	//计算平均分
	void calScore()
	{
		totalScore = 0;
		for (int i = 0; i < 4; i++)
		{
			totalScore += score[i];
		}
		averageScore = totalScore / 4.0;
	}
	bool operator==(Student& m) { return (ID == m.ID); }
	string getname()const { return name; }//获得学生姓名
	string getID()const { return ID; }//获得学生账号(学号）
	char getgender()const { return gender; }//获得学生性别
	string getclassname()const { return classname; }//获得班级号
	double getscore1() { return score[0]; }
	double getscore2() { return score[1]; }
	double getscore3() { return score[2]; }
	double getscore4() { return score[3]; }
	void addstudentnum() { studentnum++; }//添加学生数
	void deletestudentnnum() { studentnum--; }//删除学生数
	string changeID()//修改学号
	{
		string id;
		cout << "请输入修改后的学号：";
		cin >> id;
		ID = id;
		return ID;
	}
	char changegender()//修改性别
	{
		char g;
		cout << "请输入修改后的性别：";
		cin >> g;
		gender=g;
		return gender;
	}
	string changeclass()//修改班级
	{
		string classna;
		cout << "请输入修改后的班级：";
		cin >> classna;
		classname=classna;
		return classname;
	}
	void display()
	{
		cout << "姓名：" << name << " 性别：" << gender  << " 学号：" << ID << " 班级：" << classname << " 四门课程成绩：";
		for (int i = 0; i < 4; i++)
		{
			cout << score[i] << " ";
		}
		cout << endl;
	}

};
class Manager :public People
{
public:
	friend class Student;
	string pass;
	Manager* next;
	Manager(string name1 = "null", string id = "null", string p = "123456") :People(name1, id), pass(p) {}
	void changepass()//修改密码
	{
		string p;
		cout << "请输入修改后的密码：";
		cin >> p;
		pass = p;
	}
	bool operator==(const Manager& m) { return (pass == m.pass && ID == m.ID); }
	void display()//显示个人信息
	{
		cout << "账号：" << ID << " 姓名：" << name << " 密码：" << pass << endl;
	}
	string getpass() { return pass; }//获得修改后的密码
	/*Manager setmanager(string nam,string id,string password)
	{
		return Manager(nam, id, password);
	}*/
};
class Teacher :public People
{
public:
	string pass;
	friend class Student;
	Teacher(string nam = "null", string id = "null", string p = "123456") :People(nam, id), pass(p) {}
	Teacher* next;
	//void changescore(StudentList& m)//修改学生成绩
	//{

	//}
	bool operator==(const Teacher& m)
	{
		return (pass == m.pass && ID == m.ID && name == m.name);

	}
	string changePass()//修改名字
	{
		string pass1;
		cout << "请输入修改后的密码：";
		cin >> pass1;
		pass = pass1;
		return pass;
	}
	string getpass() { return pass; }
	void display()//显示个人信息
	{
		cout << "账号：" << ID << " 姓名：" << name << " 密码：" << pass << endl;
	}
	Teacher setTeacher(string name1, string id, string pass)
	{
		return Teacher(name1, id, pass);
	}
};