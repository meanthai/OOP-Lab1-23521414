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

// Object sổ tiết kiệm và các attributes để lưu trữ thông tin
struct SavingsBook {
    string code;               // Book code
    string savingsType;        // Type of savings
    string customerName;       // Customer's name
    string identityCard;       // Identity card number
    string openingDate;        // Opening date (dd/mm/yyyy)
    double depositAmount;      // Deposit amount
};

// Hàm kiểm tra tính hợp lệ của mã của sổ (đầu vào là mã sổ, đầu ra là kqua kiểm tra mã sổ hợp lệ)
bool isValidCode(const string& code) {
    if (code.length() > 5) return false;
    for (char c : code) if (!isalnum(c)) return false; // không có kí tự đặc biệt
    return true;
}

// Hàm kiểm tra tính hợp lệ của CCCD (đầu vào là CCCD, đầu ra là kqua kiểm tra CCCD hợp lệ)
bool isCCCD(const string& id) {
    if (id.length() != 9 && id.length() != 12) return false;
    for (char c : id) if (!isdigit(c)) return false; // chỉ có số
    
    return true;
}

// Hàm kiểm tra tính hợp lệ của ngày tháng năm mở sổ (đầu vào là ngày tháng năm, đầu ra là kqua kiểm tra ngày tháng năm hợp lệ)
bool isValidDate(const string& date) {
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) return false;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return day <= 29; // Năm nhuận
        else return day <= 28;
    }
 
    if ((month == 4 ||month == 6 ||month == 9 || month == 11) && day > 30) return false;
    

    return true;
}

// Hàm kiểm tra tính hợp lệ của tiền gửi vào sổ (đầu vào là tiền gửi tiết kiệm, đầu ra là kqua kiểm tra tiền là số dương)
bool isValidDepositAmount(double amount) {
    return (amount > 0); // Tiền gửi ban đầu phải dương
}

// Hàm nhập input thông tin của từng sổ tiết kiệm (đầu vào là object Savingbook, đầu ra là cập nhật các thông tin của sách)
void inputSavingsBook(SavingsBook& book) {
    cout << "+) Enter book code (maximum 5 characters): " << endl;
    cin >> book.code;
    while (!isValidCode(book.code)) {
        cout << "(*) Invalid book code. Please enter again: " << endl;
        cin >> book.code;
    }

    cout << "+) Enter savings type (maximum 10 characters - 'long term' or 'short term'): " << endl;
    cin.ignore();
    getline(cin, book.savingsType);

    cout << "+) Enter customer's name (maximum 30 characters): " << endl;
    cin.ignore();
    getline(cin, book.customerName);

    while (book.customerName.length() > 30 || any_of(book.customerName.begin(), book.customerName.end(), ::isdigit)) {
        cout << "(*) Invalid name. Please enter again: " << endl;
        getline(cin, book.customerName);
    }

    cout << "+) Enter ID card number (9 or 12 digits): " << endl;
    cin >> book.identityCard;
    while (!isCCCD(book.identityCard)) {
        cout << "(*) Invalid ID card number. Please enter again: " << endl;
        cin >> book.identityCard;
    }

    cout << "+) Enter opening date (dd/mm/yyyy): " << endl;
    cin >> book.openingDate;
    while (!isValidDate(book.openingDate)) {
        cout << "(*) Invalid date. Please enter again: " << endl;
        cin >> book.openingDate;
    }

    cout << "+) Enter deposit amount: " << endl;
    cin >> book.depositAmount;
    while (!isValidDepositAmount(book.depositAmount)) {
        cout << "(*) Deposit amount must be positive. Please enter again: " << endl;
        cin >> book.depositAmount;
    }
}

// Xuất ra thông tin các sổ tiết kiệm của khách hàng (đầu vào là object SavingsBook, đầu ra là thông tin của sách)
void displaySavingsBook(const SavingsBook& book) {
    cout << "- Book code: " << book.code << ", Savings type: " << book.savingsType << ", Name: " << book.customerName << ", ID card: " << book.identityCard << ", Opening date: " << book.openingDate << ", Deposit amount: " 
        << fixed << setprecision(2) << book.depositAmount << endl;
}

// Hàm tính tiền lãi  tùy theo kì dài hạn, ngắn hạn (Đầu vào là object Savingsbook và lãi suất, đầu ra là tiền gửi tiết kiệm) 
double calculateInterest(const SavingsBook& book, double interestRate) {
    struct tm tmOpening = {};
    sscanf(book.openingDate.c_str(), "%d/%d/%d", &tmOpening.tm_mday, &tmOpening.tm_mon, &tmOpening.tm_year);
    tmOpening.tm_year -= 2024; // bắt đầu từ năm 2024
    tmOpening.tm_mon -= 1; // tháng bắt đầu từ 0
    time_t openingTime = mktime(&tmOpening), currentTime = time(nullptr);

    double months = difftime(currentTime, openingTime) / (30 * 24 * 3600);
    
    if (book.savingsType == "short term" && months <= 6) return book.depositAmount * (interestRate / 100) * (months / 12);
    else if (book.savingsType == "long term" && months > 6) return book.depositAmount * (interestRate / 100) * (months / 12);
    
    else return 0;
}

// Hàm thực hiện chứ năng rút tiền (Đầu vào là object Savingsbook và số tiền rút) 
void withdrawMoney(SavingsBook& book, double amount) {
    if (amount > book.depositAmount) {
        cout << "Withdrawal amount exceeds the amount in the book!" << endl;
        return;
    }

    if (amount < book.depositAmount) {
        cout << "You are withdrawing early! Interest rate will drop to 0.5%." << endl;
        double interest = calculateInterest(book, 0.5);
        cout << "Interest received: " << interest << endl;
    }
    
    book.depositAmount -= amount;
    cout << "Withdrawal successful! Remaining amount: " << book.depositAmount << endl;
}

// Tìm kiếm sổ tiết kiệm  (Đầu vào là object Savingsbook và từ khóa cần tìm kiếm) 
void searchSavingsBook(const vector<SavingsBook>& books, const string& searchTerm) {
    for (const SavingsBook& book : books) {
        if (book.identityCard == searchTerm || book.code == searchTerm) displaySavingsBook(book);
    }
}

// sắp xếp theo số tiền gửi ban đầu (Đầu vào là hai object Savingsbook, đầu ra là tiền gửi tiết kiệm của object nào lớn hơn) 
bool compareByDeposit(const SavingsBook& a, const SavingsBook& b) {
    return (a.depositAmount > b.depositAmount);
}

// sắp xép theo ngày mở tài khoảng (Đầu vào là hai object Savingsbook, đầu ra là thời điểm mở sổ tiết kiệm sớm hơn) 
bool compareByOpeningDate(const SavingsBook& a, const SavingsBook& b) {
    struct tm tmA = {}, tmB = {};
    sscanf(a.openingDate.c_str(), "%d/%d/%d", &tmA.tm_mday, &tmA.tm_mon, &tmA.tm_year);
    sscanf(b.openingDate.c_str(), "%d/%d/%d", &tmB.tm_mday, &tmB.tm_mon, &tmB.tm_year);
    tmA.tm_year -= 1900; tmA.tm_mon -= 1;
    tmB.tm_year -= 1900; tmB.tm_mon -= 1;
    return (mktime(&tmA) < mktime(&tmB));
}

// Kiểm tra xem mã sổ tiết kiệm có tồn tại (đầu vào là mã sổ cần tìm và vector chứa các mã sổ tiết kiệm, đầu ra là có hoặc không tồn tại mã sổ)
bool checkExistBookCode(string withdrawCode, vector<SavingsBook> books){
    for(auto book : books) if(book.code == withdrawCode) return 1;
    return 0;
}

// Hàm xử lý chính của bài
void process8() {
    vector<SavingsBook> books;
    int n;

    cout << "Enter the number of savings books: " << endl;
    cin >> n;
    books.resize(n);

    // Input savings book information
    for (int i = 0; i < n; i++) {
        cout << "- Enter information for savings book " << (i + 1) << ":" << endl;
        inputSavingsBook(books[i]);
    }

    // Display list of savings books
    cout << "List of savings books:" << endl;
    for (auto book : books) {
        displaySavingsBook(book);
    }

    // Calculate interest
    double interestRate;
    cout << "Enter interest rate (%/year): " << endl;
    cin >> interestRate;
    for (const SavingsBook& book : books) {
        double interest = calculateInterest(book, interestRate);
        cout << "Interest for book " << book.code << ": " << interest << endl;
    }

    // Withdraw money
    string withdrawCode;
    cout << "Enter book code to withdraw money: " << endl;
    cin >> withdrawCode;
    while(!checkExistBookCode(withdrawCode, books)){
        cout << "(*) THe book code does not exist, please try again:" << endl;
        cin >> withdrawCode;
    }
    double amount;
    cout << "Enter amount to withdraw: " << endl;
    cin >> amount;

    for (SavingsBook& book : books) {
        if (book.code == withdrawCode) {
            withdrawMoney(book, amount);
            break;
        }
    }

    // Search
    string searchTerm;
    cout << "Enter book code or ID card to search: " << endl;
    cin >> searchTerm;
    cout << "Search results:" << endl;
    searchSavingsBook(books, searchTerm);

    // Sort list by deposit amount descending
    cout << "Sort list by deposit amount descending:" << endl;
    sort(books.begin(), books.end(), compareByDeposit);
    for (const SavingsBook& book : books) {
        displaySavingsBook(book);
    }

    // Sort list by opening date ascending
    cout << "Sort list by opening date ascending:" << endl;
    sort(books.begin(), books.end(), compareByOpeningDate);
    for (const SavingsBook& book : books) {
        displaySavingsBook(book);
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    while(test --) process8();
    return 0;
}
