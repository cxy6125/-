#include "List.h"
int main()
{
	Student student;
	StudentList studentlist;
	studentlist.loadFromFile("student.txt");
	string ID, password;
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
				cout << "2.按照姓名查找" << endl;
				cout << "3.查询成绩排序" << endl;
				cout << "请选择（1/2/3，输入-1返回上层结构）：" << endl;
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
						cout << "请输入想按哪一门课程进行降序排序，0代表语文，1代表数学，2代表英语，3代表物理" << endl;
						int n;
						cin >> n;
						studentlist.SortStudent(n);
						studentlist.display();
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
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
					}
				}
			}
		default:
			cout << "输入错误" << endl;
			i1 = -1;
			break;
		}
	}
}




//	StudentList studentlist;
//	studentlist.loadFromFile("student.txt");//从文件中加载学生信息
//	int choice;
//	do {
//		cout << "Student Grade Management System" << endl;
//		cout << "1.Add Student" << endl;
//		cout << "2.Modify Student Information" << endl;
//		cout << "3.Delete Student" << endl;
//		cout << "4.Search Student by ID" << endl;
//		cout << "5.Search Student by Name or Class" << endl;
//		cout << "6.Display All Students" << endl;
//		cout << "7.Save to File" << endl;
//		cout << "8.Exit" << endl;
//		cout << "Enter your choice:";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//		{
//			string name, classname;
//			char gender;
//			string ID;
//			double scores[4];
//			cout << "Enter student name:";
//			cin >> name;
//			cout << "Enter student gender(M/F):";
//			cin >> gender;
//			cout << "Enter studentID:";
//			cin >> ID;
//			cout << "Enter classname:";
//			cin >> classname;
//			cout << "Enter scores for 4 subjects:";
//			for (int i = 0; i < 4; i++)
//			{
//				cin >> scores[i];
//			}
//			Student* student = new Student(name, ID, gender, classname, scores);
//			studentlist.addStudent(student);
//			break;
//		}
//		case 2:
//		{
//			{
//				string id;
//				cout << "Enter student ID to modify:";
//				cin >> id;
//				Student* student = studentlist.findStudentID(id);
//				if (student != nullptr)
//				{
//					
//				}
//			}
//		}
//		}
//	} 
//	while (choice != 8);
//	return 0;
//}