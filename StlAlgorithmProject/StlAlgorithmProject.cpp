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

    friend bool operator==(const User& u1, const User& u2)
    {
        return u1.name == u2.name;
    }
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
    /*ContainerInit(v.begin(), v.end());
    ContainerPrint(v.begin(), v.end());
    for (int item : v)
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
    users.push_back(User("Leo", 31));
    users.push_back(User("Bill", 52));
    users.push_back(User("Tom", 52));
    users.push_back(User("Joe", 42));
    users.push_back(User("Joe", 42));
    users.push_back(User("Sam", 37));


    /*
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

    cout << none_of(users.begin(), users.end(),
        [](User user)
        {
            return user.Name().length() > 3;
        }) << "\n";
    cout << count_if(users.begin(), users.end(),
        [](User user) {
            return user.Age() > 30;
        }) << "\n";
    */

    vector<int> v1{ 3, 9, 4, 0, 0, 5, 7, 7, 8, 2, 9, 4, 5, 1 };
    list<int> l1{ 1, 5, 7, 0};

    /*auto it = find_end(v1.begin(), v1.end(), ++l1.begin(), --l1.end());
    for (; it < v1.end(); it++)
        cout << *it << " ";
    cout << "\n";

    it = find_first_of(v1.begin(), v1.end(), ++l1.begin(), --l1.end());
    for (; it != v1.end(); it++)
        cout << *it << " ";
    cout << "\n";*/

    /*auto it = adjacent_find(v1.begin(), v1.end());
    for (; it != v1.end(); it++)
        cout << *it << " ";
    cout << "\n";*/

    /*auto it = adjacent_find(users.begin(),
        users.end(),
        [](User u1, User u2)
        {
            return u1.Name() == u2.Name() && u1.Age() == u2.Age();
        });

    for (; it != users.end(); it++)
        cout << *it << "\n";
    cout << "\n";*/

    /*auto it = search(v1.begin(), v1.end(), ++l1.begin(), --l1.end());
    for (; it != v1.end(); it++)
        cout << *it << " ";
    cout << "\n";*/

    string str = "5610010001110010101001010010067";
    
    auto it = search_n(str.begin() + 2, str.end() - 2, 4, '0');
    
    if (it != str.end() - 2)
    {
        for (; it != str.end(); it++)
            cout << *it << " ";
        cout << "\n";
    }
    else
        cout << "not found\n";
    
}
