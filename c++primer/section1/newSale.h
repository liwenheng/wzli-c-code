#ifndef __NEWSALE_H__
#define __NEWSALE_H__

#include<iostream>
#include<string>

class Sale{
    friend std::istream& operator>>(std::istream&, Sale&);
    friend std::ostream& operator<<(std::ostream&, const Sale&);
    friend bool operator<(const Sale&, const Sale&);
    friend bool operator==(const Sale&, const Sale&);
    public:
        Sale() = default;
        Sale(const std::string &book): bookNo(book) { }
        Sale(std::istream &is) { is >> *this; }

        Sale& operator+=(const Sale&);
    
        // operations on Sales_item objects
        std::string isbn() const { return bookNo; }
        double avg_price() const;
        inline bool compareIsbn(const Sale &lhs, const Sale &rhs) { return lhs.isbn() == rhs.isbn(); }
       
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    




};




#endif