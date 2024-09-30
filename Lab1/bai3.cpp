
#include <bits/stdc++.h>
#define fi(i,a,b) for(i=a;i<=b;i++)
#define ll long long
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

// Hàm rút gọn hai phân số bằng cách chia tử và mẫu cho ước chung lớn nhất (Đầu vào tử số và mẫu số, đầu ra là kqua phân số được rút gọc)
void reduceFraction(long long& numerator, long long& denominator) {
    long long commonDivisor = __gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
}

// Hàm so sánh hai phân số và tìm phân số lớn hơn bằng cách sử dụng phép nhân chéo (Đầu vào tử số và mẫu số cảu hai phân số input và phân số kết quả, đầu ra là kqua phân số lớn hơn)
void compareFractions(long long n1, long long d1, long long n2, long long d2, long long& n_max, long long& d_max) {
    if (n1 * d2 > n2 * d1) {
        n_max = n1;
        d_max = d1;
    } else {
        n_max = n2;
        d_max = d2;
    }
}

// Hàm cộng hai phân số (Đầu vào tử số và mẫu số cảu hai phân số input và phân số kết quả, đầu ra là kqua tổng của hai phân số)
void addFractions(long long n1, long long d1, long long n2, long long d2, long long& num_result, long long& denom_result) { 
    num_result = n1 * d2 + n2 * d1;
    denom_result = d1 * d2;
    reduceFraction(num_result, denom_result);
}

// Hàm trừ hai phân số (Đầu vào tử số và mẫu số cảu hai phân số input và phân số kết quả, đầu ra là kqua hiệu của hai phân số)
void subtractFractions(long long n1, long long d1, long long n2, long long d2, long long& num_result, long long& denom_result) {
    num_result = n1 * d2 - n2 * d1;
    denom_result = d1 * d2;
    reduceFraction(num_result, denom_result);
}

// Hàm nhân hai phân số (Đầu vào tử số và mẫu số cảu hai phân số input và phân số kết quả, đầu ra là kqua tích của hai phân số)
void multiplyFractions(long long n1, long long d1, long long n2, long long d2, long long& num_result, long long& denom_result) {
    num_result = n1 * n2;
    denom_result = d1 * d2;
    reduceFraction(num_result, denom_result);
}

// Hàm chia hai phân số (Đầu vào tử số và mẫu số cảu hai phân số input và phân số kết quả, đầu ra là kqua thương của hai phân số)
void divideFractions(long long n1, long long d1, long long n2, long long d2, long long& num_result, long long& denom_result) {
    if (n2 == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return;
    }
    num_result = n1 * d2;
    denom_result = d1 * n2;
    reduceFraction(num_result, denom_result);
}

// Hàm kiểm tra mẫu số khác phải khác 0 để phân số xác định (Đầu vào tử số và mẫu số, đầu ra là kqua mẫu khác không)
bool isValidFraction(long long n, long long d) {
    return d != 0;
}

// Hàm xử lý input chính và các functions ở trên
void process3(){
    long long a, b, c, d;
    cout << "- Nhap phan so thu nhat: a / b" << endl;
    cin >> a >> b;
    if (!isValidFraction(a, b)) {
        cout << "(*) Phan so thu nhat khong hop le!" << endl;
        return;
    }
    cout << "- Nhap phan so thu nhai: c / d" << endl;
    cin >> c >> d;
    if (!isValidFraction(c, d)) {
        cout << "(*) Phan so thu hai khong hop le!" << endl;
        return;
    }
    reduceFraction(a, b);
    reduceFraction(c, d);

    long long n_res, d_res;
    addFractions(a, b, c, d, n_res, d_res);
    cout << "-> Tong cua hai phan so la: " << n_res << '/' << d_res << endl;

    subtractFractions(a, b, c, d, n_res, d_res);
    cout << "-> Hieu cua hai phan so la: " << n_res << '/' << d_res << endl;

    multiplyFractions(a, b, c, d, n_res, d_res);
    cout << "-> Tich cua hai phan so la: " << n_res << '/' << d_res << endl;

    divideFractions(a, b, c, d, n_res, d_res);
    cout << "-> Thuong cua hai phan so la: " << n_res << '/' << d_res << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp", "r", stdin);
    // freopen("main.out", "w", stdout);

    long long test = 1;
    // cin >> test;
    while(test --) process3();
    return 0;
}
