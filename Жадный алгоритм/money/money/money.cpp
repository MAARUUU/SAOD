#include <iostream>
#include <fstream>

//В обращении имеются монеты 1-,2-,5-,10-,25-копеечного достоинства. 
 //Jпределить сдачу наименьшим количеством монет

using namespace std;

int main()
{
    setlocale(0, "");
    ofstream fout("File.txt", ios::app);
    int money;
    int coins[] = { 25, 10 , 5 ,2, 1 };
    int i = 0;

   cout << "Введите сумму:  ";
    cin >> money;
    fout << "Монеты:  " << money ;
    cout  << "Размен монет: ";
    fout <<endl<<"Размен монет: ";
    int k = 0;

    while (money > 0) {

        if (money % coins[i] != money) {

            money -= coins[i];
            cout << coins[i] << " ";
            fout << coins[i] << " ";
            k++;
        }
        else i++;
    }
    fout << endl;
    cout << endl;
    cout << "Количество монет   " << k << endl;
    fout << "Количество монет   " << k << endl;
    fout <<"====================================="<< endl;
    fout.close();
    system("pause");
}