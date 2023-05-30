#include<iostream>
#define MAX 5
using namespace std;

class complex
{
    private:
        int real;
        int imag;

    public:
        complex()
        {

        }
        complex(int r,int i)
        {
            real=r;
            imag=i;
        }
        void takedata();
        complex add(complex);
        complex sub(complex);
        complex mul(complex);
        void putdata();
};

class stack
{
    private:
        int arr[MAX];
        int top=-1;
    public:
        void push(int);
        void pop();
        void display();
};

void stack::push(int data)
{
    if(top<MAX-1)
    {
        // cout<<"\nEnter the data to be inserted:";
        // cin>>data;
        top++;
        arr[top]=data;
        cout<<"\n"<<data<<" is inserted.";
    }
    else
    {
        cout<<"\nStack overflow!";
    }
}

void stack::pop()
{
    if(top>-1)
    {
        int data;
        data=arr[top];
        top--;
        cout<<"\n"<<data<<" is deleted.";
    }
    else
    {
        cout<<"\nStack Underflown!";
    }
}

void stack::display()
{
    if(top>-1)
    
    {
        cout<<"\nThe stack is:\n";
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
    else
    {
        cout<<"\nStack Underflown!";
    }
}

void complex::takedata()
{
    cout<<"Enter the real part:";
    cin>>real;
    cout<<"Enter the imag part:";
    cin>>imag;
}

complex complex::add(complex ca)
{
    complex result;
    result.real=real+ca.real;
    result.imag=+imag+ca.imag;
    return result;
}

complex complex::mul(complex ca)
{
    complex result;
    result.real=(real*ca.real)-(imag*ca.imag);
    result.imag=(real*ca.imag)+(imag*ca.real);
    return result;
}

complex complex::sub(complex ca)
{
    complex result;
    result.real=real-ca.real;
    result.imag=+imag-ca.imag;
    return result;
}

void complex::putdata()
{
    cout<<real<<"+i"<<imag<<endl;
}
int main()
{
    while(1)
    {
        char c;
        complex c1,c2;
        c1.takedata();
        c2.takedata();
        cout<<"\nEnter A for add, S for sbu and M for mul others for exit:";
        cin>>c;
        switch(c)
        {
            case 'A':
                c1.putdata();
                cout<<"+ \n";
                c2.putdata();
                cout<<"___________\n";
                c1.add(c2).putdata();
                break;
            case 'S':
                c1.putdata();
                cout<<"- \n";
                c2.putdata();
                cout<<"___________\n";
                c1.sub(c2).putdata();
                break;
            case 'M':
                c1.putdata();
                cout<<"* \n";
                c2.putdata();
                cout<<"___________\n";
                c1.mul(c2).putdata();
                break;
            default:
                return 1;
        }
    }
    return 1;

}