// Author: Samkit Jain
// Purpose: This concept can be very useful in atomically checking equality
//          of a group of values.

#include <iostream>
#include <cstdio>

using namespace std;

template <class data_type_1, class data_type_2>
bool grouped_equal_to(pair<data_type_1, data_type_2> const& data)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return data.first == data.second;
}

template <class data_type_1, class data_type_2, class data_type_3, class data_type_4>
bool grouped_equal_to(pair<pair<data_type_1, data_type_2> const&, pair<data_type_3, data_type_4> const&> const& data)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return grouped_equal_to(data.first) && grouped_equal_to(data.second);
}

template <class data_type_1, class data_type_2>
pair<data_type_1 const&, data_type_2 const&> operator ,(data_type_1 const& lhs, data_type_2 const& rhs)
{
    return pair<data_type_1 const&, data_type_2 const&>(lhs, rhs);
}

class MyClass
{
public:
    MyClass(int data) :m_data(data) { }
    bool operator ==(MyClass const& rhs) const
    {
        return m_data == rhs.m_data;
    }

private:
    int m_data;

    MyClass(MyClass const&);
    MyClass& operator =(MyClass const&);
};

template <class data_type>
class custom_data
{
public:
    custom_data(data_type const& data) :m_data(data) {}
    template <class data_type_2>
    bool operator ==(data_type_2 const& rhs) const
    {
        return m_data == rhs;
    }

private:
    data_type const& m_data;
};

template <class data_type>
custom_data<data_type const&> ref_data(data_type const& data)
{
    return custom_data<data_type const&>(data);
}

int main()
{
    std::pair<int, int> p1(3, 3);
    std::pair<int, int> p2(1, 1);
    std::pair<int, int> p3(1, 1);
    std::string a = "a";
    MyClass m1(1), m2(1);
    int i = 7;
    cout << boolalpha;
    cout << grouped_equal_to((
                (a, "a"),
                p1,
                p2,
                (p2, p3),
                (m1, m2),
                (ref_data(i), 7),
                ((a, "a"), (m1, m2), ((p1, p2), p2))
            )) << endl;
    return 0;
}
