#include <iostream>
using namespace std;

// Abstration
// if any classes sign to the contract of abstraction class, it has to provide
// the implementation for the method that is in the contract. Abstract class
class AbstractEmployee {
  // A pure virtual function is declared by assigning 0 in declaration
  virtual void AskForPromotion() = 0;
};

// class Employee sign to contract of abstraction class AbstractEmployee
class Employee : AbstractEmployee {
private:
  string Company;
  int Age;

  // use this when you want to access to private variables from the outer child
  // class
protected:
  string Name;

public:
  // Constructors
  Employee(string name, string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }
  void AskForPromotion() {
    if (Age > 30)
      cout << Name << " got promoted" << endl;
    else
      cout << Name << " no promoted" << endl;
  }
  void print() { cout << Name << " " << Company << " " << Age << endl; }
  // Encapsulation
  void setName(string name) // setter
  {
    Name = name;
  }
  string getName() // getter
  {
    return Name;
  }
  void setAge(int age) {
    if (age > 18)
      Age = age;
  }
  int getAge() { return Age; }
  // Khi goi toi ham ao, thi se check coi class con co implementation cua ham
  // nay hay khong, neu co thi goi toi ham con do.
  virtual void Work() { cout << Name << " is checking email..." << endl; }
};
// Inheritance
// Add public to inherit public methods from parent class
class Developer : public Employee {
public:
  string FavProgrammingLanguage;
  Developer(string name, string company, int age, string favProgrammingLanguage)
      : Employee(name, company, age) {
    FavProgrammingLanguage = favProgrammingLanguage;
  }
  void FixBug() {
    // cout << getName() << " fixed bug using " << FavProgrammingLanguage <<
    // endl;
    cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
  }
  // Polymorphism
  void Work() {
    cout << Name << " is writing " << FavProgrammingLanguage << endl;
  }
};

class Teacher : public Employee {
public:
  string Subject;
  void PrepareLessons() {
    cout << Name << " is preparing " << Subject << " lesson" << endl;
  }
  Teacher(string name, string company, int age, string subject)
      : Employee(name, company, age) {
    Subject = subject;
  }
  // Polymorphism
  void Work() { cout << Name << " is teaching " << Subject << endl; }
};

int main() {
  Employee e1{"John", "Apple", 25};
  // Employee e1 = Employee("John", "Apple", 25);
  // Employee e2{"Kevin", "Google", 39};
  // e.print();
  // e.setName("LVM");
  // cout << e.getName() << endl;
  // e.setAge(20);
  // cout << e.getAge() << endl;
  e1.Work();
  // e2.AskForPromotion();
  Developer d{"LVM", "Facebook", 19, "Javascript"};
  // d.FixBug();
  // d.AskForPromotion();
  // d.print();
  Teacher t{"Jack", "HCMUS", 47, "Computer Science"};
  // t.PrepareLessons();
  t.AskForPromotion();
  // d.Work();
  // t.Work();

  // The most common use of Polymorphism is when a parent class reference is
  // used to refer to a child class object Employee *e1 = &d;
  Employee *e2 = &t;

  // e1->Work();
  e2->Work();
  return 0;
}
