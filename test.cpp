#include "List.h"
int main()
{
	Student student;
	Teacher teacher;
	Manager manager;
	StudentList studentlist;
	Teacherlist teacherlist;
	Managerlist managerlist;
	studentlist.loadFromFile("student.txt");
	teacherlist.loadFromFile("teacher.txt");
	managerlist.loadFromFile("manager.txt");
	string ID, password, name;
	int fh = 0;
	int i1 = 0, i2,i;
	while (i1 != -1)
	{
		i1 = 0, i2 = 0;
		i = 0;
		cout << "    ------------------------------------------------------\n";
		cout << "    |           欢迎进入学生成绩管理系统                 |" << endl;
		cout << "    |           1.查询学生信息                           |" << endl;
		cout << "    |           2.登录                                   |" << endl;
		cout << "    ------------------------------------------------------\n";
		cout << "               请选择（1/2,-1为结束）：";
		cin >> i1;
		switch (i1)
		{
		case 1:
			while (i != -1)
			{
				cout << "---------------------是分割线哦------------------" << endl;
				cout << "1.按照学号查找" << endl;
				cout << "2.按照姓名、班级查找" << endl;
				cout << "3.按成绩排序" << endl;
				cout << "4.按学号排序" << endl;
				cout << "请选择（1/2/3/4，输入-1返回上层结构）：" << endl;
				cin >> i;
				switch (i)
				{
				case 1:
					while (fh != -1)
					{
						studentlist.find(i);
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					break;
				case 2:
					while (fh != -1)
					{

						studentlist.find(i);
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					break;
				case 3:
					while (fh != -1)
					{
						cout << "请输入想按哪一门课程进行降序排序，0代表语文，1代表数学，2代表英语，3代表物理,4代表平均分" << endl;
						int n;
						cin >> n;
						if (n >= 0 && n <= 3)
						{
							studentlist.SortStudent(n);
							studentlist.display();
						}
						else if(n==4)
						{
							studentlist.SortAverage();
							studentlist.display();
						}
						else
						{
							cout << "输入错诶！" << endl;
						}
						cout << "输入任意数字返回" << endl;
					    cin >> fh;
						fh = -1;
					}
					break;
				case 4:
					while (fh != -1)
					{
						studentlist.SortID();
						studentlist.display();
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					break;
				}
			    fh = 0;
			}
			break;
		case 2:
			while (i2 != -1)
			{
				cout << "---------------------是分割线哦------------------" << endl;
				cout << "用户选择" << endl;
				cout << "1.教师登录" << endl;
				cout << "2.管理人员登录" << endl;
				cout << "请选择（1/2，输入-1返回上层结构）" << endl;
				cin >> i2;
				if (i2 != -1)
				{
					if (i2 >= 3 || i2 <= 0)
						cout << "输入错误" << endl;
					else
					{
						cout << "账号：" << endl;
						cin >> ID;
						cout << "密码：" << endl;
						cin >> password;
						switch (i2)
						{
						case 1:
							teacherlist.load(ID, password);
							break;
						case 2:
							managerlist.load(ID, password);
							break;
						}
					}
				}
			}
			break;
		case -1:
			i1 = -1;
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
	}
	cout << "谢谢使用！" << endl;
}