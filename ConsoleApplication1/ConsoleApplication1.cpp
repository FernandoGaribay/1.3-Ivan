// Agregación-Composición.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Librerías

#include <iostream>
#include <string.h>

using namespace std;
#pragma warning(disable: 4996);

//Clases

class Cliente {
private:
    int numCliente;
    char* nomCliente;
    char* direccion;

public:
    Cliente();
    Cliente(char const* nom, int num, char const* dir);
    ~Cliente();

    void setNomC(char const*);
    char* getNomC();
    void setNumC(int);
    int getNumC();
    void setDirC(char const*);
    char* getDirC();

    void mostrarCliente();
};

class Empleado {
private:
    int nomina;
    char* empleado;
    int sueldo;

public:
    Empleado();
    Empleado(char const* nom, int num, int sueldo);
    ~Empleado();

    void setEmp(char const*);
    char* getEmp();
    void setNomina(int);
    int getNomina();
    void setSueldo(int);
    int getSueldo();

    void mostrarEmpleado();
};

class Empresa {
private:
    char* nombre;
    Cliente clientes[1];
    int posicion = 0;

public:
    Empleado empleados[2];
    Empresa();
    Empresa(char const* nom, int pos);
    ~Empresa();
    void setNombre(char const* nom1);
    char* getNombre();
    void agregarEmpleado(Empleado emp[]);
    void mostrarEmpleado();
    void agregarCliente(Cliente cl);
    void mostrarCliente();
    void mostrarEmpresa();
    double sueldoSuma();
};

//Constructores y Destructor

Empresa::Empresa() {
    nombre = new char[50];
    posicion = 0;
    setNombre("Ceti MX");
}

Empresa::Empresa(char const* nom, int pos) {
    nombre = new char[strlen(nom) + 1];
    posicion = pos;
    setNombre(nom);
}

Empresa::~Empresa() {
}

Cliente::Cliente() {
    nomCliente = new char[50];
    numCliente = 0;
    direccion = new char[50];
    setNomC("");
    setNumC(0);
    setDirC("");
}

Cliente::Cliente(char const* nom, int num, char const* dir) {
    nomCliente = new char[strlen(nom) + 1];
    setNomC(nom);
    setNumC(num);
    setDirC(dir);
}

Cliente::~Cliente() {
}

Empleado::Empleado() {
    empleado = new char[50];
    nomina = 0;
    sueldo = 0;
    setEmp("");
    setNomina(0);
    setSueldo(0);
}

Empleado::Empleado(char const* empleado, int nomina, int sueldo) {
    empleado = new char[strlen(empleado) + 1];
    setEmp(empleado);
    setNomina(nomina);
    setSueldo(sueldo);
}

Empleado::~Empleado() {
}

//Métodos get/set

void Empresa::setNombre(char const* nomEmpresa) {
    strcpy(nombre, nomEmpresa);
}
char* Empresa::getNombre() {
    return nombre;
}

void Cliente::setNomC(char const* nomC) {
    strcpy(nomCliente, nomC);
}
char* Cliente::getNomC() {
    return nomCliente;
}
void Cliente::setNumC(int numC) {
    numCliente = numC;
}
int Cliente::getNumC() {
    return numCliente;
}
void Cliente::setDirC(char const* DirC) {
    strcpy(direccion, DirC);
}
char* Cliente::getDirC() {
    return direccion;
}

void Empleado::setEmp(char const* nomE) {
    strcpy(empleado, nomE);
}
char* Empleado::getEmp() {
    return empleado;
}
void Empleado::setNomina(int numN) {
    nomina = numN;
}
int Empleado::getNomina() {
    return nomina;
}
void Empleado::setSueldo(int salario) {
    sueldo = salario;
}
int Empleado::getSueldo() {
    return sueldo;
}


//Métodos

void Empresa::agregarEmpleado(Empleado emp[]) {
    for (int i = 0; i < 2; i++) {
        empleados[i] = emp[i];
    }
}

void Empresa::mostrarEmpleado() {
    for (int i = 0; i < 2; i++) {
        cout << "Empleado: " << i + 1 << " " << empleados[i].getEmp() << endl;
    }
}

void Empresa::agregarCliente(Cliente cl) {
    if (posicion < 2) {
        clientes[posicion] = cl;
        posicion++;
    }
}

void Empresa::mostrarCliente() {
    for (int i = 0; i <= posicion; i++) {
        cout << "Cliente: " << i + 1 << " " << clientes[i].getNomC() << endl;
    }
}

double Empresa::sueldoSuma() {
    double sueldoTotal;

    sueldoTotal = empleados[0].getSueldo() + empleados[1].getSueldo();

    return sueldoTotal;
}

void Empresa::mostrarEmpresa() {
    cout << "Nombre de la empresa:  " << getNombre() << endl;
}

void Cliente::mostrarCliente() {
    cout << "Nombre de cliente:     " << getNomC() << endl;
    cout << "Numero de cliente:     " << getNumC() << endl;
    cout << "Direccion:             " << getDirC() << endl;
}

void Empleado::mostrarEmpleado() {
    cout << "Nombre del emplelado:  " << getEmp() << endl;
    cout << "# de nomina:           " << getNomina() << endl;
    cout << "Sueldo:                " << getSueldo() << endl;
}



// M A I N 

int main()
{
    Empresa CETI_MX;
    Cliente cliente;
    Empleado empleados[2];

    cliente.setNomC("CETI Colomos");
    cliente.setNumC(2131);
    cliente.setDirC("Calle Nueva Escocia #1885");

    empleados[0].setEmp("Jo");
    empleados[0].setNomina(21310417);
    empleados[0].setSueldo(14000);

    empleados[1].setEmp("Mike");
    empleados[1].setNomina(21310434);
    empleados[1].setSueldo(14000);

    CETI_MX.agregarEmpleado(empleados);

    CETI_MX.mostrarEmpresa();
    cout << "\n";

    cliente.mostrarCliente();
    cout << "\n";

    cout << "Empleados actuales\n" << endl;
    empleados[0].mostrarEmpleado();
    cout << "\n";
    empleados[1].mostrarEmpleado();
    cout << "\n";

    cout << "Sueldo combinado: " << CETI_MX.sueldoSuma() << endl;


    return 0;
}