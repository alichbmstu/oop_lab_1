#include "tests.hpp"

using std::cout, std::endl;

void printt();
void constructors_1();
void get_len();
void operator_check();
void contains_check();
void add_check();
void remove_check();
void to_arr_check();
void union_check();
void intersection_check();
void subtract_check();
void plus_equals();
void multyplay_equals();
void division_equals();
void containing(Set<int> s, int a);
void plus_check();
void multiplay_check();
void division_check();
void itr_begin();
void itr_end();
void property_check();

void tests(){
    constructors_1 ();
    operator_check();
    get_len();
    contains_check();
    add_check();
    remove_check();
    to_arr_check();
    union_check();
    intersection_check();
    subtract_check();
    plus_equals();
    multyplay_equals();
    division_equals();
    plus_check();
    multiplay_check();
    division_check();
    cout << "\033[0m" << endl; //меняю цвет обратно для наблюдателя
    itr_begin();
    itr_end();
    property_check();
}

void printt(){
    cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
}

void constructors_1 () {
    cout<< "Constructor" << endl;
    Set<int> s{1, 2, 3};
    cout<< "Set from code: {1, 2, 3}" << endl;
    cout<< "Set after constructor: "<< s << endl;
    Set<int> b = std::move(s);
    cout<< "Another set like s constructor: "<< b << endl;
    printt();

}

void operator_check(){
    cout<< "Check operator = " << endl;
    Set<int> a{1, 2, 3, 4};
    Set <int>b;
    cout<< "First set from code: "<< a << endl;
    cout<< "Second set from code: "<< b << endl;
    b = a;
    cout<< "After equating second to first is: " << b << endl;
    printt();
    Set<int> c{1, 2, 3, 4};
    Set<int> d{1, 5, 6, 8};
    cout<< "Third set from code: "<< c << endl;
    cout<< "Fourth set from code: "<< d << endl;
    c = d;
    cout<< "After equating 3th to 4th is: " << c << endl;
    printt();
}

void get_len(){
    std::cout<< "Check length of set" << std::endl;
    Set<int> s{1, 2, 3, 5};
    std::cout<< "Set from code: "<< s << std::endl;
    std::cout<< "Length of set: "<< s.get_length()<< std::endl;
    printt();
    std::cout<< "Check length of empty set" << std::endl;
    Set<int> s1{};
    std::cout<< "Set from code: "<< s1 << std::endl;
    std::cout<< "Length of set: "<< s1.get_length()<< std::endl;
    printt();
}

void contains_check(){
    std::cout<< "Check contains of elements" << std::endl;
    Set<int> s{1, 2, 3, 5, 6};
    cout<< "Set from code:"<< s << endl;
    containing(s, 1);
    containing(s, 7);
}

void containing(Set<int> s, int a){
    cout<< "Is element "<<a<<" contained in the set?"<< endl;
    if (s.contains(a)){
        cout<< "Yes" << endl;
    } else{
        cout<< "No" << endl;
    }
    printt();
}

void add_check(){
    cout<< "Check add of new elements" << endl;
    Set<int> s{1, 2, 3, 5, 6};
    cout<< "The original set: "<< s << endl;
    s.add(1);
    cout<< "Add element 1: "<< s << endl;
    s.add(4);
    cout<< "Add element 4: "<< s << endl;
    s.add(7);
    cout<< "Add element 7: "<< s << endl;
    s.add(-3);
    cout<< "Add element -3: "<< s << endl;
    printt();
}

void remove_check(){
    cout<< "Check remove element" << endl;
    Set<int> s{1, 2, 30, 4, 500, 6};
    cout<< "The origin set is: "<< s << endl;
    s.remove(30);
    cout<< "Remove element 30: "<< s << endl;
    cout<< "Remove element 7: ";
    try {
       s.remove(7);
    } catch(Exceptions &ex) {
       cout<< ex;
    }
    printt();
}

void to_arr_check(){
    cout<< "Array is like set" << endl;
    Set<int> s{1, 2, 30, 4, 500, 6};
    cout<< "Set from code: "<< s << endl;
    try {
        int *arr = s.to_array();
        std::cout<< "Array: ";
        for (int i = 0; i < s.get_length(); ++i)
            std::cout<<arr[i]<< " ";
        std::cout<<std::endl;
        std::cout<< "Reverse array: ";
        for (int i = s.get_length() - 1; i >= 0; --i)
            std::cout<<arr[i]<< " ";
        std::cout<<std::endl;
        delete[]arr;
    } catch (Exceptions& ex) {
        cout << ex << endl;
    }
    printt();
}

void union_check(){
    cout<< "Union a with b" << endl;
    Set<int> a{1, 4, 7, 8, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "Set a from code: "<< a << endl;
    cout<< "Set b from code: "<< b << endl;
    a.union_1(b);
    cout<< "Union sets: "<< a << endl;
    printt();
    cout<< "Union c with c" << endl;
    Set<int> c{7, 8, 9, 10};
    cout<< "Set c from code: "<< c << endl;
    c.union_1(c);
    cout<< "Union sets: "<< c << endl;
    printt();
    cout<< "Union b with empty set e" << endl;
    Set<int> e;
    cout<< "Set b from code: "<< b << endl;
    cout<< "Set e from code: "<< e << endl;
    b.union_1(e);
    cout<< "Union sets: "<< b << endl;
    printt();
}

void intersection_check(){
    std::cout<< "Intersection a with b" << std::endl;
    Set<int> a{1, 2, 6, 10};
    Set<int> b{1, 2, 3, 4, 5, 6};
    std::cout<< "Set a from code: "<< a << std::endl;
    std::cout<< "Set b from code: "<< b << std::endl;
    a.intersection(b);
    std::cout<< "Intersection sets: "<< a << std::endl;
    printt();
    std::cout<< "Intersection c with c" << std::endl;
    Set<int> c{7, 8, 9, 10};
    std::cout<< "Set c from code: "<< c << std::endl;
    c.intersection(c);
    std::cout<< "Intersection sets: "<< c << std::endl;
    printt();
    std::cout<< "Intersection b with empty set e" << std::endl;
    Set<int> e;
    std::cout<< "Set b from code: "<< b << std::endl;
    std::cout<< "Set e from code: "<< e << std::endl;
    b.intersection(e);
    std::cout<< "Intersection sets: "<< b << std::endl;
    printt();
}

void subtract_check(){
    std::cout<< "Subtract a with b" << std::endl;
    Set<int> a{1, 2, 6, 10};
    Set<int> b{1, 2, 3, 4, 5, 6};
    std::cout<< "Set a from code: "<< a << std::endl;
    std::cout<< "Set b from code: "<< b << std::endl;
    try {
        a.subtract(b);
        std::cout<< "Intersection sets: "<< a << std::endl;
    } catch(Exceptions &ex) {
        std::cout<< ex;
    }
    printt();
    std::cout<< "Subtract c with c" << std::endl;
    Set<int> c{7, 8, 9, 10};
    std::cout<< "Set c from code: "<< c << std::endl;
    try {
        c.subtract(c);
        std::cout<< "Intersection sets: "<< c << std::endl;
    } catch(Exceptions &ex) {
        std::cout<< ex;
    }
    printt();
    std::cout<< "Subtract b with empty set e" << std::endl;
    Set<int> e;
    std::cout<< "Set b from code: "<< b << std::endl;
    std::cout<< "Set e from code: "<< e << std::endl;
    try {
       b.subtract(e);
    } catch(Exceptions &ex) {
        std::cout<< ex;
    }
    printt();
}

void plus_equals(){
    cout<< "Plus and equal a with b" << endl;
    Set<int> a{1, 4, 7, 8, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "Set a from code: "<< a << endl;
    cout<< "Set b from code: "<< b << endl;
    a+=b;
    cout<< "After plus_equals operand: "<< a << endl;
    printt();
    cout<< "Plus and equal h with j" << endl;
    Set<int> h{-1, -4, 70};
    Set<int> j{1, 2, 3, 4};
    cout<< "Set h from code: "<< h << endl;
    cout<< "Set j from code: "<< j << endl;
    h+=j;
    cout<< "After plus_equals operand: "<< h << endl;
    printt();
}

void multyplay_equals(){
    cout<< "Multiplay and equal a with b" << endl;
    Set<int> a{1, 4, 7, 8, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "Set a from code: "<< a << endl;
    cout<< "Set b from code: "<< b << endl;
    a*=b;
    cout<< "After Multiplay_equals operand: "<< a << endl;
    printt();
    cout<< "Multiplay and equal h with j" << endl;
    Set<int> h{1, -4, 70};
    Set<int> j{1, 2, 3, 4};
    cout<< "Set h from code: "<< h << endl;
    cout<< "Set j from code: "<< j << endl;
    h*=j;
    cout<< "After Multiplay_equals operand: "<< h << endl;
    printt();
}

void division_equals(){
    cout<< "Division and equal long with short" << endl;
    Set<int> a{1, 4, 7, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "Long set from code: "<< a << endl;
    cout<< "Short set from code: "<< b << endl;
    a/=b;
    cout<< "After division_equals operand: "<< a << endl;
    printt();
    cout<< "Division and equal h with j" << endl;
    Set<int> h{1, -4, 70};
    Set<int> j{1, 2, 3, 4};
    cout<< "Set h is : "<< h << endl;
    cout<< "Set j is : "<< j << endl;
    h/=j;
    cout<< "After division_equals operand: "<< h << endl;
    printt();
}

void plus_check(){
    cout<< "Plus operator check" << endl;
    Set<int> a{1, 4, 7, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "First of sets: "<< a << endl;
    cout<< "Second of sets: "<< b << endl;
    cout<< "After plus operand: "<< a+b << endl;
    printt();
    cout<< "2th plus operator check" << endl;
    Set<int> h{1, -4, 70};
    Set<int> j{1, 2, 3, 4};
    Set<int> k{10, 0, 7, 4, 5};
    cout<< "Sets are: "<< h << " and "<< j << " and "<< k <<endl;
    cout<< "After plus operand: "<< h+j+k << endl;
    printt();
}

void multiplay_check(){
    cout<< "Multiplay operator check" << endl;
    Set<int> a{1, 4, 7, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "First set: "<< a << endl;
    cout<< "Second set: "<< b << endl;
    cout<< "After multiplay operand: "<< a*b << endl;
    printt();
    cout<< "2th multiplay operator check" << endl;
    Set<int> h{1, -4, 0, 70, 5};
    Set<int> j{1, 2, 0, 3, 4, 5};
    Set<int> k{10, 0, 7, 4, 5};
    cout<< "Sets are: "<< h << " and "<< j << " and "<< k <<endl;
    cout<< "After multiplay operand: "<< h*j*k << endl;
    printt();
}

void division_check(){
    cout<< "Division operator check" << endl;
    Set<int> a{1, 4, 7, 9, 10};
    Set<int> b{1, 2, 3, 4};
    cout<< "First set: "<< a << endl;
    cout<< "Second set: "<< b << endl;
    cout<< "After division operand: "<< a/b << endl;
    printt();
    cout<< "2th division operator check" << endl;
    Set<int> h{1, -4, 0, 70, 5};
    Set<int> j{1, 2, 0, 3, 4, 5};
    cout<< "Sets are: "<< h << " and "<< j <<endl;
    cout<< "After division operand: "<< h/j<< endl;
    printt();
}

void itr_begin(){
    cout<< "Iterator begin check" << endl;
    Set<int> g{4, 7, 9, 10};
    Set<int> a(g);
    cout<< "First set: "<< a << endl;
    Iterator<int> val = a.iterator_begin();
    try {
        int v = val.value();
        cout<< "Element of begin index: "<< v << endl;
    } catch(Exceptions &ex){
        cout<<ex<<endl;
    }
    printt();
}

void itr_end(){
    cout<< "Iterator end check" << endl;
    Set<int> g{4, 7, 9, 10};
    Set<int> a(g);
    cout<< "First set: "<< a << endl;
    Iterator<int> val = a.iterator_end();
    try {
        val.value();
    } catch(Exceptions &ex){
        cout<<ex<<endl;
    }
    printt();
}

void property_check() {
    Set<int> set{1,2,3,4,5,6,7,8,9,10};
    SetSizeProperty sizeProperty(set, 0, 100);
    try {
       sizeProperty.setter(5);
       cout << "Set after property: " << sizeProperty << endl;
       cout << "Size of set: " << sizeProperty.get() << endl;
    } catch(Exceptions &ex) {
       cout<< ex;
    }
    printt();
    try {
       sizeProperty.setter(-1);
       cout << "Set values: " << sizeProperty << endl;
       cout << "Size of set: " << sizeProperty.get() << endl;
    } catch(Exceptions &ex) {
       cout<< ex;
    }
    printt();
}
