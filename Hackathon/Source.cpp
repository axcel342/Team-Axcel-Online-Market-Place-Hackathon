#include<iostream>
#include<bitset>
#include<map>
#include <stdlib.h>    
#include <time.h>
#include<fstream>
#include<string.h>
using namespace std;



int ProofofWork(int HashValue)
{
	int Pof = 0, Miner1 = 0, Miner2 = 0, Miner3 = 0, Winner;
	bool check = false;
	
	srand(time(NULL));


	Pof = HashValue;
	int count = 0;

	time_t start1, start2, start3;

	do
	{

		Miner1 = rand() % 10 + 1;
		start1 = time(NULL);
		Miner2 = rand() % 10 + 1;
		start2 = time(NULL);
		Miner3 = rand() % 10 + 1;
		start3 = time(NULL);

		if (Miner1 == Pof || Miner2 == Pof || Miner3 == Pof)
		{
			check = true;

			if (Miner1 == Pof)
				Winner = 1;

			if (Miner2 == Pof)
				Winner = 2;

			if (Miner3 == Pof)
				Winner = 3;

			if (Miner1 == Pof && Miner2 == Pof && Miner3 == Pof)
			{
			


				if (start1 > start2 && start1 > start3) {
					Winner = 1;
				}
				else if (start2 > start1 && start2 > start3) {
					Winner = 2;
				}
				else {
					Winner = 3;
				}
			}

			else if (Miner1 == Pof && Miner2 == Pof)
			{
				if (start1 > start2)
					Winner = 1;

				else
					Winner = 2;
			}

			else if (Miner1 == Pof && Miner3 == Pof)
			{
				if (start1 > start3)
					Winner = 1;

				else
					Winner = 3;
			}

			else if (Miner2 == Pof && Miner3 == Pof)
			{
				if (start2 > start3)
					Winner = 2;

				else
					Winner = 3;
			}


		}
		count++;


	} while (check == false);


	//  cout << count << endl;                //Too check count of loops




	if (Winner == 1)
	{
		cout << "Miner1 prevails" << endl;
		return 1;
	}
	if (Winner == 2)
	{
		cout << "Miner2 prevails" << endl;
		return 2;
	}
	if (Winner == 3)
	{
		cout << "Miner3 prevails" << endl;
		return 3;
	}
}

void Blockchain(int Transaction_id, string Public_Key, int Hash_Value)
{

	int size = 0;
	int arr[100][4] = { 0 };
	string a[100][1];
	ifstream fin;
	fin.open("Blockchain.txt");
	if (!fin)
		cout << "An Error has Occured in opening Blockchain.txt" << endl;

	else
	{
		fin >> size;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 4; j++)
			{


				if (j == 2)
					fin >> a[i][1];

				else
					fin >> arr[i][j];
			}

		}

	}

	size++;

	arr[size - 1][0] = Transaction_id;
	arr[size - 1][1] = arr[size - 2][0];
	a[size - 1][1] = Public_Key;
	arr[size - 1][3] = ProofofWork(Hash_Value);


	fin.close();

	ofstream fout;
	fout.open("Blockchain.txt");

	if (!fout)
		cout << "An error has occured while writing to Blockchain.txt" << endl;

	else
	{

		fout << size << endl;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == 2)
					fout << a[i][1] << " ";
				else
					fout << arr[i][j] << " ";
			}
			fout << endl;

		}
	}

	fout.close();


}

void main()
{
	string name;
	string password;
	int bal;
	int sr_no;
	int save;

	string* arr_name;
	string* arr_pass;
	int* arr_bal;
	int* arr_serial;




	bool old = false;
	bool news = false;
	bool authentic = false;
	bool customer = false;
	bool work = false;




	string product;
	int price;
	int serial;

	string* product_name;
	int* arr_price;
	int* arr_key;



	int num;
	bool op = true;

	while (op == true)
	{

		cout << "Enter your name\n";

		cin >> name;
		ifstream in;

		in.open("user.txt");

		in >> num;

		arr_name = new string[num];
		arr_pass = new string[num];
		arr_bal = new int[num];
		arr_serial = new int[num];

		for (int i = 0; i < num; i++)
		{
			in >> arr_serial[i];
			in >> arr_name[i];
			in >> arr_pass[i];
			in >> arr_bal[i];
		}

		in.close();

		int authe = false;
		for (int i = 0; i < num && authe == false; i++)
		{
			if (name == arr_name[i])
			{
				old = true;
				authe = true;
				save = i;
			}
		}
		if (authe == false) {
			news = true;
		}
		if (old == true)
		{
			bool auth = false;
			cout << "Enter your Password\n";
			cin >> password;

			if (password == arr_pass[save])
			{
				customer = true;
				auth = true;
			}
			if (auth == false)
			{
				cout << "\n\nWrong Password\n\n\n";
			}
		}
		else if (news == true)
		{
			cout << "\n\nYou are a new user, Enter your details\n";

			string p;
			int m;

			cout << "\n\nEnter a strong password(This can not be changed later) : ";
			cin >> p;
			cout << "\n\nEnter the amount of Bitcoins in your wallet : ";
			cin >> m;


			ofstream out;
			out.open("user.txt");

			out << num + 1 << endl;

			for (int i = 0; i < num; i++)
			{
				out << arr_serial[i] << " " << arr_name[i] << " " << arr_pass[i] << " " << arr_bal[i] << endl;
			}
			out << num + 1 << " " << name << " " << p << " " << m << endl;

			out.close();

			num = num + 1;

			cout << "\n\nYou have been successfully registered, You will be returned to the Login \n\n\n";

		}

		if (customer == true)
		{
			cout << "\n\n\n\n Welcome :" << arr_name[save] << endl;
			cout << "Your account balance is :" << arr_bal[save] << endl << endl << endl;
			work = true;
		}

		while (work == true)
		{

			int number;

			ifstream in;
			in.open("product.txt");

			in >> number;

			product_name = new string[number];
			arr_price = new int[number];
			arr_key = new int[number];

			for (int i = 0; i < number; i++)
			{
				in >> arr_key[i];
				in >> product_name[i];
				in >> arr_price[i];
			}

			in.close();



			char choice;


			cout << "\n\n\nWelcome to the marketplace , your go to place to Buy and Sell at the best rates" << endl << endl;

			cout << "To look at the your products that are up for sale, Enter L \n";
			cout << "To Add a new product for trade, Enter N \n";
			cout << "To look at the products available to Purchase on the Marketplace , enter T\n";
			cout << "To take one off your products of the marketplace, Enter R\n";
			cout << "To peek into your wallet , Enter W\n";
			cout << "To see the Blockchain Enter B\n";
			cout << "To Exit the Market , press E\n\n\n\n";

			cin >> choice;

			if (choice == 'L')
			{
				cout << "\n\n\nYour products\n\n";
				for (int i = 0; i < number; i++)
				{
					if (arr_serial[save] == arr_key[i])
					{
						cout << "Product : " << product_name[i];
						cout << "       Price : " << arr_price[i] << endl;
					}
				}
				cout << endl;
			}
			if (choice == 'N')
			{
				string sname;
				int sprice;

				cout << "\n\n\nEnter name of the product : ";
				cin >> sname;

				cout << "Enter price of product : ";
				cin >> sprice;

				ofstream out;
				out.open("product.txt");

				out << number + 1;
				out << endl;

				for (int i = 0; i < number; i++)
				{
					out << arr_key[i] << " " << product_name[i] << " " << arr_price[i] << endl;
				}
				out << arr_serial[save] << " " << sname << " " << sprice << endl;

				out.close();
			}


			if (choice == 'T')
			{
				int Buy_index = 0, Transaction_id = 0, Transaction_Ref = 0, Hash_Value = 0;
				string prod, Public_Key, Private_key;
				char b;
				

				cout << "\n\n\nThe Market today : \n\n\n";
				for (int i = 0; i < number; i++)
				{
					if (arr_serial[save] != arr_key[i])
					{
						cout << "Product : " << product_name[i];
						cout << "       Price : " << arr_price[i] << endl;
					}
				}
				cout << endl;

				cout << "Enter name of product you desire" << endl;
				cin >> prod;



				for (int i = 0; i < number; i++)
				{
					if (prod == product_name[i])
					{

						Buy_index = i;
					}
				}

				cout << "Would you like to buy this product\nPress B to buy the product " << endl;
				cin >> b;

				if (b == 'B')
				{
					cout << "Enter a private key\n";
					cin >> Private_key;

					cout << "Enter a public key\n";
					cin >> Public_Key;

					cout << "Enter Transaction id\n";
					cin >> Transaction_id;

					arr_bal[save] = arr_bal[save] - arr_price[Buy_index];
					arr_bal[Buy_index] = arr_bal[Buy_index] + arr_price[Buy_index];
					srand(time(NULL));
					Hash_Value = rand() % 10 + 1;

					Blockchain( Transaction_id, Public_Key, Hash_Value);

					ofstream out;
					out.open("product.txt");

					out << number - 1 << endl;

					for (int i = 0; i < number; i++)
					{
						if (product_name[i] != prod)
						{
							out << arr_key[i] << " " << product_name[i] << " " << arr_price[i] << endl;
						}
					}

					out.close();
					

					ofstream out1;
					out1.open("user.txt");

					out1 << num << endl;

					for (int i = 0; i < num; i++)
					{
						out1 << arr_serial[i] << " " << arr_name[i] << " " << arr_pass[i] << " " << arr_bal[i] << endl;
					}

					out1.close();
					

				}




				
			}


			if (choice == 'R')
			{
				bool check = false;
				string srname;

				cout << "\n\n\n\nEnter name of product you want to remove : ";
				cin >> srname;

				ofstream out;

				out.open("product.txt");




				for (int i = 0; i < number && check == false; i++)
				{
					if (product_name[i] == srname)
					{
						out << number - 1 << endl;
						check = true;
					}
				}

				if (check == false)
				{
					cout << "\n\nEnter a valid product\n\n\n";
					out << number << endl;
				}

				for (int i = 0; i < number; i++)
				{
					if (product_name[i] != srname)
					{
						out << arr_key[i] << " " << product_name[i] << " " << arr_price[i] << endl;
					}
				}

				out.close();
			}

			if (choice == 'W')
			{
				cout << "\n\n\nYour wallet has : " << arr_bal[save] << " bitcoins.\n\n\n";
			}

			if (choice == 'E')
			{
				cout << "\n\n\nGoodbye for now, Have a great day\n\n\n";
				work = false;
				op = false;
			}

			if (choice == 'B')
			{
				int size = 0;
				string a[100][100], b[100];
				int arr[100][100],id[100], ref[100], MinerId[100];
				

				ifstream fin;
				fin.open("Blockchain.txt");
				if (!fin)
					cout << "An Error has Occured in opening Blockchain.txt" << endl;

				else
				{
					fin >> size;

					for (int i = 0; i < size; i++)
					{

						fin >> id[i];
						fin >> ref[i];
						fin >> b[i];
						fin >> MinerId[i];

					}
					
					for (int i = 0; i < size; i++)
					{

						cout << "Transaction id: " << id[i] << " Transaction ref " << ref[i] << " Public id " << b[i] << " Miner id " << MinerId[i] << endl;

					}
			

				}
			}
		}
	}
}