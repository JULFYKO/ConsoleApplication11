#include <iostream>
#include <string>
using namespace std;

class Test {
public:
    const char* cStr = "my text";
    const string* cppStr = new string("my test");
    const int fld = 42;

    void testCString() {
        char arr[] = "my text";
        const char* t = arr;
        char* mod = const_cast<char*>(t);
        cout << "Original: " << t << endl;
        mod[0] = 'M';
        cout << "Modified: " << mod << endl;
    }

    void testCppString() {
        const string* ps = cppStr;
        string* mod = const_cast<string*>(ps);
        cout << "Original: " << *ps << endl;
        mod->append(" modified");
        cout << "Modified: " << *mod << endl;
        delete cppStr;
    }

    void testConstField() {
        const int& fldRef = fld;
        int& mod = const_cast<int&>(fldRef);
        cout << "Original: " << fld << endl;
        mod = 0;
        cout << "Modified: " << fld << endl;
    }
};

int main() {
    Test test;

    cout << "C-string" << endl;
    test.testCString();

    cout << "C++ string" << endl;
    test.testCppString();

    cout << "Const field" << endl;
    test.testConstField();

    return 0;
}
