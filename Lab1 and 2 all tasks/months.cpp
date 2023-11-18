#include <iostream>
using namespace std ;
enum Month
{
    January=1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};
Month operator++(Month& month)
{
    month = (month == December) ? January : static_cast<Month>(month + 1);
    return month;
}

Month operator--(Month& month)
{
    month = (month == January) ? December : static_cast<Month>(month - 1);
    return month;
}

int main()
{
    Month month = January;
    while(1){
    char c ;
    cin>>c ;
    if (c == '+')
    {
        ++month;
        cout << "Next month: " ;
    }
    else if (c == '-')
    {
        --month;
        cout << "Previous month: ";
    }
    switch(month)
    {
    case 1 :
        cout<<"Jan"<<endl;
        break;
    case 2 :
        cout<<"Feb"<<endl;
        break;
    case 3 :
        cout<<"Mar"<<endl;
        break;
    case 4 :
        cout<<"Apr"<<endl;
        break;
    case 5 :
        cout<<"May"<<endl;
        break;
    case 6 :
        cout<<"Jun"<<endl;
        break;
    case 7 :
        cout<<"Jul"<<endl;
        break;
    case 8 :
        cout<<"Aug"<<endl;
        break;
    case 9 :
        cout<<"Sep"<<endl;
        break;
    case 10 :
        cout<<"Oct"<<endl;
        break;
    case 11 :
        cout<<"Nov"<<endl;
        break;
    case 12 :
        cout<<"Dec"<<endl;
        break;
    }
    }
    return 0;
}