#include "People.h"
class StudentList
{
private:
	int size;
	Student* head;
public:
	StudentList() :head(nullptr),size(0){}//构造函数初始化
	void addStudent(Student* student);//添加学生信息
	void deleteStudentID(string id);//根据学号删除学生信息
	void find(int i);//查找
	//Student* findStudent(int i);//查找学生
	void saveToFile(string filename);//将学生信息写到文件中
	void tihuanFile(string filename);//更新文本信息
    void loadFromFile(string filename);	//从文件中加载学生信息
	void display();//显示学生信息
	void SortStudent(int n);//根据学生成绩进行降序排序，0代表语文，1代表数学，2代表英语，3代表物理
	void SortID();//按照学号进行升序排序
	void swapData(Student* a, Student* b);//交换两个节点数据
	//析构函数
	~StudentList();
};
class Managerlist
{
private:
	int size;
	Manager* head;
public:
	Managerlist() :head(nullptr),size(0) {}
	//void remove(string rmv);//移除
	//void add(Manager& manager);//添加信息到链表中
	void load(Manager& manager, StudentList& studentlist);//登录
	void display();
	Manager* find(Manager& a);//查找
	void write();//写入文件
	bool yanzhengfind(Manager& a);
	~Managerlist();
};
class Teacherlist
{
private:
	int size;
	Teacher* head;
	Teacherlist():head(nullptr),size(0){}
	Teacher* find(Teacher& a);
	Teacher* yanzhengfind(Teacher& a);
	void remove(string rmv);//移除
	void add(Teacher& a);//添加信息到链表中
	void load(Teacher& a,StudentList& student);//登录
	void Teacherdisplay();
	~Teacherlist();
};