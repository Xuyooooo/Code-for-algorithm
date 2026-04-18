#include <iostream>
const double pi = 3.14;
using namespace std;
class juxing
{
public:
    void show()
    {
        cout << length * width << '\n';
    }
    void change(double x, double y)
    {
        length = x;
        width = y;
    }

private:
    double length;
    double width;
};
class circle
{
public:
    void change(double x)
    {
        r = x;
    }
    void show()
    {
        cout << pi * r * r << '\n';
    }

private:
    double r;
};
int main()
{
    printf("请选择图形类型\n1.圆形\n2.长方形\n3.正方形\n");
    int n;
    cin >> n;
    switch (n)
    {

    case 1:
        circle a;
        double temp;
        cin >> temp;
        a.change(temp);
        a.show();
        break;
    case 2:
        juxing a;
        double temp1, temp2;
        cin >> temp1 >> temp2;
        a.change(temp1, temp2);
        a.show();
        break;
    case 3:
        juxing a;
        double temp1, temp2;
        cin >> temp1 >> temp2;
        a.change(temp1, temp2);
        a.show();
        break;
    }
}