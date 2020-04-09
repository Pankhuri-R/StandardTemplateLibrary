#include<iostream>
#include<vector>
#include<algorithm>

class Person
{
    friend std::ostream &operator<<(std::ostream &os,const Person &p);
private:
    std::string name;
    int age;
public:
    Person()=default;
    Person(std::string name,int age)
         :name{name},age{age}
         {}
    bool operator<(const Person &p){
        return this->age<p.age;
    }
    bool operator==(const Person &p){
       return (this->age==p.age&&this->name==p.name);
    }
     
};

std::ostream &operator<<(std::ostream &os,const Person &p)
{
    os<<p.name<<" "<<p.age<<std::endl;
    return os;
}

void display2(std::vector<int>&v)
{
    std::cout<<"[ ";
    std::for_each(v.begin(),v.end(),[] (int x) { std::cout<<x<<" ";});
    std::cout<<"]"<<std::endl;
}

template<typename T>
void display(std::vector<T>&v)
{
    std::cout<<"[ ";
    for(auto &i:v)
        std::cout<<i<<" ";
   std::cout<<"]"<<std::endl;     
}

void test1()
{
    std::vector<int>vec{1,2,3,4,5};
    display(vec);
    
    vec={10,20,30,40,50};
    display2(vec);
    
    std::vector<double>vec1(5,1.5);
    display(vec1);
    
}

void test2()
{
    std::vector<int>vec{1,2,3,4,5};
    display2(vec);
    
    std::cout<<"Size: "<<vec.size()<<std::endl;
    std::cout<<"Maximum size: "<<vec.max_size()<<std::endl;
    std::cout<<"Capacity: "<<vec.capacity()<<std::endl;
    
    vec.push_back(6);
    display2(vec);
    
    std::cout<<"Size: "<<vec.size()<<std::endl;
    std::cout<<"Maximum size: "<<vec.max_size()<<std::endl;
    std::cout<<"Capacity: "<<vec.capacity()<<std::endl;
    
    vec.shrink_to_fit();
    std::cout<<"After using shrink: "<<std::endl;
    std::cout<<"Size: "<<vec.size()<<std::endl;
    std::cout<<"Maximum size: "<<vec.max_size()<<std::endl;
    std::cout<<"Capacity: "<<vec.capacity()<<std::endl;
    
    vec.reserve(100);
    std::cout<<"Using reserve: "<<std::endl;
    std::cout<<"Size: "<<vec.size()<<std::endl;
    std::cout<<"Maximum size: "<<vec.max_size()<<std::endl;
    std::cout<<"Capacity: "<<vec.capacity()<<std::endl;
}

void test3()
{
    std::vector<double>vec{0.5,1.5,2.5,3.5,4.5};
    display(vec);
    
    vec[0]=1.1;
    vec.at(3)=7.5;
    
    display(vec);
}

void test4()
{
    std::vector<Person>people;
    display(people);
    Person p1{"Harry",50};
    people.push_back(p1);
    display(people);
    
    people.push_back(Person{"Hermione",100});
    display(people);
    
    people.emplace_back("Ron",30);
    display(people);
}


void test5()
{
    std::vector<Person>people{
        {"Larry",70},
        {"Moe",40},
        {"Curly",20}
    };
    
    display(people);
    std::cout<<"Front: "<<people.front();
    std::cout<<"Back: "<<people.back()<<std::endl;
    
    people.pop_back();
    display(people);
}

void test6()
{
    std::vector<int>vec{1,2,3,4,5};
    display(vec);
    
    vec.clear();
    display(vec);
    
    vec={1,2,3,4,5,6,7,8,9};
    display(vec);
    vec.erase(vec.begin(),vec.begin()+3);
    display(vec);
    
    vec={1,2,3,4,5,6,7,8,9,10};
    auto it=vec.begin();
    while(it!=vec.end()){
        if(*it%2!=0)
            vec.erase(it);
        else
            it++;    
    }
    display(vec);
}

void test7()
{
    std::vector<int>vec1{1,2,3,4,5};
    std::vector<int>vec2{10,20,30,40,50};
    display(vec1);
    display(vec2);
    vec1.swap(vec2);
    std::cout<<"After swap: ";
    display(vec1);
    display(vec2);
}

void test8()
{
    std::vector<int>vec{23,65,1,789,39};
    display(vec);
    std::sort(vec.begin(),vec.end());
    display(vec);
}

void test9()
{
    std::vector<int>vec1{9,78,65,44,12};
    std::vector<int>vec2{1,2};
    std::sort(vec1.begin(),vec1.end());
    std::copy(vec1.begin(),vec1.end(),std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    
    vec1={2,4,6,8,10};
    vec2={12,14,15,16,17,13,18,20};
    std::copy_if(vec2.begin(),vec2.end(),std::back_inserter(vec1),[] (int x) {return x%2==0; });
    display(vec1);
    display(vec2);
}

void test10()
{
    std::vector<int>vec1{1,2,3,4,5};
    std::vector<int>vec2{10,20,30,40,50};
    std::vector<int>vec3;
    
    std::transform(vec1.begin(),vec1.end(),vec2.begin(),std::back_inserter(vec3),[] (int x,int y) {return x*y;});
    display(vec1);
    display(vec2);
    display(vec3);
}

void test11()
{
    std::vector<int>vec1{1,3,5,7,9,11};
    std::vector<int>vec2{13,15,17,19};
    
    display(vec1);
    display(vec2);
    
    auto it=std::find(vec1.begin(),vec1.end(),5);
    if(it!=vec1.end())
    {
        std::cout<<"inserting......"<<std::endl;
        vec1.insert(it,vec2.begin(),vec2.end());
    }
    else{
        std::cout<<"5 not found"<<std::endl;
    }
    display(vec1);
}

int main()
{
    std::cout<<"***************Test 1***************"<<std::endl;
    test1();
    std::cout<<"***************Test 2***************"<<std::endl;
    test2();
    std::cout<<"***************Test 3***************"<<std::endl;
    test3();
    std::cout<<"***************Test 4***************"<<std::endl;
    test4();
    std::cout<<"***************Test 5***************"<<std::endl;
    test5();
    std::cout<<"***************Test 6***************"<<std::endl;
    test6();
    std::cout<<"***************Test 7***************"<<std::endl;
    test7();
    std::cout<<"***************Test 8***************"<<std::endl;
    test8();
    std::cout<<"***************Test 9***************"<<std::endl;
    test9();
    std::cout<<"***************Test 10***************"<<std::endl;
    test10();
    std::cout<<"***************Test 11***************"<<std::endl;
    test11();
    return 0;
}
