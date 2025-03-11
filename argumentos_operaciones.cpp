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
    // Método 1, que los datos ingresados tengan espacios entre ellos (num1 + num2)
    if (argc == 4){
        // Se convierte a string cada argumento ingresado
        std::string arg1= argv[1];
        std::string arg2= argv[2];
        std::string arg3= argv[3];
    // Se verifica si los argumentos en las posiciones 1 y 3 del arreglo argv son numeros
        num1 = stoi(arg1);
        num2 = stoi(arg3);
    // Se le asigna a op el caracter de la posición 2 de argv
        op = argv[2];
    }
    // Método 2, que los datos sean ingresados sin espacios (num1xnum2)
    else if(argc == 2){
        // Se crea una variable de tipo string para asignarle el elemento de la posición 1 de argv
        std::string temp = argv[1];
        int size_temp = temp.size();

        // Recorrer argv[1], el primer número detectado será num1, se detecta el operador y el segundo número detectado será num2
        // Un indicador para saber cuando se detecta el signo o caracter no numerico
        bool indicador = false;
        std::string temp_num1, temp_num2;
        for(int i = 0; i < size_temp; i++){
            // Se recorre elemento 1 de argv (porque su tamaño es de 2 y la operación estaría asignada a la posición 1)
            if(isdigit(temp[i])){
            // Indicador se va modificando el indicador del signo, si es true es porque el elemento actual del string temp no es un número sino un caracter
            // Esta condición permite detectar el primer número antes del signo
            // En caso de tener más de un digito, va concatenando caracteres númericos   
                if (indicador == false){
                    temp_num1 = temp_num1 + temp[i];
                }
            // Esta condición detecta el segundo numero, luego del signo
            // En caso de tener más de un digito, va concatenando caracteres númericos
                else{
                    temp_num2 = temp_num2 + temp[i];
                }
            }
            // Si el elemento actual no es un número, indicador = true y se detecta signo
            else{
                indicador = true;
                op = temp[i];
            }
        
        }
        // Se asignan los respectivos valores númericos a num1 y num2
        num1 = stoi(temp_num1);
        num2 = stoi(temp_num2);
    }

    std::cout << "Números: " << num1 << " y " << num2 << std::endl;

    // Mediante Condiciones, se evalua a que es igual la variable op y si es una operación válida, la realiza
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