#include "List.h"
// 查找学生
void StudentList::find(int i) {
    string name = "null", ID = "null", classname = "null";
    Student* current = head;
    bool flag = false;
    switch (i) {
        case 1:
            cout << "请输入学号:";
            cin >> ID;
            while (current != nullptr) {
                if (current->ID == ID) {
                    cout << "找到该学生,";
                    current->display();
                    flag = true;
                }
                current = current->next;
            }
            if (flag == false) {
                cout << "未找到该学生" << endl;
            }
            break;
        case 2:
            cout << "请输入姓名：";
            cin >> name;
            cout << "请输入班级：";
            cin >> classname;
            while (current != nullptr) {
                if (current->name == name && current->classname == classname) {
                    cout << "找到该学生,";
                    current->display();
                    flag = true;
                }
                current = current->next;
            }
            if (flag == false) {
                cout << "未找到该学生！" << endl;
            }
            break;
        default:
            cout << "输入错误！" << endl;
            break;
    }
}
// 添加学生
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
// 删除学生
void StudentList::deleteStudentID(string id) {
    if (head == nullptr)  // 如果头节点为空
    {
        return;
    }
    if (head->ID == id)  // 如果要删除节点为头节点
    {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "删除成功！" << endl;
        tihuanFile("student.txt");  // 文件中数据同步
        return;
    }
    Student* current = head;  // 要删除节点不是头节点
    while (current->next != nullptr && current->next->ID != id) {
        current = current->next;
    }
    if (current->next == nullptr)  // 如果没有符合的删除节点
    {
        cout << "删除失败，未找到该学生！" << endl;
        return;
    }
    // 找到了删除的节点
    Student* temp = current->next;
    current->next = current->next->next;
    delete temp;
    cout << "删除成功！" << endl;
    tihuanFile("student.txt");  // 文件中数据同步
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
/// 写入文本
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
// 文件中加载学生信息
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
// 显示学生信息
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
    // 交换两个节点的全部数据
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
// 查找教师信息
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
                cout << "密码正确" << endl;
                return true;
            } else {
                cout << "密码错误" << endl;
                return false;
            }
        }
    }
    return false;
}
// 登录教师账户
void Teacherlist::load(string id, string password) {
    StudentList studentlist;
    studentlist.loadFromFile("student.txt");
    if (yanzheng(id, password)) {
        Teacher* teacher;
        cout << "登录成功" << endl;
        for (teacher = head; teacher; teacher = teacher->next) {
            if (teacher->ID == id)
                break;
        }
        int n = 0, fh = 0;
        while (n != -1) {
            n = 0;
            fh = 0;
            cout << "---------------------是分割线哦------------------" << endl;
            cout << "1.显示个人信息" << endl;
            cout << "2.修改密码" << endl;
            cout << "3.修改姓名" << endl;
            cout << "4.查询学生信息" << endl;
            cout << "5.按成绩排序" << endl;
            cout << "6.按学号排序" << endl;
            cout << "请选择（1/2/3/4/5/6,输入-1返回上层结构）：";
            cin >> n;
            switch (n) {
                case 1:
                    while (fh != -1) {
                        teacher->display();
                        cout << "按任意键返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 2:
                    while (fh != -1) {
                        teacher->changePass();
                        cout << "修改后的密码为：" << teacher->getpass()
                             << endl;
                        write();
                        cout << "按任意键返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 3:
                    while (fh != -1) {
                        teacher->changeName();
                        cout << "修改后的姓名为：" << teacher->getname()
                             << endl;
                        write();
                        cout << "按任意键返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 4:
                    while (fh != -1) {
                        cout << "1.按照学号查找" << endl;
                        cout << "2.按照姓名、班级查找" << endl;
                        cout << "请选择：";
                        int i1;
                        cin >> i1;
                        studentlist.find(i1);
                        cout << "按任意键返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 5:
                    while (fh != -1) {
                        cout << "请输入想按哪一门课程进行降序排序，0代表语文，1"
                                "代表数学，2代表英语，3代表物理,4代表平均分"
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
                            cout << "输入错误！" << endl;
                        }
                        cout << "输入任意数字返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 6:
                    while (fh != -1) {
                        studentlist.SortID();
                        studentlist.display();
                        cout << "输入任意数字返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case -1:
                    fh = -1;
                    break;
                default:
                    cout << "输入错误！" << endl;
                    cout << "输入任意数字返回" << endl;
                    cin >> fh;
                    fh = -1;
                    break;
            }
            fh = 0;
        }
    } else {
        cout << "用户名或密码错误，登录失败！" << endl;
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
// 从文件中加载老师信息
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
// 查找管理员的信息
Manager* Managerlist::find(Manager& a) {
    for (Manager* m = head; m; m = m->next) {
        if (m->ID == a.ID) {
            return m;
        }
    }
}
// 验证是否找到
bool Managerlist::yanzheng(string id, string password) {
    for (Manager* m = head; m; m = m->next) {
        if (m->ID == id) {
            if (m->pass == password) {
                cout << "密码正确" << endl;
                return true;
            } else {
                cout << "密码错误" << endl;
                return false;
            }
        }
    }
    return false;
}

// 登录管理员账户
void Managerlist::load(string id, string password) {
    StudentList studentlist;
    studentlist.loadFromFile("student.txt");
    if (yanzheng(id, password)) {
        Manager* manager;
        cout << "登录成功" << endl;
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
            cout << "1.显示个人信息" << endl;
            cout << "2.修改密码" << endl;
            cout << "3.修改名字" << endl;
            cout << "4.管理学生成绩" << endl;
            cout << "5.维护学生信息" << endl;
            cout << "6.维护老师信息" << endl;
            cout << "请选择（1/2/3/4/5/6,输入-1返回上一层结构）：" << endl;
            cin >> n;
            fh = 0;
            switch (n) {
                case 1:
                    while (fh != -1) {
                        manager->display();
                        cout << "请输入任意数字返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                case 2: {
                    while (fh != -1) {
                        manager->changepass();
                        cout << "修改后的密码为：" << manager->getpass()
                             << endl;
                        write();
                        cout << "输入任意数字返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                }
                case 3: {
                    while (fh != -1) {
                        manager->changeName();
                        write();
                        cout << "修改后的姓名为：" << manager->getname()
                             << endl;
                        cout << "输入任意数字返回" << endl;
                        cin >> fh;
                        fh = -1;
                    }
                    break;
                }
            }
            if (n == 4) {
                while (n4 != -1) {
                    fh = 0;
                    cout << "1.添加学生" << endl;
                    cout << "2.删除学生" << endl;
                    cout << "3.修改学生信息" << endl;
                    cout << "请选择1/2/3，输入-1返回上层结构：";
                    cin >> n4;
                    switch (n4) {
                        case 1: {
                            while (fh != -1) {
                                cout << "请输入新加入学生的姓名：";
                                cin >> name;
                                cout << "请输入新加入学生学号：";
                                cin >> ID;
                                cout << "请输入新加入学生性别：";
                                cin >> gender;
                                cout << "请输入新加入学生班级：";
                                cin >> classname;
                                cout << "请输入四门课程成绩:";
                                for (int k = 0; k < 4; k++) {
                                    cin >> s[k];
                                }
                                Student* student =
                                    new Student(name, ID, gender, classname, s);
                                studentlist.addStudent(student);
                                studentlist.saveToFile("student");
                                cout << "输入任意数字返回" << endl;
                                cin >> fh;
                                fh = -1;
                            }
                            break;
                        }
                        case 2: {
                            while (fh != -1) {
                                cout << "请输入要删除学生学号：";
                                cin >> ID;
                                studentlist.deleteStudentID(ID);
                                cout << "输入任意数字返回" << endl;
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
// 从文件中加载管理员信息
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
