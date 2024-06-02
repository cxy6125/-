#include "List.h"
// ����ѧ��
void StudentList::find(int i) {
    string name = "null", ID = "null", classname = "null";
    Student* current = head;
    bool flag = false;
    switch (i) {
        case 1:
            cout << "������ѧ��:";
            cin >> ID;
            while (current != nullptr) {
                if (current->ID == ID) {
                    cout << "�ҵ���ѧ��,";
                    current->display();
                    flag = true;
                }
                current = current->next;
            }
            if (flag == false) {
                cout << "δ�ҵ���ѧ��" << endl;
            }
            break;
        case 2:
            cout << "������������";
            cin >> name;
            cout << "������༶��";
            cin >> classname;
            while (current != nullptr) {
                if (current->name == name && current->classname == classname) {
                    cout << "�ҵ���ѧ��,";
                    current->display();
                    flag = true;
                }
                current = current->next;
            }
            if (flag == false) {
                cout << "δ�ҵ���ѧ����" << endl;
            }
            break;
        default:
            cout << "�������" << endl;
            break;
    }
}
// ���ѧ��
void StudentList::addStudent(Student* student) {
    if (head == nullptr)
        head = student;
    else {
        Student* current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
        current->next = student;
    }
}
// ɾ��ѧ��
void StudentList::deleteStudentID(string id) {
    if (head == nullptr)  // ���ͷ�ڵ�Ϊ��
    {
        return;
    }
    if (head->ID == id)  // ���Ҫɾ���ڵ�Ϊͷ�ڵ�
    {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "ɾ���ɹ���" << endl;
        tihuanFile("student.txt");  // �ļ�������ͬ��
        return;
    }
    Student* current = head;  // Ҫɾ���ڵ㲻��ͷ�ڵ�
    while (current->next != nullptr && current->next->ID != id) {
        current = current->next;
    }
    if (current->next == nullptr)  // ���û�з��ϵ�ɾ���ڵ�
    {
        cout << "ɾ��ʧ�ܣ�δ�ҵ���ѧ����" << endl;
        return;
    }
    // �ҵ���ɾ���Ľڵ�
    Student* temp = current->next;
    current->next = current->next->next;
    delete temp;
    cout << "ɾ���ɹ���" << endl;
    tihuanFile("student.txt");  // �ļ�������ͬ��
    return;
}
void StudentList::tihuanFile(string filename) {
    ofstream infile(filename, ios::out);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        Student* current = head;
        while (current != nullptr) {
            infile << current->name << " " << current->gender << " "
                   << current->ID << " " << current->classname << " ";
            for (int i = 0; i < 4; i++) {
                infile << current->score[i] << " ";
            }
            infile << endl;
            current = current->next;
        }
        infile.close();
    }
}
/// д���ı�
void StudentList::saveToFile(string filename) {
    ofstream infile(filename);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        Student* current = head;
        while (current != nullptr) {
            infile << current->name << " " << current->gender << " "
                   << current->ID << " " << current->classname << " ";
            for (int i = 0; i < 4; i++) {
                infile << current->score[i] << " ";
            }
            infile << endl;
            current = current->next;
        }
        infile.close();
    }
}
// �ļ��м���ѧ����Ϣ
void StudentList::loadFromFile(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        string name, classname;
        char gender;
        string ID;
        double score[4];
        while (infile >> name >> gender >> ID >> classname) {
            for (int i = 0; i < 4; i++) {
                infile >> score[i];
            }
            Student* student = new Student(name, ID, gender, classname, score);
            addStudent(student);
        }
        infile.close();
    }
}
// ��ʾѧ����Ϣ
void StudentList::display() {
    Student* current = head;
    while (current != nullptr) {
        cout << "Name:" << current->name << ",Gender:" << current->gender
             << ",StudentID:" << current->ID << ",Class:" << current->classname
             << ",Score:";
        for (int i = 0; i < 4; i++) {
            cout << current->score[i] << " ";
        }
        cout << ",Total Score:" << current->totalScore << ",Average Score:";
        cout << current->averageScore << endl;
        current = current->next;
    }
}
void StudentList::swapData(Student* a, Student* b) {
    // ���������ڵ��ȫ������
    Student temp = *a;
    *a = *b;
    *b = temp;
    Student* tmp = a->next;
    a->next = b->next;
    b->next = tmp;
}
void StudentList::SortStudent(int n) {
    if (head == nullptr) {
        return;
    } else {
        for (Student* current = head; current != nullptr;
             current = current->next) {
            Student* temp;
            Student* p = current;
            for (temp = current->next; temp != nullptr; temp = temp->next) {
                if (p->score[n] < temp->score[n]) {
                    p = temp;
                }
            }
            if (p != current) {
                swapData(p, current);
            }
        }
    }
}
void StudentList::SortID() {
    if (head == nullptr) {
        return;
    } else {
        for (Student* current = head; current != nullptr;
             current = current->next) {
            Student* temp;
            Student* p = current;
            for (temp = current->next; temp != nullptr; temp = temp->next) {
                if (p->ID > temp->ID) {
                    p = temp;
                }
            }
            if (p != current) {
                swapData(p, current);
            }
        }
    }
}
void StudentList::SortAverage() {
    if (head == nullptr) {
        return;
    } else {
        for (Student* current = head; current != nullptr;
             current = current->next) {
            Student* temp;
            Student* p = current;
            for (temp = current->next; temp != nullptr; temp = temp->next) {
                if (p->averageScore < temp->averageScore) {
                    p = temp;
                }
            }
            if (p != current) {
                swapData(p, current);
            }
        }
    }
}
StudentList::~StudentList() {
    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}
////////////////////////////////////////////////////////////////////////////////////
// ���ҽ�ʦ��Ϣ
Teacher* Teacherlist::find(Teacher& a) {
    for (Teacher* m = head; m; m = m->next) {
        if (m->ID == a.ID)
            return m;
    }
    return nullptr;
}
bool Teacherlist::yanzheng(string id, string password) {
    for (Teacher* m = head; m; m = m->next) {
        if (m->ID == id) {
            if (m->pass == password) {
                cout << "������ȷ" << endl;
                return true;
            } else {
                cout << "�������" << endl;
                return false;
            }
        }
    }
    return false;
}
// ��¼��ʦ�˻�
void Teacherlist::load(string id, string password) {
    StudentList studentlist;
    studentlist.loadFromFile("student.txt");
    if (yanzheng(id, password)) {
        Teacher* teacher;
        cout << "��¼�ɹ�" << endl;
        for (teacher = head; teacher; teacher = teacher->next) {
            if (teacher->ID == id)
                break;
        }
        int n = 0, fh = 0;
        while (n != -1) {
            n = 0;
            fh = 0;
            cout << "---------------------�Ƿָ���Ŷ------------------" << endl;
            cout << "1.��ʾ������Ϣ" << endl;
            cout << "2.�޸�����" << endl;
            cout << "3.�޸�����" << endl;
            cout << "4.��ѯѧ����Ϣ" << endl;
            cout << "5.���ɼ�����" << endl;
            cout << "6.��ѧ������" << endl;
            cout << "��ѡ��1/2/3/4/5/6,����-1�����ϲ�ṹ����";
            cin >> n;
            switch (n) {
                case 1:
                    while (fh != -1) {
                        teacher->display();
                        cout << "�����������" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 2:
                    while (fh != -1) {
                        teacher->changePass();
                        cout << "�޸ĺ������Ϊ��" << teacher->getpass()
                             << endl;
                        write();
                        cout << "�����������" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 3:
                    while (fh != -1) {
                        teacher->changeName();
                        cout << "�޸ĺ������Ϊ��" << teacher->getname()
                             << endl;
                        write();
                        cout << "�����������" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 4:
                    while (fh != -1) {
                        cout << "1.����ѧ�Ų���" << endl;
                        cout << "2.�����������༶����" << endl;
                        cout << "��ѡ��";
                        int i1;
                        cin >> i1;
                        studentlist.find(i1);
                        cout << "�����������" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 5:
                    while (fh != -1) {
                        cout << "�������밴��һ�ſγ̽��н�������0�������ģ�1"
                                "������ѧ��2����Ӣ�3��������,4����ƽ����"
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
                            cout << "�������" << endl;
                        }
                        cout << "�����������ַ���" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 6:
                    while (fh != -1) {
                        studentlist.SortID();
                        studentlist.display();
                        cout << "�����������ַ���" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case -1:
                    fh = -1;
                    break;
                default:
                    cout << "�������" << endl;
                    cout << "�����������ַ���" << endl;
                    cin >> fh;
                    fh = -1;
                    break;
            }
            fh = 0;
        }
    } else {
        cout << "�û�����������󣬵�¼ʧ�ܣ�" << endl;
    }
}
void Teacherlist::write() {
    ofstream infile("teacher.txt", ios::out);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        Teacher* current = head;
        while (current != nullptr) {
            infile << current->name << " " << current->ID << " "
                   << current->pass << endl;
            current = current->next;
        }
        infile.close();
    }
}
void Teacherlist::addTeacher(Teacher* teacher) {
    if (head == nullptr)
        head = teacher;
    else {
        Teacher* current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
        current->next = teacher;
    }
}
// ���ļ��м�����ʦ��Ϣ
void Teacherlist::loadFromFile(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        string name, ID, pass;
        while (infile >> name >> ID >> pass) {
            Teacher* teacher = new Teacher(name, ID, pass);
            addTeacher(teacher);
        }
        infile.close();
    }
}

/////////////////////////////////////
// ���ҹ���Ա����Ϣ
Manager* Managerlist::find(Manager& a) {
    for (Manager* m = head; m; m = m->next) {
        if (m->ID == a.ID) {
            return m;
        }
    }
}
// ��֤�Ƿ��ҵ�
bool Managerlist::yanzheng(string id, string password) {
    for (Manager* m = head; m; m = m->next) {
        if (m->ID == id) {
            if (m->pass == password) {
                cout << "������ȷ" << endl;
                return true;
            } else {
                cout << "�������" << endl;
                return false;
            }
        }
    }
    return false;
}

// ��¼����Ա�˻�
void Managerlist::load(string id, string password) {
    StudentList studentlist;
    studentlist.loadFromFile("student.txt");
    if (yanzheng(id, password)) {
        Manager* manager;
        cout << "��¼�ɹ�" << endl;
        for (manager = head; manager; manager = manager->next) {
            if (manager->ID == id)
                break;
        }
        int n = 0, n4 = 0, fh = 0;
        string name, ID, classname;
        char gender;
        double s[4];
        while (n != -1) {
            n4 = 0;
            cout << "1.��ʾ������Ϣ" << endl;
            cout << "2.�޸�����" << endl;
            cout << "3.�޸�����" << endl;
            cout << "4.����ѧ���ɼ�" << endl;
            cout << "5.ά��ѧ����Ϣ" << endl;
            cout << "6.ά����ʦ��Ϣ" << endl;
            cout << "��ѡ��1/2/3/4/5/6,����-1������һ��ṹ����" << endl;
            cin >> n;
            fh = 0;
            switch (n) {
                case 1:
                    while (fh != -1) {
                        manager->display();
                        cout << "�������������ַ���" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 2: {
                    while (fh != -1) {
                        manager->changepass();
                        cout << "�޸ĺ������Ϊ��" << manager->getpass()
                             << endl;
                        write();
                        cout << "�����������ַ���" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                }
                case 3: {
                    while (fh != -1) {
                        manager->changeName();
                        write();
                        cout << "�޸ĺ������Ϊ��" << manager->getname()
                             << endl;
                        cout << "�����������ַ���" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                }
            }
            if (n == 4) {
                while (n4 != -1) {
                    fh = 0;
                    cout << "1.���ѧ��" << endl;
                    cout << "2.ɾ��ѧ��" << endl;
                    cout << "3.�޸�ѧ����Ϣ" << endl;
                    cout << "��ѡ��1/2/3������-1�����ϲ�ṹ��";
                    cin >> n4;
                    switch (n4) {
                        case 1: {
                            while (fh != -1) {
                                cout << "�������¼���ѧ����������";
                                cin >> name;
                                cout << "�������¼���ѧ��ѧ�ţ�";
                                cin >> ID;
                                cout << "�������¼���ѧ���Ա�";
                                cin >> gender;
                                cout << "�������¼���ѧ���༶��";
                                cin >> classname;
                                cout << "���������ſγ̳ɼ�:";
                                for (int k = 0; k < 4; k++) {
                                    cin >> s[k];
                                }
                                Student* student =
                                    new Student(name, ID, gender, classname, s);
                                studentlist.addStudent(student);
                                studentlist.saveToFile("student");
                                cout << "�����������ַ���" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                        }
                        case 2: {
                            while (fh != -1) {
                                cout << "������Ҫɾ��ѧ��ѧ�ţ�";
                                cin >> ID;
                                studentlist.deleteStudentID(ID);
                                cout << "�����������ַ���" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Managerlist::display() {
    for (Manager* p = head; p; p = p->next) {
        p->display();
    }
}
void Managerlist::write() {
    ofstream infile("teacher.txt", ios::out);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        Manager* current = head;
        while (current != nullptr) {
            infile << current->name << " " << current->ID << " "
                   << current->pass << endl;
            current = current->next;
        }
        infile.close();
    }
}
void Managerlist::addManager(Manager* manager) {
    if (head == nullptr)
        head = manager;
    else {
        Manager* current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
        current->next = manager;
    }
}
// ���ļ��м��ع���Ա��Ϣ
void Managerlist::loadFromFile(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "open error!" << endl;
        abort();
    } else {
        string name, ID, pass;
        while (infile >> name >> ID >> pass) {
            Manager* manager = new Manager(name, ID, pass);
            addManager(manager);
        }
        infile.close();
    }
}
Managerlist::~Managerlist() {
    for (Manager* p = head; p = head; delete p) {
        head = head->next;
    }
}
