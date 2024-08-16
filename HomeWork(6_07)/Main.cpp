// ���� ������ �������� � ��������� �����, ������� ����� ��������� � ���� ��������� �������� ������ ������, �������� ��� ����� ����������.

#include <iostream>
using namespace std;

// ����� "�����"
class Point
{
    int X;
    int Y;
public:
    Point()
    {
        X = Y = 0;
    }

    void SetPoint(int iX, int iY)
    {
        X = iX;
        Y = iY;
    }

    void Show()
    {
        cout << "----------------------------\n\n";
        cout << X << "\t" << Y << "\n\n";
        cout << "----------------------------\n\n";
    }
};

// ����� "������"
class Figura
{
    Point* obj;
    int count;
    int color;

public:
    Figura()
    {
        count = color = 0;
        obj = NULL;
    }

    void CreateFigura(int cr, int ct)
    {
        if (ct < 3) exit(0);
        count = ct;
        color = cr;
        obj = new Point[count];
        if (!obj) exit(0);

        int tempX, tempY;
        for (int i = 0; i < count; i++)
        {
            cout << "Set X\n";
            cin >> tempX;
            cout << "Set Y\n";
            cin >> tempY;
            obj[i].SetPoint(tempX, tempY);
        }
    }

    void ShowFigura()
    {
        cout << "----------------------------\n\n";
        cout << "Color: " << color << "\n\nPoints: " << count << "\n\n";
        for (int i = 0; i < count; i++) {
            obj[i].Show();
        }
    }

    ~Figura() {
        if (obj != NULL) delete[]obj;
    }
};

// ����� "��������� �����" - ����������
class ShapeCollection
{
    Figura* shapes;
    int numShapes;

public:
    ShapeCollection(int size)
    {
        numShapes = size;
        shapes = new Figura[numShapes];
    }

    void CreateAllFigures()
    {
        for (int i = 0; i < numShapes; i++)
        {
            int color, count;
            cout << "Creating figure " << i + 1 << ":\n";
            cout << "Enter color: ";
            cin >> color;
            cout << "Enter number of points: ";
            cin >> count;
            shapes[i].CreateFigura(color, count);
        }
    }

    void ShowAllFigures()
    {
        for (int i = 0; i < numShapes; i++)
        {
            cout << "\nDisplaying figure " << i + 1 << ":\n";
            shapes[i].ShowFigura();
        }
    }

    ~ShapeCollection()
    {
        delete[] shapes;
    }
};

int main()
{
    // ������� ��������� �� 2 �����
    ShapeCollection collection(2);

    // ������� ��� ������ � ���������
    collection.CreateAllFigures();

    // ���������� ��� ������
    collection.ShowAllFigures();

    return 0;
}

