#include <bits/stdc++.h>
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

/*
     /\_/\
    (  ._.)
    / >() \>()
*/

// Hàm kiểm tra mẫu số khác không để tồn tại phân số (Đầu vào tử số và mẫu số, đầu ra là kqua mẫu khác không)
bool isValidFraction(int n, int d) { 
    return d != 0;
}

// Hàm tính ước chung lớn nhất bằng function __gcd() (Đầu vào tử số và mẫu số, đầu ra là kqua ước chung lớn nhất)
int calculateGCD(int a, int b){
    int tmp = __gcd(a, b);
    return tmp;
}

// Hàm xử lý input chính và thực hiện rút gọn phân số, ta sẽ tìm ước chung lớn nhất và chia cả tử lẫn mẫu
void process1()
{
    int a, b;
    cout << "nhap tu so: " << endl;

    cin >> a;

    cout << "nhap mau so: " << endl;
    cin >> b;

    if (!isValidFraction(a, b)) {
        cout << "phan so da cho khong hop le!" << endl;
        return;
    }
    int GCDvalue = calculateGCD(a, b);

    cout << "Phan so da duoc rut gon la: " << a / GCDvalue << '/' << b / GCDvalue << endl;

    return;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    while(test --) process1();
    return 0;
}
