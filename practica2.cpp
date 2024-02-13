#include <iostream>
#include <stdlib.h>
using namespace std;

class Usuario{
private:
    string nombre;
    int telefono;
    int edad;
    string contra;

protected:
    bool sesionIniciada;

public:
    Usuario(string,int,int,string);
    virtual void login(string, string);
    void deslogear();
    void cambiar_contra(string);
};

//Constructor Usuario
Usuario::Usuario(string _nombre, int _telefono, int _edad, string _contra){
    nombre = _nombre;
    telefono = _telefono;
    edad = _edad;
    contra = _contra;
    sesionIniciada = false;
}

class Cliente : public Usuario{
    private:
        int numeroCliente;
    public:
    Cliente(string, int, int, string, int);
    void comprar();
    void reclamar();
    void devolver();
};

//Constructor de cliente 
Cliente::Cliente(string _nombre, int _telefono, int _edad, string _contra, int _numeroCliente) : Usuario(_nombre,_telefono,_edad,_contra){
    numeroCliente = _numeroCliente;
}

class Vendedor : public Usuario{
    private:
    int numVendedor;
    public:
    Vendedor(string, int, int, string, int);
    void vender();
    void actualizar();
};

//Contructor de vendedor
Vendedor::Vendedor(string _nombre, int _telefono, int _edad, string _contra, int _numVendedor) :Usuario(_nombre,_telefono,_edad,_contra){
    numVendedor = _numVendedor;
}

//metodo para iniciar sesion
void Usuario::login(string nombre, string contra) {
    if (nombre == this->nombre && contra == this->contra) {
        cout << "Bienvenido, " << nombre << " tu sesión esta iniciada." << endl;
        sesionIniciada = true;
    } else {
        cout << "Error: Nombre de usuario o contraseña incorrectos." << endl;
    }
}

void Usuario::deslogear() {
    if (sesionIniciada) {
        cout << "Sesión cerrada para usuario " << nombre << endl;
        sesionIniciada = false;
    } else {
        cout << "Error: No hay ninguna sesión iniciada para este usuario." << endl;
    }
}

void Usuario::cambiar_contra(string nuevaContra) {
    cout << "Contraseña anterior: " << contra << endl;
    contra = nuevaContra;
    cout << "Contraseña nueva: " << nuevaContra << endl;
    cout << "Contraseña cambiada para usuario " << nombre << "." << endl;
}

void Cliente::comprar(){
    if (sesionIniciada) {
        cout << "El cliente está comprando" << endl;
    } else {
        cout << "Error: La sesión no está iniciada." << endl;
    }
}

void Cliente::reclamar(){
    if (sesionIniciada) {
        cout << "El cliente está reclamando" << endl;
    } else {
        cout << "Error: La sesión no está iniciada." << endl;
    }
}

void Cliente::devolver(){
    if (sesionIniciada) {
        cout << "El cliente está devolviendo" << endl;
    } else {
        cout << "Error: La sesión no está iniciada." << endl;
    }
}

void Vendedor::vender(){
   if (sesionIniciada) {
        cout << "El vendedor está vendiendo" << endl;
    } else {
        cout << "Error: La sesión no está iniciada." << endl;
    }
}

void Vendedor::actualizar(){
    if (sesionIniciada) {
        cout << "El vendedor está actualizando" << endl;
    } else {
        cout << "Error: La sesión no está iniciada." << endl;
    }
}

int main(){

    Cliente cliente1("Cliente1", 12345, 20, "contra123", 001);
    Vendedor vendedor1("Vendedor1", 12234, 50, "password", 002);

    cliente1.login("Cliente1", "contra123"); 
    cliente1.comprar();
    cliente1.cambiar_contra("nuevaContra123"); 
    cliente1.deslogear(); 

    vendedor1.login("Vendedor1", "password"); 
    vendedor1.actualizar();
    vendedor1.cambiar_contra("mundogei");
    vendedor1.deslogear(); 

    return 0;
}

