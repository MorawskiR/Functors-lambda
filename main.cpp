

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <vector>

//wskaznik na funkcje :

int compute(int a, int b, int(*operation)(int, int))
{
    return operation(a,b);
}

int sum(int a, int b)
{
    return a+b;
}
int main(){

    auto s = compute(2, 3, sum); 
    std::cout<<s<<"\n";
    //Functor /obiekt funkcyjny 

    struct Functor {
        void operator() () {
            std::cout << "I'm a functor!\n";
        }
    };

    struct Functor2{
        void operator() (int a){
            std::cout<<"a = "<<a<<"\n";
        }
    };


        Functor funct{};
        funct();      // named object
        Functor{}();  // temporary object

        Functor2 funct2{};
        funct2(3);
        
        
        struct Functor3 {
        void operator()(int el) {
            std::cout << el << ' ';
        }
    };

        std::vector<int> vec {1, 2, 3, 4, 5};
        std::for_each(begin(vec), end(vec), Functor3{});
        std::cout << '\n';

        std::vector<int> vec2 {1, 2, 3, 4, 5};
    std::for_each(begin(vec2), end(vec2), [index = 0](int el) mutable {
        std::cout << index << ": " << el << " | ";
        index++;
    });


  []() { std::cout << "Hello"; } (); // lambda printing Hello (not called)

    std::vector<int> vec3 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec3.erase(std::remove_if(vec3.begin(),
                             vec3.end(),
                             [](int num) { return num % 2; }),
              vec3.end());

    auto print = [](int num) { std::cout << num << ' '; };  // named lambda
    std::for_each(vec3.begin(), vec3.end(), print);


}

