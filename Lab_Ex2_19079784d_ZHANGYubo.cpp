#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


void rat(char symbol,int width,int number)  //generate right-angled triangle
{
	string str="";  //str record the ith line of one triangle
	for(int i=1;i<=width;i++)
	{
		cout<<setiosflags(ios::left)<<setw(width);  //output on the left and set output width is "width"
		str+=symbol;  //ith line str has i symbols
		for(int j=0;j<number;j++)
		   cout<<setiosflags(ios::left)<<setw(width)<<str;  //output the "number" str perline
		cout<<endl;
	}
}
void lat(char symbol,int width,int number)  //generate left-angled triangle
{
	//like rat() except that setiosflags(ios::right)
	string str="";
	for(int i=1;i<=width;i++)
	{
		cout<<setiosflags(ios::right)<<setw(width);
		str+=symbol;
		for(int j=0;j<number;j++)
		   cout<<setiosflags(ios::right)<<setw(width)<<str;
		cout<<endl;
	}	
}
void tat(char symbol,int width,int number)  //generate two-equal-sided-angled triangle
{
	if(width%2!=1)  //input width of the base must be positive odd integer. If not, print an error message
	{
		cout<<"Error: the width of the must be a positive odd number";
	}
	else
	{
		string str="";
		int middle=(width-1)/2;  //identify the middle position
		for(int i=0;i<width;i++)   //intial str is width's " "
			str+=" ";
		str[middle]=symbol;   //assign the symbol to the middle position
		for(int i=0;i<width;i++)
		{
			str[middle-i]=symbol;   //add a symbol at left
			str[middle+i]=symbol;   //add a symbol at left
			for(int j=0;j<number;j++)
				cout<<str;
			cout<<endl;
		}	
		
	}
	
}
int main()
{
	char symbol,specify_char;  //specify_char is < > or ^
	int width,number;
	cout<<"Please enter a symbol: ";
	cin>>symbol;

	cout<<"Please enter width of the base: ";
	cin>>width;

	cout<<"Please enter number of the triangles: ";
	cin>>number;

	cout<<"Please specify how to print the triangle:"<<endl;
	cout<<"\t'<' for right-angled triangle"<<endl;
	cout<<"\t'>' for left-angled triangle"<<endl;
	cout<<"\t'^' for two-equal-sided triangle"<<endl;

	cin>>specify_char;
	if(specify_char=='<')	rat(symbol,width,number);
	else if(specify_char=='>')	lat(symbol,width,number);
	else	tat(symbol,width,number);

	return 0;
}