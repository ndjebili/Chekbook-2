#include <iostream>
#include <string>

using namespace std;

#define N 5

class Check {

    public:
    Check();
    float getCheckAmount(){return checkAmount;}
    int getCheckNum(){return checkNum;}
    string getCheckMemo(){return checkMemo;}
    void setCheckAmount(float amt){checkAmount=amt;}
    void setCheckNum(int num){checkNum=num;}
    void setCheckMemo();

    private:
        float checkAmount;
        int checkNum;
        string checkMemo;
        static int number;
};

class CheckBook{
public:
    friend class Check;
    CheckBook():balance(0), numOfChecks(0){}
    CheckBook(float initBal):balance(initBal), numOfChecks(0){}
    void deposit(float amount){balance+=amount, lastDeposit=amount, cout<<"Last deposit: "<<lastDeposit<<endl;}
    void displayChecks();
    bool writeCheck(float amount);
    int getAllChecks();

private:
    float balance, lastDeposit;
    int numOfChecks, checkLimit = N;
    Check array[N];
    int static allChecks;

};

int main() {
    std::cout << "Hello, World!" << std::endl;








   CheckBook cb1(1000), cb2(500);

   for (int i=0; i<10; i++)
   {
       cb1.writeCheck(150);
       cb2.writeCheck(130);
   }

   cout<<"cb1 check details"<<endl;
   cb1.displayChecks();
   cout<<"cb2 check details"<<endl;
   cb2.displayChecks();

   cout <<cb1.getAllChecks();
   cout<<cb2.getAllChecks();

    return 0;
}




Check::Check():checkAmount(0), checkNum(0), checkMemo(" ")
{
    number++;
}

void Check::setCheckMemo() {
    string memo;
    cout<<"Memo?"<<endl;
    cin>>memo;
    checkMemo=memo;
}

int CheckBook::getAllChecks()
{

    return allChecks;
}

void CheckBook::displayChecks()
{
    for (int i=numOfChecks-1; i>=0; i--)
    {
        cout<<"Check Number: "<<array[i].getCheckNum()<<endl;
        cout<<"Check Amount: "<<array[i].getCheckAmount()<<endl;
        cout<<"Check Memo: "<<array[i].getCheckMemo()<<endl;

    }
}

bool CheckBook::writeCheck(float amount) {
    if (balance >= amount && numOfChecks < N && allChecks<10) {
        array[numOfChecks].setCheckAmount(amount);
        array[numOfChecks].getCheckAmount();
        array[numOfChecks].setCheckMemo();
        array[numOfChecks].getCheckMemo();
        array[numOfChecks].setCheckNum(numOfChecks + 1);
        array[numOfChecks].getCheckNum();
        balance-=amount;
        numOfChecks++;
        CheckBook::allChecks++;

    } else {
        cout << "Not enough in balance!" << endl;
        return false;
    }
}