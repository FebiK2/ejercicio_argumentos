#include <iostream>
#include <cctype>
#include <vector>


// Callback functions for different operations
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

// Function that performs an operation using a callback
void performOperation(int (*callback)(int, int), int x, int y)
{
    std::cout << "El resultado de la operación es: " << callback(x, y) << std::endl;
}

int main(int argc, char *argv[]){
    // Lectura de argumentos
    int num1;
    int num2;
    std::string op;
    if(argc != 4 && argc!=2){
        std::cout << "Ingrese los datos de la siguiente forma: " << "<num1> <operador> <num2>" << std::endl;
        std::cout << "O de forma combinada: " << "<num1> <operador> <num2>" << std::endl;
    
    }

    if (argc == 4){
        std::string arg1= argv[1];
        std::string arg2= argv[2];
        std::string arg3= argv[3];
    
        num1 = stoi(arg1);
        num2 = stoi(arg3);
        op = argv[2];
    }
    else if(argc == 2){
        std::string temp = argv[1];
        int size_temp = temp.size();

        // Recorrer argv[1], el primer número detectado será num1, se detecta el operador y el segundo número detectado será num2
        bool indicador = false;
        std::string temp_num1, temp_num2;
        
        for(int i = 0; i < size_temp; i++){

            if(isdigit(temp[i])){
                if (indicador == false){
                    temp_num1 = temp_num1 + temp[i];
                }
                else{
                    temp_num2 = temp_num2 + temp[i];
                }
            }
            else{
                indicador = true;
                op = temp[i];
            }
        
        }
        num1 = stoi(temp_num1);
        num2 = stoi(temp_num2);
    }

    std::cout << "Números: " << num1 << " y " << num2 << std::endl;
    // Passing different functions as callbacks
    if (op == "+"){
        std::cout << "Suma: ";
        performOperation(add, num1, num2);
    }
    else if (op == "x" || op == "X"){
        std::cout << "Multiplicación: ";
        performOperation(multiply, num1, num2);
    }
    else if (op == "-"){
        std::cout << "Resta: ";
        performOperation(subtract, num1, num2);
    }
    else{
        std::cout << "Operador No valido: " << op << " Los operadores deben ser suma (+), resta (-) y multipicación (x no usar *)" << std::endl;
    
    }
    int (*operations[])(int, int) = {add, multiply, subtract};

    return 0;
}