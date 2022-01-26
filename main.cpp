#include <iostream>
using namespace std;

int vvod();
int recursion(int n, int* arr, int& CallCount, int* memory, int DepthLevel, int* Levels);
void vivod(int CallCount, int* arr, bool D);

int main()
{
    int arr[99]; // массив множителей
    int CallCount = 0;  //  Переменная для количества вызовов рекурсивной функции
    int memory[50];   // Массив значений изменяющегося параметра n
    int DepthLevel = 0; // Переменная для индекса текущего уровня для каждой вызванной функции
    int Levels[50];  // Массив для отслеживания глубины рекурсии при расчете от 0 при первом вызове
     
    cout << "Input a number ";
    int n;
    n = vvod();
    cout << "Choose how to decompose the number \n1 - from the lowest\n2 - from the biggest" << endl;
    int p;
    cin >> p;
    bool D;
    switch (p)
    {
    case 1:
        D = true;
        cout << "\n///////////////////////////////////////////////////////////////\n" << endl;
        cout << "Decomposing number " << n << " on multipliers from the lowest: \n";
        break;
    case 2:
        D = false;
        cout << "\n///////////////////////////////////////////////////////////////\n" << endl;
        cout << "Decomposing number " << n << " on multipliers from the biggest: \n";
        break;
    default:
        cout << "You'be inputted the wrong variant option\nOnly 1 and 2 are avaible\nTry again" << endl;
        return 1;
        
    }

    CallCount = recursion(n, arr, CallCount, memory, DepthLevel, Levels); // вызов рекурсии
    vivod(CallCount, arr, D); // вывод на экран множителей
    cout << endl;

    cout << "\nAmount of calls to recursive function = " << CallCount << endl;
    cout << endl;

    cout << "Array of n argumetn values : " << endl;
    for (int i = 0; i <= CallCount - 1; i++) cout << memory[i] << " ";
    
    cout << endl;

    cout << "\nAn array to keep track of the recursion depth when calculating from 0 the first time the function is called: " << endl;
    for (int i = 0; i <= CallCount - 1; i++) cout << Levels[i] << " ";
    
    cout << endl;
    return 0;
}

int vvod()
{
    int n;
    do
    {
        if (!(cin >> n))
        {
            cin.clear();
            while (cin.get() != '\n');
            cerr << "Invalid input.\nThe number must be an integer and greater than 1\nPlease try again.\n ";
            continue;
        }

        if (cin.peek() != '\n')
        {
            cin.ignore(cin.rdbuf()->in_avail());
            cerr << "Invalid input.\nThe number must be an integer and greater than 1\nPlease try again.\n ";
            continue;
        }

        if (n <= 1)
        {
            cin.clear();
            while (cin.get() != '\n');
            cerr << "Invalid input.\nThe number must be an integer and greater than 1\nPlease try again.\n ";
            continue;
        }
        break;
    } while (true);
    return n;
}
// Рекурсия
int  recursion(int n, int* arr, int &CallCount, int *memory, int DepthLevel, int *Levels)
{
    int num;
    if (n == 1)  return CallCount;  // Условие выхода из рекурсии  
    num = 2;
    while (n % num != 0)
        num++;

    memory[CallCount] = n;
    Levels[CallCount] = DepthLevel;
    CallCount++;
    arr[CallCount] = num;

    recursion(n / num, arr, CallCount, memory, DepthLevel + 1, Levels);  
}

void vivod(int CallCount, int* arr, bool D)
{
    if (D == true)
    {
        // cout << "\nВывод множителей, начиная с наименьшего: " << endl;
        for (int i = 1; i <= CallCount; i++)
        {
            cout << arr[i] << " ";
        }
    }
    if (D == false)

    {
       //  cout << "\nВывод множителей, начиная с наибольшего: " << endl;
        for (int i = CallCount; i > 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
}
