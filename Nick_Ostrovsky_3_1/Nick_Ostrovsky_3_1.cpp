

#include <iostream>
#include <fstream>
int main()
{
    int n = 0;
    int m = 0;
    std::cout << "Hello World!\n";
    std::ifstream in ("in.txt");
    //проверка удачного открытия
    if (in.is_open())
    {
        std::cout << "in.txt is_open() value: \t" << in.is_open() << std::endl;
    }
    else
    {

        std::cout << " File not found \t" << in.is_open() << std::endl;
        return (-1);
    }
    // создание и чтение массива N
    in >> n;
    int* arrayN = new int [n];
    for (int i = 0; i < n; i++)
    {
        in >> arrayN[i];
      //  std::cout << arrayN[i];
    
    }
    //создание и чтение массива M
    in >> m;
    int* arrayM = new int[m];
    for (int i = 0; i < m; i++)
    {
        in >> arrayM[i];

    }
    //перемена местами элементов массива M
    int half = m / 2;
    for (int i = 0; i < half; i++)
    {
        int temp = arrayM[i];
        arrayM[i] = arrayM[m - 1 - i];
        arrayM[m - 1 - i] = temp;
        

    }
   /* for (int i = 0; i < n; i++)
    {
        std::cout << arrayN[i] << "\t";


    }*/
    //перемена мест элементов массива M 
    int temp_N = arrayN[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            arrayN[i] = arrayN[i + 1];
        }
        else
        {
            arrayN[i] = temp_N;
        }


    }

   // int temp = arrayN[0];
     //   arrayN[0] = arrayN[n - 1];
     //   arrayN[n - 1] = temp;
    /*    for (int i = 0; i < n; i++)
        {
            std::cout << arrayN[i] << "\t";


        }
        */
        std::ofstream out("out.txt");
        out << m << std::endl;
        for (int i = 0; i < m; i++)
        {
            out << arrayM[i] << " ";

        }
        out << "\n" << n << std::endl;

        for (int i = 0; i < n; i++)
        {
            out << arrayN[i] << " ";

        }
        delete[] arrayN;
        delete[] arrayM;
        in.close();
        out.close();
        return (0);
}

