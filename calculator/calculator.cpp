#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib> // для функций strtol, exit
#include <unistd.h> // для функции getopt
using namespace std;

void help()
{
    std::cout << "Параметры:\n'-s' Сумма операндов\n'-v' Вычитание операндов\noperand 2-4  \n";
    exit(1);
}

int main (int argc, char *argv[])
{
    int Summa=0, a=0;
    int Rez;
    string Operation=argv[1];
    if(Operation=="-o summa") {
        for (int i = 2; i < argc; i++) {
            Summa+=atoi(argv[i]);
        }
        cout<<"Результат вычислений: "<<Summa<<endl;
    } else if(Operation=="-o subtraction") {
        Rez=atoi(argv[2]);

        for (int i = 3; i < argc; i++) {
            Rez-=atoi(argv[i]);
        }
        cout<<"Результат вычислений: "<<Rez<<endl;
    } else if(argc <2 || argc >4) {
        cout<<"Количество операндов от 2 до 4"<<endl;
        help();
    } else if(argc==1) {
        cout<<"Введите операцию:\nСумма:-o summa\nВычитание:-o subtraction"<<endl;
        cout<<"Далее введите операнды"<<endl;
        cout<<"Пример: -o summa 1 2 3\nРезультат вычислений: 6"<<endl;
    }
    int opt, as=0;
    while((opt = getopt(argc, argv, "s:r:h")!= -1)) {
        switch (opt) {
        case 's':
            if (as == 0) {
                cout << "-o summa: " << as+(a) << endl;
                as+=1;
            }
            break;
        case 'r':
            if (as == 0) {
                cout << "-o subtraction" << as-(a) << endl;
                as+=1;
            }
            break;
        case '?':
            help();
        case 'h':
            help();
        }
    }
    if (as == 0) {
        help();
    }
    return 0;
}
