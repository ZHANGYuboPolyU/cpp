#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

string A_code[]={"A1","A2","A3"};
string A_name[]={"Cheese veggie sandwich","Salmon & cheese sandwich","Chicken Caesar Sandwich"};
int A_price[]={30,34,32};

string B_code[]={"B1","B2","B3"};
string B_name[]={"(Quebec homemade) Quiche","Bagel with Cream Cheese","(East Village Chicken) Pie"};
int B_price[]={28,20,28};

string C_code[]={"C1","C2","C3","C4","C5"};
string C_name[]={"Coffee","Green Tea","Hot Chocolate","Milk","Juice"};
int C_price[]={36,28,28,26,26};

string S_code[]={"S1","S2","S3","S4","S5"};
string S_name[]={"Refreshing Breakfast","Best Value Breakfast","Veggie Lunch","Power Lunch","Afternoon Tea Set"};
string S_inclu[]={"Coffee+Bagel with cream cheese","Milk+Chicken Caesar Sandwich+Bagel withCream Cheese",
                    "Juice+Cheese veggie sandwich","Juice+Coffee+Salmon & cheese sandwich+Pie","Coffee or Tea+Quiche or Pie"};
int S_price[]={48,60,50,90,50};
string S5;  //S5 identify the combination of food and drink of S5;

void init(int count[])
{
    for(int i=0;i<16;i++)
       count[i]=0; //reset all items' quantity is 0
    cout<<"*****************Welcome to Ordering System!*****************"<<endl<<endl;

    cout<<"$$$$$$$$\\        $$$$$$\\  $$$$$$\\         $$$$$$\\            $$$$$$\\ "<<endl;           
    cout<<"\\____$$  |      $$  __$$\\$$ ___$$\\       $$  __$$\\          $$  __$$\\ "<<endl;        
    cout<<"    $$  /       \\__/  $$ \\_/   $$ |      $$ /  \\__|$$$$$$\\  $$ /  \\__|$$$$$$\\ "<<endl; 
    cout<<"   $$  /$$$$$$\\  $$$$$$  | $$$$$ /       $$ |      \\____$$\\ $$$$\\    $$  __$$\\ "<<endl; 
    cout<<"  $$  / \\______|$$  ____/  \\___$$\\       $$ |      $$$$$$$ |$$  _|   $$$$$$$$ | "<<endl;
    cout<<" $$  /          $$ |     $$\\   $$ |      $$ |  $$\\$$  __$$ |$$ |     $$   ____| "<<endl;
    cout<<"$$  /           $$$$$$$$\\$$$$$$  |      \\$$$$$$  \\$$$$$$$ |$$ |     \\$$$$$$$\\  "<<endl;
    cout<<"\\__/            \\________|\\______/        \\______/ \\_______|\\__|      \\_______| "<<endl;
}
void menu()
{
    cout<<"MENU--Sandwiches"<<endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << setiosflags(ios::left) << setw(14) << "Item code" << resetiosflags(ios::left) // 用完之后清除
         <<setiosflags(ios::left)<<setw(28)<<"name" <<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(9)<<"price"
         << resetiosflags(ios::right) << endl;
    cout << "-----------------------------------------------------------" << endl;
    for(int i=0;i<3;i++){
        cout << setiosflags(ios::left) << setw(14) << A_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<A_name[i]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<A_price[i]
        << resetiosflags(ios::right) << endl;
    }
    cout << "-----------------------------------------------------------" << endl<<endl;
    cout<<"MENU--Quiche, Pei, and Bagel with Cream Cheese"<<endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << setiosflags(ios::left) << setw(14) << "Item code" << resetiosflags(ios::left) // 用完之后清除
         <<setiosflags(ios::left)<<setw(28)<<"name" <<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(9)<<"price"
         << resetiosflags(ios::right) << endl;
    cout << "-----------------------------------------------------------" << endl;
    for(int i=0;i<3;i++){
        cout << setiosflags(ios::left) << setw(14) << B_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<B_name[i]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<B_price[i]
        << resetiosflags(ios::right) << endl;
    }
    cout << "-----------------------------------------------------------" << endl<<endl;
    cout<<"MENU--Coffee, Tea, Hot Chocolate, Milk, and Juice"<<endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << setiosflags(ios::left) << setw(14) << "Item code" << resetiosflags(ios::left) // 用完之后清除
         <<setiosflags(ios::left)<<setw(28)<<"name" <<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(9)<<"price"
         << resetiosflags(ios::right) << endl;
    cout << "-----------------------------------------------------------" << endl;
    for(int i=0;i<5;i++){
        cout << setiosflags(ios::left) << setw(14) << C_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<C_name[i]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<C_price[i]
        << resetiosflags(ios::right) << endl;
    }
    cout << "-----------------------------------------------------------" << endl<<endl;
    cout<<"MENU--Set meals"<<endl;
    cout << "-----------------------------------------------------------------------------------------------------"<< endl;
    cout << setiosflags(ios::left) << setw(14) << "Item code" << resetiosflags(ios::left) 
         <<setiosflags(ios::left)<<setw(28)<<"name" <<setw(51)<<"Set includes" <<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(8)<<"price"
         << resetiosflags(ios::right) << endl;
    cout << "-----------------------------------------------------------------------------------------------------"<< endl;
    for(int i=0;i<5;i++){
        cout << setiosflags(ios::left) << setw(14) << S_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<S_name[i]<<setw(51)<<S_inclu[i]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<S_price[i]
        << resetiosflags(ios::right) << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------"<< endl;   
}
char combination_S5()
{
    int sum=0,item=0;  //use sum to identify the combination (Coffee=1,Tea=3,Quiche=4,Pie=5)
    Drink:
    cout<<"Which drink do you want?"<<endl;
    cout<<"     1: Coffee"<<endl;
    cout<<"     3: Tea"<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<"Drink code: ";
    cin>>item;
    //Check input item code is correct
    if(cin.fail()||(item!=1&&item!=3))
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Drink;   
    }
    sum+=item;
    item=0;
    Food:
    cout<<"Which food do you want?"<<endl;
    cout<<"     4: Quiche"<<endl;
    cout<<"     5: Pie"<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<"Food code: ";
    cin>>item;
    //Check input item code is correct
    if(cin.fail()||(item!=4&&item!=5))
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Food;   
    }
    sum+=item;
    return sum+'0';
}
double package(double price,int count[],string &S5)  //packaged ordered items as a setmeal with a cheapest price
{
    int set_count;  //quantity of set meal
    //S4
    set_count=min(min(count[1],count[5]),min(count[6],count[10]));  //quantity of set meal depend on the minimal meal in the meal
    price=price-set_count*124+set_count*90;  //package individual items in to set meal
    count[1]-=set_count; count[5]-=set_count; count[6]-=set_count; count[10]-=set_count;  //decrease quantity of packaged items
    count[14]+=set_count;  //increase quantity of set meal
    //S2
    set_count=min(min(count[2],count[4]),count[9]);
    price=price-set_count*78+set_count*60;
    count[2]-=set_count; count[4]-=set_count; count[9]-=set_count;
    count[12]+=set_count;
    //S5-Coffee+Quiche
    set_count=min(count[3],count[6]);
    price=price-set_count*64+set_count*50;
    count[3]-=set_count; count[6]-=set_count;
    count[15]+=set_count;
    if(set_count>0)
        S5+='5';
    //S5-Coffee+Pie
    set_count=min(count[5],count[6]);
    price=price-set_count*64+set_count*50;
    count[5]-=set_count; count[6]-=set_count;
    count[15]+=set_count;
    if(set_count>0)
        S5+='6';
    //S1
    set_count=min(count[4],count[6]);
    price=price-set_count*56+set_count*48;
    count[4]-=set_count; count[6]-=set_count;
    count[11]+=set_count;
    //S3
    set_count=min(count[0],count[10]);
    price=price-set_count*56+set_count*50;
    count[0]-=set_count; count[10]-=set_count;
    count[13]+=set_count;
    //S5-Tea+Quiche
    set_count=min(count[7],count[3]);
    price=price-set_count*56+set_count*50;
    count[7]-=set_count; count[3]-=set_count;
    count[15]+=set_count;
    if(set_count>0)
        S5+='7';
    //S5-Tea+Pie
    set_count=min(count[7],count[5]);
    price=price-set_count*56+set_count*50;
    count[7]-=set_count; count[5]-=set_count;
    count[15]+=set_count;
    if(set_count>0)
        S5+='8';
    return price;
}
void print_order(string ois,double price,int count[],string S5)
{
    cout << endl<<"-----------------------------------------------------------------------------------" << endl;
    cout<<"The System has automatically packaged ordered items as a setmeal."<<endl;
    cout<<fixed<<setprecision(2);  //The total have a fixed precision to 2 digits after the decimal point.
    cout<<ois<<"'s order\n"<<"Total price: "<<"$"<<price<<endl<<endl;
    cout << setiosflags(ios::left) << setw(14) << "Item code" << resetiosflags(ios::left) // 用完之后清除
         <<setiosflags(ios::left)<<setw(28)<<"name" <<setw(9)<<"quantity"<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(9)<<"price"
         << resetiosflags(ios::right) << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    for(int i=0;i<3;i++){
        if(count[i]!=0){
        cout << setiosflags(ios::left) << setw(14) << A_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<A_name[i]<<setw(9)<<count[i]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<A_price[i]*count[i]
        << resetiosflags(ios::right) << endl;
        }
    }
    
    for(int i=0;i<3;i++){
        if(count[i+3]!=0){
        cout << setiosflags(ios::left) << setw(14) << B_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<B_name[i]<<setw(9)<<count[i+3]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<B_price[i]*count[i+3]
        << resetiosflags(ios::right) << endl;
        }
    }
    for(int i=0;i<5;i++){
        if(count[i+6]!=0){
        cout << setiosflags(ios::left) << setw(14) << C_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<C_name[i]<<setw(9)<<count[i+6]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<C_price[i]*count[i+6]
        << resetiosflags(ios::right) << endl;
        }
    }
    for(int i=0;i<5;i++){
        if(count[i+11]!=0){
        cout << setiosflags(ios::left) << setw(14) << S_code[i] << resetiosflags(ios::left)
        <<setiosflags(ios::left)<<setw(28)<<S_name[i]<<setw(9)<<count[i+11]<<resetiosflags(ios::left)<<setiosflags(ios::right)<<setw(6)<<'$'<<S_price[i]*count[i+11]
        << resetiosflags(ios::right) << endl;
        }
    }
    for(int i=1;i<=count[15];i++)  //print each S5's combination
    {
        switch(S5[i-1]-'0')
        {
            case 5: cout<<"\tS5-"<<i<<"contains: "<<"Coffee+Quiche"<<endl;break;
            case 6: cout<<"\tS5-"<<i<<"contains: "<<"Coffee+Pie"<<endl;break;
            case 7: cout<<"\tS5-"<<i<<"contains: "<<"Tea+Quiche"<<endl;break;
            case 8: cout<<"\tS5-"<<i<<"contains: "<<"Tea+Pie"<<endl;break;
        }
    }
}
void edit_order(int count[])  // edit some wrong ordered items
{
    string order0;
    int edit_command;

    Edit_order:
    cout<<"Which item do you want to delete? Please enter the item code:"<<endl;
    cin>>order0;

    if((order0=="A1"||order0=="a1")&&count[0]>0) count[0]--;     //quantity must> 0
    else if((order0=="A2"||order0=="a2")&&count[1]>0) count[1]--;
    else if((order0=="A3"||order0=="a3")&&count[2]>0) count[2]--;
    else if((order0=="B1"||order0=="b1")&&count[3]>0) count[3]--;
    else if((order0=="B2"||order0=="b2")&&count[4]>0) count[4]--;
    else if((order0=="B3"||order0=="b3")&&count[5]>0) count[5]--;
    else if((order0=="C1"||order0=="c1")&&count[6]>0) count[6]--;
    else if((order0=="C2"||order0=="c2")&&count[7]>0) count[7]--;
    else if((order0=="C3"||order0=="c3")&&count[8]>0) count[8]--;
    else if((order0=="C4"||order0=="c4")&&count[9]>0) count[9]--;
    else if((order0=="C5"||order0=="c5")&&count[10]>0) count[10]--;
    else if((order0=="S1"||order0=="s1")&&count[11]>0) count[11]--;
    else if((order0=="S2"||order0=="s2")&&count[12]>0) count[12]--;
    else if((order0=="S3"||order0=="s3")&&count[13]>0) count[13]--;
    else if((order0=="S4"||order0=="s4")&&count[14]>0) count[14]--;
    else if((order0=="S5"||order0=="s5")&&count[15]>0) count[15]--;
    else
    {
        cout<<"Wrong item code! Please input again."<<endl<<endl;
        goto Edit_order;
    }

    int sum;
    for(int i=0;i<16;i++)
    {
        sum+=count[i];
    }
    if(sum!=0)
    {
        cout<<"Would you like to delete another item?"<<endl;
        cout<<"     0: NO"<<endl;
        cout<<"     1: YES"<<endl;
        cout<<"**************************************"<<endl;
        cout<<"Command: ";

        cin>>edit_command;

        Enter_edit_command:
        if(cin.fail())
        {
            cin.clear();
            cin.sync();
            cout<<"Invalid input, please try again."<<endl<<endl; 
            goto Enter_edit_command;   
        }
        if(edit_command!=0)
        {
            if(edit_command==1)  
                goto Edit_order;
            else  
            {
                cout<<"Invalid input, please try again."<<endl<<endl; 
                goto Enter_edit_command;
            }
        }  
    }
}
int main()
{
    int system_command,order_command,start_new_command;
    int count[16]={0};   //quantity of each item
    double price;
    string ois;  //order identify string
    string order;

    Start_system:    
    init(count);
    S5="";
    price=0;

    cout<<"Please enter system command"<<endl;
    cout<<"     0: Exit the System"<<endl;
    cout<<"     1: Start Ordering"<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<"System Command: ";
    cin>>system_command;
    //Check input system command is integer
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Start_system;   
    }
    //Check input system command is 1/0 or other number
    if(system_command!=1)
    {
        if(system_command==0)  
          return 0;
        else  
        {
            cout<<"Invalid input, please try again."<<endl<<endl; 
            goto Start_system;
        }
    }

    Start_order:
    cout<<"Please input an Order Identification String: ";
    cin.clear();   //clear the input buffer for getline()
    cin.sync();
    getline(cin,ois);
    if(ois.length()>40)
    {
        cout<<"Wrong! Please input an Order Identification String whose lenghth is less than 40 characters"<<endl;
        goto Start_order;
    }
    cout<<endl;

    menu();

    Continue_order:
    cout<<"Please select one item from the food menu using item code: ";
    cin>>order;

    if(order=="A1"||order=="a1") count[0]++;
    else if(order=="A2"||order=="a2") count[1]++;
    else if(order=="A3"||order=="a3") count[2]++;
    else if(order=="B1"||order=="b1") count[3]++;
    else if(order=="B2"||order=="b2") count[4]++;
    else if(order=="B3"||order=="b3") count[5]++;
    else if(order=="C1"||order=="c1") count[6]++;
    else if(order=="C2"||order=="c2") count[7]++;
    else if(order=="C3"||order=="c3") count[8]++;
    else if(order=="C4"||order=="c4") count[9]++;
    else if(order=="C5"||order=="c5") count[10]++;
    else if(order=="S1"||order=="s1") count[11]++;
    else if(order=="S2"||order=="s2") count[12]++;
    else if(order=="S3"||order=="s3") count[13]++;
    else if(order=="S4"||order=="s4") count[14]++;
    else if(order=="S5"||order=="s5") 
    {
        count[15]++;
        S5+=combination_S5(); 
    }
    else
    {
        cout<<"Wrong item code! Please input again."<<endl<<endl;
        goto Continue_order;
    }
    
    Enter_order_command:
    cout<<"Would you like to continue to select the next food item or delete ordered items?"<<endl;
    cout<<"     0: order completed, ready to check out"<<endl;
    cout<<"     1: continue this order"<<endl;
    cout<<"     2: delete items"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"Order Command: ";
    cin>>order_command;
    
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Enter_order_command;   
    }
    if(order_command!=0)
    {
        if(order_command==1)
          goto Continue_order;
        else if(order_command==2)
        {
            edit_order(count);
            goto Enter_order_command;
        }
        else
        {
            cout<<"Invalid input, please try again."<<endl<<endl; 
            goto Enter_order_command;
        }
    }

    //calculate price
    for(int i=0;i<3;i++)
      price+=A_price[i]*count[i];
    for(int i=3;i<6;i++)
      price+=B_price[i-3]*count[i];
    for(int i=6;i<11;i++)
      price+=C_price[i-6]*count[i];
    for(int i=11;i<16;i++)
      price+=S_price[i-11]*count[i];

    price=package(price,count,S5);
    price=(price>100?price*0.95:price);  //discount
    print_order(ois,price,count,S5);
    
    cout << "-----------------------------------------------------------------------------------" << endl;
    
    cout<<"Would you like to start a new order?"<<endl;
    cout<<"     0: Exit the System"<<endl;
    cout<<"     1: Start New Order"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"Command: ";
    cin>>start_new_command;

    Enter_start_new_command:
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Enter_start_new_command;   
    }
    if(start_new_command!=1)
    {
        if(start_new_command==0)  
          return 0;
        else  
        {
            cout<<"Invalid input, please try again."<<endl<<endl; 
            goto Enter_start_new_command;
        }
    }
    goto Start_system;
    return 0;
    
}


    
