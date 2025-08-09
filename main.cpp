#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <windows.h>
using namespace std;
//string login[] = {"root","0xSeui"}; 
const vector <string> login = {"root","0xSeui"};
//string in[2];
vector <string> in(2);


void print_welcome() {
    cout << "\033[1;34m============================================\033[0m" << endl;
    cout << "\033[1;32m      🏦  Welcome to Seui Bank System       \033[0m" << endl;
    cout << "\033[1;33m            Secure | Fast | Trusted         \033[0m" << endl;
    cout << "\033[1;34m============================================\033[0m" << endl;
    cout << "\033[1;36m        Please Login to Access Account      \033[0m" << endl;
    cout << endl;
}

// Fucntion Clear Screen cls or clear in linux
void cls() {
#ifdef _WIN32
    system("cls");   
#else
    system("clear"); 
#endif
}

// Function GO Back 
bool back()
{
    char choice;
    cout << "\033[33mBack (B) : \033[0m";
    cin >> choice;

    return (choice == 'B' || choice == 'b');
}
// Function GO Animation Processing
void Processing()
{
       cout << "\033[36mProcessing";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl;
}
// Fucntion Add Balance
void add(vector <int>& status_balance)
{
while(true){
    int add_b , total_balance;
    total_balance = 0 ;
    cout << "\033[36mEnter The Amount To Add To Your Balance : \033[0m";
    cin >> add_b ;
    if(add_b <= 0){

      cout << "\033[31mInvalid Amount. Please Enter At Least 1$.\033[0m\n";
      continue;

    }
    Processing();
    cout <<"\033[0m" <<endl;
    status_balance.push_back(add_b);
    for(int i = 0 ; i <  status_balance.size() ; i++)
    {

         //cout << status_balance.at(i) << endl;
         total_balance += status_balance.at(i);


    }
    cout << "Balance Successfully added \033[32m[ "<< add_b <<" $ ]\033[0m" << endl ;
    char choice ;
    cout << "Add More  : (Y) or (N) : ";
    cin >> choice ;
    if(choice == 'N' || choice=='n')
    {
        cout << "\033[31mReturning to Home...\033[0m\n";
        cls();       
        break;

    }

    }


}
// Fucntion See Balance
void see(vector<int>& status_balance)
{
int total_balance = 0 ;
  for(int i = 0 ; i <  status_balance.size() ; i++)
    {

         //cout << status_balance.at(i) << endl;
         total_balance += status_balance.at(i);


    }
    Processing();
    cout <<"\033[32m===============================\033[0m\n";
    cout << "Current Balance : \033[32m"<< total_balance <<" $\033[0m" << endl ;
    cout <<"\033[32m===============================\033[0m\n";
while (true) {
    if (back()) {
        cls();
        return;
    }
    cout << "\033[31mInvalid input. Please press B to go back.\033[0m\n";

}

}
// Fucntion See Transactions
void see_transaction_history(vector<int>& status_balance)

{
    Processing();
       for(int i = 0 ; i <  status_balance.size() ; i++)
    {

         cout <<"\033[0mTransaction [" << i+1 << "] : \033[32m" <<status_balance.at(i) << " $\033[0m" << endl;
         //total_balance += status_balance.at(i);


    }

   while (true) {
    if (back()) {
        cls();
        return;
    }
    cout << "\033[31mInvalid input. Please press B to go back.\033[0m\n";
}


}
// FUnction Withdraw 
void withdrawal(vector<int>& status_balance)
{
    
int total_balance = 0;
    for (int i = 0; i < status_balance.size(); i++) {
        total_balance += status_balance.at(i);
    }
int amount_withdraw;
    Processing();
    cout <<"\033[32m===============================\033[0m\n";
    cout << "Current Balance : \033[32m"<< total_balance <<" $\033[0m" << endl ;
    cout <<"\033[32m===============================\033[0m\n"; 
    while(true){
    cout << "\033[32mEnter The Amount You Want to Withdraw : ";
    cin >> amount_withdraw;
    if(amount_withdraw <= 0){
      cout << "\033[31mInvalid Amount. Please Enter At Least 1$.\033[0m\n";
      continue;

    }if(amount_withdraw > total_balance)
    {
       cout << "\033[31mInsufficient funds. Please enter a lower amount.\033[0m\n";
       continue;
    }
    Processing();
    status_balance.push_back(-amount_withdraw);
    total_balance -= amount_withdraw ;
    total_balance = 0;
      for(int i = 0 ; i <  status_balance.size() ; i++)
    {

         //cout << status_balance.at(i) << endl;
         total_balance += status_balance.at(i);


    }
    cout << "\033[32mSuccessfully Withdraw \n\033[0m";
    cout <<"\033[32m===============================\033[0m\n";
    cout << "Current Balance : \033[32m"<< total_balance <<" $\033[0m" << endl ;
    cout <<"\033[32m===============================\033[0m\n";
    while (true) {
    if (back()) {
        cls();
        return;
    }
    cout << "\033[31mInvalid input. Please press B to go back.\033[0m\n";

}

    }

}
//Fucntion Start The Programe
void start()
{
    vector <int> status_balance  = {10};
    while(true)
{   
    cout << "\033[32m";
    cout << "========================\n";
    cout << "|         HOME         | \n";
    cout << "========================\n";
    cout << "\033[0m";  
    char choice ;
    cout << "\033[34m"; 
    cout << "[A] Add Balance  \n";
    cout << "[B] See Balance  \n";
    cout << "[C] Transaction Balance  \n";
    cout << "[W] Withdrawal Balance  \n";
    cout << "[E] Exit \n";
    cout << "\033[0m";  
    cout << "\033[32mPlease, Enter Your Choice : \033[0m";
    cin >> choice ;
    switch (choice)
    {
    case 'A':
    case 'a':
        add(status_balance);
        break;
    case 'B':
    case 'b':
        see(status_balance);
        break;
    case 'C':
    case 'c':
        see_transaction_history(status_balance);
        break;
    case 'W':
    case 'w':
        withdrawal(status_balance);
        break;
    case 'E':
    case 'e':
        cout << "\033[32mThank you for using the system. Goodbye!\033[0m\n";
        return;
    default:
        cls();
        cout << "\033[31mInvalid Choice.\033[0m\n";
        break;
    }



}
    



}
void syslogin()
{
    int attempts = 0 , max_attempts = 3 ;

     while(attempts < max_attempts)
        {
            cout << "\033[1;34mUserName : \033[0m ";
            //cin >> in[0];
            getline(cin,in.at(0));
            cout << "\033[1;32mPassWord : \033[0m ";
            //cin >> in.at(1);
            //cin >> in[0];
            getline(cin,in.at(1));
           if(in.at(0) == login.at(0)  && in.at(1) == login.at(1))
             {
                cls();
                start();
                return;
             }else{
                
                cout << "\033[1;31mError: Invalid Username or Password. \033[0m \n";
                attempts++;
             }     
        }

}

int main()
{
   SetConsoleTitle("Seui Bank System");
   print_welcome();
   syslogin();




    return 0;
}
