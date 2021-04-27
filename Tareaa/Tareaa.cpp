// Tareaa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;

int main()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "4716", "clientes", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion Exitosa..." << endl; 
        string Clientes_1;
        cout << "Ingrese cliente:";
        cin >> Clientes_1;
        string insert = "insert into Clientes_1(clientes) values('" + Clientes_1 + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitoso..." << endl;
        }
        else {
            cout << "xxx  Error al ingresar  xxx" << endl;
        }

        string consulta = "select * from puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << " xxx Error al consultar xxx" << endl;
        }
    }
    else {
        cout << "Error en la conexion... " << endl;

    }
    system("pause");
    return 0;

}

