#include <bits/stdc++.h>
#define fi(i,a,b) for(i=a;i<=b;i++)
#define ll long long
#define ff first
#define ss second
#define ii pair<int, int>
#define iii pair<ll, pair<int, int>>
#define MASK(c) (1LL << (c))
const ll N =  1e6 + 30;
const ll inf = 1e9 + 7;
const ll base = 7013;
using namespace std;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y)
        {
            x = y;
            return 1;
        }
        return 0;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y)
        {
            x = y;
            return 1;
        }
        return 0;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/*
     /\_/\
    (  ._.)
    / >() \>()
*/
// Tạo object Date có các attributes để lưu trữ thông tin
struct Date {
    int day;
    int month;
    int year;
};

// Kiểm tra năm nhuận chia hết cho 4 và 100
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Số ngày trong từng tháng để chia trường hợp nhằm tính toán chính xác
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Tháng không hợp lệ
    }
}

// Kiểm tra tính hợp lệ của ngày tháng năm nhập vào
bool isValidDate(Date date) {
    return date.year > 0 && date.month >= 1 && date.month <= 12 && 
           date.day >= 1 && date.day <= daysInMonth(date.month, date.year);
}

// Tìm ngày kế tiếp bằng cách xét các điều kiện
Date nextDay(Date date) {
    date.day++;
    if (date.day > daysInMonth(date.month, date.year)) {
        date.day = 1;
        date.month+= 1;
        if (date.month > 12) {
            date.month = 1;
            date.year+= 1;
        }
    }
    return date;
}

// Tìm ngày trước bằng cách xét các điều kiện
Date previousDay(Date date) {
    date.day -= 1;
    if (date.day <= 0) {
        date.month--;
        if (date.month < 1) {
            date.month = 12;
            date.year-=1;
        }
        date.day = daysInMonth(date.month, date.year);
    }
    return date;
}

// Tính ngày thứ bao nhiêu trong năm
int dayOfYear(Date date) {
    int dayCount = 0;
    for (int m = 1; m < date.month; m++) {
        dayCount += daysInMonth(m, date.year);
    }
    dayCount += date.day;
    return dayCount;
}

// Hàm xử lý chính input và các functions khác
void process5() {
    Date date;
    cout << "Enter date (day month year)-(dd mm yyyy): " << endl;
    cin >> date.day >> date.month >> date.year;

    if (!isValidDate(date)) {
        cout << "Invalid date!" << endl;
        return;
    }

    // Ngày kế tiếp
    Date next = nextDay(date);
    cout << "The next day: " << setw(2) << setfill('0') << next.day << "/" 
         << setw(2) << setfill('0') << next.month << "/" << next.year << endl;

    // Ngày trước
    Date previous = previousDay(date);
    cout << "The previous day: " << setw(2) << setfill('0') << previous.day << "/" 
         << setw(2) << setfill('0') << previous.month << "/" << previous.year << endl;

    // Ngày thứ bao nhiêu trong năm
    int dayNum = dayOfYear(date);
    cout << "This is the " << dayNum << "th day in the year." << endl;

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp", "r", stdin);
    // freopen("main.out", "w", stdout);

    int test = 1;
    // cin >> test;
    while(test --) process5();
    return 0;
}
