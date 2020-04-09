#include<iostream>
#include<algorithm>
#include<array>
#include<list>
#include<string>
#include<numeric>

void display(const std::array<int,5>&a)
{
    std::cout<<"[ ";
    for (const auto &i:a)
        std::cout<<i<<" ";
    std::cout<<"]"<<std::endl;    
}

void test1()
{
    std::array<int,5>arr1 {10,20,30,40,50};
    std::array<int,5>arr2;
    
    display(arr1);
    display(arr2);
    
    arr2= {60,70,80,90,100};
    
    display(arr1);
    display(arr2);
    
    arr1[0]=0;
    arr1.at(2)=100;
    
    display(arr1);
    
    std::cout<<"Size of arr1 is: "<<arr1.size()<<std::endl;
    std::cout<<"Size of arr2 is: "<<arr2.size()<<std::endl;
    
   std::cout<<"Front of arr1 is "<<arr1.front()<<std::endl;
   std::cout<<"Back of arr2 is "<<arr2.back()<<std::endl;
}

void test2()
{
    std::array<int,5>nums1{1,2,3,4,5};
    std::array<int,5>nums2{6,7,8,9,10};
    
    display(nums1);
    display(nums2);
    
    nums1.fill(0);
    display(nums1);
    
    nums1.swap(nums2);
    
    display(nums1);
    display(nums2);
}

void test3()
{
    std::array<int,5>arr{9,8,7,6,5};
    int *ptr=arr.data();
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    display(arr);
    *ptr=99;
    display(arr);
}

void test4()
{
    std::array<int,5>arr{90,65,36,75,10};
    display(arr);
    std::sort(arr.begin(),arr.end());
    display(arr);
}

void test5()
{
    std::array<int,5>arr{98,5,78,65,43};
    std::sort(arr.begin(),arr.end());
    display(arr);
    std::array<int,5>::iterator min_num=std::min_element(arr.begin(),arr.end());
    auto max_num=std::max_element(arr.begin(),arr.end());
    std::cout<<"Minimum element is "<<*min_num<<std::endl;
    std::cout<<"Maximum element is "<<*max_num<<std::endl;
}

void test6()
{
    std::array<int,5>arr{1,2,3,4,4};
    auto adjacent=std::adjacent_find(arr.begin(),arr.end());
    if(adjacent!=arr.end())
        std::cout<<"Adjacent element found with value "<<*adjacent<<std::endl;
    else
        std::cout<<"Adjacent element not found."<<std::endl;
}

void test7()
{
    std::array<int,5>arr{2,4,6,8,10};
    auto sum=std::accumulate(arr.begin(),arr.end(),0);
    std::cout<<"Sum of elements are "<<sum<<std::endl;
}

void test8()
{
    std::array<int,8>arr{2,2,2,2,2,2,2,4};
    auto count=std::count(arr.begin(),arr.end(),2);
    std::cout<<"Found 2: "<<count<<" times "<<std::endl;
}

void test9()
{
    std::array<int,7>arr{100,20,300,42,5,65,9};
    int count=std::count_if(arr.begin(),arr.end(),[] (int x) { return  x>10&&x<200;});
    std::cout<<count<<" matches found with the condition"<<std::endl;
}

int main()
{
    std::cout<<"***********Test 1**************"<<std::endl;
    test1();
    std::cout<<"***********Test 2**************"<<std::endl;
    test2();
    std::cout<<"***********Test 3**************"<<std::endl;
    test3();
    std::cout<<"***********Test 4**************"<<std::endl;
    test4();
    std::cout<<"***********Test 5**************"<<std::endl;
    test5();
    std::cout<<"***********Test 6**************"<<std::endl;
    test6();
    std::cout<<"***********Test 7**************"<<std::endl;
    test7();
    std::cout<<"***********Test 8**************"<<std::endl;
    test8();
    std::cout<<"***********Test 9**************"<<std::endl;
    test9();
    return 0;
}
