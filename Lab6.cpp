#include <iostream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

/*
namespace Space {
    /*
    Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з
    елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами.
    Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням.Вивести
    розміри об’єктів даних класів.
    */
/*    class Base1
    {
    protected:
        int dat1;
        double a[5] = { 1,2,3,4,5 };
    public:
        Base1() : dat1(1) {}
        Base1(int d) : dat1(d) {}
    };

    class Base2
    {
    protected:
        int dat2;
        double a[5] = { 10,1,7,1,9 };
    public:
        Base2() : dat2(1) {}
        Base2(int d) : dat2(d) {}
    };


    class D1 : protected Base1
    {
    protected:
        int d1;
    public:
        D1() : d1(1) {}
        D1(int d) : d1(d) {}
        D1(int d, int dt) : Base1(dt), d1(d) {}
    };

    class D2 : protected Base2
    {
    protected:
        double dt;
    public:
        D2() : dt(1) {}
        D2(int d) : dt(d) {}
        D2(int a, int e) : Base2(a), dt(e) {}
    };

    class D1B2 : protected Base2, protected D1
    {
    protected:
        double dt;
    public:
        D1B2() : dt(1) {}
        D1B2(int d) : dt(d) {}
        D1B2(int a, int b, int c, int e) : Base2::Base2(a), D1(b, c), dt(e) {}
    };

    class D1B1 : protected Base1, protected D1
    {
    protected:
        double dt;
    public:
        D1B1() : dt(1) {}
        D1B1(int d) : dt(d) {}
        D1B1(int a, int b, int c, int e) : Base1::Base1(a), D1(b, c), dt(e) {}
    };

    class D12B1 : protected D1B1, protected D2
    {
    protected:
        double dt;
    public:
        D12B1() : dt(1) {}
        D12B1(int d) : dt(d) {}
        D12B1(int a, int b, int c, double d, int e) : D2(a,b), D1B1(b, c, d, e), dt(e) {}
    };


    class R : protected D1B2, protected D12B1
    {
    protected:
        double dt;
    public:
        R() : dt(1) {}
        R(int d) : dt(d) {}
        R(int a, int b, int c, double d, int e) : D1B2(a), D12B1(a, b, c, d, e), dt(e) {}

        void showDat()
        {
            std::cout << " dat = " << dt << std::endl;
            std::cout << "D1B2V::D1V::Base1::dat = " << D1B2::D1::Base1::dat1 << std::endl;
            std::cout << "D12B1V::D2V::Base2::dat = " << D12B1::D2::Base2::dat2 << std::endl;
            std::cout << "Base1::dat = " << Base1::dat1 << std::endl;
            std::cout << "Base2::dat = " << Base2::dat2 << std::endl;
        }
    };

    //
    //  virtual
    //

    class D1V : virtual protected Base1
    {
    protected:
        int d1;
    public:
        D1V() : d1(1) {}
        D1V(int d) : d1(d) {}
        D1V(int d, int dt) : Base1(dt), d1(d) {}
    };

    class D2V : virtual protected Base2
    {
    protected:
        double dt;
    public:
        D2V() : dt(1) {}
        D2V(int d) : dt(d) {}
        D2V(int a, int b, int c, double d, int e) : Base2(a), dt(e) {}
    };


    class D1B2V : protected Base2, protected D1V
    {
    protected:
        double dt;
    public:
        D1B2V() : dt(1) {}
        D1B2V(int d) : dt(d) {}
        D1B2V(int a, int b, int c, int e) : Base2(a), D1V(b, c), dt(e) {}
    };

    class D1B1V : protected Base1, protected D1V
    {
    protected:
        double dt;
    public:
        D1B1V() : dt(1) {}
        D1B1V(int d) : dt(d) {}
        D1B1V(int a, int b, int c, int e) : Base1(a), D1V(b, c), dt(e) {}
    };

    class D12B1V : protected D1B1V, protected D2V
    {
    protected:
        double dt;
    public:
        D12B1V() : dt(1) {}
        D12B1V(int d) : dt(d) {}
        D12B1V(int a, int b, int c, double d, int e) : D2V(a), D1B1V(b, c, d, e), dt(e) {}
    };


    class RV : protected D1B2V, protected D12B1V
    {
    protected:
        double dt;
    public:
        RV() : dt(1) {}
        RV(int d) : dt(d) {}
        RV(int a, int b, int c, double d, int e) : D1B2V(a), D12B1V(a, b, c, d, e), dt(e) {}

        void showDat()
        {
            std::cout << " dat = " << dt << std::endl;
            std::cout << "D1B2V::D1V::Base1::dat = " << D1B2V::D1V::Base1::dat1 << std::endl;
            std::cout << "D12B1V::D2V::Base2::dat = " << D12B1V::D2V::Base2::dat2 << std::endl;
            std::cout << "Base1::dat = " << Base1::dat1 << std::endl;
            std::cout << "Base2::dat = " << Base2::dat2 << std::endl;
        }
    };



    int main1()
    {
        std::cout << " Example  \n";
        R a, b(1, 2, 3, 4.5, 5);
        RV av, bv(1, 2, 3, 4.5, 5);

        std::cout << "Test !\n";
        std::cout << "Size for Base1 " << sizeof(Base1) << std::endl;
        std::cout << "Size for Base2 " << sizeof(Base2) << std::endl;

        std::cout << "Size for D1 " << sizeof(D1) << std::endl;
        std::cout << "Size for D2 " << sizeof(D2) << std::endl;

        std::cout << "Size for D1B2 " << sizeof(D1B2) << std::endl;
        std::cout << "Size for D1B1 " << sizeof(D1B1) << std::endl;
        std::cout << "Size for D12B2 " << sizeof(D12B2) << std::endl;

        std::cout << "Size for R " << sizeof(R) << std::endl;


        std::cout << "Size for Base1 " << sizeof(Base1) << std::endl;
        std::cout << "Size for Base2 " << sizeof(Base2) << std::endl;

        std::cout << "Size for D1V " << sizeof(D1V) << std::endl;
        std::cout << "Size for D2V " << sizeof(D2V) << std::endl;

        std::cout << "Size for D1B2V " << sizeof(D1B2V) << std::endl;
        std::cout << "Size for D1B1V " << sizeof(D1B1V) << std::endl;
        std::cout << "Size for D12B2V " << sizeof(D12B2V) << std::endl;

        std::cout << "Size for RV " << sizeof(RV) << std::endl;

        std::cout << "Size for object class R " << sizeof(R) << " or  "
            << sizeof(a) << " or  " << sizeof(b) << std::endl;
        std::cout << "Size for object class RV " << sizeof(RV) << " or  "
            << sizeof(av) << " or  " << sizeof(bv) << std::endl;
        b.showDat();
        bv.showDat();

        return 0;
    }
}
*/


/*
Створити абстрактний базовий клас фігура із віртуальною функцією
площа. Створити похідні класи: прямокутник, коло, прямокутний трикутник,
трапеція зі своїми функціями площі.
*/

class Figure {
protected:
    string name;
    int a;
    int b = 0;
public:
    Figure() : a(0), b(0), name("noname") { }
    Figure(string n, int a, int b) : a(a), b(b), name(n) { }
    virtual string N() = 0;
    virtual int S() = 0;
};
class Rect : public Figure {
public:
    Rect(string n, int a, int b) : Figure(n, a, b) {}
    virtual string N() override
    {
        string rt = string("Rectangle ") + name;
        return rt;
    }
    virtual int S() override { 
        int s = a * b;
        return s; }
};
class Circle : public Figure {
public:
    Circle(string n, int a, int b) : Figure(n, a, b) {}
    virtual string N() override
    {
        string rt = string("Circle ") + name;
        return rt;
    }
    virtual int S() override {
        int s = 2 * 3.14 * a;
        return s;
    }
};
class Triangle : public Figure {
public:
    Triangle(string n, int a, int b) : Figure(n, a, b) {}
    virtual string N() override
    {
        string rt = string("Triangle ") + name;
        return rt;
    }
    virtual int S() override {
        int s = 0.5 * a * b;
        return s;
    }
};
class Trapeze : public Figure {
public:
    Trapeze(string n, int a, int b) : Figure(n, a, b) {}
    virtual string N() override
    {
        string rt = string("Trapeze ") + name;
        return rt;
    }
    virtual int S() override {
        int s = a * b;
        return s;
    }
};
string set() {
    string name;
    int r = 1;
    string n1[4] = { "Rectangle", "Circle", "Triangle", "Trapeze"};
    r = rand() % 3;
    name = n1[r];
    return name;
}
int main2()
{
    cout << "Test \n";
    Figure** mas;
    int n = 0, type = 1;
    int a = 0, b = 0;
    string name;
    do {
        cout << "How many figure:  \n";
        cin >> n;
    } while (n <= 0 || n > 100);
    mas = new Figure * [n];
    cout << " input random figure press 1 <enter> ";
    int rn;
    srand(n);
    cin >> rn;
    for (int i = 0; i < n; i++) {
        if (rn == 1) {
            a = rand() % 20;
            b = rand() % 20;
            name = set();
            if (name == "Circle")type = 2;
            if (name == "Triangle")type = 3;
            if (name == "Trapeze")type = 4;
        }
        else {
            do {
                cout << "Input: \n";
                cout << "1 - if it is a Rectangle \n";
                cout << "2 - if it is a Circle \n";
                cout << "3 - if it is a Triangle \n";
                cout << "4 - if it is a Trapeze \n";
                cin >> type;

            } while (type < 1 || type>4);
            cout << "Input a, b: "; cin >> a >> b;
        }
        switch (type) {
        case 1: mas[i] = new Rect(name, a, b); break;
        case 2: mas[i] = new Circle(name, a,b); break;
        case 3: mas[i] = new Triangle(name, a, b); break;
        case 4: mas[i] = new Trapeze(name, a, b); break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] -> N() << endl;
        cout << mas[i] -> S() << endl;
    }

    return 0;
}


/*
Ієрархія типів складається з сутностей: студент, батько сімейства та
студент-батько сімейства
*/

class Student {
protected:
    string name;
    int age;
    int code;
public:
    Student() : name("Neol"), age(5), code(635) {
    }
    Student(string m, float p, int nw) : name(m), age(p), code(nw) {
    }
    string getName() { return name; }
    void setName(string m) { name = m; }
    float getAge() {
        return age;
    }
    void setAge(int p) {
        age = p;
    }
    int getCode() {
        return code;
    }
    void setCode(int n) {
        code = n;
    }
    string toString() {
        string r = name + "\t" + to_string(age) + "\t" + to_string(code) +
            "\t";
        return r;
    }
};

class Dad {
protected:
    int num;
    int stage;
public:
    Dad() : num(1), stage(5) {}
    Dad(int f, int n) : num(f), stage(n) {}
    int getNum() { return num; }
    void getNum(int f) { num = f; }
    int getStage() { return stage; }
    void getStage(int n) { stage = n; }
    string toString() {
        string r = to_string(num) + "\t" + to_string(stage) + "\t";
        return r;
    }
};
class DS : public Student, public Dad
{
    string place;
public:
    DS() : place("Kyiv") {}
    DS(string m, float p, int nw, int f, int n, string bs)
        : Student(m, p, nw), Dad(f, n), place(bs) {}
    string getPlace() {
        return place;
    }
    void setPlace(string bs) { place = bs; }
    string toString() {
        string r = Student::toString() + Dad::toString() + place;
        return r;
    }
};
int main3()
{
    cout << " Name   Age     Code   Num    Stage     Place \n";
    DS def;
    DS lv("Ivek", 16, 547, 0, 3, "Lviv");
    DS* pV = new DS();
    pV->setName("Ikar");
    pV->setAge(27);
    pV->setCode(648);
    pV->getNum(3);
    pV->getStage(15);
    pV->setPlace("Chernivci");
    cout << def.toString() << endl;
    cout << lv.toString() << endl;
    cout << pV->toString() << endl;

    return 0;
}



int main()
{
    int n;
    cout << "N: ";
e: cin >> n;

    switch (n) {
  //  case 1: main1(); break;
    case 2: main2(); break;
    case 3: main3(); break;
    default: cout << "Error\n"; goto e;
    }

    return 0;
}
