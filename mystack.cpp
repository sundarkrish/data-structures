//author :sundar.k
//date:26-june-2017

#include <iostream>
#include <stdlib.h>
using namespace std;

class MyStack
{
  public :
    int *top;   //Top of the stack pointer
    static const int MAX=5;   //Maximum size of the stack
    int size;
    int st_arr[MAX];

    MyStack() // empty constructor
    {

      top=st_arr-1;
      size=0;
      //cout<<"Empty cosntructor\n";


    }

    int push(int);     // Stack related API starts here
    int pop();
    bool isEmpty();
    int st_top();           // Stack related API  ends here
    void printStack();

};

int MyStack::push(int n)
{
  if(size<=MAX)
  {
      size++;
      top++;

      *top=n;
      //cout<<size<<*top;


  }
}

int MyStack::pop()
{
  int p;
  if(!isEmpty())
  {
    p=*top;
    top--;
    size--;
    return p;
  }

}


bool MyStack::isEmpty()
{
  if(size==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


int MyStack::st_top()
{
  //cout<<*top<<size;
  if(!isEmpty())
  {
    //cout<<*top<<size;
    int m;
    m=*top;
    return m;
  }
return 0;
}

void MyStack::printStack()
{
  for(int i=(size-1);i>=0;i--)
  {
    char top_ptr=32;
    if(&st_arr[i]==top)
    {
      top_ptr='*';
    }
    cout<<"\t\t|"<<st_arr[i]<<"|"<<top_ptr<<"\n";
  }

}


int main(void)
{
  cout<<"main() starts here\n";

  MyStack one;
  MyStack two;
  //cout<<"\n"<<one.st_top();
  //cout<<"\n"<<two.st_top();

  while(1)
  {
    int choice,tmp1,mdl,tmp2;
    cout<<"\nEnter your choice\n1.push 2.pop 3.top 4.sort\n ";
    cin>>choice;

    switch(choice)
    {
      case 1:
        cout<<"Enter the value to add to the stack !\n";
        cin>>tmp1;
        one.push(tmp1);
       one.printStack();
        break;

      case 2 :
        cout<<"The popped element is : \t"<<one.pop()<<"\n";
       one.printStack();
       //cout<<one.size;
        break;

      case 3 :
        cout<<"The top element of the stack is : \t"<<one.st_top()<<"\n";
        break;

      case 4 :
        //while(!(one.size==two.size))
        int tmp_size=one.size;
        while(!one.isEmpty())
        //for(int k=0;k<100;k++)
        {
          //int flag=0;
          //two.push(one.pop());
          mdl=one.pop();
          if(mdl>=two.st_top())
          {
            //cout<<two.size;
            two.push(mdl);
            //flag=1;
          }
          else if(mdl<two.st_top())
          {
            one.push(two.pop());
            two.push(mdl);
            //flag=1;
          }

        }

        two.printStack();
        //one.printStack();
        exit(0);
      //  break;

    }

  }

}
