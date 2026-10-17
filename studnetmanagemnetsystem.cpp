#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    int rollNo;
    char name[30];
    float cgpa;

public:

    // Default constructor
    Student()
    {
        rollNo = 0;
        name[0] = '\0';
        cgpa = 0.0;
    }

    // Setters
    void setRollNo(int r)
    {
        rollNo = r;
    }

    void setName(const char n[])
    {
        int i = 0;

        while (n[i] != '\0' && i < 29)
        {
            name[i] = n[i];
            i++;
        }

        name[i] = '\0';
    }

    void setCgpa(float c)
    {
        cgpa = c;
    }

    // Getters
    int getRollNo()
    {
        return rollNo;
    }

    const char* getName()
    {
        return name;
    }

    float getCgpa()
    {
        return cgpa;
    }

    // Input student data
    void input()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    // Display student data
    void display()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "------------------------" << endl;
    }
};


// ADD STUDENT
void addStudent()
{
    Student s;

    s.input();

    ofstream fout("students.dat", ios::binary | ios::app);

    if (!fout)
    {
        cout << "File could not be opened.\n";
        return;
    }

    fout.write((char*)&s, sizeof(s));

    fout.close();

    cout << "Student added successfully.\n";
}


// DISPLAY ALL STUDENTS
void displayStudents()
{
    Student s;

    ifstream fin("students.dat", ios::binary);

    if (!fin)
    {
        cout << "File could not be opened.\n";
        return;
    }

    bool found = false;

    while (fin.read((char*)&s, sizeof(s)))
    {
        s.display();
        found = true;
    }

    if (!found)
    {
        cout << "No students found.\n";
    }

    fin.close();
}


// SEARCH STUDENT
void searchStudent()
{
    int roll;
    bool found = false;

    cout << "Enter Roll No to search: ";
    cin >> roll;

    Student s;

    ifstream fin("students.dat", ios::binary);

    if (!fin)
    {
        cout << "File could not be opened.\n";
        return;
    }

    while (fin.read((char*)&s, sizeof(s)))
    {
        if (s.getRollNo() == roll)
        {
            cout << "\nStudent Found!\n";
            s.display();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }

    fin.close();
}


// UPDATE STUDENT
void updateStudent()
{
    int roll;
    bool found = false;

    cout << "Enter Roll No to update: ";
    cin >> roll;

    fstream file("students.dat",
                 ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "File could not be opened.\n";
        return;
    }

    Student s;

    while (file.read((char*)&s, sizeof(s)))
    {
        if (s.getRollNo() == roll)
        {
            cout << "\nCurrent Record:\n";
            s.display();

            float newCgpa;

            cout << "Enter new CGPA: ";
            cin >> newCgpa;

            s.setCgpa(newCgpa);

            // Move write pointer back to beginning
            // of the record we just read.
            file.seekp(-static_cast<long>(sizeof(s)), ios::cur);

            file.write((char*)&s, sizeof(s));

            cout << "Student updated successfully.\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }

    file.close();
}


// DELETE STUDENT
void deleteStudent()
{
    int roll;
    bool found = false;

    cout << "Enter Roll No to delete: ";
    cin >> roll;

    ifstream fin("students.dat", ios::binary);

    if (!fin)
    {
        cout << "File could not be opened.\n";
        return;
    }

    ofstream temp("temp.dat", ios::binary);

    Student s;

    while (fin.read((char*)&s, sizeof(s)))
    {
        if (s.getRollNo() == roll)
        {
            found = true;

            // Do NOT write this student
            continue;
        }

        temp.write((char*)&s, sizeof(s));
    }

    fin.close();
    temp.close();

    if (found)
    {
        // Remove old file
        remove("students.dat");

        // Rename temporary file
        rename("temp.dat", "students.dat");

        cout << "Student deleted successfully.\n";
    }
    else
    {
        remove("temp.dat");

        cout << "Student not found.\n";
    }
}


// MAIN
int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}