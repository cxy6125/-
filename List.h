#include "People.h"
class StudentList
{
private:
	int size;
	Student* head;
public:
	StudentList() :head(nullptr),size(0){}//���캯����ʼ��
	void addStudent(Student* student);//���ѧ����Ϣ
	void deleteStudentID(string id);//����ѧ��ɾ��ѧ����Ϣ
	void find(int i);//����
	Student* findStudentID(string id);//ͨ��id����ѧ��������ָ��
	void saveToFile(string filename);//��ѧ����Ϣд���ļ���
	void tihuanFile(string filename);//�����ı���Ϣ
    void loadFromFile(string filename);	//���ļ��м���ѧ����Ϣ
	void display();//��ʾѧ����Ϣ
	void SortStudent(int n);//����ѧ���ɼ����н�������0�������ģ�1������ѧ��2����Ӣ�3��������
	void SortID();//����ѧ�Ž�����������
	void SortAverage();//���ճɼ����н�������
	void swapData(Student* a, Student* b);//���������ڵ�����
	//��������
	~StudentList();
};
class Managerlist
{
private:
	int size;
	Manager* head;
public:
	Managerlist() :head(nullptr),size(0) {}
	//void remove(string rmv);//�Ƴ�
	//void add(Manager& manager);//�����Ϣ��������
	void load(string id,string password);//��¼
	void display();
	Manager* find(Manager& a);//����
	bool yanzheng(string id, string password);//��֤�Ƿ��û���������һ��
	void write();//д���ı�
	void addManager(Manager* manager);
	void loadFromFile(string filename);//�����ļ�
	~Managerlist();
};
class Teacherlist
{
private:
	int size;
	Teacher* head;
public:
	Teacherlist():head(nullptr),size(0){}
	Teacher* findteacher(string id);
	bool yanzheng(string id, string password);//��֤�Ƿ��û���������һ��
	void write();//д���ı�
	void loadFromFile(string filename);//���ļ��м�����ʦ��Ϣ
	void addTeacher(Teacher* teacher);//�����ʦ
	void deleteTeacherID(string id);//ɾ����ʦ��Ϣ
	void load(string id,string password);//��¼
	/*void Teacherdisplay();
	~Teacherlist();*/
};