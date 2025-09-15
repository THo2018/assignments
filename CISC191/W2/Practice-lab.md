# Practice-lab code submission
## Task A1
```C++
#include <iostream>  // Preprocessor directive (not a token, but expands before tokens)
using namespace std; // Keywords: using, namespace

int main() {         // Keywork: int, Identifier: main, Punctuators: ()
    // ---- Identifiers, Literals, Operators, Punctuators ----
    int a, b, c;     // Keyword: int | Identifier: a, b, c | Punctuator: ;
    
    cout << "Input: ";
    cin >> a; //a = 5
    cin.ignore(1, '\n');
    cin >> b; //b = 2
    cin.ignore(1, '\n');
    cin >> c; //c = 3
    
    cout << "a + b * c = " << a+b*c << endl << "(a + b) * c = " << (a+b)*c << endl << "a / b * c = " << a/b*c << endl << "a / (b * c) = " << a/(b*c) << endl;
    return 0;
}
```
## Task A2
```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double balance;
    int deposits, withdrawals;

    cout << "Input: balance=";
    cin >> balance;
    cout << " deposits=";
    cin >> deposits;
    cout << " withdrawals=";
    cin >> withdrawals;

    double finalBalance = balance + deposits * 25.50 - withdrawals * 12.75;

    cout << fixed << setprecision(2);
    cout << "Final balance = " << balance << " + " << deposits << "*25.50 - "
         << withdrawals << "*12.75 = " << finalBalance << "\n";

    return 0;
}
```
## Task B1
```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int score1, score2, score3;
    cout << "Input: ";
    cin >> score1 >> score2 >> score3;

    int sum = score1 + score2 + score3;
    int rawAverage = sum / 3;
    double correctAverage = static_cast<double>(sum) / 3;

    cout << "Raw average (implicit): " << rawAverage << endl;

    cout << fixed << setprecision(1); // force one decimal place
    cout << "Correct average (explicit cast): " << correctAverage << endl;

    return 0;
}
```
## Task B2
```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int wins, games;
    cout << "Input: ";
    cin >> wins >> games;

    if (games == 0) {
        cout << "No games played.\n";
    } else {
        double pct = static_cast<double>(wins) / static_cast<double>(games) * 100.0;
        cout << fixed << setprecision(1);
        cout << "Win% = " << pct << "%\n";
    }

    return 0;
}
```
## Part C
```C++
#include <iostream>
#include <iomanip>
#include <algorithm>  // for min, max
using namespace std;

int main() {
    double hours, rate;
    cout << "Input: hours= ";
    cin >> hours;
    cout << "rate= ";
    cin >> rate;

    double regHours = min(hours, 40.0);
    double otHours = max(hours - 40.0, 0.0);
    double gross = regHours * rate + otHours * rate * 1.5;
    double tax = gross * 0.18;
    double benefits = 35.0;
    double net = gross - tax - benefits;

    cout << fixed << setprecision(2);
    cout << "Regular: " << regHours << ", Overtime: " << otHours << "\n";
    cout << "Gross: $" << gross << "\n";
    cout << "Tax (18%): $" << tax << "\n";
    cout << "Benefits: $" << benefits << "\n";
    cout << "Net: $" << net << "\n";

    return 0;
}
```
## Task D
```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int items;
    double price;

    cout << "Enter items and price: ";
    cin >> items >> price;

    double total = items * price;

    int discountPercent = 15;
    double discount = total * (static_cast<double>(discountPercent) / 100.0);

    double shipping = 5 + 2 * items;
    double afterDiscount = total - discount;

    if (afterDiscount >= 100.0) {
        shipping = 0;
    }

    cout << fixed << setprecision(2);
    cout << "Total: $" << total << "\n";
    cout << "Discount: $" << discount << "\n";
    cout << "Shipping: $" << shipping << "\n";
    cout << "Grand Total: $" << (afterDiscount + shipping) << "\n";

    return 0;
}
```
## Reflection
1. I learned that with implicit conversion, it makes your final answer less precise, especially when doing double integer devision. Thats why you do explicit conversion to make sure the answer is more accurate, especially when doing things like percentages.
2. In Part D, the original code had a bug which had the shipping always be added even with the total after discount allowing for free shipping. Using an if statement, this would set the shipping to zero when the total was at least 100 dollars. I found this when looking out the output and comparing it to the test case.
