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

// Object Flight và các attributes để lưu trữ thông tin
struct Flight {
    string flightCode;
    string departureDate; // định dạng dd/mm/yyyy
    string departureTime; // định dạng HH:MM
    string departurePlace;
    string arrivalPlace;
};

// Kiểm tra năm nhuận
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Kiểm tra tính hợp lệ của ngày
bool isValidDate(const string& date) {
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) return false;

    if (month == 2) {
        if (isLeapYear(year)) return day <= 29;
        else return day <= 28;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    

    return true;
}

// Kiểm tra tính hợp lệ của giờ
bool isValidTime(const string& time) {
    int hour, minute;
    sscanf(time.c_str(), "%d:%d", &hour, &minute);
    return (hour >= 0 && hour < 24 && minute >= 0 && minute < 60);
}

// Kiểm tra mã chuyến bay
bool isValidFlightCode(const string& code) {
    if (code.length() > 5) return false;
    for (char c : code) if (!isalnum(c) || isspace(c)) return false; // không chứa khoảng trắng và ký tự đặc biệt
    return true;
}

// Kiểm tra tên địa danh
bool isValidPlace(const string& place) {
    if (place.length() > 20) return false;
    for (char c : place) if (isdigit(c) || !isalnum(c) && c != ' ') return false; // không chứa số và ký tự đặc biệt
    
    return true;
}

// Nhập thông tin chuyến bay
void inputFlight(Flight& flight) {
    cout << "+)Flight code(at most 5 characters): " << endl;
    cin >> flight.flightCode;
    while (!isValidFlightCode(flight.flightCode)) {
        cout << "*Invalid flight code, please try again: " << endl;
        cin >> flight.flightCode;
    }

    cout << "+)Enter departure date (dd/mm/yyyy): " << endl;
    cin >> flight.departureDate;
    while (!isValidDate(flight.departureDate)) {
        cout << "*Invalid departure date, please try again: " << endl;
        cin >> flight.departureDate;
    }

    cout << "+)Enter departure time (HH:MM): " << endl;
    cin >> flight.departureTime;
    while (!isValidTime(flight.departureTime)) {
        cout << "*Invalid departure time, please try again: " << endl;
        cin >> flight.departureTime;
    }

    cout << "+)Enter departure place (at most 20 characters): " << endl;
    cin.ignore();
    getline(cin, flight.departurePlace);
    while (!isValidPlace(flight.departurePlace)) {
        cout << "*Invalid departure place, please try again: " << endl;
        getline(cin, flight.departurePlace);
    }

    cout << "+)Enter your destination (at most 20 characters): " << endl;
    getline(cin, flight.arrivalPlace);
    while (!isValidPlace(flight.arrivalPlace)) {
        cout << "*Invalid arrival place (at most 20 characters): " << endl;
        getline(cin, flight.arrivalPlace);
    }
}

// Xuất thông tin chuyến bay
void displayFlight(const Flight& flight) {
    cout << "+ Flight code: " << flight.flightCode << ", departure date: " << flight.departureDate << ", departure time: " << flight.departureTime << ", departure place: " << flight.departurePlace
         << ", destination: " << flight.arrivalPlace << endl;
}

// Tìm kiếm chuyến bay
void searchFlight(const vector<Flight>& flights, const string& searchTerm) {
    cout << searchTerm << endl;
    for (const Flight& flight : flights) {
        if (flight.flightCode == searchTerm || flight.departurePlace == searchTerm || flight.arrivalPlace == searchTerm) displayFlight(flight);
        
    }
}

// Sắp xếp chuyến bay
bool compareFlights(const Flight& a, const Flight& b) {
    // Chuyển đổi ngày và giờ thành thời gian để so sánh
    struct tm tmA = {}, tmB = {};
    sscanf(a.departureDate.c_str(), "%d/%d/%d", &tmA.tm_mday, &tmA.tm_mon, &tmA.tm_year);
    sscanf(a.departureTime.c_str(), "%d:%d", &tmA.tm_hour, &tmA.tm_min);
    tmA.tm_year -= 1900; // năm tính từ 1900
    tmA.tm_mon -= 1; // tháng tính từ 0
    time_t timeA = mktime(&tmA);

    sscanf(b.departureDate.c_str(), "%d/%d/%d", &tmB.tm_mday, &tmB.tm_mon, &tmB.tm_year);
    sscanf(b.departureTime.c_str(), "%d:%d", &tmB.tm_hour, &tmB.tm_min);
    tmB.tm_year -= 1900;
    tmB.tm_mon -= 1;
    time_t timeB = mktime(&tmB);

    return timeA < timeB;
}

// Hiển thị chuyến bay theo nơi và ngày
void displayFlightsByPlaceAndDate(const vector<Flight>& flights, const string& place, const string& date) {
    for (const Flight& flight : flights) {
        if (flight.departurePlace == place && flight.departureDate == date) displayFlight(flight);
        
    }
}

// Đếm số chuyến bay từ nơi đi đến nơi đến
int countFlights(const vector<Flight>& flights, const string& from, const string& to) {
    int count = 0;
    for (const Flight& flight : flights) {
        if (flight.departurePlace == from && flight.arrivalPlace == to) count++;
        
    }
    return count;
}

// Hàm xử lý chính của bài
void process7() {
    int n;
    cout << "Enter the number of flights: " << endl;
    cin >> n;
    vector<Flight> flights(n);

    // Nhập thông tin chuyến bay
    for (int i = 0; i < n; i++) {
        cout << "- Enter the information about the " << (i + 1) << "th flight:" << endl;
        inputFlight(flights[i]);
    }

    // Sắp xếp danh sách chuyến bay theo ngày và giờ
    sort(flights.begin(), flights.end(), compareFlights);
    cout << "List of flights sorted based on departure date and time:" << endl;
    for (const Flight& flight : flights) {
        displayFlight(flight);
    }

    // Tìm kiếm chuyến bay
    string searchTerm;
    cout << "Enter flight code, departure place or destination to search for flights: " << endl;
    getline(cin, searchTerm);
    cout << "Results:" << endl;
    searchFlight(flights, searchTerm);

    // Hiển thị chuyến bay khởi hành từ nơi cụ thể vào ngày chỉ định
    string place, date;
    cout << "Enter departure place and time (dd/mm/yyyy) to get flights: " << endl;
    cin.ignore();
    getline(cin, place);
    cin >> date;
    cout << "a flight from " << place << " on " << date << ":" << endl;
    displayFlightsByPlaceAndDate(flights, place, date);

    // Đếm số chuyến bay từ nơi đi đến nơi đến
    string from, to;
    cout << "Enter departure places and destinations to count the number of flights: " << endl;
    cin.ignore();
    getline(cin, from);
    getline(cin, to);
    int count = countFlights(flights, from, to);
    cout << "the number of flights from " << from << " to " << to << ": " << count << endl;

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
    while(test --) process7();
    return 0;
}
