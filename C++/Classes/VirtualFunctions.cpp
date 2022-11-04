// https://www.hackerrank.com/challenges/virtual-functions/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{   //Abstract class
    public:
    char name[20];
    int age;
    
    virtual void getdata()=0;    //pure function
    virtual void putdata()=0;
};

class Professor: public Person{
    public:
    int publications, cur_id;
    static int tid;
     
    Professor(){
       tid++;
       cur_id=tid;
    }
    
    virtual void getdata(){     //add virtual keyword for forward passing
        cin>>name>>age>>publications;
    }
    
   virtual void putdata(){
        cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
    }
};

class Student: public Person{
    
    public:
    int mark[6], cur_id;
     static int tid;
     
     Student(){
         tid++;
         cur_id=tid;
     }
      virtual void getdata();
       virtual void putdata();
};


    void Student::putdata(){
         int sm=0,i;
    for(i=0; i<6; i++)
    sm += mark[i];
    
        cout<<name<<" "<<age<<" "<<sm<<" "<<cur_id<<endl;
    }

void Student::getdata(){
        cin>>name>>age;
        
        for(int i=0; i<6; i++){
        cin>>mark[i];}
    }
    
    int Professor::tid=0;   // it's mandatory to initialise the static data members
    int Student::tid=0;     //insite the class or outside



int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
