#include<iostream>
#include<string>
using namespace std;

void rotate(char *charArray, int sizeOfArray)
{
    char temp0, temp1; //temp0 record temporary char and temp0 record next char
    //
    temp0=*charArray;
    temp1=*(charArray+1);
    *charArray=*(charArray+sizeOfArray-1);  //move the last char to the beginning
    charArray++;

    for(int i=1; i<sizeOfArray;i++)
    {
        *charArray=temp0;  //move the last char to the temporary position
        temp0=temp1;    //let temp0 be temporary char
        temp1=*(charArray+1);//let temp1 be next char
        charArray++;
    }
    
    *charArray='\0';  //the end of the string should be \0
}

int main()
{
    string str;
    cout<<"Please enter a string: ";
    char *p;   //p points to 1st char of str
    p=&str[0];

    cin>>str;
    for(int i=0; i<str.length();i++)  //rotate str.length() times
    {
        rotate(p,str.length());
        cout<<str<<endl;
    }
    return 0;
}