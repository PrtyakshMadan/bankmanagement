#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
void openacc(int i);
void deposit_money(int bachat_khata_sankhaya, int amount);
void login001(int accountnumber);
void withdraw001(int index_user);
/*class Customer
{
    public:
    long account_number;
    string name;
    long pan_number;
    int balance;
};  */
int account_number[1000];
string pan_number[1000];
string name[1000];
int balance[1000];
int password01[1000];

int accountFinder(int accNumber){
    int len = sizeof(account_number)/sizeof(account_number[0]);
    for(int i=0;i<len;i++)
    {
        if(accNumber==account_number[i]) return i;
    }
    return -1;
}
int main()
{
    int i = 0;
    bool continueprog = true;
    int x = 0;

    int process01 = 0;

    cout << "-----------Welcome To Madan Bank-------------" << endl;
    while (continueprog)
    {
        cout << "1. Open Account" << endl << "2. Log In" << endl;
        cout << "3. Deposit Money " << endl << "4. All Accounts (Admin only)" << endl;
        cin >> process01;
        switch (process01)
        {
            case 1: // open new account in bank
            {
                int tempacc = rand();
                openacc(i);
                i++; //so that all acount data is stored in diffrent indexes of our arrays
                break;
            }
            case 2: //login
            {
                double userInputPassword =0;
                int khata_sankhya;
                cout<<"___-----WELCOME TO LOGIN PORTAL____-----"<<endl;
                cout<<"Account Number: ";
                cin>>khata_sankhya;
                int verifier1= accountFinder(khata_sankhya); //checks whether this account exists in our bank or not
                if(verifier1 == -1)
                {
                    cout<<"Account not found"<<endl;
                }
                else
                {
                login001(khata_sankhya);
                }
                break;
            }
            case 3:
            {
                int temp=-2;
                do{
                int amount = 0;
                int deposit_jama = 0;
                cout << "Enter Account Number";
                cin >> deposit_jama;
                temp=accountFinder(deposit_jama);
                if(temp==-1)
                {
                    cout<<"Acc not found!"<<endl;
                }
                else{

              /*  cout << "Amount: " << endl;
                cin >> amount;
                deposit_money(temp, amount);
                    */}
                }while(temp ==-1);
                break;
            }
        }
    }
}

void openacc(int i)
{
    cout << "Name: " << endl;
    cin >> name[i];
    while(true){
    cout << "Pan Number" << endl;
    cin >> pan_number[i];

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid Input "<<endl<<"Enter Again: ";

    }
    else
    {
        break;
    }
    }
    do
    {
        cout << "Enter Initial Amount" << endl;
        cin >> balance[i];
        if (balance[i] < 500)
        {
            cout << "Min. Balance should be 500. Thanks" << endl;
        }
    }
    while (balance[i] < 500);
    account_number[i]=  10000 + rand() % 90000;
    cout<<"Set Password";
    cin>>password01[i];
    cout << "Account Created Sucessfully" << endl << "Your Account number is: " << account_number[i] << endl;

}

void deposit_money(int bachat_khata_sankhaya, int amount)
{
    balance[bachat_khata_sankhaya] = balance[bachat_khata_sankhaya] + amount;
    cout << "Updated Balance: " << balance[bachat_khata_sankhaya] << endl;
}


void login001(int accountnumber)
{
    bool chabi = false;
    int length = sizeof(account_number)/sizeof(account_number[0]);
    int index_user =-2;
    int user_inputPassWord;
        do{
        for(int i=0;i<length;i++)
        {
        if(accountnumber ==account_number[i])
        {
            index_user = i;

        }
        if(index_user == -2)
        {
            cout<<"Account Not Found"<<endl;
        }
    }}while(index_user<0);
    do{
    cout<<"Enter Password: ";
    cin>>user_inputPassWord;
    for(int j=0; j<length; j++)
    {
        if(user_inputPassWord == password01[index_user])
        {
            chabi = true;
        }
    }}while(chabi==false);
    if(chabi == true)
    {
        int comand010;

        cout<<"------Login Sucessful-------"<<endl;
        cout<<"1. Get Account Info "<<endl<<"2. Withdraw Money"<<endl;
        cin>>comand010;
        switch(comand010){
            case 1:
            {
                cout<<"Name - "<<name[index_user]<<endl;
                cout<<"Account Number - "<<account_number[index_user]<<endl;
                cout<<"Balance: "<< balance[index_user]<<endl;
                break;
            }
            case 2:
            {
                withdraw001(index_user);

            }
            }

    }
    if(chabi == false) cout<<"Wrong Password"<<endl;
}



void withdraw001(int index_user)
{
    int withdraw =0; //amount user want to withdraw
    do{
    cout<<"Amount: ";
    cin>>withdraw;
    if(balance[index_user]<withdraw)//checks if account has sufficient balance
    {
        cout<<"Insufficient Balance"<<endl;
    }
    else
    {
        int withdrawl_op =0;
        cout<<"Withdrawl Methods"<<endl;
        cout<<"1. Cash  2. UPI "<< "3. Bank To Bank Transfer"<<endl;
        cin>>withdrawl_op;

        switch(withdrawl_op){

        case 1:
        {
            cout<<"$"<<withdraw<<" withdrawl sucessfull"<<endl;
            balance[index_user]= balance[index_user] - withdraw;
            cout<<"Updated Balance: $"<<balance[index_user]<<endl;
        }}
        break;

    }
    }while(balance[index_user]<withdraw); // continues the loop untill the withdrawl amount which is less than the balance.
}
