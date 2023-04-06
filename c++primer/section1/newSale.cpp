#include<iostream>
#include"newSale.h"

using namespace std;

std::istream& operator>>(std::istream& in, Sale& s)
{
    double price;
    std::cout << "请输入书本的信息： " << std::endl;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else 
        s = Sale();  // input failed: reset object to default state
    return in;
}
std::ostream& operator<<(std::ostream& out, const Sale& s)
{
    out <<"输出ISBN号" <<s.isbn() << " 卖出的本数 " << s.units_sold << " 总得卖出价格："
        << s.revenue << " 平均价格：" << s.avg_price();
    return out;
}

inline bool operator==(const Sale &lhs, const Sale &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sale &lhs, const Sale &rhs)
        {
            return !(lhs == rhs); // != defined in terms of operator==
        }

Sale& Sale::operator+=(const Sale& rhs) 
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue; 
    return *this;
}
Sale operator+(const Sale& lhs, const Sale& rhs) 
{
    Sale ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}
double Sale::avg_price() const
{
    if (units_sold) 
        return revenue/units_sold; 
    else 
        return 0;
}
