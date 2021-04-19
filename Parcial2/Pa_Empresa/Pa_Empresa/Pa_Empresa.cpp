// Pa_Empresa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <string>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "Parcial_6163_YG", "*54168217Ny", "empleados", 3306, NULL, 0);
		if (conectar) {
			cout << "Ingreso Exitoso..." << endl;

			string Nombres, Apellidos, Direccion, Telefono, DPI, Genero, fecha_nacimiento, idPuestos, Fecha_inicio_labores, Fecha_ingreso;
			cout << "Ingrese Nombre: ";
			cin >> Nombres;
			cout << "Ingrese Apellidos: ";
			cin >> Apellidos;
			cout << "Ingrese Direccion: ";
			cin >> Direccion;
			cout << "Ingrese Telefono: ";
			cin >> Telefono;
			cout << "Ingrese DPI: ";
			cin >> DPI;
			cout << "Ingrese Genero: ";
			cin >> Genero;
			cout << "Ingrese fecha_nacimiento: ";
			cin >> fecha_nacimiento;
			cout << "Ingrese idPuestos: ";
			cin >> idPuestos;
			cout << "Ingrese Fecha_inicio_labores";
			cin >> Fecha_inicio_labores;
			cout << "Ingrese Fecha_ingreso: ";
			cin >> Fecha_ingreso;

			string insert = "insert into empleado (Nombres, Apellidos, Direccion, Telefono, DPI, Genero, fecha_nacimiento, idPuestos, Fecha_inicio_labores, Fecha_ingreso) values('" + Nombres + "', '" + Apellidos + "', '"+ Direccion + "', '"+ Telefono +"', '" + DPI + "', '" + Genero + "', '"+ fecha_nacimiento +"', '"+ idPuestos +"', '" + Fecha_inicio_labores + "', '" + Fecha_ingreso + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "**** Error al ingresar ****" << endl;
			}

			string consulta = "select * from empleados.empleado";
			const char* c = consulta.c_str();
			q_estado = mysql_query(conectar, c);
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			if (!q_estado) {
				resultado = mysql_store_result(conectar);

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10] << "," << fila[11] << endl;
				}
			}
			else {
				cout << "**** Error al ingresar la info****" << endl;
			}

			string e;
			cout << "Ingrese el idEmpleado a eliminar: ";
			cin >> e;
			string eliminar = "delete from empleados.empleado where idEmpleado= '" + e + "'";
			const char* f = eliminar.c_str();
			q_estado = mysql_query(conectar, f);
			
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "**** Error al ingresar ****" << endl;
			}

			string a;
			string b;
			string h;
			string j;
			string k;
			string l;
			string m;
			string n;
			string o;
			string p;
			string g;
			cout << "Ingrese el ID a Editar: ";
			cin >> g;
			cout << "Ingrese nuevo Nombre: ";
			cin >> a;
			cout << "Ingrese nuevo Apellido: ";
			cin >> b;
			cout << "Ingrese nueva Direccion: ";
			cin >> h;
			cout << "Ingrese nuevo Telefono: ";
			cin >> j;
			cout << "Ingrese nuevo DPI: ";
			cin >> k;
			cout << "Ingrese nuevo Genero: ";
			cin >> l;
			cout << "Ingrese nueva Fecha de Nacimiento: ";
			cin >> m;
			cout << "Ingrese nuevo idPuesto: ";
			cin >> n;
			cout << "Ingrese nueva Fecha incio de Labores: ";
			cin >> o;
			cout << "Ingrese nueva Fecha de ingreso: ";
			cin >> p;
			string editar = "update empleado set Nombres= '" + a + "', Apellidos= '" + b + "', Direccion= '" + h + "', Telefono= '" + j + "', DPI= '" + k + "', Genero= '" + l + "', Fecha_nacimiento= '" + m + "', idPuestos= '" + n + "', Fecha_inicio_labores= '" + o + "', Fecha_ingreso= '" + p + "' where idEmpleado= '" + g + "'";
			const char* c = editar.c_str();
			q_estado = mysql_query(conectar, c);

			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "**** Error al ingresar ****" << endl;
			}

		}
		else {
			cout << "Error en la Matrix..." << endl;
		}
		system("pause");
		return 0;
}
