#include <iostream>
#include <cstring>

class Element
{
protected:
    char *name;
    int numInp;
    int numOutp;

public:
    Element(const char *elemName, int inp, int outp)
        : numInp(inp), numOutp(outp)
    {
        name = new char[strlen(elemName) + 1];
        strcpy(name, elemName);
    }

    ~Element()
    {
        delete[] name;
    }

    void setName(const char *elemName)
    {
        delete[] name;
        name = new char[strlen(elemName) + 1];
        strcpy(name, elemName);
    }
};

class Combinational : public Element
{
private:
    bool *inp;

public:
    Combinational(const char *elemName, int numInp)
        : Element(elemName, numInp, 1)
    {
        inp = new bool[numInp]();
    }

    Combinational(Combinational &other)
        : Element(other.name, other.numInp, 1)
    {
        inp = new bool[numInp];
        std::copy(other.inp, other.inp + numInp, inp);
    }

    ~Combinational()
    {
        delete[] inp;
    }

    void setInputs(bool *values)
    {
        std::copy(values, values + numInp, inp);
    }

    bool getInput(int index)
    {
        if (index >= 0 && index < numInp)
        {
            return inp[index];
        }
        return false;
    }

    bool ResultOut()
    {
        return !(inp[0] && inp[1] && inp[2]);
    }
};

class Memory : protected Element
{
private:
    bool inp[2];
    bool q;
    bool qNot;

public:
    Memory()
        : Element("RS", 2, 2), q(false), qNot(true)
    {
        inp[0] = false;
        inp[1] = false;
    }

    Memory(const char *elemName)
        : Element(elemName, 2, 2), q(false), qNot(true)
    {
        inp[0] = false;
        inp[1] = false;
    }

    Memory(Memory &other)
        : Element(other.name, 2, 2), q(other.q), qNot(other.qNot)
    {
        inp[0] = other.inp[0];
        inp[1] = other.inp[1];
    }

    ~Memory() {}

    void setInputs(bool s, bool r)
    {
        inp[0] = s;
        inp[1] = r;
    }

    bool getInput(int index)
    {
        if (index >= 0 && index < 2)
        {
            return inp[index];
        }
        return false;
    }

    void Resultmem()
    {
        if (inp[0] && !inp[1])
        {
            q = true;
            qNot = false;
        }
        else if (!inp[0] && inp[1])
        {
            q = false;
            qNot = true;
        }
        else if (inp[0] && inp[1])
        {
            q = false;
            qNot = false;
        }
    }

    bool getQ()
    {
        return q;
    }

    bool getQNot()
    {
        return qNot;
    }

    bool operator==(Memory &other)
    {
        return (q == other.q && qNot == other.qNot);
    }
};
class Register : private Element
{
private:
    bool reset;
    bool set;
    static const int size = 12;
    Memory memСount[size];
    bool inp[size][2];

public:
    Register()
        : Element("MEM", 2, 2), reset(false), set(false)
    {
        for (int i = 0; i < size; i++)
        {
            memСount[i] = Memory();
        }
    }

    ~Register() {}

    void setInputs(bool newInp[12][2])
    {
        for (int i = 0; i < size; i++)
        {
            inp[i][0] = newInp[i][0];
            inp[i][1] = newInp[i][1];
            memСount[i].setInputs(inp[i][0], inp[i][1]);
        }
    }

    bool getOutput(int index)
    {
        if (index >= 0 && index < size)
        {
            return memСount[index].getQ();
        }
        return false;
    }

    void Resultreg()
    {
        for (int i = 0; i < size; ++i)
        {
            memСount[i].Resultmem();
        }
    }
};

int main()
{
    std::cout << "Combinational---------------" << std::endl;
    Combinational ggo1("AND-NO", 3);
    bool inpVal[] = {false, false, false};
    ggo1.setInputs(inpVal);
    std::cout << ggo1.ResultOut() << std::endl;
    ggo1.setName("Oppm");

    std::cout << "\nMemory----------------------" << std::endl;
    Memory RS("RS");
    RS.setInputs(1, 0);
    RS.Resultmem();
    std::cout << "QNot: " << RS.getQNot() << "\nQ: " << RS.getQ() << std::endl;
    RS.setInputs(0, 1);
    RS.Resultmem();
    std::cout << "QNot: " << RS.getQNot() << "\nQ: " << RS.getQ() << std::endl;
    Memory RS2;
    RS2.setInputs(1, 0);
    RS2.Resultmem();
    std::cout << "QNot2: " << RS2.getQNot() << "\nQ2: " << RS2.getQ() << std::endl;

    std::cout << "\nResult----------------------" << std::endl;
    Register reg;
    bool inpval[12][2] = {{true, false}, {false, true}, {false, false}, {true, false}};
    reg.setInputs(inpval);
    reg.Resultreg();
    std::cout << "Регистер вывод:" << reg.getOutput(0) << std::endl;
    std::cout << "Регистер вывод:" << reg.getOutput(1) << std::endl;
    std::cout << "Регистер вывод:" << reg.getOutput(2) << std::endl;
    std::cout << "Регистер вывод:" << reg.getOutput(3) << std::endl;

    return 0;
}
