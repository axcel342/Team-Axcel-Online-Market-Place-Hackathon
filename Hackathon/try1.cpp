//#include<iostream>
//#include<bitset>
//#include<map>
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>
//#include<fstream>
//#include<string.h>
//
//using namespace std;
//
////void encryptyfunc( string text )
////{
////    char text[100];
////    char temp;
////    int i, key;
////
////    //cout << "Enter a message to encrypt: " << endl;
////   // cin >> text;
////    cout << "Enter key: " << endl;
////    cin >> key;
////    for (i = 0; text[i] != '\0'; ++i) {
////        temp = text[i];
////        //If the message to be encypted is in lower case
////        if (temp >= 'a' && temp <= 'z') {
////            temp = temp + key;
////
////            if (temp > 'z') {
////                temp = temp - 'z' + 'a' - 1;
////            }
////
////            text[i] = temp;
////        }
////        //If the message to be encypted is in upper case
////        else if (temp >= 'A' && temp <= 'Z') {
////            temp = temp + key;
////
////            if (temp > 'Z') {
////                temp = temp - 'Z' + 'A' - 1;
////            }
////
////            text[i] = temp;
////        }
////    }
////
////    cout << "Encrypted message:" << text << endl;
////}
////
//int stringHashing( int a )
//{
//
//    // Get the string
//    // to get its hash value
//    int hashing1 = a;
//
//    // Instatiation of Object
//    hash<int> mystdhash;
//
//    return mystdhash(hashing1);
//       
//}
//
//int ProofofWork(int HashValue)
//{
//    int Pof = 0, Miner1 = 0, Miner2 = 0, Miner3 = 0, Winner;
//    bool check = false;
//    /* initialize random seed: */
//    srand(time(NULL));
//
//    /* generate secret number between 1 and 10: */
//  //  Pof = rand() % 10 + 1;
//    Pof = HashValue;
//    int count = 0;
//
//    time_t start1, start2, start3;
//
//    do
//    {
//
//        Miner1 = rand() % 10 + 1;
//        start1 = time(NULL);
//        Miner2 = rand() % 10 + 1;
//        start2 = time(NULL);
//        Miner3 = rand() % 10 + 1;
//        start3 = time(NULL);
//
//        if (Miner1 == Pof || Miner2 == Pof || Miner3 == Pof)
//        {
//            check = true;
//
//            if (Miner1 == Pof)
//                Winner = 1;
//
//            if (Miner2 == Pof)
//                Winner = 2;
//
//            if (Miner3 == Pof)
//                Winner = 3;
//
//            if (Miner1 == Pof && Miner2 == Pof && Miner3 == Pof)
//            {
//                /*if( difftime(start1, difftime(start2,start3)) > 0 )
//                    Winner = 1;*/
//
//
//                if (start1 > start2 && start1 > start3) {
//                    Winner = 1;
//                }
//                else if (start2 > start1 && start2 > start3) {
//                    Winner = 2;
//                }
//                else {
//                    Winner = 3;
//                }
//            }
//
//            else if (Miner1 == Pof && Miner2 == Pof)
//            {
//                if (start1 > start2)
//                    Winner = 1;
//
//                else
//                    Winner = 2;
//            }
//
//            else if (Miner1 == Pof && Miner3 == Pof)
//            {
//                if (start1 > start3)
//                    Winner = 1;
//
//                else
//                    Winner = 3;
//            }
//
//            else if (Miner2 == Pof && Miner3 == Pof)
//            {
//                if (start2 > start3)
//                    Winner = 2;
//
//                else
//                    Winner = 3;
//            }
//
//
//        }
//        count++;
//
//
//    } while (check == false);
//
//
//  //  cout << count << endl;                //Too check count of loops
//
//    
//
//
//    if (Winner == 1)
//    {
//        cout << "Miner1 prevails" << endl;
//        return 1;
//    }
//    if (Winner == 2)
//    {
//        cout << "Miner2 prevails" << endl;
//        return 2;
//    }
//    if (Winner == 3)
//    {
//        cout << "Miner3 prevails" << endl;
//        return 3;
//    }
//}
//
//void Blockchain(int Transaction_id, int Transaction_Ref , string Public_Key ,int Hash_Value)
//{
//
//    int size = 0;
//    int arr[100][4] = { 0 };
//    string a[100][1];
//    ifstream fin;
//    fin.open("Blockchain.txt");
//    if (!fin)
//        cout << "An Error has Occured in opening Blockchain.txt" << endl;
//
//    else
//    {
//        fin >> size;
//
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = 0; j < 4; j++)
//            {
//                
//                
//                if (j == 2)
//                    fin >> a[i][1];
//
//                else
//                    fin >> arr[i][j];
//            }
//
//        }   
//        
//    }
//
//    size++;
//    
//    arr[size - 1][0] = Transaction_id;
//    arr[size - 1][1] = arr[size - 2][1];
//    a[size - 1][1] = Public_Key;
//    arr[size - 1][3] = ProofofWork(Hash_Value);
//    
//            
//    fin.close();
//
//    ofstream fout;
//    fout.open("Blockchain.txt");
//
//    if (!fout)
//        cout << "An error has occured while writing to Blockchain.txt" << endl;
//
//    else
//    {
//        
//        fout << size<<endl;
//
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = 0; j < 4; j++)
//            {
//                if( j == 2 )
//                    fout << a[i][1] <<" ";
//                else
//                    fout << arr[i][j]<<" ";
//            }
//            fout << endl;
//
//        }
//    }
//
//    fout.close();
//
//    
//}
//
//int main()
//{
//	/*map<int, int> Customer;
//
//    string a = "wow";
//    string b = "wow";
//
//    Customer.insert(std::pair<int, int>(1, stringHashing(a)));*/
//    
//    int x = 0;
//
//    x = rand() % 10 + 1;
//
//    Blockchain(1990,2000, "hvdn38346", x);
//
//    /*string a = "10";
//
//    cout << stringHashing(a) << endl;
//
//
//    encryptyfunc();*/
//
//
//	return 0;
//}
