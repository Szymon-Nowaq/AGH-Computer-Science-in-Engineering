#include <iostream>
#include <string>
using namespace std;

class President{
public:
    string name;
    string party;
    int years;
    int start;
    int end;

    President(string n, string p, int y, int s, int e) : name(n), party(p), years(y), start(s), end(e) {}
    President() : years(0), name(""), party(""), start(0), end(0) {}

    void show(){
        cout<<"name: "<<name<<"\nparty:"<<party<<"\nyears:"<<years<<"\nstart:"<<start<<"\nend:"<<end<<endl;
    }
};

class Object{
public:
    President president;
    Object *next;
    Object *prev;
    int index;

    Object(President pr, Object *n, Object *p, int i) : president(pr), next(n), prev(p), index(i) {}
    Object(President pr, int i) : president(pr), index(i), next(nullptr), prev(nullptr) {}
    Object() : next(nullptr), prev(nullptr), president(President()), index(0) {}

    void show(){
        cout<<"index: "<<index<<endl;
        president.show();
    }
};

class TwoWayList{
public:
    Object* head;
    Object* tail;
    int count = 0;

    TwoWayList() : head(nullptr), tail(nullptr) {}

    void append(President prs){
        Object* newObj = new Object(prs, count);
        count++;
        if(head == nullptr){
            head = newObj;
            tail = newObj;
        }else{
            newObj->prev = tail;
            tail->next = newObj;
            tail = newObj;
        }
    }

    void show(){
        Object* current = head;
        while(current != nullptr){
            if(current->index != 0)
                cout<<"\t↑\n\t↓"<<endl;
            current->show();
            current = current->next;
        }
        cout<<"End of the list\n\n\n";
    }

    TwoWayList getShortestCadence() {
        Object *current = head;
        int min = current->president.years;
        for (int i = 0; i < count; i++) {
            if (current->president.years < min)
                min = current->president.years;
            current = current->next;
        }
        Object *current2 = head;
        TwoWayList list;
        for(int i = 0; i < count; i++) {
            if (current2->president.years == min)
                list.append(current2->president);
            current2 = current2->next;
        }
        return list;
    }

    TwoWayList getAllFromParty(string party){
        TwoWayList list;
        Object* current = head;
        for(int i = 0; i < count; i++){
            if(current->president.party == party)
                list.append(current->president);
            current = current->next;
        }
        return list;
    }

    TwoWayList getPrsdByYear(int year){
        TwoWayList list;
        Object* current = head;
        for(int i = 0; i < count; i++){
            if(current->president.start <= year && year <= current->president.end)
                list.append(current->president);
            current = current->next;
        }
        return list;
    }
};

int main() {
    string names[25] = {"George Washington","John Adams","Thomas Jefferson","James Madison","James Monroe","John Quincy Adams","Andrew Jackson","Martin Van Buren","William Henry Harrison","John Tyler","James K. Polk","Zachary Taylor","Millard Fillmore","Franklin Pierce","James Buchanan","Abraham Lincoln","Andrew Johnson","Ulysses S. Grant","Rutherford B. Hayes","James A. Garfield","Chester A. Arthur","Grover Cleveland","Benjamin Harrison","Grover Cleveland","William McKinley"};
    string party[25] = {"Unaffiliated","Federalist","Democratic-Republican","Democratic-Republican","Democratic-Republican","Democratic-Republican","Democratic","Democratic","Whig","Whig","Democratic","Whig","Whig","Democratic","Democratic","Republican","Democratic","Republican","Republican","Republican","Republican","Democratic","Republican","Democratic","Republican"};
    int start[25] = {1789 , 1797 , 1801 , 1809 , 1817 , 1825 , 1829 , 1837 , 1841 , 1841 , 1845 , 1849 , 1850 , 1853 , 1857 , 1861 , 1865 , 1869, 1877 , 1881 , 1881 , 1885 , 1889 , 1893 , 1897};
    int end[25] = {1797 , 1801 , 1809 , 1817 , 1825 , 1829 , 1837 , 1841 , 1841 , 1845 , 1849 , 1850 , 1853 , 1857 , 1861 , 1865 , 1869 , 1877, 1881 , 1881 , 1885 , 1889 , 1893 , 1897 , 1901};
    int ruleYears[25] = {8 , 4 , 8 , 8 , 8 , 4 , 8 , 4 , 0 , 4 , 4 , 1 , 3 , 4 , 4 , 4 , 4 , 8 , 4 , 0 , 4 , 4 , 4 , 4 , 4};

    TwoWayList usa;
    for(int i = 0; i < 25; i++)
        usa.append(President(names[i], party[i], ruleYears[i], start[i], end[i]));
    //usa.show();

    //zad 1
    TwoWayList shrCadence = usa.getShortestCadence();
    shrCadence.show();

    //zad 2
    TwoWayList republicans = usa.getAllFromParty("Republican");
    republicans.show();

    //zad 3
    TwoWayList prsd_1841 = usa.getPrsdByYear(1841);
    prsd_1841.show();

    return 0;
}
