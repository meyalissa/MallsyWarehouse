//SEMESTER: OCT 2022-FEB 2023
//SUBJECT: CSC126 GROUP ASSIGNMENT
//TITLE : MALLSY WAREHOUSE : IMPORT EXPORT SYSTEM 
//DATE : 16 FEB 2023
//TEAM MEMBERS : 
//MELISSA SOFIA BINTI SHAHRAN (LEADER),
//NUR ATIQAH ZULAIKA BINTI ISMAIL, 
//AHMAD FARIS BINTI MOHD KAMAL, 
//SYAKIR MUZAFFAR BIN SAIFUL BAHARI

#include <iostream>
#include <iomanip>
#include <windows.h> //sleep
#include <unistd.h> //sleep
using namespace std;
	
	//function declare
	//custinformation
	void intcustinfo(string& ,string& ,string& ,string& ,string& ,string& ,string& ,string& ,string& );
	void printcustinfo(string ,string ,string ,string ,string ,string ,string ,string ,string );
	
	void optbrand ( char, float& ,float& , string&  ); // A B C D E F G
	void calcquantity (int&, float , float , float&, float&,float&,float&);
	void calcfinalprice ( string , float , float, float&, float&, float&);
	float payment ( );
	
	// Code and Option 
	float Brandlist ();
	int inputoptproduct (int);
	
	//function declaration
	void optMunchyList ();
	void optMunchy(int, float&, float&, string&);
	
	void optJulieList();
	void optJulie(int, float&, float&, string&);
	
	void optMameeList();
	void optMamee(int, float&, float&, string&);
	
	void optOLDTOWNList ();
	void optOldTown(int, float&, float&, string&);
	
	void optVochelleList ();
	void optVochelle(int, float&, float&, string&);
	
	void optBrahimList();
	void optBrahim (int, float&, float&, string&);
	
	void optBerylList();
	void optBeryl (int, float&, float&, string&);
	
	
	//Variable declare 
	char choiceorder, choice, codebrand;
	string item;
	float kg, price, priceperitem, kgperitem, totalprice =0 ,totalkg=0 ;
	int optproduct, quantity, x=1, count=1;
	
int main ()
{
	//information
	string name, email, premistype, storefront, street, city, state, phonenum, postcode;
	
	//Final Price declare
	float statedelivery, kgdelivery, delivery, discount, Afterprice , total;
	
	//array declare
	int printquantityperitem [100];
	float printpriceperitem [100], printprice [100] ;	
	string printitemname [100];
	
	//Program start
	cout << "\n*********************WELCOME TO MALLSY WAREHOUSE IMPORT/EXPORT SYSTEM *********************" <<endl;
	cout << "\n PLEASE FILL THIS INFORMATION CORRECTLY ";
	
	intcustinfo (name, phonenum, email, premistype, storefront, street, city, postcode, state);	
	//atiqah
	cout << "\n\n Would you like to start order? (Y/N) : "; 
	cin >> choice;
	
	system("cls");   
	system("pause");
	
	cout<< "Loading";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            sleep(1);
    }
	
	while (toupper (choice) != 'N')
	{
		
		choiceorder = 'Y';

		while ( toupper (choiceorder) != 'N' )
		{	
		
			codebrand = Brandlist ();
		
			// user choose code and option
			optbrand ( codebrand, priceperitem, kgperitem, item );
		//syakir
			calcquantity (quantity,priceperitem,kgperitem,price,kg,totalprice,totalkg);
			
			//calculation
			printpriceperitem [x]    = priceperitem;
			printquantityperitem [x] = quantity;
			printprice [x]           = price;
			printitemname [x]        = item;
			x++;
			
			count ++;
			cout << fixed << showpoint ; 		
			cout << "---------------------------" <<endl;
			cout << "\n Total Price : RM" << setprecision (2)<< totalprice << endl;
			cout << " Total Weight : " << totalkg << "kg" <<endl;

			cout << "\n Add more items ? (Y/N) : ";
			cin >> choiceorder;	
			
			system("cls"); 
			
			cout<< "Loading";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            sleep(1);
    	}	
	
		}
		
		calcfinalprice ( state,  totalkg, totalprice,  delivery, discount, total);
		
		// Printing receipt
		cout << endl << " Shipping Details "<<endl;
		
		printcustinfo(name, email, premistype,storefront,street,city,state,phonenum,postcode);
		
		cout << endl << " Order Details ";
		cout << endl << "\n\t Product \t\t\t\t\t    Quantity \t     Unit Price \t Sub Total" <<endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" <<endl;
		
		x=1;
		for ( int attempt=1; attempt < count; attempt ++ )
		{	
			cout << x << " . " << printitemname [x] << "\t\t\t" << printquantityperitem [x] << "\t\t" << printpriceperitem [x] << "\t\t  " <<printprice [x] <<endl ;
			x++;
		}
	
		cout << "\t\t\t\t\t\t\t\t\t\t\t      ---------------" <<endl;
		cout << "\t\t\t\t\t\t\t\t\t   Total Item Price\t  " <<totalprice <<endl ; 
		cout << "\t\t\t\t\t\t\t\t\t   Delivery Charge \t  " <<delivery <<endl ;
		cout << "\t\t\t\t\t\t\t\t\t\t Discount \t  -" <<discount <<endl ;
		cout << "\t\t\t\t\t\t\t\t\t\t\t       ---------------" <<endl;
		cout << "\t\t\t\t\t\t\t\t\t\t  Total \t  " <<total <<endl ;
	
		choice = payment ();
	}
	
	cout << "\n THANKYOU FOR USING OUR SYSTEM HAVE A GREAT DAY " ;
	
	return 0;	
}




// FUNCTION

	float Brandlist ()
	{
		system("cls"); 
		char code;
		cout << "\n+------+-------------------------+"<<endl;
		cout << "| CODE |\t BRAND  \t |" <<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  A   | Munchy's \t\t |"<<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  B   | Julie's \t\t |"<<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  C   | Mamee \t\t\t |"<<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  D   | OLDTOWN N White Coffee  |"<<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  E   | Vochelle \t\t |"<<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  F   | Beryl's \t\t |"<<endl;
		cout << "+------+-------------------------+"<<endl;
		cout << "|  G   | Brahim's \t\t |"<<endl;
		cout << "+------+-------------------------+"<<endl;
	
		cout << " Enter code for which brand : ";
		cin >> code;
		
		while (toupper(code)!= 'A' && toupper(code)!= 'B' && toupper(code)!= 'C' && toupper(code)!= 'D' && toupper(code)!= 'E' && toupper(code)!= 'F' && toupper(code)!= 'G' )
			{
				cout <<endl<<" THE CODE OF THE BRAND YOU ENTERED NOT EXISTED" <<endl;
				cout <<" PLEASE ENTER A VALID CODE OF THE BRAND" <<endl<<endl;
				
				cout << " Enter code for which brand : ";
				cin >> code;
			}
			
		return code;
	}
	
	int inputoptproduct (int optlimit)
	{
		int optproduct;
		cout << " Enter option for product type : ";
		cin >> optproduct;

		while ( optproduct < 1 || optproduct > optlimit )
			{
				cout <<endl<<" THE OPTION OF THE PRODUCT NOT AVAIALBLE" <<endl;
				cout <<" PLEASE ENTER A VALID OPTION OF THE PRODUCT" <<endl<<endl;
			
				cout << " Enter option for product type : ";
				cin >> optproduct;
			}
		return optproduct;
	}
	
	
	
	void optMunchyList()
	{
		system("cls"); 
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|OPTION | TYPE OF PRODUCT AVAILABLE | Item/carton |\tPrice/carton |" <<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  1    | Original Cream Crackers   |      12 \t  |\t RM 51.30    |"<<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  2    | Cream Cracker \t    | \t   12 \t  | \t RM 52.70    |"<<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  3    | Wheat Cracker \t    | \t   12     | \t RM 51.30    |"<<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  4    | Sugar Crackers \t    | \t   12     | \t RM 51.70    |"<<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  5    | Vege Crackers \t    |\t   12 \t  | \t RM 51.70    |" <<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  6    | Chocolate Sandwhich \t    | \t   12\t  | \t RM 53.70    |"<<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
		cout << "|  7    | Butter Sandwhich \t    | \t   12 \t  | \t RM 53.70    |"<<endl;
		cout << "+-------+---------------------------+-------------+------------------+"<<endl;
	}
	
	void optMunchy(int optproduct, float &priceperitem, float &kgperitem, string &item) 
	{
			if (optproduct == 1) // Munchy : Original Cream Cracker
			{
				priceperitem = 51.30;
				kgperitem = 5.50;
				
				item = " Munchy Original Cream Cracker \t";
			}			
			
			else if (optproduct == 2) // Munchy : Cream Cracker
			{
				priceperitem = 52.70;
				kgperitem = 4.60;
				
				item = " Munchy Cream Cracker \t\t";
			}
			
			else if (optproduct == 3) // Munchy : Wheat Cracker
			{
				priceperitem = 51.30;
				kgperitem = 4.31;
				
				item = " Munchy Wheat Cracker \t\t";
			}
			
			else if (optproduct == 4) // Munchy : Sugar Crackers
			{
				priceperitem = 51.70;
				kgperitem = 5.68;
				
				item = " Munchy Sugar Cracker \t\t";
			}
			
			else if (optproduct == 5) // Munchy : Vege Crackers
			{
				priceperitem = 51.70;
				kgperitem = 5.68;
				
				item = " Munchy Vege Cracker \t\t";
			}
			
			else if (optproduct == 6) // Munchy : Chocolate Sandwhich
			{
				priceperitem = 53.70;
				kgperitem = 4.09;
				
				item = " Munchy Chocolate Sandwhich \t";
			}
			
			else if (optproduct == 7) // Munchy : Butter Sandwhich
			{
				priceperitem = 53.70;
				kgperitem = 4.24;
				
				item = " Munchy Butter Sandwhich \t\t";
			}
	}
	
	void optJulieList()
	{
		system("cls"); 
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "| OPTION | TYPE OF PRODUCT AVAILABLE | Item/carton | Price/carton  |" <<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  1 \t |   Peanut Butter Sandwich  | \t  12   \t   |\t RM 86 \t   |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  2 \t |   Cheese Sandwich \t     | \t  12 \t   |\t RM 85 \t   |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  3 \t |   Finger Lemon Sandwich   |\t  24 \t   |\t RM 67.20  |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  4 \t |   Orange Sandwich \t     |\t  24 \t   |\t RM 67.20  |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
	 	cout << "|  5 \t |   Banana Sandwich \t     | \t  24 \t   | \t RM 67.20  |" <<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  6 \t |   Lemon Sandwich \t     | \t  12 \t   | \t RM 68.10  |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  7 \t |   Biscuit Assorties\t     | \t   8 \t   |\t RM 72.50  |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  8 \t |   OAT 25 Hazelnut\t     | \t  12 \t   |\t RM 83.6   |"<<endl; 
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "|  9 \t |   Oat 25 Strawberry\t     | \t  12 \t   |\t RM 80.50  |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
		cout << "| 10 \t |   Oat 25 Ten Grains\t     | \t  12 \t   |\t RM 80.50  |"<<endl;
		cout << "+--------+---------------------------+-------------+---------------+"<<endl;
	}
	
	void optJulie(int optproduct, float &priceperitem, float &kgperitem, string &item)
	{
			if (optproduct == 1) // Julie's : Peanut Butter Sandwich
			{
				priceperitem = 86.00;
				kgperitem = 5.32; 
				
				item = " Julie's Peanut Butter Sandwich \t";
			}			
			
			else if (optproduct == 2) // Julie's : Cheese Sandwich
			{
				priceperitem = 85.00;
				kgperitem = 4.96;
				
				item = " Julie's Cheese Sandwich \t\t";
			}
			
			else if (optproduct == 3) // Julie's : Finger Lemon Sandwich
			{
				priceperitem = 67.20;
				kgperitem = 4.02;
				
				item = " Julie's Finger Lemon Sandwich \t";
			}
			
			else if (optproduct == 4) // Julie's : Orange Sandwich
			{
				priceperitem = 67.20;
				kgperitem = 4.12;
				
				item = " Julie's Orange Sandwich \t\t";
			}
			
			else if (optproduct == 5) // Julie's : Banana Sandwich
			{
				priceperitem = 67.20;
				kgperitem = 4.02;
				
				item = " Julie's Banana Sandwich \t\t";
			}
			
			else if (optproduct == 6) // Julie's : Lemon Sandwich
			{
				priceperitem = 68.10;
				kgperitem = 4.13;
				
				item = " Julie's Lemon Sandwich \t\t";
			}
			
			else if (optproduct == 7) // Julie's : Biscuit Assorties 
			{
				priceperitem = 72.50;
				kgperitem = 5.24;
				
				item = " Julie's Biscuit Assorties \t\t";
			}
			
			else if (optproduct == 8) // Julie's : OAT 25 Hazelnut 
			{
				priceperitem = 83.60;
				kgperitem = 4.60;
				
				item = " Julie's OAT 25 Hazelnut \t\t";
			}
			
			else if (optproduct == 9) // Julie's : Oat 25 Strawberry 
			{
				priceperitem = 80.50;
				kgperitem = 4.60;
				
				item = " Julie's Oat 25 Strawberry \t\t";
			}
			
			else if (optproduct == 10) // Julie's : Oat 25 Ten Grains 
			{
				priceperitem = 80.50;
				kgperitem = 4.60;
				
				item = " Julie's Oat 25 Ten Grains \t\t";
			}
	}
	
	
	void optMameeList()
	{
		system("cls"); 
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "| OPTION  |\tTYPE OF PRODUCT AVAILABLE \t\t       | Item/carton |\tPrice/carton  |" <<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  1 \t  | \t Cream Cracker-Sugar Crackers \t\t       |   12 \t     |\t RM 34.80     |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  2 \t  | \t Cream Cracker-Vege Crackers \t\t       |   12 \t     |\t RM 34.80     |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  3 \t  | \t Cream Cracker-Original Crackers \t       |   24 \t     |\t RM 34.80     |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  4 \t  | \t Monster Family Pack BBQ  \t\t       |   24 \t     | \t RM 140       |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  5 \t  | \t Monster Family Pack Hot & Spicy \t       |   24 \t     |\t RM 140       |" <<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  6 \t  | \t Monster Family Pack Black Pepper \t       |   24 \t     |\t RM 140       |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  7 \t  | \t Monster Family Pack Chicken  \t\t       |   24 \t     |\t RM 142       |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  8 \t  | \t Mister Potato Crisps x Neymar - Honey Cheese  |   12 \t     |\t RM 38.50     |"<<endl; 
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "|  9 \t  | \t Mister Potato Crisps x Neymar - BBQ \t       |   12 \t     |\t RM 38        |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "| 10 \t  | \t Mister Potato Crisps x Neymar - Original      |   12 \t     |\t RM 36        |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "| 11 \t  | \t Mister Potato Crisps x Neymar - Tomato        |   12 \t     |\t RM 38        |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
		cout << "| 12 \t  | \t Mister Potato Crisps x Neymar - Sweet Corn    |   12 \t     |\t RM 38        |"<<endl;
		cout << "+---------+----------------------------------------------------+-------------+----------------+"<<endl;
	}

	void optMamee(int optproduct, float &priceperitem, float &kgperitem, string &item)
	{
		if (optproduct == 1) // Mamee : Cream Cracker-Sugar
			{
				priceperitem = 34.8;
				kgperitem = 5.26; 
				
				item = " Mamee Cream Cracker-Sugar \t\t";
			}			

			
			else if (optproduct == 2) // Mamee : Cream Cracker-Vege 
			{
				priceperitem = 34.8;
				kgperitem = 5.26;
				
				item = " Mamee Cream Cracker-Vege \t\t";
			}
			
			else if (optproduct == 3) // Mamee : Cream Cracker- Original
			{
				priceperitem = 34.8;
				kgperitem = 5.26;
				
				item = " Mamee Cream Cracker-Original \t";
			}
			
			else if (optproduct == 4) // Mamee : Monster Family Pack BBQ
			{
				priceperitem = 140;
				kgperitem = 2.2;
				
				item = " Mamee Monster Family BBQ \t\t";
			}
			
			else if (optproduct == 5) // Mamee : Monster Family Pack Hot & Spicy
			{
				priceperitem = 140;
				kgperitem = 2.2;
				
				item = " Mamee Monster Family H&S \t\t";
			}
			
			else if (optproduct == 6) // Mamee : Monster Family Pack Black Pepper
			{
				priceperitem = 140;
				kgperitem = 2.2;
				
				item = " Mamee Monster Family BP \t\t";
			}
			
			else if (optproduct == 7) // Mamee : Monster Family Pack Chicken
			{
				priceperitem = 142;
				kgperitem = 2.2;
				
				item = " Mamee Monster Family Chicken \t";
			}
			
			else if (optproduct == 8) // Mamee : Mister Potato Crisps x Neymar -Honeeycheese
			{
				priceperitem = 38.5;
				kgperitem = 2.74;
				
				item = " Mamee MPS x Neymar - HC \t\t";
			}
			
			else if (optproduct == 9) // Mamee : Mister Potato Crisps x Neymar - BBQ
			{
				priceperitem = 38;
				kgperitem = 2.74;
				
				item = " Mamee MPS x Neymar - BBQ \t\t";
			}
			
			else if (optproduct == 10) // Mamee : Mister Potato Crisps x Neymar - Original
			{
				priceperitem = 36;
				kgperitem = 2.74;
				
				item = " Mamee MPS x Neymar - Original \t ";
			}
			
			else if (optproduct == 11) // Mamee : Mister Potato Crisps x Neymar - Tomato
			{
				priceperitem = 38;
				kgperitem = 2.74;
				
				item = " Mamee MPS x Neymar - Tomato \t ";
			}	
			
			else if (optproduct == 12) // Mamee : Mister Potato Crisps x Neymar - Sweet Corn
			{
				priceperitem = 38;
				kgperitem = 2.5;
				
				item = " Mamee MPS x Neymar - S.Corn \t ";
			}
	}
	
	void optOLDTOWNList()
	{
		system("cls"); 
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "| OPTION | TYPE OF PRODUCT AVAILABLE \t\t\t| Item/carton |\tPrice/carton \t     |" <<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "|  1 \t | White Coffee 3in1 Classic 15*38g \t        |  12 \t      |\t RM184.90 \t     |"<<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "|  2 \t | White Coffee 3in1 Hazelnut 15*38g \t        |  12\t      |\t RM 186.90 \t     |"<<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "|  3 \t | White Coffee 3in1 Less Sugar 15*38g \t        |   2 \t      |\t RM 185.90 \t     |"<<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "|  4 \t | White Coffee 3in1 Extra Rich 15*38g \t        |  12 \t      |\t RM 185.90 \t     |     "<<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "|  5 \t | White Coffee 3in1 Coffee and Creamer 15*38g  |  12 \t      |\t RM 186.90 \t     |" <<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "|  6 \t | White Coffee 3in1 Cane Sugar 15*38g \t        |  12 \t      |\t RM 183.50 \t     |"<<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
		cout << "| 7 \t | White Coffee 3in1 Salted Caramel 15*38g      |  12 \t      |\t RM 183 \t     |"<<endl;
		cout << "+--------+----------------------------------------------+-------------+----------------------+"<<endl;
	
	}

	void optOldTown(int optproduct, float &priceperitem, float &kgperitem, string &item)
	{
		if (optproduct == 1) // OLDTOWN White Coffee : 3in1 Classic
			{
				priceperitem = 184.9;
				kgperitem = 8.8; 
				
				item = " OWC 3in1 Classic \t\t\t";
			}			

			
			else if (optproduct == 2) // OLDTOWN White Coffee : 3in1 Hazelnut
			{
				priceperitem = 186.9;
				kgperitem = 8.8;
				
				item = " OWC 3in1 Hazelnut \t\t\t";
			}
			
			else if (optproduct == 3) // OLDTOWN White Coffee : 3in1 Less Sugar
			{
				priceperitem = 185.9;
				kgperitem = 8.8;
				
				item = " OWC 3in1 Less Sugar \t\t";
			}
			
			else if (optproduct == 4) // OLDTOWN White Coffee : 3in1 Extra Rich
			{
				priceperitem = 185.9;
				kgperitem = 8.8;
				
				item = " OWC 3in1 Extra Rich \t\t";
			}
			
			else if (optproduct == 5) // OLDTOWN White Coffee : 3in1 Coffee and Creamer
			{
				priceperitem = 186.9;
				kgperitem = 8.8;
				
				item = " OWC 3in1 Coffee and Creamer \t";
			}
			
			else if (optproduct == 6) // OLDTOWN White Coffee : 3in1 Cane Sugar
			{
				priceperitem = 183.5;
				kgperitem = 8.8;
				
				item = " OWC 3in1 Cane Sugar \t\t";
			}
			
			else if (optproduct == 7) // OLDTOWN White Coffee : 3in1 Salted Caramel
			{
				priceperitem = 183;
				kgperitem = 8.8;
				
				item = " OWC 3in1 Salted Caramel \t\t";
			}

	}
	
	void optVochelleList()
	{
		system("cls"); 
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "| OPTION | TYPE OF PRODUCT AVAILABLE \t\t| Item/carton |\t Price/carton\t |" <<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  1 \t | Dairy Milk Chocolate 175g Dairy Milk |     16      |\t RM 83.99 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  2 \t | Dairy Milk Chocolate 175g Almonds \t|     16      |\t RM 83.99 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  3 \t | Dairy Milk Chocolate 175g Hazelnut \t|     16      |\t RM 83.99 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  4 \t | Dairy Milk Chocolate 175g Fruit Nut \t|     16      |\t RM 83.99 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  5 \t | Box Fruit & Nuts 205g \t\t|     12      |\t RM 194.90 \t |" <<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  6 \t | Box Hazelnuts 205g \t\t        |     12      |\t RM 196.90 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  7 \t | Box Almonds 205g \t\t        |     12      |\t RM 194.90 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "|  8 \t | Canister 330g Fruits & Nuts \t\t|     12      |\t RM 183.50 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl; 
		cout << "|  9 \t | Canister 330g Hazelnuts \t\t|     12      |\t RM 180 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
		cout << "| 10 \t | Canister 330G Almonds \t\t|     12      |\t RM 180 \t |"<<endl;
		cout << "+--------+--------------------------------------+-------------+------------------+"<<endl;
	}


	void optVochelle(int optproduct, float &priceperitem, float &kgperitem, string &item)
	{
		if (optproduct == 1) // Vochelle : Dairy Milk Chocolate Original
			{
				priceperitem = 83.99;
				kgperitem = 3.8; 
				
				item = " Vochelle Dairy Milk Chocolate Original ";
			}			

			
			else if (optproduct == 2) // Vochelle : Dairy Milk Chocolate Almonds
			{
				priceperitem = 83.99;
				kgperitem = 3.8;
				
				item = " Vochelle Dairy Milk Chocolate Almonds";
			}
			
			else if (optproduct == 3) // Vochelle : Dairy Milk Chocolate Hazelnut
			{
				priceperitem = 83.99;
				kgperitem = 3.8;
				
				item = " Vochelle Dairy Milk Chocolate Hazelnut ";
			}
			
			else if (optproduct == 4) // Vochelle : Dairy Milk Chocolate Fruit Nut
			{
				priceperitem = 83.99;
				kgperitem = 3.8;
				
				item = " Vochelle Dairy Milk Chocolate Fruit Nut";
			}
			
			else if (optproduct == 5) // Vochelle : Box Fruit & Nuts
			{
				priceperitem = 194.9;
				kgperitem = 3.46;
				
				item = " Vochelle Box Fruit & Nuts \t";
			}
			
			else if (optproduct == 6) // Vochelle: Box Hazelnuts
			{
				priceperitem = 196.9;
				kgperitem = 3.46;
				
				item = " Vochelle Box Hazelnuts \t\t";
			}
			
			else if (optproduct == 7) // Vochelle : Box Almonds
			{
				priceperitem = 194.9;
				kgperitem = 3.46;
				
				item = " Vochelle Box Almonds \t\t";
			}
			
			else if (optproduct == 8) // Vochelle : Canister Fruits & Nuts
			{
				priceperitem = 183.5;
				kgperitem = 5;
				
				item = " Vochelle Canister Fruits & Nuts \t\t";
			}
			
			else if (optproduct == 9) // Vochelle : Canister Hazelnuts
			{
				priceperitem = 180;
				kgperitem = 5;
				
				item = " Vochelle Canister Hazelnuts \t";
			}
			
			else if (optproduct == 10) // Vochelle : Canister Almonds
			{
				priceperitem = 180;
				kgperitem = 5;
				
				item = " Vochelle Canister Almonds \t\t";
			}

	}
	
	void optBerylList()
	{
		system("cls"); 
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "| OPTION  | TYPE OF PRODUCT AVAILABLE \t\t     | Item/carton | Price/carton    |" <<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  1 \t  | Tiramisu Chocolate 65g (Milk) \t     | \t 24 \t   |   RM 89.90      |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  2 \t  | Tiramisu Chocolate 65g (Almond Milk)     | \t 24 \t   |   RM 89.90      |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  3 \t  | Tiramisu Chocolate 65g (Almond White)    | \t 24 \t   |  RM 89.90       |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  4 \t  | Tiramisu Chocolate 65g (Almond Green Tea)| \t 24 \t   |  RM 89.90       |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  5 \t  | Almond Milk Chocolate 450g \t\t     | \t 12 \t   |  RM 220\t     |" <<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  6 \t  | Almond Dark Chocolate 450g \t\t     | \t 12 \t   |  RM 215.50\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  7 \t  | Almond Bittersweet Chocolate 450g \t     | \t 12 \t   |  RM 215.50\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  8 \t  | Almond Green Tea Chocolate 410g \t     | \t 12 \t   |  RM 215.50\t     |"<<endl; 
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "|  9 \t  | Dragees Almond Mix Chocolate 370g \t     | \t 12 \t   |  RM 210.20\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "| 10 \t  | Raisins Milk Chocolate 450g \t     | \t 12 \t   |  RM 215.50\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "| 11 \t  | Assorted Milk Chocolate 450g \t     | \t 12 \t   |  RM 220\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "| 12 \t  | Crunchy Almond Milk Chocolate 380g \t     | \t 12 \t   |  RM 215.50\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
		cout << "| 13 \t  | Crunchy Almond White Chocolate 380g      | \t 12 \t   |  RM 215.50\t     |"<<endl;
		cout << "+---------+------------------------------------------+-------------------------------+"<<endl;
	}

	void optBeryl(int optproduct, float &priceperitem, float &kgperitem, string &item)
	{
		if (optproduct == 1) // Beryl's : Tiramisu Chocolate Milk
			{
				priceperitem = 89.9;
				kgperitem = 2.56; 
				
				item = " Beryl's : Tiramisu Chocolate Milk \t";
			}			

			
			else if (optproduct == 2) // Beryl's : Tiramisu Chocolate Almond Milk
			{
				priceperitem = 89.9;
				kgperitem = 2.56;
				
				item = " Beryl's : Tiramisu Chocolate Almond Milk";
			}
			
			else if (optproduct == 3) // Beryl's : Tiramisu Chocolate Almond White 
			{
				priceperitem = 89.9;
				kgperitem = 2.56;
				
				item = " Beryl's : Tiramisu Chocolate Almond White ";
			}
			
			else if (optproduct == 4) // Beryl's : Tiramisu Chocolate Almond Green Tea
			{
				priceperitem = 89.9;
				kgperitem = 2.56;
				
				item = " Beryl's : Tiramisu Chocolate Almond Green Tea ";
			}
			
			else if (optproduct == 5) // Beryl's : Almond Milk Chocolate
			{
				priceperitem = 220;
				kgperitem = 6.4;
				
				item = " Beryl's : Almond Milk Chocolate \t";
			}
			
			else if (optproduct == 6) // Beryl's : Almond Dark Chocolate
			{
				priceperitem = 215.5;
				kgperitem = 6.4;
				
				item = " Beryl's : Almond Dark Chocolate \t";
			}
			
			else if (optproduct == 7) // Beryl's : Almond Bittersweet Chocolate
			{
				priceperitem = 215.5;
				kgperitem = 6.4;
				
				item = " Beryl's : Almond Bittersweet Chocolate ";
			}
			
			else if (optproduct == 8) // Beryl's : Almond Green Tea Chocolate
			{
				priceperitem = 215.5;
				kgperitem = 6.0;
				item = " Beryl's : Almond Green Tea Chocolate ";
			}
			
			else if (optproduct == 9) // Beryl's : Dragees Almond Mix Chocolate
			{
				priceperitem = 210.2;
				kgperitem = 5.44;
				
				item = " Beryl's : Dragees Almond Mix Chocolate ";
			}
			
			else if (optproduct == 10) // Beryl's : Raisins Milk Chocolate
			{
				priceperitem = 215.5;
				kgperitem = 6.4;
				
				item = " Beryl's : Raisins Milk Chocolate \t\t ";
			}
			
			else if (optproduct == 11) // Beryl's : Assorted Milk Chocolate
			{
				priceperitem = 220;
				kgperitem = 6.4;
				
				item = " Beryl's : Assorted Milk Chocolate ";
			}	
			
			else if (optproduct == 12) // Beryl's : Crunchy Almond Milk Chocolate
			{
				priceperitem = 215.5;
				kgperitem = 5.56;
				
				item = " Beryl's : Crunchy Almond Milk Chocolate ";
			}
			
			else if (optproduct == 13) // Beryl's : Crunchy Almond White Chocolate
			{
				priceperitem = 215.5;
				kgperitem = 5.56;
				
				item = " Beryl's : Crunchy Almond White Chocolate ";
			}
	}
	
	void optBrahimList()
	{
		system("cls"); 
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "| OPTION | TYPE OF PRODUCT AVAILABLE \t      | Item/carton |  Price/carton  |" <<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  1 \t | Beef Kurma With Potatoes 180g      |   24 \t    |\t RM 146.90   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  2 \t | Beef Curry With Potatoes 180g      |   24 \t    |\t RM 143.50   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  3 \t | Beef Rendang 180g \t\t      |   24 \t    |\t RM 143.50   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  4 \t | Chicken Curry With Potatoes 180g   |   24 \t    |\t RM 146.90   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  5 \t | Tomato Chicken With Carrots 180g   |   24 \t    |\t RM 143.50   |" <<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  6 \t | Chicken Rendang 180g \t      |  24 \t    |\t RM 143.5    |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  7 \t | Anchovies Sambal 180g \t      |  24 \t    |\t RM 140      |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  8 \t | Nasi Goreng Kampung 250g \t      |  16 \t    |\t RM 134.90   |"<<endl; 
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "|  9 \t | Nasi Briyani Kambing 250g \t      |  16 \t    |\t RM 134.90   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "| 10 \t | Nasi Lemak & Sambal Ikan Bilis 250g|  16 \t    |\t RM 129.90   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "| 11 \t | Nasi Goreng Ayam 250g \t      |  16 \t    |\t RM 136.50   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;
		cout << "| 12 \t | Nasi Cendawan & Keju 250g \t      |  16 \t    |\t RM 134.90   |"<<endl;
		cout << "+--------+------------------------------------+-------------+----------------+"<<endl;

	}

//Brahims

	void optBrahim(int optproduct, float &priceperitem, float &kgperitem, string &item)
	{
		if (optproduct == 1) // Brahim's : Beef Kurma With Potatoes
			{
				priceperitem = 146.9;
				kgperitem = 5.32; 
				
				item = " Brahim's : Beef Kurma With Potatoes ";
			}			

			
			else if (optproduct == 2) // Brahim's : Beef Curry With Potatoes
			{
				priceperitem = 143.5;
				kgperitem = 5.32;
				
				item = " Brahim's : Beef Curry With Potatoes ";
			}
			
			else if (optproduct == 3) // Brahim's : Beef Rendang
			{
			
				priceperitem = 143.5;
				kgperitem = 5.32;
				
				item = " Brahim's : Beef Rendang \t\t";
			}
			
			else if (optproduct == 4) // Brahim's : Chicken Curry With Potatoes
			{
				priceperitem = 146.9;
				kgperitem = 5.32;
				
				item = " Brahim's : Chicken Curry With Potatoes";
			}
			
			else if (optproduct == 5) // Brahim's : Tomato Chicken With Carrots
			{
				priceperitem = 143.5;
				kgperitem = 5.32;
				
				item = " Brahim's : Tomato Chicken With Carrots ";
			}
			
			else if (optproduct == 6) // Brahim's : Chicken Rendang
			{
				priceperitem = 143.5;
				kgperitem = 5.32;
				
				item = " Brahim's : Chicken Rendang \t";
			}
			
			else if (optproduct == 7) // Brahim's : Anchovies Sambal
			{
				priceperitem = 140;
				kgperitem = 5.32;
				
				item = " Brahim's : Anchovies Sambal \t ";
			}
			
			else if (optproduct == 8) // Brahim's : Nasi Goreng Kampung 
			{
				priceperitem = 134.9;
				kgperitem = 5;
				item = " Brahim's : Nasi Goreng Kampung \t";
			}
			
			else if (optproduct == 9) // Brahim's : Nasi Briyani Kambing 
			{
				priceperitem = 134.9;
				kgperitem = 5;
				
				item = " Brahim's : Nasi Briyani Kambing \t";
			}
			
			else if (optproduct == 10) // Brahim's : Nasi Lemak & Sambal Ikan Bilis
			{
				priceperitem = 129.9;
				kgperitem = 5;
				
				item = " Brahim's : NL & Sambal Ikan Bilis \t";
			}
			
			else if (optproduct == 11) // Brahim's : Nasi Goreng Ayam
			{
				priceperitem = 136.5;
				kgperitem = 5;
				
				item = " Brahim's : Nasi Goreng Ayam \t";
			}	
			
			else if (optproduct == 12) // Nasi Cendawan & Keju 
			{
				priceperitem = 134.9;
				kgperitem = 5;
				
				item = " Nasi Cendawan & Keju \t\t";
			}
	}

	void calcfinalprice ( string state, float totalkg, float totalprice, float &delivery,float &discount,float &total)
	{
		float statedelivery, kgdelivery, Afterprice;
		//calculate for State Shipping Charge
		if ( state == "Malaysia")
		{
			statedelivery = 15;
		}
		
		else 
		{
			statedelivery = 75;
		}
		
		//calculate for Kg Shipping Charge 
			
		if ( totalkg >= 40)
		{
			kgdelivery = 150;
		}
		
		else 
		{
			kgdelivery = 75;
		}
		
		delivery = kgdelivery + statedelivery;
		Afterprice = totalprice + delivery;
		
		//calculate for discount 
		if ( Afterprice >=1000)
		{
			discount = (Afterprice * 0.1); // discount
			total = Afterprice - discount;
		}
		
		else 
		{
			total = Afterprice;
		}
	}

	void printcustinfo(string name,string email,string premistype,string storefront,string street,string city,string state,string phonenum,string postcode)
	{
		cout<<"\t" <<name<<endl;
		cout<<"\t" <<phonenum<<endl;
		cout<<"\t" <<email<<endl;
		cout<<"\t" <<storefront<<", "<<premistype<<", "<<street<<", "<<postcode<<", "<<city<<", "<<state<<endl;
	}
	
	void intcustinfo (string&name,string& phonenum,string& email,string& premistype,string& storefront,string& street,string& city,string& postcode,string& state)
	{
		cout << "\n Name \t\t  : " ;
		getline (cin,name);
		cout << "\n Phone No. \t  : " ;
		getline (cin,phonenum);
		cout << "\n Email \t\t  : " ;
		getline (cin,email);
		cout << "\n Type of Premises : ";
		getline (cin,premistype);
		cout << "\n Storefront name  : ";
		getline (cin,storefront);
		cout << "\n Street name \t  : " ;
		getline (cin,street);
		cout << "\n City \t\t   : " ;
		getline (cin,city);
		cout << "\n postcode \t  : " ; 
		getline (cin,postcode);
		cout << "\n State \t\t  : " ; 
		getline (cin,state);
	}	
	
	void optbrand ( char codebrand, float& priceperitem,float& kgperitem, string& item )
		{
			
				if (toupper(codebrand)== 'A' )
			{
				optMunchyList(); //change : option name list
				
				int optlimit = 7; // change : number of the option in each Code
					
				optproduct = inputoptproduct (optlimit);  
				
				optMunchy (optproduct, priceperitem, kgperitem, item) ;
					
			}
		
			else if (toupper(codebrand)== 'B' )
			{
				optJulieList(); //change : option list
				
				int optlimit = 10; // change : number of the option in each Code
				
				optproduct = inputoptproduct (optlimit);
	
				optJulie (optproduct, priceperitem, kgperitem, item) ;
				
			}
		
			else if (toupper(codebrand)== 'C' )
			{
				optMameeList(); //change : option list
				
				int optlimit = 12; // change : number of the option in each Code
				
				optproduct = inputoptproduct (optlimit);
	
				optMamee (optproduct, priceperitem, kgperitem, item);
			
			}
			
			else if (toupper(codebrand)== 'D')
			{
				optOLDTOWNList(); //change : option list
				
				int optlimit = 7; // change : number of the option in each Code
				
				optproduct = inputoptproduct (optlimit);
				
				optOldTown (optproduct, priceperitem, kgperitem, item);
			}
			
			else if (toupper(codebrand) == 'E')
			{
				optVochelleList(); //change : option list
				
				int optlimit = 10; // change : number of the option in each Code
				
				optproduct = inputoptproduct (optlimit);
				
				optVochelle (optproduct, priceperitem, kgperitem, item);
			}
			
			
			else if (toupper(codebrand)== 'F')
			{
				optBerylList(); //change : option list
				
				int optlimit = 13; // change : number of the option in each Code
				
				optproduct = inputoptproduct (optlimit);
				
				optBeryl (optproduct, priceperitem, kgperitem, item);
			}
			
			else if (toupper(codebrand)== 'G')
			{
				optBrahimList(); //change : option list
				
				int optlimit = 12; // change : number of the option in each Code
				
				optproduct = inputoptproduct (optlimit);
				
				optBrahim (optproduct, priceperitem, kgperitem, item);
			}
		}
		
		float payment ( )
	{
	
		char proceed, choice;
		//print receipt		
		cout << "\n Do you want to proceed with payment? (Y/N):" ;
		cin >> proceed;
	
		if ( toupper (proceed) == 'Y')
		{
			cout << endl << " Your item will be delivered after payment confirmation";
			choice = 'N';	
		}
	
		else
		{
			cout << "\n Continue Shopping? (Y/N) : ";
			cin >> choice;
		}
	
		return choice;
	}
	
	void calcquantity (int &quantity, float priceperitem, float kgperitem, float &price, float &kg, float &totalprice, float &totalkg)
	{
		cout << " Enter quantity of carton: ";
		cin >> quantity;
				
		price = priceperitem * quantity;
		kg    = kgperitem    * quantity;
			
		totalprice += price;
		totalkg    += kg;
	}



