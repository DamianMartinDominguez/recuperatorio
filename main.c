/*
legajo:102757             Dominguez Damian                                  Email:d.dominguez@live.com.ar

Teoría
1) Explicar: Que es la fragmentación interna en memoria dinámica.
es la fragmentacion que se reserva para operar con la memoria dinamica

2) Como agrego un registro en MySql.
 con el comando insert into
Práctica

1) Existe un archivo binario “datos.dat” de organización secuencial, con la siguiente estructura:

clave (int),
 descripción (char de 20), 
 catidad (int),
  baja( char ‘A’:alta ‘B’baja)
  
Diariamente al finalizar el día se actualiza utilizando el archivo “Actual.dat” con la siguiente estructura:
clave(int),
operación(unsigned int), 
cantidad(int).

En el campo operación se encuentra la forma que se actualizará el archivo:
Bit 2 encendido: Se trata de una actualización positiva, hay que sumarle al registro datos campo cantidad el
contenido de actual cantidad, si existe un error, se guardará el registro en una Pila.
Bit 6 encendido: Se trata de un alta: Se deberá dar de alta el registro en el archivo “datos.dat” con los datos del
archivo “Actual.dat”(faltará el dato de la descripción), si existe un error, se guardará el registro en el archivo
“error.dat”.
Se pide realizar la actualización en el main() y 2 funciones que realice cada una de las tareas de actualización. No
utilizar variables Globales.
Enviar a Gustavo Viard: gviard_electronica@yahoo.com.ar



*/

#include<stdio.h>
#include<stdlib.h>



typedef struct {
 				int clave;
 				char descripcion[20];
 				int cantidad;
  				char baja; //( char ‘A’:alta    ‘B’baja)
  				
 				}     datos_t;
 				
typedef struct {
 				int clave;
 				unsigned int operacion;
 				int cantidad;
 				
 				
 				}     data_t;


struct pila{
			struct datos d;
			struct pila *l;
			}pila_t;


void crearPila (struct pila **l);

void actualizacion (void);


void actualizar()//Bit 2 encendido: Se trata de una actualización positiva, hay que sumarle al registro datos campo cantidad el contenido de actual cantidad, 
                 //si existe un error, se guardará el registro en una Pila.
void alta()		//Bit 6 encendido: Se trata de un alta: Se deberá dar de alta el registro en el archivo “datos.dat” con los datos del
           		//archivo “Actual.dat”(faltará el dato de la descripción), si existe un error, se guardará el registro en el archivo
           		//“error.dat”.


int main()

{
	pila_t *p=NULL,*aux=NULL;
	
	struct pila *aux;
	struct data_t bfa;
	struct data_t bfd;
	struct data_t bfe;
	FILE *fa;//puntero de archivo actual
	FILE *fd;//puntero de archivo datos
	FILE *fe;//puntero de archivo error
	
	
	
	
		if((fa=fopen("actual.dat","rb"))==NULL)
	{
		printf("\nno se puede leer el archivo\n");
		return;
	}
	
	if((fd=fopen("datos.dat","rb"))==NULL)
	{
		printf("\nno se puede leer el archivo\n");
		return;
	}
	
	if((fe=fopen("error.dat","ab"))==NULL)
	{
		printf("\nno se puede leer el archivo\n");
		return;
	}
	
	fread(&bfa,sizeof(datos_t)),fa);
	fread(&bfd,sizeof(datos_t)),fd);
	fread(&bfe,sizeof(datos_t)),fe);
	
	while(!feof(fa))
	{
			fread(&bfa,sizeof(datos_t)),fa);
			fread(&bfd,sizeof(datos_t)),fd);
	
	if(bfa.cantidad & ox04)//busco que el bit numero 2 tenga un 1
	{
		bfd.cantidad=bfa.cantidad;
		fwrite(bfd,sizeof(struct datos_t),1,fd);
	}
	
	else
	{
		aux=(pila_t*)malloc(sizeof(pila_t));
		aux->d=bfd;
		aux->l=p;
		p=aux;
		free(aux);
	}
	if((bfa.cantidad & ox20)&&(bfd.baja=='B'))//busco que el bit numero 6 tenga un 1
	{
		bfd.clave=bfa.clave;
		bfd.cantidad=bfa.cantidad;
		fwrite(bfd,sizeof(struct datos_t),1,fd);
	}
	if((bfa.cantidad & ox20)&&(bfd.baja=='A'))//caso que sea un error
	{
		fwrite(bfe,sizeof(struct datos_t),1,fe);
	}
}
	fclose(fd);
	fclose(fa);
	fclose(fe);
}


void crearPila (struct pila **l);
{
}	
	
void actualizacion (void);
{
	
}	
	
	
	
	
	
