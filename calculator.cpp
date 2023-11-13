#include<iostream>
using namespace std;
int main()
{   
    int choice,a,b;
    cout<<"\n 1.addition";
    cout<<"\n 2.substraction";
    cout<<"\n 3.multiplication";
    cout<<"\n 4.division";
    cout<<"\n 5.exit";
    while (2)
    {
    cout<<"\nChoose what you want to do :";
    cin>>choice;
    switch (choice)
        {
        case 1:
                cout<<"Enter two numbers : ";
                cin>>a>>b;
                cout<<"The sum is "<<a+b;            
                break;
        case 2:
                cout<<"Enter two numbers : ";
                cin>>a>>b;
                cout<<"The difference is "<<a-b;            
                break;
        case 3:
                cout<<"Enter two numbers : ";
                cin>>a>>b;
                cout<<"The product is : "<<a*b;            
                break;
        case 4:
                cout<<"Enter two numbers : ";
                cin>>a>>b;
                cout<<"The answer is : "<<(float)a/b;            
                break;

        case 5:
            exit(0);
        default:
        printf("invalid choice");
        }
    }
    return 0;
}