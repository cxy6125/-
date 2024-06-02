#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class People  //����
{
public:
	string name;//����
	string ID;//�˺�
	People(string name1 = "null",string id = "null") :name(name1), ID(id) {}
	string changeName()//�޸�����
	{
		string nam;
		cout << "�������޸ĺ�����֣�";
		cin >> nam;
		name = nam;
		return name;
	}
	string getname() { return name; }//����޸ĺ������
	virtual void display() 
	{
		cout << "������" << name << " �˺ţ�" << ID << endl;
	}
};
class Student :public People//�̳л����������Student
{
public:
	char gender;
	string classname;
	int studentnum;//ѧ������
	double score[4];//����ѧ�Ƶĳɼ�
	double totalScore;//�ܷ֣���̬���ݣ�
	double averageScore;//ƽ���֣���̬���ݣ�
	Student* next;//����ָ��
	//���캯����ʼ��
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
	//����ƽ����
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
	string getname()const { return name; }//���ѧ������
	string getID()const { return ID; }//���ѧ���˺�(ѧ�ţ�
	char getgender()const { return gender; }//���ѧ���Ա�
	string getclassname()const { return classname; }//��ð༶��
	double getscore1() { return score[0]; }
	double getscore2() { return score[1]; }
	double getscore3() { return score[2]; }
	double getscore4() { return score[3]; }
	void addstudentnum() { studentnum++; }//���ѧ����
	void deletestudentnnum() { studentnum--; }//ɾ��ѧ����
	string changeID()//�޸�ѧ��
	{
		string id;
		cout << "�������޸ĺ��ѧ�ţ�";
		cin >> id;
		ID = id;
		return ID;
	}
	char changegender()//�޸��Ա�
	{
		char g;
		cout << "�������޸ĺ���Ա�";
		cin >> g;
		gender=g;
		return gender;
	}
	string changeclass()//�޸İ༶
	{
		string classna;
		cout << "�������޸ĺ�İ༶��";
		cin >> classna;
		classname=classna;
		return classname;
	}
	void display()
	{
		cout << "������" << name << " �Ա�" << gender  << " ѧ�ţ�" << ID << " �༶��" << classname << " ���ſγ̳ɼ���";
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
	void changepass()//�޸�����
	{
		string p;
		cout << "�������޸ĺ�����룺";
		cin >> p;
		pass = p;
	}
	bool operator==(const Manager& m) { return (pass == m.pass && ID == m.ID); }
	void display()//��ʾ������Ϣ
	{
		cout << "�˺ţ�" << ID << " ������" << name << " ���룺" << pass << endl;
	}
	string getpass() { return pass; }//����޸ĺ������
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
	//void changescore(StudentList& m)//�޸�ѧ���ɼ�
	//{

	//}
	bool operator==(const Teacher& m)
	{
		return (pass == m.pass && ID == m.ID && name == m.name);

	}
	string changePass()//�޸�����
	{
		string pass1;
		cout << "�������޸ĺ�����룺";
		cin >> pass1;
		pass = pass1;
		return pass;
	}
	string getpass() { return pass; }
	void display()//��ʾ������Ϣ
	{
		cout << "�˺ţ�" << ID << " ������" << name << " ���룺" << pass << endl;
	}
	Teacher setTeacher(string name1, string id, string pass)
	{
		return Teacher(name1, id, pass);
	}
};