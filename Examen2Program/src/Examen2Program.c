/*
 ============================================================================
 Name        : Examen2Program.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




typedef struct{

	int id;
	char marca[20];
	int tipo;
	float peso;

}eVehiculo;


eVehiculo* eVehiculo_New();
eVehiculo* eVehiculo_NewParametros(int id, char* marca, char tipo, float peso);
int eVehiculo_Set_Id(eVehiculo* Vehiculo, int id);
int eVehiculo_Set_Marca(eVehiculo* Vehiculo, char* Marca);
int eVehiculo_Get_tipo(eVehiculo* Vehiculo, char tipo);
int eVehiculo_Set_peso(eVehiculo* Vehiculo, float peso);

int main(void) {

	setbuf(stdout,NULL);
	eVehiculo* vehiculo;

	vehiculo=eVehiculo_NewParametros(12334, "Marca", 2, 34000);
	FILE* f = fopen("Archivo.txt","w");
	if(f == NULL)
	{
		printf("No se pudo cargar el archivo\n");
		exit(1);
	}


	if(fwrite(vehiculo,sizeof(eVehiculo),1,f)==1)
	{
		printf("Vehiculo guardado con exito\n");
	}

	fclose(f);



	return EXIT_SUCCESS;
}


eVehiculo* eVehiculo_New()
{
	eVehiculo* nuevoVehiculo;

	nuevoVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
	if(nuevoVehiculo!=NULL)
	{
		nuevoVehiculo->id=0;
		strcpy(nuevoVehiculo->marca,"nnn");
		nuevoVehiculo->tipo=0;
		nuevoVehiculo->peso=0;
	}

	return nuevoVehiculo;
}

eVehiculo* eVehiculo_NewParametros(int id, char* marca, char tipo, float peso)
{
	eVehiculo* nuevoVehiculo;

	nuevoVehiculo = eVehiculo_New();
	if(nuevoVehiculo!=NULL)
	{
		if( !( eVehiculo_Set_Id(nuevoVehiculo, id) &&
				eVehiculo_Set_Marca(nuevoVehiculo, marca) &&
				eVehiculo_Get_tipo(nuevoVehiculo, tipo) &&
				eVehiculo_Set_peso(nuevoVehiculo, peso) ) ) {

			free(nuevoVehiculo);
			nuevoVehiculo=NULL;
		}
	}

	return nuevoVehiculo;
}

int eVehiculo_Set_Id(eVehiculo* Vehiculo, int id)
{
	int rtn=0;

	if(Vehiculo!=NULL && id>=10000 && id<=50000)
	{
		Vehiculo->id=id;
		rtn=1;
	}else {
		printf("Id invalido\n");
	}

	return rtn;
}

int eVehiculo_Set_Marca(eVehiculo* Vehiculo, char* Marca)
{
	int rtn=0;
	char Auxmarca[20];

	if(Vehiculo!=NULL && Marca!=NULL && strlen(Marca)<20 && strlen(Marca)>2)
	{
		strcpy(Auxmarca,Marca);
		strlwr(Auxmarca);
		Auxmarca[0] = toupper(Auxmarca[0]);
		strcpy(Vehiculo->marca,Auxmarca);
		rtn=1;
	}else {
		printf("Nombre invalido\n");
	}

	return rtn;
}

int eVehiculo_Get_tipo(eVehiculo* Vehiculo, char tipo)
{
	int rtn=0;

	if(Vehiculo!=NULL)
	{
		tipo=Vehiculo->tipo;
		rtn=1;
	}

	return rtn;
}

int eVehiculo_Set_peso(eVehiculo* Vehiculo, float peso)
{
	int rtn=0;

	if(Vehiculo!=NULL && peso>=20000 && peso<=500000)
	{
		Vehiculo->peso=peso;
		rtn=1;
	} else {
		printf("Sueldo invalido\n");
	}

	return rtn;
}
