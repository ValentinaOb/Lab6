#include <iostream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

    /*
    Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з
    елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами.
    Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням.Вивести
    розміри об’єктів даних класів.
    */

    class Base
{
protected:
    int dat;
    double a[5] = { 1,2,3,4,5 };
public:
    Base() : dat(1) {}
    Base(int d) : dat(d) {}
};

    class D1 : protected Base
{
protected:
    int d1;
public:
    D1() : d1(1) {}
    D1(int d) : d1(d) {}
    D1(int d, int dt) : Base(dt), d1(d) {}
};
    class D2 : protected Base
{
protected:
    double d2;
public:
    D2() : d2(1) {}
    D2(int d) : d2(d) {}
    D2(int a, double dt) : Base(a), d2(dt) {}
};
    class D3 : protected D1, protected D2
{
protected:
    double dt;
public:
    D3() : dt(1) {}
    D3(int d) : dt(d) {}
    D3(int a, int b, int c, double d, int e) : D1(a, b), D2(a, c), dt(e) {}
};
    class D4 : protected D2
{
protected:
    double dt;
public:
    D4() : dt(1) {}
    D4(int d) : dt(d) {}
    D4(int a, int b, int e) : D2(a, b), dt(e) {}
};
    class R1 : protected D2, protected D3
{
protected:
    double dt;
public:
    R1() : dt(1) {}
    R1(int d) : dt(d) {}
    R1(int a, int b, int c, double d, int e) : D2(a, b), D3(a, b, c, d,e), dt(e) {}

    void showDat()
    {
        std::cout << "R1::D3::D2::Base::dat = " << R1::D3::D2::Base::dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "R1::D2::Base::dat = " << R1::D2::Base::dat << std::endl;
    }

};
    class R2 : protected D1, protected D4
{
    protected:
        double dt;
public:
    R2() : dt(1) {}
    R2(int d) : dt(d) {}
    R2(int a, int b, int c, double d, int e) : D1(a, b), D4(b, c, d), dt(e) {}

    void showDat()
    {
        std::cout << "R2::D4::D2::Base::dat = " << R2::D4::D2::Base::dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "R2::D1::Base::dat = " << R2::D1::Base::dat << std::endl;
    }
    };
//
    //  virtual
    //
    class D1V : virtual protected Base
{
protected:
    int d1;
public:
    D1V() : d1(1) {}
    D1V(int d) : d1(d) {}
    D1V(int d, int dt) : Base(dt), d1(d) {}
};
    class D2V : virtual protected Base
{
protected:
    double dt;
public:
    D2V() : dt(1) {}
    D2V(int d) : dt(d) {}
    D2V(int a, int e) : Base(a), dt(e) {}
};
    class D3V : virtual protected D1V, virtual protected D2V
{
protected:
    double dt;
public:
    D3V() : dt(1) {}
    D3V(int d) : dt(d) {}
    D3V(int a, int b, int c, double d, int e) : D1V(a, b), D2V(c, d), dt(e) {}
};
    class D4V : virtual protected D2V
{
protected:
    double dt;
public:
    D4V() : dt(1) {}
    D4V(int d) : dt(d) {}
    D4V(int a, int b, int e) : D2V(a, b), dt(e) {}
};
    class R1V : virtual protected D2V, virtual protected D3V
{
protected:
    double dt;
public:
    R1V() : dt(1) {}
    R1V(int d) : dt(d) {}
    R1V(int a, int b, int c, double d, int e) : D2V(a, b), D3V(a, b, c, d, e), dt(e) {}

    void showDat()
    {
        std::cout << "R1V::D3V::D1V::Base::dat = " << R1V::D3V::D1V::Base::dat << std::endl;
        std::cout << "R1V::D3V::D2V::Base::dat = " << R1V::D3V::D2V::Base::dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "R1V::D2V::Base::dat = " << R1V::D2V::Base::dat << std::endl;
    }
};
    class R2V : virtual protected D1V, virtual protected D4V
{
protected:
    double dt;
public:
    R2V() : dt(1) {}
    R2V(int d) : dt(d) {}
    R2V(int a, int b, int c, double d, int e) : D1V(a, b), D4V(b, c, d), dt(e) {}

    void showDat()
    {
        std::cout << "R2V::D4V::D2V::Base::dat = " << R2V::D4V::D2V::Base::dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "R2V::D1V::Base::dat = " << R2V::D1V::Base::dat << std::endl;
    }
};    

int main1()
    {
        R1 a, b(1, 2, 3, 4.5, 5);
        R2 a1, b1(1, 2, 3, 4.5, 5);

        R1V av, bv(1, 2, 3, 4.5, 5);
        R2V a1v, b1v(1, 2, 3, 4.5, 5);

        std::cout << "Test !\n";
        std::cout << "Size for Base " << sizeof(Base) << std::endl;

        std::cout << "Size for D1 " << sizeof(D1) << std::endl;
        std::cout << "Size for D2 " << sizeof(D2) << std::endl;

        std::cout << "Size for D3 " << sizeof(D3) << std::endl;
        std::cout << "Size for D4 " << sizeof(D4) << std::endl;

        std::cout << "Size for R1 " << sizeof(R1) << std::endl;
        std::cout << "Size for R2 " << sizeof(R2) << std::endl;


        std::cout << "Size for Base " << sizeof(Base) << std::endl;

        std::cout << "Size for D1V " << sizeof(D1V) << std::endl;
        std::cout << "Size for D2V " << sizeof(D2V) << std::endl;

        std::cout << "Size for D3V " << sizeof(D3V) << std::endl;
        std::cout << "Size for D4V " << sizeof(D4V) << std::endl;

        std::cout << "Size for R1V " << sizeof(R1V) << std::endl;
        std::cout << "Size for R2V " << sizeof(R2V) << std::endl;

        std::cout << "Size for object class R1 " << sizeof(R1) << " or  "
            << sizeof(a) << " or  " << sizeof(b) << std::endl;
        std::cout << "Size for object class R2 " << sizeof(R2) << " or  "
            << sizeof(a1) << " or  " << sizeof(b1) << std::endl;

        std::cout << "Size for object class R1V " << sizeof(R1V) << " or  "
            << sizeof(av) << " or  " << sizeof(bv) << std::endl;
        std::cout << "Size for object class R2V " << sizeof(R2V) << " or  "
            << sizeof(a1v) << " or  " << sizeof(b1v) << std::endl;

        b.showDat();
        bv.showDat();

        b1.showDat();
        b1v.showDat();

        return 0;
    }

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
            return s;
        }
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
            int s = 3.14 * a * a;
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
        string n1[4] = { "Rectangle", "Circle", "Triangle", "Trapeze" };
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
                if(type==2){ cout << a << endl; }
                else
                cout << a << " " << b << endl;
                name = "";
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
                if(type==2){ cout << "Input a: "; cin >> a; }
                else { cout << "Input a, b: "; cin >> a >> b; }
            }
            switch (type) {
            case 1: mas[i] = new Rect(name, a, b); break;
            case 2: mas[i] = new Circle(name, a, b); break;
            case 3: mas[i] = new Triangle(name, a, b); break;
            case 4: mas[i] = new Trapeze(name, a, b); break;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << mas[i]->N() << endl;
            cout << mas[i]->S() << endl;
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
        case 1: main1(); break;
        case 2: main2(); break;
        case 3: main3(); break;
        default: cout << "Error\n"; goto e;
        }
        return 0;
    }

