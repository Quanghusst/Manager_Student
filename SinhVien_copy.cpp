#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
    string name;
    double gpa;
    int id;

public:
    Student() {}
    // Student(string name, double gpa, int id)
    // {
    //     this->name = name;
    //     this->gpa = gpa;
    //     this->id = id;
    // }
    Student(string name, double gpa, int id) : name(name), id(id), gpa(gpa) {}

    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << "Ho va ten: " << student.name << endl
           << "id: " << student.id << endl
           << "GPA: " << student.gpa << endl;
        return os;
    }
    friend istream &operator>>(istream &is, Student &student)
    {
        cout << "Nhap ho va ten: ";
        std::cin.ignore();
        getline(is, student.name);
        cout << "nhap id: ";
        is >> student.id;
        cout << "GPA: ";
        is >> student.gpa;
        return is;
    }

    // getter
    int getid()
    {
        return id;
    }
    int getGPA()
    {
        return gpa;
    }
};
vector<Student> students;
int Menu()
{
    int choice = 0;
    cout << "Student management program" << endl;
    cout << "1. Add information of student " << endl;
    cout << "2. Delete one student" << endl;
    cout << "3. Show data of students" << endl;
    cout << "4. Sort by GPA " << endl;
    cout << "5. Sort by ID" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;
    system("cls");
    return choice;
}
void showDataOfStudents(vector<Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        cout << "Student " << i + 1 << endl
             << students[i] << endl;
    }
    system("pause");
}
void deleteOneStudent(vector<Student> &students)
{
    int n;
    cout << "Enter the student number you want to delete: ";
    cin >> n;
    students.erase(students.begin() + --n);
}
void sortBy(vector<Student> &students, string mode)
{
    int n = students.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mode == "gpa" ? students[i].getGPA() < students[j].getGPA()
                              : students[i].getid() < students[j].getid())
            {
                Student tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
    cout << "Sort by " << mode << " is running . . . " << endl;
    system("pause");
}

int main()
{
    Student student;
    int choice;
    do
    {
        choice = Menu();
        switch (choice)
        {
        case 1:
            cin >> student;
            students.push_back(student);
            break;
        case 2:
            deleteOneStudent(students);
            break;
        case 3:
            showDataOfStudents(students);
            break;
        case 4:
            sortBy(students, "gpa");
            break;
        case 5:
            sortBy(students, "id");
            break;
        }
        system("cls");

    } while (choice);

    return 0;
}