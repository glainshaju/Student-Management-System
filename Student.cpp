#include<iostream>
#include<string>
using namespace std;
class Student{

    private:
    int rollNo;
    string name;
    float marks;
    public:    
    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        setMarks(m);
    }
    int getRollNo()
    {
        return rollNo;
    }

    string getName()
    {
        return name;
    }

    float getMarks()
    {
        return marks;
    }
    void setMarks(float m)
    {
        while(m < 0 || m > 100)
        {
            cout << "Invalid marks! Enter marks between 0 and 100: ";
            cin >> m;
        }

        marks = m;
    }

    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

void printResult(Student s)
{
    cout << "\n----------------------" << endl;
    cout << "Roll Number: " << s.getRollNo() << endl;
    cout << "Name: " << s.getName() << endl;
    cout << "Marks: " << s.getMarks() << endl;

    if(s.getMarks() >= 40)
        cout << "Result: PASS" << endl;
    else
        cout << "Result: FAIL" << endl;

    cout << "----------------------" << endl;
}

int main()
{
    Student batch[3] =
    {
        Student(101, "Arun", 85),
        Student(102, "Rahul", 35),
        Student(103, "Anu", 75)
    };
    int choice;
    cout << "\nDo you want to re-evaluate marks?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice 1 or 2 : ";
    cin >> choice;

    if(choice == 1)
    {
        int roll;
        float newMarks;
        bool found = false;

        cout << "Enter Roll Number: ";
        cin >> roll;

        for(int i = 0; i < 3; i++)
        {
            if(batch[i].getRollNo() == roll)
            {
                cout << "Student Found!" << endl;
                cout << "Enter New Marks: ";
                cin >> newMarks;

                batch[i].setMarks(newMarks);

                cout << "Marks Updated Successfully!" << endl;

                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "Student not found!" << endl;
        }
    }
    else if(choice != 2)
    {
        cout << "Invalid choice!" << endl;
    }
    cout << "\n========== STUDENT RESULTS ==========" << endl;

    for(int i = 0; i < 3; i++)
    {
        printResult(batch[i]);
    }

    return 0;
}