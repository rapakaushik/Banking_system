#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class Bank{
	private:
		int total;
		string id;
		struct person{
			string name ,ID,address;
			int contact,cash;
		}person [100];
		public:
			Bank(){					// creating constructor for bank class
			total = 0;
			} 
			void choice();
			void Person_Data();     // for entering new data we have created a new function
			void show();            // for showing data on screen                               
			void update();			 // for updating data
			void search();
			void transaction();
			void remove();
			
};
int main(){
	
	Bank b;
	b.choice();
	
	return 0;
}
void Bank::choice(){				// scope resolution operator is used to access the functions in class
	char ch;                        //to receive input or choice from user we have created a variablr ch of character type
	while(1){											// running infinite loop until user press EXIT 
		
	cout << "\n\n!!!....SELECT.....!!!"<< endl;
	cout << "1. Create new account"<< endl;
	cout << "2. Veiw customers list"<< endl;
	cout << "3. Update Info of existing account"<< endl;
	cout << "4. Check the details of the existing account"<< endl;
	cout << "5.  Perform Transactions"<< endl;
	cout << "6. Remove the existing account"<< endl;
	cout << "7. .....EXIT....."<< endl;
	ch = getch();
	system("CLS");
	switch(ch){
		case '1':
		Bank::Person_Data();
		break;
		case '2':
			if(total ==0)
			{
				cout << "!!!!....NO DATA IS EXISTING....!!!!"<<endl;
			}
			else
			{
		Bank::show();
			}
		break;
		case '3':
			if(total ==0)
			{
				cout << "!!!!....NO DATA IS EXISTING....!!!!"<<endl;
			}
			else
			{
			Bank::update();
			}
			break;
		case '4':
			if(total ==0)
			{
				cout << "!!!!....NO DATA IS EXISTING....!!!!"<<endl;
			}
			else
			{
		   Bank::search();
			}		
		   break;
		   case'5':
		   	if(total ==0)
			{
				cout << "!!!!....NO DATA IS EXISTING....!!!!"<<endl;
			}
			else
			{
		   Bank::transaction();	
			}
		   break;
		   case '6':
		   	if(total ==0)
			{
				cout << "!!!!....NO DATA IS EXISTING....!!!!"<<endl;
			}
			else
		   Bank::remove();
		   break;
		   case '7':
		      exit(0);
			  break;
			default:
			cout<<"Invalid input "<< endl;
			break;	
	}
			}	
}

void Bank::Person_Data(){
	
		cout << "Enter data of person"<< total+1 << endl;
		cout << "Enter Name:  ";
		cin >> person[total].name;
		cout << "ID:  ";
		cin >> person[total].ID;
		cout << "Adress:  ";
		cin>> person[total].address;
		cout << "Contact:  ";
		cin >> person[total].contact;
		cout << "Cash:  ";
		cin >> person[total].cash;
		total++;
}
void Bank::show(){
		for(int i = 0;i<total;i++){
			cout<<"Data of person"<<i+1<<endl;
			cout << "Name:  "<< person[i].name<< endl;
			cout << "ID:  "<<person[i].ID<< endl;
			cout << "Adress:  "<<person[i].address<< endl;
			cout << "Contact:  "<<person[i].contact<< endl;
			cout << "Cash:  "<<person[i].cash<< endl;
		}
}
void Bank::update(){
	cout<<"Enter ID of the person that has to be updated"<< endl;
	cin >> id;
	for(int i = 0;i<total;i++){
		if(id  == person[i].ID){
			cout<<"Data of person"<<i+1<<endl;
			cout << "Name:  "<< person[i].name<< endl;
			cout << "ID:  "<<person[i].ID<< endl;
			cout << "Adress:  "<<person[i].address<< endl;
			cout << "Contact:  "<<person[i].contact<< endl;
			cout << "Cash:  "<<person[i].cash<< endl;
			cout << "\nEnter New Data"<<endl;
																	// the update function has two fuctions included in it "SHOW()" 
																	//  andPerson_Data(). 
								
			cout << "Enter Name:  ";
			cin >> person[i].name;
			cout << "ID:  ";
			cin >> person[i].ID;
			cout << "Adress:  ";
			cin>> person[i].address;
			cout << "Contact:  ";
			cin >> person[i].contact;
			cout << "Cash:  ";
			cin >> person[i].cash;
			break;			
		}
		if(i == total-1){
			cout << "NO SUCH RECORD FOUND....!!"<<endl;
		}
	}
	
}
void Bank::search(){
	cout << "Enter ID of the person to search"<< endl;
	cin>>id;
	for(int i =0;i<total;i++){
		if(id == person[i].ID){
				cout<<"Data of person"<<i+1<<endl;
			cout << "Name:  "<< person[i].name<< endl;
			cout << "ID:  "<<person[i].ID<< endl;
			cout << "Adress:  "<<person[i].address<< endl;
			cout << "Contact:  "<<person[i].contact<< endl;
			cout << "Cash:  "<<person[i].cash<< endl;
			break;
		}
		if(i == total-1){
			cout << "NO SUCH RECORD FOUND....!!"<<endl;
		}
	}
}
void Bank::transaction(){
	char ch;
	int  cash;
	cout<<"Enter ID of the person to perform transaction"<< endl;
	cin >> id;
	for(int i = 0;i<total;i++){
		if(id == person[i].ID){
				cout << "Name:  "<< person[i].name<< endl;
				cout << "Adress:  "<<person[i].address<< endl;
				cout << "Contact:  "<<person[i].contact<< endl;
				cout << "\n Existing Cash:  "<<person[i].cash<< endl;
				cout << "Press 1 to DEPOSIT" <<endl;
				cout << "Press 2 to WITHDRAW"<<endl;
				ch = getch();
				switch(ch){
					case '1':
						cout <<"Enter the amount for DEPOSIT......"<<endl;
						cin >> cash;
						person[i].cash += cash;
						cout << "AVALA BALANCE:  "<<person[i].cash<< endl;
						break;
					case '2':
							back:
					      cout <<"Enter the amount for WITHDRAWL......"<<endl;	
					      cin>> cash;
					      if(person[i].cash < cash){
					      	cout << "INSUFFICIENT FUNDS...!!"<<endl;
					      	Sleep(3000);                                   // DELAY PERFORMANCE
					      	goto back;
						  }
						  person[i].cash -= cash; 
						  cout << "AVALA BALANCE:  "<<person[i].cash<< endl;
						  break;
					default:
					cout << "INVALID INPUT"<<endl;
					break;	  
				}
				break;
		}
		if(i == total-1){
			cout << "NO SUCH RECORD FOUND....!!"<<endl;
		}
	}
}

void Bank::remove(){
	char ch;
	cout << "Press 1 to remove specific record " <<endl;
	cout << "Press 2 to remove entire record"<<endl;
	ch = getch();
	switch(ch){
		case '1':
			cin >> id;
			for(int i =0;i<total;i++){
				if(id  == person[i].ID){
					for(int j =i;j<total;j++){
					person[i].name = person[i+1].name;		// next data will be overrided.
					person[i].ID = person[i+1].ID;    
					person[i].address = person[i+1].address;
					person[i].contact = person[i+1].contact;
					person[i].cash = person[i+1].cash;     
					total--;
					cout<< "data successfully deleted"<<endl;
					break;
				}
				}
				if(i == total-1){
			cout << "NO SUCH RECORD FOUND....!!"<<endl;
				}
				
			}
			break;
			case'2':
				total = 0;
				cout << "ALL DATA IS DELETED....!!"<<endl;
				break;
				default:
				cout<<"INVALID INPUT"<<endl;
				break;
	}
}
