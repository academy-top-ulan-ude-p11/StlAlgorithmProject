#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name, int age) : name{ name }, age{ age } {}
    friend ostream& operator<<(ostream& out, const User& u)
    {
        out << "(" << u.name << ") - [" << u.age << "]";
        return out;
    }
    string& Name(){ return name; }
    int& Age() { return age; }
};

template <class Iterator>
void ContainerInit(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        *begin = rand() % 11;
        begin++;
    }
}

template <class Iterator>
void ContainerPrint(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        cout << *begin << " ";
        begin++;
    }
    cout << "\n";
}

int main()
{
    srand(time(nullptr));
    vector<int> v(10);
    ContainerInit(v.begin(), v.end());
    ContainerPrint(v.begin(), v.end());
    /*for (int item : v)
        cout << item << " ";
    cout << "\n";*/

    /*for_each(v.begin(), v.end(),
        [](auto item) {
            item = 10;
        });
    cout << "\n";*/

    /*for_each(v.begin(), v.end(),
        [](auto item) {
            cout << item << " ";
        });
    cout << "\n";*/

    list<User> users;
    users.push_back(User("Bob", 34));
    users.push_back(User("Tim", 22));
    users.push_back(User("Leo", 19));
    //users.push_back(User("Bill", 52));
    users.push_back(User("Joe", 42));
    users.push_back(User("Sam", 37));


    
    cout << boolalpha << none_of(v.begin(), 
        v.end(), 
        [](auto item) 
        { 
            return item % 2 == 0; 
        }) << "\n";
    cout << count(v.begin(), v.end(), 5) << "\n";
    cout << count_if(v.begin(), v.end(),
        [](auto item) {
            return item > 5;
        }) << "\n";
    //cout << *(find(v.begin(), v.end(), 5)) << "\n";
    cout << *(find_if(v.begin(), v.end(),
        [](auto item) {
            return item % 2 == 0;
        })) << "\n";

    /*cout << none_of(users.begin(), users.end(),
        [](User user)
        {
            return user.Name().length() > 3;
        }) << "\n";*/
    cout << count_if(users.begin(), users.end(),
        [](User user) {
            return user.Age() > 30;
        }) << "\n";
}
