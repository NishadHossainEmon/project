#include<bits/stdc++.h>
using namespace std;

class calculator
{
private:
    int n1,n2;
    void calculate_add()
    {
        while(1)
        {
            string s;
            cout << "Enter operands with operator : ";
            getline(cin >> ws,s);
            int pos = 0,nextpos,is_invalid_input = 0,is_syntax_error= 0,flag = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '*' || s[i] == '/')
                {
                    cout << "Invalid operator.Please try again." << endl;
                    is_invalid_input++;
                    is_syntax_error++;
                    break;
                }
                if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
                {
                    cout << "Invalid operands.Please try again." << endl;
                    is_invalid_input++;
                    is_syntax_error++;
                    break;
                }
            }
            while((pos < s.size()) && is_invalid_input == 0)
            {
                nextpos = s.find_first_of("+-",pos);
                if(nextpos == string::npos) break;
                if(s[nextpos+1] == '+' || s[nextpos+1] == '-' ||  s[nextpos+1] == '*' ||  s[nextpos+1] == '/' || nextpos == s.size()-1)
                {
                    cout << "Syntax error.Please try again." << endl;
                    is_syntax_error++;
                    break;
                }
                else
                {
                    pos = nextpos+1;
                }
            }
            if(is_syntax_error == 0)
            {
                stringstream ss(s);
                float num,sum = 0.0;
                char current_operator = '+';
                while(ss >> num)
                {
                    if(current_operator == '+') sum+=num;
                    else if(current_operator == '-') sum-=num;
                    ss >> current_operator;
                }
                cout << "The result is : " << sum << endl;
                flag++;
            }
            if(flag != 0) break;
        }
    }
    void calculate_sub()
    {
        calculate_add();
    }
    void calculate_multy()
    {
        while(1)
        {
            string s;
            cout << "Enter operands with operator : ";
            getline(cin >> ws,s);
            int pos = 0,nextpos,is_invalid_input = 0,is_syntax_error = 0,flag = 0;
            if(s[0] == '*' || s[0] == '/')
            {
                cout << "Invalid operator.Please try again." << endl;
            }
            else
            {
                for(int i = 0; i < s.size(); i++)
                {
                    if(s[i] == '+' || s[i] == '-')
                    {
                        if(s[i] != s[0])
                        {
                            cout << "Invalid operator.Please try again." << endl;
                            is_invalid_input++;
                            is_syntax_error++;
                            break;
                        }
                    }
                    if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
                    {
                        cout << "Invalid operands.Please try again." << endl;
                        is_invalid_input++;
                        is_syntax_error++;
                        break;
                    }
                }
                while((pos < s.size()) && is_invalid_input == 0)
                {
                    nextpos = s.find('*',pos);
                    if(nextpos == string::npos) break;
                    if(s[nextpos+1] == '+' || s[nextpos+1] == '-' ||  s[nextpos+1] == '*' ||  s[nextpos+1] == '/' || nextpos == s.size()-1)
                    {
                        cout << "Syntax error.Please try again." << endl;
                        is_syntax_error++;
                        break;
                    }
                    else
                    {
                        pos = nextpos+1;
                    }
                }
                if(is_syntax_error == 0)
                {
                    stringstream ss(s);
                    float num,multy = 1.0;
                    char current_operator = '*';
                    while(ss >> num)
                    {
                        multy*=num;
                        ss >> current_operator;
                    }
                    cout << "The result is : " << multy << endl;
                    flag++;
                }
                if(flag != 0) break;
            }

        }
    }
    void calculate_div()
    {
        while(1)
        {
            string s;
            cout << "Enter operands with operator : ";
            getline(cin >> ws,s);
            int pos = 0,nextpos,is_invalid_input = 0,is_syntax_error = 0,flag = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '+' || s[i] == '-' || s[i] == '*')
                {
                    if(s[i] != s[0] || s[0] == '*')
                    {
                        cout << "Invalid operator.Please try again." << endl;
                        is_invalid_input++;
                        is_syntax_error++;
                        break;
                    }
                }
                if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
                {
                    cout << "Invalid operands.Please try again." << endl;
                    is_invalid_input++;
                    is_syntax_error++;
                    break;
                }
            }
            while((pos < s.size()) && is_invalid_input == 0)
            {
                nextpos = s.find('*',pos);
                if(nextpos == string::npos) break;
                if(s[nextpos+1] == '+' || s[nextpos+1] == '-' ||  s[nextpos+1] == '*' ||  s[nextpos+1] == '/' || nextpos == s.size()-1)
                {
                    cout << "Syntax error.Please try again." << endl;
                    is_syntax_error++;
                    break;
                }
                else
                {
                    pos = nextpos+1;
                }
            }
            if(is_syntax_error == 0)
            {
                stringstream ss(s);
                int c = 0;
                float num,div;
                char current_operator = '/';
                while(ss >> num)
                {
                    if(c == 0)
                    {
                        div=num;
                        c++;
                    }
                    else
                    {
                        div/=num;
                    }
                    ss >> current_operator;
                }
                cout << "The result is : " << div << endl;
                flag++;
            }
            if(flag != 0) break;
        }
    }
    int bigmod(int a,int b,int M)
    {
        if(b == 0) return 1 % M;
        int x = bigmod(a,b/2,M);
        x = (x*x) % M;
        if(b % 2 == 1) x = (x*a) % M;
        return x;
    }
    void calculate_big_mod()
    {
        while(1)
        {
            int a,b,M;
            bool flag = true;
            cout << "Enter a positive number and it's power : ";
            cin >> a >> b;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else if(a < 0 || b < 0)
            {
                if(a < 0 && b < 0)
                {

                    cout << "Number and power must be positive.Please try again." << endl;
                }
                else if(a < 0)
                {
                    cout << "Number must be positive.Please try again." << endl;
                }
                else
                {
                    cout << "Power must be positive.Please try again." << endl;
                }
            }
            else
            {
                cout << a << "^" << b << " mod __? : ";
                cin >> M;
                cout << "The result is : " << bigmod(a,b,M) << endl;
                break;
            }
        }
    }
    void calculate_square_rt()
    {
        while(1)
        {
            long long n;
            float ans;
            cout << "Enter the number : ";
            cin >> n;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                ans = sqrt(n);
                if(n < 0) cout << "Invalid number.Please try again." << endl;
                else
                {
                    cout << "sqrt(" << n << ") = " << ans << endl;
                    break;
                }
            }
        }
    }
    void calculate_power()
    {
        while(1)
        {
            long long n,p,ans;
            cout << "Enter the number and its power : ";
            cin >> n >> p;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                ans = pow(n,p);
                if(ans < INT_MIN)
                {
                    cout << "The result is out of range(INT_MAX)." << endl;
                    break;
                }
                else
                {
                    cout << n << "^" << p << " = " << ans << endl;
                    break;
                }
            }
        }
    }
    void calculate_fact()
    {
        while(1)
        {
            long long num,fact = 1,temp;
            cout << "Enter the number(1 to 20) : ";
            cin >> num;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                temp = num;
                for(int i = 0; i < temp; i++)
                {
                    fact = fact*num;
                    num--;
                }
                if(temp <= 20)
                {
                    cout << temp << "! = " << fact << endl;
                    break;
                }
                else cout << "The result is out of range.Please enter a valid number." << endl;
            }
        }
    }
    void calculate_fibo()
    {
        while(1)
        {
            int n;
            cout << "Enter the series number : ";
            cin >> n;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                int dp[n+1];
                dp[0] = 0;
                dp[1] = 1;
                cout << "Fibonacci series is(0 to " << n << ") : ";
                cout << dp[0] << " " << dp[1] << " ";
                for(int i = 2; i <= n; i++)
                {
                    dp[i] = dp[i-1]+dp[i-2];
                    cout << dp[i] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    long long fact(long long n)
    {
        if(n==0)
            return 1;
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }
    long long nCr(long long n, long long r)
    {
        return fact(n) / (fact(r) * fact(n - r));
    }
    void calculate_ncr()
    {
        while(1)
        {
            long long n,r;
            cout << "Enter the value of n and r : ";
            cin >> n >> r;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if(n < 0 || r < 0)
                {
                    cout << "Invalid input.Please try again." << endl;
                }
                else
                {
                    cout << n << "C" << r << " = " << nCr(n, r) << endl;
                    break;
                }
            }
        }
    }
    long long factorial(long long n)
    {
        if(n==0)
            return 1;
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }
    long long nPr(long long n, long long r)
    {
        return factorial(n) / (factorial(n - r));
    }
    void calculate_npr()
    {
        while(1)
        {
            long long n,r;
            cout << "Enter the value of n and r : ";
            cin >> n >> r;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if(n < 0 || r < 0)
                {
                    cout << "Invalid input.Please try again." << endl;
                }
                else
                {
                    cout << n << "P" << r << " = " << nPr(n, r) << endl;
                    break;
                }
            }
        }
    }
    void  calculate_sum_of_digits()
    {
        while(1)
        {
            cout << "Enter a positive number : ";
            string s;
            getline(cin >> ws,s);
            int sum = 0;
            bool flag = true;
            for(int i = 0; i < s.size(); i++)
            {
                if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||(s[i] >= 32 && s[i] <= 47))
                {
                    cout << "Invalid input.Please try again." << endl;
                    flag = false;
                    break;
                }
                sum = sum + (s[i] - '0');
            }
            if(flag)
            {
                cout << "The sum of the digits is : "<< sum << endl;
                break;
            }
        }
    }
    void calculate_decimal_to_binary()
    {
        while(1)
        {
            cout << "Enter the decimal number : ";
            string s;
            getline(cin >> ws,s);
            bool flag = true;
            for(int i = 0; i < s.size(); i++)
            {
                if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||(s[i] >= 32 && s[i] <= 47))
                {
                    if(s[0] != '+' && s[0] != '-')
                    {
                        cout << "Invalid input.Please try again." << endl;
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                if(s.size() > 10)
                {
                    cout << "The result is out of range.Please try again." << endl;
                    flag = false;
                }
            }
            if(flag)
            {
                cout << "The binary number of " << s << " is ";
                if(isdigit(s[0])) cout << "0";
                else if(s[0] == '+' || s[0] == '-')
                {
                    if(s[0] == '+') cout << "0";
                    else
                    {
                        cout << "1";
                        s.erase(0,1);
                    }
                }
                long long num = stoi(s);
                int binaryNum[32];
                int i = 0;
                while (num > 0)
                {
                    binaryNum[i] = num % 2;
                    num = num / 2;
                    i++;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    cout << binaryNum[j];
                }
                cout << "." << endl;
                break;
            }
        }
    }
    void calculate_decimal_to_octal()
    {
        while(1)
        {
            cout << "Enter the decimal number : ";
            string s;
            getline(cin >> ws,s);
            bool flag = true;
            for(int i = 0; i < s.size(); i++)
            {
                if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||(s[i] >= 32 && s[i] <= 47))
                {
                    if(s[0] != '+' && s[0] != '-')
                    {
                        cout << "Invalid input.Please try again." << endl;
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                if(stof(s) > INT_MAX)
                {
                    cout << "The result is out of range.Please try again." << endl;
                    flag = false;
                }
            }
            if(flag)
            {
                cout << "The octal number of " << s << " is ";
                if(s[0] == '-')
                {
                    cout << "-";
                    s.erase(0,1);
                }
                int num = stoi(s);
                int octalNum[32];
                int i = 0;
                while (num > 0)
                {
                    octalNum[i] = num % 8;
                    num = num / 8;
                    i++;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    cout << octalNum[j];
                }
                cout << "." << endl;
                break;
            }
        }
    }
    void calculate_decimal_to_hexadecimal()
    {
        while(1)
        {
            cout << "Enter the decimal number : ";
            string s,str = "";
            getline(cin >> ws,s);
            bool flag = true;
            for(int i = 0; i < s.size(); i++)
            {
                if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||(s[i] >= 32 && s[i] <= 47))
                {
                    if(s[0] != '+' && s[0] != '-')
                    {
                        cout << "Invalid input.Please try again." << endl;
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                if(stof(s) > INT_MAX)
                {
                    cout << "The result is out of range.Please try again." << endl;
                    flag = false;
                }
            }
            if(flag)
            {
                cout << "The hexadecimal number of " << s << " is ";
                if(s[0] == '-')
                {
                    cout << "-";
                    s.erase(0,1);
                }
                int num = stoi(s);
                while (num != 0)
                {
                    int remainder = 0;
                    char chr;
                    remainder = num % 16;
                    if (remainder < 10)
                    {
                        chr = remainder + 48;
                    }
                    else
                    {
                        chr = remainder + 55;
                    }
                    str += chr;
                    num = num / 16;

                }
                for(int i = str.size()-1; i >= 0; i--)
                {
                    cout << str[i];
                }
                cout << "." << endl;
                break;
            }
        }
    }
    void calculate_prime_num()
    {
        while(1)
        {
            int i, n;
            bool is_prime = true;
            cout << "Enter the number: ";
            cin >> n;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if(n < 0) cout << n << " is not a prime number." << endl;
                else
                {
                    if (n == 0 || n == 1)
                    {
                        is_prime = false;
                    }

                    for (i = 2; i <= n/2; ++i)
                    {
                        if (n % i == 0)
                        {
                            is_prime = false;
                            break;
                        }
                    }
                    if (is_prime)
                        cout << n << " is a prime number." << endl;
                    else
                        cout << n << " is not a prime number." << endl;
                }
                break;
            }
        }

    }
    void calculate_palindrome()
    {
        while (1)
        {
            int flag = 0;
            cin.ignore(100, '\n');
            string s;
            cout << "Enter the string : ";
            getline(cin,s);
            for (int i = 0; i < s.size(); i++)
            {
                if (isspace(s[i]))
                {
                    cout << "Invalid input.Please try again." << endl;
                    break;
                }
                flag++;
            }
            if (flag == s.size())
            {
                string p = s;
                reverse(p.begin(), p.end());
                if (s == p)
                {
                    cout << s << " is a palindrome." << endl;
                    break;
                }
                else
                {
                    cout << s << " is not a palindrome." << endl;
                    break;
                }
            }
        }
    }
    int gcd(int a,int b)
    {
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    int lcm(int a,int b)
    {
        return (a*b)/gcd(a,b);
    }
    int multiple_lcm(vector<int>& v)
    {
        int result = v[0];
        for(int i = 1; i < v.size(); i++)
        {
            result = lcm(result,v[i]);
        }
        return result;
    }
    void calculate_LCM()
    {
        while(true)
        {
            int num;
            cout << "Enter numbers : ";
            string s;
            getline(cin >> ws,s);
            stringstream ss(s);
            vector<int>v;
            bool flag = true;
            while(ss >> num)
            {
                v.push_back(num);
                if (num < 0)
                {
                    cout << "Invalid input. Please try again." << endl;
                    flag = false;
                    break;
                }
            }
            int result = multiple_lcm(v);
            if (flag && ss.eof() && result)
            {
                cout << "LCM(";
                for(auto i : v)
                {
                    if(i == v[v.size()-1])
                    {
                        cout << i;
                    }
                    else
                        cout << i << ", ";
                }
                cout << ") = ";
                cout << result << endl;
                break;
            }
            else if (!flag)
            {
                continue;
            }
            else
            {
                cout << "Invalid input.Please try again." << endl;
            }
        }
    }
    void calculate_GCD()
    {
        while (true)
        {
            string s;
            cout << "Enter numbers: ";
            getline(cin >> ws, s);
            stringstream ss(s);
            vector<int>v;
            int num, count = 0, GCD, num2;
            bool flag = true;
            while (ss >> num)
            {
                v.push_back(num);
                if (num < 0)
                {
                    cout << "Invalid input. Please try again." << endl;
                    flag = false;
                    break;
                }
                count++;
                if (count == 1)
                {
                    num2 = num;
                }
                else if (count == 2)
                {
                    GCD = __gcd(num2, num);
                }
                else
                {
                    GCD = __gcd(GCD, num);
                }
            }
            if (flag && ss.eof())
            {
                cout << "GCD(";
                for(auto i : v)
                {
                    if(i == v[v.size()-1])
                    {
                        cout << i;
                    }
                    else
                        cout << i << ", ";
                }
                cout << ") = ";
                cout << GCD << endl;
                break;
            }
            else if (!flag)
            {
                continue;
            }
            else
            {
                cout << "Invalid input.Please try again." << endl;
            }
        }
    }
    void Merge(int arr[],int left,int mid,int right)
    {
        int size_l = mid - left+1;
        int size_r = right - mid;
        int L[size_l+1],R[size_r+1];
        for(int i = 0; i < size_l; i++)
        {
            L[i]= arr[left+i];
        }
        for(int i = 0; i < size_r; i++)
        {
            R[i]= arr[mid+1+i];
        }
        L[size_l] = R[size_r] = INT_MAX;
        int index_l = 0,index_r = 0;
        for(int i = left; i <= right; i++)
        {
            if(L[index_l] <= R[index_r])
            {
                arr[i] = L[index_l];
                index_l++;
            }
            else
            {
                arr[i] = R[index_r];
                index_r++;
            }
        }
    }
    void merge_sort(int arr[],int left,int right)
    {
        if(left == right) return;
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }

    void get_ascending_order()
    {
        while(1)
        {
            int n;
            cout << "Enter the amount of number : ";
            cin >> n;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                int arr[n];
                cout << "Before sorting : ";
                for(int i = 0; i< n; i++)
                {
                    cin >> arr[i];
                }
                merge_sort(arr,0,n-1);
                cout << "After  sorting : ";
                for(int i = 0; i< n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    void get_descending_order()
    {
        while(1)
        {
            int n;
            cout << "Enter the amount of number : ";
            cin >> n;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                int arr[n];
                cout << "Before sorting : ";
                for(int i = 0; i< n; i++)
                {
                    cin >> arr[i];
                }
                merge_sort(arr,0,n-1);
                cout << "After  sorting : ";
                for(int i = n-1; i>= 0; i--)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    void  calculate_sorting()
    {
        bool flag = true;
        int choice;
        cout << "=====================\n";
        cout << "1. Ascending order.\n";
        cout << "2. Descending order.\n";
        cout << "=====================\n";
        while(flag)
        {
            cout << "Enter your choice : ";
            cin >> choice;
            if(cin.fail())
            {
                cout << "Invalid choice.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                flag = true;
            }
            else
            {
                switch(choice)
                {
                case 1:
                    get_ascending_order();
                    flag = false;
                    break;
                case 2:
                    get_descending_order();
                    flag = false;
                    break;
                default:
                    cout << "Invalid choice.Please try again." << endl;
                    break;
                }
            }
        }
    }
    void calculate_leap_year()
    {
        while(1)
        {
            int year;
            cout << "Enter a year: ";
            cin >> year;
            if(cin.fail())
            {
                cout << "Invalid input.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if(year < 0) cout << "Invalid year.Please try again." << endl;
                else
                {
                    if (year % 400 == 0)
                    {
                        cout << year << " is a leap year." << endl;
                        break;
                    }
                    else if (year % 100 == 0)
                    {
                        cout << year << " is not a leap year." << endl;
                        break;
                    }
                    else if (year % 4 == 0)
                    {
                        cout << year << " is a leap year." << endl;
                        break;
                    }
                    else
                    {
                        cout << year << " is not a leap year." << endl;
                        break;
                    }
                }
            }
        }
    }
    void calculate_AND_operator()
    {
        while(true)
        {
            string s;
            cout << "Enter numbers: ";
            getline(cin >> ws, s);
            stringstream ss(s);
            vector<int>v;
            int num, count = 0, ans, num2;
            bool flag = true;
            while (ss >> num)
            {
                v.push_back(num);
                if (num < 0)
                {
                    cout << "Invalid input. Please try again." << endl;
                    flag = false;
                    break;
                }
                count++;
                if (count == 1)
                {
                    num2 = num;
                }
                else if (count == 2)
                {
                    ans = (num2&num);
                }
                else
                {
                    ans =(ans&num);
                }
            }
            if (flag && ss.eof())
            {
                cout << "(";
                for(auto i : v)
                {
                    if(i == v[v.size()-1])
                    {
                        cout << i;
                    }
                    else
                        cout << i << "&";
                }
                cout << ") = ";
                cout << ans << endl;
                break;
            }
            else if (!flag)
            {
                continue;
            }
            else
            {
                cout << "Invalid input.Please try again." << endl;
            }
        }
    }
    void calculate_OR_operator()
    {
        while (true)
        {
            string s;
            cout << "Enter numbers: ";
            getline(cin >> ws, s);
            stringstream ss(s);
            vector<int>v;
            int num, count = 0, ans, num2;
            bool flag = true;
            while (ss >> num)
            {
                v.push_back(num);
                if (num < 0)
                {
                    cout << "Invalid input. Please try again." << endl;
                    flag = false;
                    break;
                }
                count++;
                if (count == 1)
                {
                    num2 = num;
                }
                else if (count == 2)
                {
                    ans = (num2|num);
                }
                else
                {
                    ans =(ans|num);
                }
            }
            if (flag && ss.eof())
            {
                cout << "(";
                for(auto i : v)
                {
                    if(i == v[v.size()-1])
                    {
                        cout << i;
                    }
                    else
                        cout << i << "|";
                }
                cout << ") = ";
                cout << ans << endl;
                break;
            }
            else if (!flag)
            {
                continue;
            }
            else
            {
                cout << "Invalid input.Please try again." << endl;
            }
        }
    }
    void calculate_NOT_operator()
    {
        while(true)
        {
            bool flag = false;
            int num;
            cout << "Enter the number : ";
            cin >> num;
            if(cin.fail())
            {
                cout << "Invalid choice.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                flag = true;
            }
            else
            {
                cout << "(~" << num << ") = " << (~num) << endl;
                break;
            }
        }
    }
    void calculate_XOR_operator()
    {
        while (true)
        {
            string s;
            cout << "Enter numbers: ";
            getline(cin >> ws, s);
            stringstream ss(s);
            vector<int>v;
            int num, count = 0, ans, num2;
            bool flag = true;
            while (ss >> num)
            {
                v.push_back(num);
                if (num < 0)
                {
                    cout << "Invalid input. Please try again." << endl;
                    flag = false;
                    break;
                }
                count++;
                if (count == 1)
                {
                    num2 = num;
                }
                else if (count == 2)
                {
                    ans = (num2^num);
                }
                else
                {
                    ans =(ans^num);
                }
            }
            if (flag && ss.eof())
            {
                cout << "(";
                for(auto i : v)
                {
                    if(i == v[v.size()-1])
                    {
                        cout << i;
                    }
                    else
                        cout << i << "^";
                }
                cout << ") = ";
                cout << ans << endl;
                break;
            }
            else if (!flag)
            {
                continue;
            }
            else
            {
                cout << "Invalid input.Please try again." << endl;
            }
        }
    }
    void calculate_Left_Shift_operator()
    {
        while(1)
        {
            int a,b;
            cout << "Enter the number and shifted number : ";
            cin >> a >> b;
            if(cin.fail())
            {
                cout << "Invalid choice.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if(b < 0)
                {
                    cout << "Shifted number must be positive.Please try again." << endl;
                }
                else
                {
                    cout << "(" << a << " >> " << b << ") = " << (a >> b) << endl;
                    break;
                }
            }
        }
    }
    void  calculate_Right_Shift_operator()
    {
        while(1)
        {
            int a,b;
            cout << "Enter the number and shifted number : ";
            cin >> a >> b;
            if(cin.fail())
            {
                cout << "Invalid choice.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if(b < 0)
                {
                    cout << "Shifted number must be positive.Please try again." << endl;
                }
                else
                {
                    cout << "(" << a << " << " << b << ") = " << (a << b) << endl;
                    break;
                }
            }
        }
    }
    void  calculate_bitwise_operator()
    {
        bool flag = true;
        int choice;
        cout << "===========================================================\n";
        cout << "1. AND(&)operator.\t\t";
        cout << "2. OR(|)operator.\n";
        cout << "3. NOT(~)operator.\t\t";
        cout << "4. XOR(^)operator.\n";
        cout << "5. Left-Shift(>>)operator.\t";
        cout << "6. Right-Shift(<<)operator.\n";
        cout << "===========================================================\n";
        while(flag)
        {
        cout << "Enter your choice : ";
        cin >> choice;
            if(cin.fail())
            {
                cout << "Invalid choice.please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                flag = true;
            }
            else
            {
                switch(choice)
                {
                case 1:
                    calculate_AND_operator();
                    flag = false;
                    break;
                case 2:
                    calculate_OR_operator();
                    flag = false;
                    break;
                case 3:
                    calculate_NOT_operator();
                    flag = false;
                    break;
                case 4:
                    calculate_XOR_operator();
                    flag = false;
                    break;
                case 5:
                    calculate_Left_Shift_operator();
                    flag = false;
                    break;
                case 6:
                    calculate_Right_Shift_operator();
                    flag = false;
                    break;
                default:
                    cout << "Invalid choice.Please try again." << endl;
                    break;
                }
            }
        }

    }
public:
    void get_sum()
    {
        calculate_add();
    }
    void get_sub()
    {
        calculate_sub();
    }
    void get_multy()
    {
        calculate_multy();
    }
    void get_div()
    {
        calculate_div();
    }
    void get_big_mod()
    {
        calculate_big_mod();
    }
    void get_square_rt()
    {
        calculate_square_rt();
    }
    void get_power()
    {
        calculate_power();
    }
    void get_fact()
    {
        calculate_fact();
    }
    void get_fibo()
    {
        calculate_fibo();
    }
    void get_ncr()
    {
        calculate_ncr();
    }
    void get_npr()
    {
        calculate_npr();
    }
    void get_sum_of_digits()
    {
        calculate_sum_of_digits();
    }
    void get_decimal_to_binary()
    {
        calculate_decimal_to_binary();
    }
    void get_decimal_to_octal()
    {
        calculate_decimal_to_octal();
    }
    void get_decimal_to_hexadecimal()
    {
        calculate_decimal_to_hexadecimal();
    }
    void get_prime_num()
    {
        calculate_prime_num();
    }
    void get_palindrome()
    {
        calculate_palindrome();
    }
    void get_LCM()
    {
        calculate_LCM();
    }
    void get_GCD()
    {
        calculate_GCD();
    }
    void get_sorting()
    {
        calculate_sorting();
    }
    void get_leap_year()
    {
        calculate_leap_year();
    }
    void get_bitwise_operator()
    {
        calculate_bitwise_operator();
    }
};
int main()
{
    cout << "**Welcome to programming Calculator**\n";
    cout << "**Name Of Operations**\n";
    cout << "======================================================\n";
    cout << "1.  Addition.\t\t\t";
    cout << "2.  Substraction.\n";
    cout << "3.  Multiplication.\t\t";
    cout << "4.  Division.\n";
    cout << "5.  Big mod.\t\t\t";
    cout << "6.  Square Root.\n";
    cout << "7.  Power.\t\t\t";
    cout << "8.  Factorial.\n";
    cout << "9.  Fibonacci.\t\t\t";
    cout << "10. ncr.\n";
    cout << "11. npr.\t\t\t";
    cout << "12. Sum of Digits.\n";
    cout << "13. Decimal to Binary.\t\t";
    cout << "14. Decimal to Octal.\n";
    cout << "15. Decimal to Hexa Decimal.\t";
    cout << "16. Prime Number.\n";
    cout << "17. Palindrome.\t\t\t";
    cout << "18. LCM.\n";
    cout << "19. GCD.\t\t\t";
    cout << "20. Sorting.\n";
    cout << "21. Leap Year.\t\t\t";
    cout << "22. Bitwise Operator.\n";
    cout << "======================================================\n";
    string ch;
    int choice;
    bool flag = false;
    calculator obj;
    do
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if(cin.fail())
        {
            cout << "Invalid choice.please try again." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            flag = true;
        }
        else
        {
            switch(choice)
            {
            case 1:
                obj.get_sum();
                flag = false;
                break;
            case 2:
                obj.get_sub();
                flag = false;
                break;
            case 3:
                obj.get_multy();
                flag = false;
                break;
            case 4:
                obj.get_div();
                flag = false;
                break;
            case 5:
                obj.get_big_mod();
                flag = false;
                break;
            case 6:
                obj.get_square_rt();
                flag = false;
                break;
            case 7:
                obj.get_power();
                flag = false;
                break;
            case 8:
                obj.get_fact();
                flag = false;
                break;
            case 9:
                obj.get_fibo();
                flag = false;
                break;
            case 10:
                obj.get_ncr();
                flag = false;
                break;
            case 11:
                obj.get_npr();
                flag = false;
                break;
            case 12:
                obj.get_sum_of_digits();
                flag = false;
                break;
            case 13:
                obj.get_decimal_to_binary();
                flag = false;
                break;
            case 14:
                obj.get_decimal_to_octal();
                flag = false;
                break;
            case 15:
                obj.get_decimal_to_hexadecimal();
                flag = false;
                break;
            case 16:
                obj.get_prime_num();
                flag = false;
                break;
            case 17:
                obj.get_palindrome();
                flag = false;
                break;
            case 18:
                obj.get_LCM();
                flag = false;
                break;
            case 19:
                obj.get_GCD();
                flag = false;
                break;
            case 20:
                obj.get_sorting();
                flag = false;
                break;
            case 21:
                obj.get_leap_year();
                flag = false;
                break;
            case 22:
                obj.get_bitwise_operator();
                flag = false;
                break;
            default:
                cout << "Invalid choice.Please try again." << endl;
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout << "Do you want to continue?(Yes or No)" << endl;
            cin >> ch;
            if(ch == "Yes" || ch == "YES" || ch == "yeS" ||  ch == "YEs" ||  ch == "yEs" || ch == "yES" ||  ch == "YeS" ||  ch == "yes")
            {
                cout << endl;
            }
        }
    }
    while(ch == "Yes" || ch == "YES" || ch == "yeS" ||  ch == "YEs" ||  ch == "yEs" || ch == "yES" ||  ch == "YeS" ||  ch == "yes" || flag);
    cout << "**Thank you for using me.**" << endl;
    return 0;
}
