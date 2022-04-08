#include <iostream>
#include <map>
#include <concepts>

template <typename T>
concept myconcept =  std::is_integral_v<T> ;

template <typename T>
requires myconcept<T> 
T func( T a ,  T b ) {
    return a+b ;

}

int main()
{
    std::string name;
    int age{10};
    bool red{true} ;
    bool green {false} ;

    std::cout << "Hello world" << std::endl ;
/*
    std::cout << "Enter your age and name" << std::endl ;


    std::cin >> name >> age ;

    std::cout << "Hi " <<name << " your age is " << age << std::endl;
*/

    std::cout << std::boolalpha;
    std::cout << "red is " << red << std::endl;
    std::cout << "blue is " << green   << std::endl ;

    /* range based for loop */
    for(double multiplier{4}; int i : {1,2,3,4,5,6,7,8,9,10}){
        std::cout << "result : " << ( i * multiplier) << std::endl;
    }

    std::map <int, int> MAP({{1, 1}, {2, 2}, {3, 3}});
    for (auto i : MAP) {

        std::cout << "{" << i.first << ", " 
                  << i.second << "}\n";
    }

    char str[5] {"Hell"};
    std::cout << str << std::endl ;

    const char *ptr {"Hello world"};
    std::cout << ptr << std::endl ;
    std::cout << *ptr << std::endl ;


     int *intptr {nullptr};
     intptr  = new int ;
     *intptr = 55;

    std::cout << "Intptr = " << *intptr << std::endl ;

    delete intptr;
    intptr = nullptr;

    int *ptr2 {new int {33}};
    std::cout << "ptr2 = " << *ptr2 << std::endl ;

    delete ptr2;
    ptr2 = nullptr;

    int  *data = new(std::nothrow) int [100000000000000];
    if(data == nullptr) {
        std::cout << " NULL \n" ;
     
    }else {
        std::cout << "Alloc succeeded " << std::endl ;
    }

    try {
        int  *d = new int [100000000000000];
    } catch (std::exception& ex) {
        std::cout <<  "Program caught exception " << ex.what() << std::endl;
    }


    int& ref_int {age};

    int page {20};

    std::cout << "age = " << age << std::endl;
    std::cout << "ref age = " << ref_int << std::endl;
    std::cout << "page = " << page << std::endl;

    ref_int = 30;

    std::cout << "age = " << age << std::endl;
    std::cout << "ref age = " << ref_int << std::endl;
    std::cout << "page = " << page << std::endl;

    ref_int = page;
    ref_int = 80;
    std::cout << "age = " << age << std::endl;
    std::cout << "ref age = " << ref_int << std::endl;
    std::cout << "page = " << page << std::endl;



      int  *  p_age {&age};

    *p_age = 100;

    std::cout << "age = " << age << std::endl;

    std::cout << "Program ended " << std::endl;


    auto f1 = [=](){
        std::cout << "I am here " << std::endl;
        std::cout << "age = " << *p_age << std::endl;

    };


    
    f1();

        auto x = func(10,2);
    std::cout << "Output from template function is " << x << std::endl;

    return 0;

}
