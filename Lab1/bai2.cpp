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

// Hàm kiểm tra mẫu số khác 0 để tồn tại phân số
bool isValidFraction(int n, int d) {
    return d != 0;
}

// Rút gọn phân số bằng cách chia tử và mẫu cho ước chung lớn nhất
void reduceFraction(int& numerator, int& denominator) {
    int commonDivisor = __gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
}

// Hàm so sánh hai phân số và tìm phân số lớn hơn
void compareFractions(int n1, int d1, int n2, int d2, int& n_max, int& d_max) {
    // So sánh n1/d1 và n2/d2 bằng cách sử dụng phép nhân chéo
    if (n1 * d2 > n2 * d1) {
        n_max = n1;
        d_max = d1;
    } else {
        n_max = n2;
        d_max = d2;
    }
}

// Hàm xử lý input chính và các functions trên
void process2(){
    int a, b, c, d;
    cout << "nhap phan so thu nhat: a / b" << endl;
    cin >> a >> b;
    if (!isValidFraction(a, b)) {
        cout << "phan so thu nhat khong hop le!" << endl;
        return;
    }
    cout << "nhap phan so thu nhat: c / d" << endl;
    cin >> c >> d;
    if (!isValidFraction(c, d)) {
        cout << "phan so thu hai khong hop le!" << endl;
        return;
    }
    reduceFraction(a, b);
    reduceFraction(c, d);

    if(a == c && b == d){
        cout << "hai phan so bang nhau" << endl;
        return;
    }

    int n_max, d_max;

    compareFractions(a, b, c, d, n_max, d_max);

    cout << "phan so lon nhat la: " << n_max << '/' << d_max << endl;
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
    while(test --) process2();
    return 0;
}
