

#include <iostream>
#include <vector>

using namespace std;

string to_string(int val)
{ 
    char buff[32];
    sprintf_s(buff, "%d", val);
    return string(buff);
}

class sub 
{
private:
    vector<pair<int, int>> arr; 
public:
    sub(int count, int begin, int Y) 
    { 
        for (int i = begin; i < begin + count; i++) 
        { 
            arr.reserve(sizeof(pair<int, int>) * count); 
            arr.push_back(make_pair(i, Y));
        }
    }
    string show(int N) 
    { 
        string buf = ""; 
        vector<pair<int, int>>::iterator i, b;
        for (i = b = arr.begin(); i != arr.end(); i++)
            if (i - b == 0 || i + 1 == arr.end() || (i - b + 1) % N == 0) 
            {
                buf += string(" (") + to_string(arr[i - b].first) + string(", ") + to_string(arr[i - b].second) + string(")");
                if (i + 1 != arr.end()) buf += ",";
            }
        return buf;
    }
};

vector<sub> indications; 

void hard_load(vector<sub>& v) 
{
    
    v.push_back(sub(1, 1, 10));
    v.push_back(sub(4, 2, 11));
    v.push_back(sub(1, 6, 10));
    v.push_back(sub(4, 7, 11));
    v.push_back(sub(1, 11, 10));
    cout << endl;
}

int main(int argc, char* argv[])
{
    hard_load(indications);
    string myout = "";
    
    vector<sub>::iterator i, b;
    for (int N = 1; N < 5; N++) 
    { 
        if (N == 1) myout = " First line: "; 
        else myout = string("Result for N=") + to_string(N) + string(": ");
        for (i = b = indications.begin(); i != indications.end(); i++)
            myout += indications[i - b].show(N);
        cout << myout.c_str();
    }
    return 0;
}



