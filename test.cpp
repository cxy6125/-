#include "List.h"
int main() {
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
    int i1 = 0, i2, i;
    while (i1 != -1) {
        i1 = 0, i2 = 0;
        i = 0;
        cout << "    ------------------------------------------------------\n";
        cout << "    |           ��ӭ����ѧ���ɼ�����ϵͳ                 |"
             << endl;
        cout << "    |           1.��ѯѧ����Ϣ                           |"
             << endl;
        cout << "    |           2.��¼                                   |"
             << endl;
        cout << "    ------------------------------------------------------\n";
        cout << "               ��ѡ��1/2,-1Ϊ��������";
        cin >> i1;
        switch (i1) {
            case 1:
                while (i != -1) {
                    cout << "---------------------�Ƿָ���Ŷ------------------"
                         << endl;
                    cout << "1.����ѧ�Ų���" << endl;
                    cout << "2.�����������༶����" << endl;
                    cout << "3.���ɼ�����" << endl;
                    cout << "4.��ѧ������" << endl;
                    cout << "��ѡ��1/2/3/4������-1�����ϲ�ṹ����" << endl;
                    cin >> i;
                    switch (i) {
                        case 1:
                            while (fh != -1) {
                                studentlist.find(i);
                                cout << "�����������ַ���" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                        case 2:
                            while (fh != -1) {
                                studentlist.find(i);
                                cout << "�����������ַ���" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                        case 3:
                            while (fh != -1) {
                                cout << "�������밴��һ�ſγ̽��н�������0��"
                                        "�����ģ�1������ѧ��2����Ӣ�3������"
                                        "��,4����ƽ����"
                                     << endl;
                                int n;
                                cin >> n;
                                if (n >= 0 && n <= 3) {
                                    studentlist.SortStudent(n);
                                    studentlist.display();
                                } else if (n == 4) {
                                    studentlist.SortAverage();
                                    studentlist.display();
                                } else {
                                    cout << "���������" << endl;
                                }
                                cout << "�����������ַ���" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                        case 4:
                            while (fh != -1) {
                                studentlist.SortID();
                                studentlist.display();
                                cout << "�����������ַ���" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                    }
                    fh = 0;
                }
                break;
            case 2:
                while (i2 != -1) {
                    cout << "---------------------�Ƿָ���Ŷ------------------"
                         << endl;
                    cout << "�û�ѡ��" << endl;
                    cout << "1.��ʦ��¼" << endl;
                    cout << "2.������Ա��¼" << endl;
                    cout << "��ѡ��1/2������-1�����ϲ�ṹ��" << endl;
                    cin >> i2;
                    if (i2 != -1) {
                        if (i2 >= 3 || i2 <= 0)
                            cout << "�������" << endl;
                        else {
                            cout << "�˺ţ�" << endl;
                            cin >> ID;
                            cout << "���룺" << endl;
                            cin >> password;
                            switch (i2) {
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
            default:
                cout << "�������" << endl;
                i1 = -1;
                break;
        }
    }
}