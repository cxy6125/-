#include "List.h"
//查找学生
void StudentList::find(int i)
{
	string name = "null", ID = "null";
	Student* current = head;		
	bool flag = false;
	switch (i)
	{
	case 1:
		cout << "请输入学号:";
		cin >> ID;	
		while (current != nullptr)
		{
			if (current->ID == ID)
			{
				cout << "找到该学生,";
				current->display();
				flag = true;
			}
			current = current->next;
		}
		if (flag == false)
		{
			cout << "未找到该学生" << endl;
		}
		break;
	case 2:
		cout << "请输入姓名：";
		cin >> name;
		while (current != nullptr)
		{
			if (current->name == name)
			{
				cout << "找到该学生,";
				current->display();
				flag = true;
			}
			current = current->next;
		}
		if (flag == false)
		{
			cout << "未找到该学生！" << endl;
		}
		break;
	default:
		cout << "输入错误！" << endl;
		break;
	}
}
//添加学生
void StudentList::addStudent(Student* student)
{
	if (head == nullptr)
		head = student;
	else
	{
		Student* current = head;
		while (current != nullptr && current->next != nullptr)
		{
			current = current->next;
		} 
		current->next = student;
	}
}
//删除学生
void StudentList::deleteStudentID(string id)
{
	if (head == nullptr)//如果头节点为空
	{
		return;
	}
	if (head->ID == id)//如果要删除节点为头节点
	{
		Student* temp = head;
		head = head->next;
		delete temp;
		tihuanFile("student.txt");//文件中数据同步
		return;
	}
	Student* current = head;//要删除节点不是头节点
	while (current->next != nullptr && current->next->ID != id)
	{
		current = current->next;
	}
	if (current->next == nullptr)//如果没有符合的删除节点
	{
		return;
	}
	//找到了删除的节点
	Student* temp = current->next;
	current->next = current->next->next;
	delete temp;
	tihuanFile("student.txt");//文件中数据同步
	return;
}
void StudentList::tihuanFile(string filename)
{
	ofstream infile(filename,ios::out);
	if (!infile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	else
	{
		Student* current = head;
		while (current != nullptr)
		{
			infile << current->name << " " << current->gender << " " << current->ID << " " << current->classname << " ";
			for (int i = 0; i < 4; i++)
			{
				infile << current->score[i] << " ";
			}
			infile << endl;
			current = current->next;
		}
		infile.close();
	}
}
///写入文本
void StudentList::saveToFile(string filename)
{
	ofstream infile(filename);
	if (!infile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	else
	{
		Student* current = head;
		while (current != nullptr)
		{
			infile << current->name << " " << current->gender << " " << current->ID << " " << current->classname << " ";
			for (int i = 0; i < 4; i++)
			{
				infile << current->score[i] << " ";
			}
			infile << endl;
			current = current->next;
		}
		infile.close();
	}
}
//文件中加载学生信息
void StudentList::loadFromFile(string filename)
{
	ifstream infile(filename);
	if (!infile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	else
	{
		string name, classname;
		char gender;
		string ID;
		double score[4];
		while (infile >> name >> gender >> ID >> classname)
		{
			for (int i = 0; i < 4; i++)
			{
				infile >> score[i];
			}
			Student* student = new Student(name,ID, gender, classname, score);
			addStudent(student);
		}
		infile.close();
	}
}
//显示学生信息
void StudentList::display()
{
	Student* current = head;
	while (current != nullptr)
	{
		cout << "Name:" << current->name << ",Gender:" << current->gender << ",StudentID:" << current->ID << ",Class:" << current->classname << ",Score:";
		for (int i = 0; i < 4; i++)
		{
			cout << current->score[i] << " ";
		}
		cout << ",Total Score:" << current->totalScore << ",Average Score:";
		cout<< current->averageScore << endl;
		current = current->next;
	}
}
void StudentList::swapData(Student* a, Student* b) {
	// 交换两个节点的全部数据
	Student temp = *a;
	*a = *b;
	*b = temp;
}
void StudentList::SortStudent(int n)
{
	if (head == nullptr)
	{
		return;
	}
	else {
		for (Student* current = head; current != nullptr; current = current->next)
		{
			Student* temp;
			Student* p = current;
			for (temp = current->next; temp != nullptr; temp = temp->next)
			{
				if (p->score[n] < temp->score[n]) 
				{
					p = temp;
				}
			}
			if (p != current) 
			{
				swapData(p, current);
			}
		}
	}
}
void StudentList::SortID()
{
	Student* current=head;
	Student* temp;
	if (current == nullptr)
		return;
	else
	{
		for (current = head; current->next; current = current->next)
		{
			Student* p = current;
			for (temp = current->next; temp; temp = temp->next)
			{
				if (p->ID  > temp->ID)
					p = temp;
			}
			if (p != current)
				swap(p, current);
		}
	}
	display();
}
StudentList::~StudentList()
{
	while (head != nullptr)
	{
		Student* temp = head;
		head = head->next;
		delete temp;
	}
}
////////////////////////////////////////////
//查找教师信息
Teacher* Teacherlist::find(Teacher& a)
{
	for (Teacher* m = head; m; m = m->next)
	{
		if (m->ID == a.ID)
			return m;
	}
	return nullptr;
}
Teacher* Teacherlist::yanzhengfind(Teacher& a)
{
	for (Teacher* m = head; m; m = m->next)
	{
		if (*m == a)
		{
			return m;
		}
	}
	return nullptr;
}
//登录教师账户
void Teacherlist::load(Teacher& a, StudentList& student)
{
	if (yanzhengfind(a))
	{
		Teacher* teacher;
		teacher = find(a);
		cout << "登录成功" << endl;
		teacher->display();
		int n = 0, fh = 0;
		while (n != -1)
		{
			n = 0;
			fh = 0;
			cout << "---------------------是分割线哦------------------" << endl;
			cout << "1.显示个人信息" << endl;
			cout << "2.修改密码" << endl;
			cout << "3.修改姓名" << endl;
			cout << "4.根据学号查询学生信息" << endl;
			cout << "5.根据姓名、班级查询学生信息" << endl;
			cout << "5.查询成绩平均分" << endl;
			cout << "";
		}
	}

}
/////////////////////////////////////
//查找管理员的信息
Manager* Managerlist::find(Manager& a)
{
	for (Manager* m = head; m; m = m->next)
	{
		if (m->ID == a.ID)
		{
			return m;
		}
	}
}
//验证是否找到
bool Managerlist::yanzhengfind(Manager& a)
{
	for (Manager* m = head; m; m = m->next)
	{
		if (*m == a)
		{
			return true;
		}
	}
	return false;
}
//登录管理员账户
void Managerlist::load(Manager& a, StudentList& studentlist)
{
	int fh = 0;
	if (yanzhengfind(a))
	{
		Manager* z;
		Student stu;
		Teacher tea;
		z = find(a);
		cout << "登录成功" << endl;
		int n = 0, n4 = 0;
		while (n != -1)
		{
			n4 = 0;
			z->display();
			cout << "1.显示个人信息" << endl;
			cout << "2.修改密码" << endl;
			cout << "3.修改名字" << endl;
			cout << "4.管理学生成绩" << endl;
			cout << "5.维护学生信息" << endl;
			cout << "6.维护老师信息" << endl;
			cout << "请选择（输入-1返回上一层结构）：" << endl;
			cin >> n;
			fh = 0;
			switch (n)
			{
			case 1:
				while (fh != -1)
				{
					z->display();
					cout << "请输入任意数字返回" << endl;
					cin >> fh;
					fh = -1;
				}
				break;
			case 2:
			{
				while (fh != -1)
				{
					z->changepass();
					cout << "修改后的密码为：" << z->getpass() << endl;
					write();
					cout << "输入任意数字返回" << endl;
					cin >> fh;
					fh = -1;
				}
				break;
			case 3:
				while (fh != -1)
				{
					z->changeName();
					write();
					cout << "修改后的姓名为：" << z->getname() << endl;
					cout << "输入任意数字返回" << endl;
					cin >> fh;
					fh = -1;
				}
				break;
			}
			if (n == 4)
			{
				while (n4 != -1)
				{
					fh = 0;
					cout << "1.添加学生" << endl;
					cout << "2.删除学生" << endl;
					cout << "3.修改学生信息" << endl;
					cout << "请选择1/2/3，输入-1返回上层结构：";
					cin >> n4;
					switch (n4)
					{
					case1:
						while (fh != -1)
						{
							//				cout << "请输入新加入学生的姓名：";
						}
					}
				}
			}
			}
		}
	}
}
void Managerlist::display()
{
	for (Manager* p = head; p; p = p->next)
	{
		p->display();
	}
}
void Managerlist::write()
{
	ofstream out("manager.txt");
	for (Manager* p = head; p; p = p->next)
	{
		out << p->name << " " << p->ID << " " << p->getpass() << endl;
	}
}
Managerlist::~Managerlist()
{
	for (Manager* p = head; p = head; delete p)
	{
		head = head->next;
	}
}
