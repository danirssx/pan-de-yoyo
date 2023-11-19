/*******************************************************************************************************
 *
 * Filename: Proyecto_Tienda_de_Articulos_(Base).cpp
 *
 * Proposito: Base para el Proyecto Tienda de Artículos (Proyecto de Algoritmos y Estructuras de Datos)
 *
 * Language: C (Extendido)
 *
 * Compilador: G++ 3.4.2 
 *
 * Autor:  Antonio Lemus
 *
 * Date: 13.11.2023
 *          
 * Copyleft (L) Universidad Católica Andrés Bello (UCAB) - Escuela de Ingenieria Informática 
 *
 ******************************************************************************************************/

// ---------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ---------------------------------------------------------------------
#include <conio.h>
//
#include <iostream>
using namespace std;
// ---------------------------------------------------------------------
#define ARCHIVO_ARTICULOS "Articulos.txt"
#define ARCHIVO_VENDEDORES "Vendedores.txt"
//
#define numero_de_columnas_archivo 20
// ---------------------------------------------------------------------
// Declaración de Tipos y Variables Globales 
// ---------------------------------------------------------------------	

	// ----------------------------------------------------------------------------
	// TDAs Listas Simplemente Enlazadas 
	// ----------------------------------------------------------------------------

	// ---------------------------------------------------------------------
	// articulos 
	// ---------------------------------------------------------------------	
		
	struct articulos {
		
		char codigo[numero_de_columnas_archivo];
		char nombre[numero_de_columnas_archivo];
		float precio;
		int cantidad;
	
	};	
	
	// En esta variable global se lleva el conteo del numero actual de articulos
	int numero_de_articulos = 0;

	// Tipos Auxiliares
	struct articulos articulo_entrante;	
	int clave_articulo;
	
	// ----------------------------------------------------------------------------	

	struct nodo_articulo {
		//
		int clave;
		//
		struct articulos articulo;
		// 
		struct nodo_articulo *siguiente;
		//
	};
	
	// ----------------------------------------------------------------------------
	
	nodo_articulo *apuntador_a_articulo = NULL; 
	nodo_articulo *aux_articulo = NULL; 
	//
	nodo_articulo *Lista_Articulos = NULL; 	
	
	// ----------------------------------------------------------------------------
	
	// ---------------------------------------------------------------------
	// vendedores
	// ---------------------------------------------------------------------	
	
	struct fecha {
	  int dia;
	  int mes;
	  int anio;
	};
	  
	struct vendedores {
	  char nombre[20];
	  char ci[10];
	  struct fecha fechaing;
	  int comision; 		
	};
	
	struct nodo_vendedor { 
	  struct vendedores vendedor;
	  struct nodo_vendedor *siguiente;
	};
	
	// ----------------------------------------------------------------------------
	
	nodo_vendedor *apuntador_a_vendedor = NULL; 
	nodo_vendedor *aux_vendedor = NULL; 
	//
	nodo_vendedor *Lista_Vendedores = NULL; 	
	
	// ----------------------------------------------------------------------------
	
		
	// Tipos Auxiliares
	struct vendedores vendedor_entrante;		
	
	// ----------------------------------------------------------------------------
	// Definicion de Operaciones 
	// ----------------------------------------------------------------------------
	
	// ---------------------------------------------------------------------
	// Crear_Articulo
	// ---------------------------------------------------------------------	
	void Crear_Articulo(int clave, struct articulos nuevo_articulo, nodo_articulo *L) 
	{
	  	// La Lista puede o no ser NULL	
	   	
	   	aux_articulo = new nodo_articulo; // aux = (nodo_articulo *) malloc(sizeof(nodo_articulo)); (Equivalentes)
	  	
	   	
		// nodo_articulo *anterior = (nodo_articulo *) malloc(sizeof(nodo_articulo));
		nodo_articulo *anterior = new nodo_articulo; 
		
		// nodo_articulo *i = (nodo_articulo *) malloc(sizeof(nodo_articulo));
	   	nodo_articulo *i = new nodo_articulo; 
	   	
		i = L;
	   	
		 do
		  {
		     anterior = i;
			 i = i->siguiente;
		  }  while( i != NULL );
		  
	 
	  	// Ingreso al final o en la cola
	  	/*
		printf("\n Ingresar Articulo Clave: %d", clave);
	 	printf("\n Articulo Codigo: %s", nuevo_articulo.codigo);
	 	printf("\n Articulo Nombre: %s", nuevo_articulo.nombre);
	 	printf("\n Articulo Precio: %.2f", nuevo_articulo.precio);
	 	printf("\n Articulo Cantidad: %d", nuevo_articulo.cantidad);
	 	*/
	 	
	  	aux_articulo->clave = clave; 
		  
		// aux_articulo->articulo.codigo = nuevo_articulo.codigo; 
	  	strcpy(aux_articulo->articulo.codigo, nuevo_articulo.codigo);

		strcpy(aux_articulo->articulo.nombre, nuevo_articulo.nombre);
		
		aux_articulo->articulo.precio = nuevo_articulo.precio;
		
		aux_articulo->articulo.cantidad = nuevo_articulo.cantidad;
			  	
	  	//
	  	aux_articulo->siguiente = NULL;
	  
	  	anterior->siguiente = aux_articulo; 
		//   	
	  	
	    cout<<"\nNuevo Ariculo Insertado al Final de la Lista..!\n";
 	
 	    system("pause");
	 
	}								 
	// ---------------------------------------------------------------------	

	// ---------------------------------------------------------------------
	// primitiva Insertar_Articulo_En_Cabeza
	// ---------------------------------------------------------------------		
	nodo_articulo * Insertar_Articulo_En_Cabeza(int clave, struct articulos nuevo_articulo, nodo_articulo *L) 
	{	  	
		// Lista_Articulo: L	
	   
	   // Nota: nodo *aux_articulo = NULL; (Puntero a Nodo Articulo Declarado Variable Global)		  
		
		aux_articulo = new nodo_articulo; // aux = (nodo *) malloc(sizeof(nodo)); (Equivalentes)
		
		// Nota: nodo *apuntador_a_nodo = NULL; (Declarado en Variables Globales) 
		 
		// apuntador_a_articulo = (nodo_articulo*) malloc(sizeof(nodo_articulo));
		apuntador_a_articulo = new nodo_articulo; // (Equivalente)
		
		apuntador_a_articulo->clave = clave;
		//
		strcpy(apuntador_a_articulo->articulo.codigo, nuevo_articulo.codigo);
		strcpy(apuntador_a_articulo->articulo.nombre, nuevo_articulo.nombre);
		apuntador_a_articulo->articulo.precio = nuevo_articulo.precio;
		apuntador_a_articulo->articulo.cantidad = nuevo_articulo.cantidad;
		
		apuntador_a_articulo->siguiente = NULL;
		 
		// 
	 	if( L == NULL ) // Lista vacia
  			L = apuntador_a_articulo;
		else
		{
			aux_articulo = L;
			apuntador_a_articulo->siguiente = aux_articulo;
			L = apuntador_a_articulo;
		 }
		//
		
		return L;	
		//
	}								 
	// ---------------------------------------------------------------------

	// ---------------------------------------------------------------------
	// Voltear_Lista_Articulo
	// ---------------------------------------------------------------------	
	nodo_articulo * Voltear_Lista_Articulo( nodo_articulo *L ) 
	{
	  	
	  	if (L != NULL) { 
		 
			 // Declaración de Nodos Auxiliares
			// ------------------		
			nodo_articulo *nodo_anterior, *este_nodo, *sig_nodo; // Declaración de Punteros Auxiliares (Temporales) 
			//
			nodo_anterior = new nodo_articulo; 	// nodo_anterior = (nodo_articulo *) malloc(sizeof(nodo_articulo));  		// (Equivalentes)	
			este_nodo = new nodo_articulo; 		// este_nodo_anterior = (nodo_articulo *) malloc(sizeof(nodo_articulo));  // (Equivalentes)	
			sig_nodo = new nodo_articulo; 		// sig_nodo = (nodo_articulo *) malloc(sizeof(nodo_articulo));  			// (Equivalentes)	
			// ------------------
			
			// Procedimiento
			// ------------------ 
			
			nodo_anterior = NULL;
		   	
		   	este_nodo = L;
		   	
		   	sig_nodo = (este_nodo)->siguiente;
			   
			while ( sig_nodo != NULL ) 
			{
			 	// Cambio de Dirección 
				este_nodo->siguiente = nodo_anterior;
			 	
			 	// Avance 
			 	nodo_anterior = este_nodo;
			 	este_nodo = sig_nodo;
			 	sig_nodo = sig_nodo->siguiente;
			 	//	
			}	   
		   	
			este_nodo->siguiente = nodo_anterior;
			
			L = este_nodo;
			
			// ------------------ 
		}
		
		return L;	
	 
	}								 
	// ----------------------------------------------------------------------------

	// ---------------------------------------------------------------------
	// primitiva Insertar_Vendedor (En Cabeza)
	// ---------------------------------------------------------------------		
	nodo_vendedor * Insertar_Vendedor(struct vendedores nuevo_vendedor, nodo_vendedor *L) 
	{	  	
		// Lista_Vendedores: L	
	   
	   
		aux_vendedor = new nodo_vendedor;
	
		apuntador_a_vendedor = new nodo_vendedor; 
		
		//
		strcpy(apuntador_a_vendedor->vendedor.nombre, nuevo_vendedor.nombre);
		strcpy(apuntador_a_vendedor->vendedor.ci, nuevo_vendedor.ci);
		//
		apuntador_a_vendedor->vendedor.fechaing.anio = nuevo_vendedor.fechaing.anio;
		apuntador_a_vendedor->vendedor.fechaing.mes = nuevo_vendedor.fechaing.mes;
		apuntador_a_vendedor->vendedor.fechaing.dia = nuevo_vendedor.fechaing.dia;
		//
		apuntador_a_vendedor->vendedor.comision = nuevo_vendedor.comision;
		//
		apuntador_a_vendedor->siguiente = NULL;
		 
		// 
	 	if( L == NULL ) // Lista vacia
  			L = apuntador_a_vendedor;
		else
		{
			aux_vendedor = L;
			apuntador_a_vendedor->siguiente = aux_vendedor;
			L = apuntador_a_vendedor;
		 }
		//
		
		return L;	
		//
	}								 
	// ---------------------------------------------------------------------

	// ---------------------------------------------------------------------
	// mostrar_vendedores
	// ---------------------------------------------------------------------	
	void mostrar_vendedores(nodo_vendedor *i)
	{
	  // 
	  
		//ascii codes
	    char row 		= 205;		
		char col 		=	186;
		char cornerRR 	= 187;		
		char cornerLD 	= 200;
	    char cornerRD 	= 188;
	    char cornerLL 	= 201;
	  
	  
	  system("cls");
	  cout<<"\n<<< LISTA DE VENDEDORES >>>"<<endl;
	  if(i==NULL)
	  {
	    cout<<"\nLista de Vendedores Vacia..!\n\n";
	    // getch();
	    return;
	  }
	
	  do
	  {
	     
		cout<<"\n";
		//
		printf("%c", cornerLL);  	//  
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			// 
		printf("%c", row);			// 
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", cornerRR);  	// 
		// 
			
		// cout<<"\n";
	     
	     cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Nombre: ";
		 cout<< i->vendedor.nombre;

		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"CI: ";
		 cout<< i->vendedor.ci;				 

		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Fecha Ing: ";
		 cout<< i->vendedor.fechaing.dia;				 
		 cout<<"/";
		 cout<< i->vendedor.fechaing.mes;		
		 cout<<"/";
		 cout<< i->vendedor.fechaing.anio;	
		 
 		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Comision: ";
		 cout<< i->vendedor.comision;				 

	    //
	  	cout<<"\n";
		printf("%c", cornerLD);  	//  
		printf("%c", row);			//
		printf("%c", 203);			// 
		printf("%c", row);			//
		printf("%c", row);			// 
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", cornerRD);  	// 
		// 

		cout<<"\n";
		printf("%c", 32);  			//  
		printf("%c", 32);			//
		printf("%c", 186);			// 

		cout<<"\n";
		printf("%c", 32);  			//  
		printf("%c", 32);			//
		printf("%c", 86);			// 


		//     
		i=i->siguiente;	  
	  
	  } while(i!=NULL);
	  
	  
	  cout<<"\nNULL"<<endl;
	  
	  cout<<"\n";
	}
	
	// ---------------------------------------------------------------------
	// cargar_archivo_vendedores
	// ---------------------------------------------------------------------	
	nodo_vendedor * cargar_archivo_vendedores(nodo_vendedor * Lista) {
		
	  printf("\nCargando Archivo Vendedores...");
      printf("\n");
		  		  		
	  int ind, i, cont;
	  
	  FILE *fp;
	  fp = fopen(ARCHIVO_VENDEDORES,"r");
	  if (fp == NULL) return Lista;
	  
	  cont = 0;
	  ind = 1;
	  //
	  while (ind) 
	  {			
		    i = fscanf(fp,"%s",vendedor_entrante.nombre);
			//    
			if (i == EOF) ind = 0;
		    else 
			{
				  cont++;		
				  // 	
			      fscanf(fp,"%s",vendedor_entrante.ci);
			      fscanf(fp,"%d/%d/%d",&(vendedor_entrante.fechaing.dia),&(vendedor_entrante.fechaing.mes),&(vendedor_entrante.fechaing.anio));
			      fscanf(fp,"%d",&(vendedor_entrante.comision));	  
			      //
			      Lista = Insertar_Vendedor(vendedor_entrante, Lista);
		    }
		  
		  	/*
			printf("\n ");
		 	printf("\n Vendedor Nombre: %s", vendedor_entrante.nombre);
		 	printf("\n Vendedor CI: %s", vendedor_entrante.ci);
		 	printf("\n Vendedor Fecha Ing: %d/%d/%d", vendedor_entrante.fechaing.dia, vendedor_entrante.fechaing.mes, vendedor_entrante.fechaing.anio);
		 	printf("\n Vendedor Comision: %d", vendedor_entrante.comision);
			*/
	  
	  }
	  
	  //
	  fclose(fp);
	  
	    printf("\nArchivo de Vendedores Cargado en Memoria Dinamica.");
		printf("\n");	
		printf("Lista: nodo_vendedor ");
		printf("(%i Vendedores Leidos)", cont);
		printf("\n");
	  
	  return Lista;
	}
	
			
	// ---------------------------------------------------------------------
	// mostrar_articulos
	// ---------------------------------------------------------------------	
	void mostrar_articulos(nodo_articulo *i)
	{
	  // 
	  
		//ascii codes
	    char row 		= 205;		
		char col 		=	186;
		char cornerRR 	= 187;		
		char cornerLD 	= 200;
	    char cornerRD 	= 188;
	    char cornerLL 	= 201;
	  
	  
	  system("cls");
	  cout<<"\n<<< LISTA DE ARTICULOS >>>"<<endl;
	  if(i==NULL)
	  {
	    cout<<"\nLista de Articulos Vacia..!\n\n";
	    // getch();
	    return;
	  }
	
	  do
	  {
	     
		cout<<"\n";
		//
		printf("%c", cornerLL);  	//  
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			// 
		printf("%c", row);			// 
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", cornerRR);  	// 
		// 
			
		// cout<<"\n";
	     
	     cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"*Clave: ";
		 cout<< i->clave;
		 
		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Codigo: ";
		 cout<< i->articulo.codigo;

		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Nombre: ";
		 cout<< i->articulo.nombre;				 

		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Precio: ";
		 cout<< i->articulo.precio;				 

 		 cout<<"\n";
		 printf("%c", 186);			// 
		 cout<<"Stock#: ";
		 cout<< i->articulo.cantidad;				 

	    //
	  	cout<<"\n";
		printf("%c", cornerLD);  	//  
		printf("%c", row);			//
		printf("%c", 203);			// 
		printf("%c", row);			//
		printf("%c", row);			// 
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", row);			//
		printf("%c", cornerRD);  	// 
		// 

		cout<<"\n";
		printf("%c", 32);  			//  
		printf("%c", 32);			//
		printf("%c", 186);			// 

		cout<<"\n";
		printf("%c", 32);  			//  
		printf("%c", 32);			//
		printf("%c", 86);			// 


		//     
		i=i->siguiente;	  
	  
	  } while(i!=NULL);
	  
	  //
	  cout<<"\nNULL"<<endl;
	  
	  cout<<"\n";
	}

	
	// ---------------------------------------------------------------------
	// cargar_archivo_articulos
	// ---------------------------------------------------------------------	
	nodo_articulo * cargar_archivo_articulos(nodo_articulo * Lista)
	{
	    
		printf("\nCargando Archivo de Articulos...");
		printf("\n");
	
		// Variable temporal para procesar el codigo ASCII de cada linea leida
		// (en este caso, solo para verificar que la linea leida NO es EOF)  
		int c;
		
		// BUFFER Char 'Temporal' para la lectura y procesamiento del archivo.txt
		// La carga se hace linea por linea (como si fuera un vector char)...  
		char BUFFER[ numero_de_columnas_archivo ];
			    
		// Apuntador al Archivo
		FILE *fichero;
		fichero= fopen(ARCHIVO_ARTICULOS, "r");
		
	   	// Lectura de la linea Cabecera
		c = fscanf(fichero, "%s", BUFFER);
	   
	   	// if (c != EOF) { printf("\%s", &BUFFER); } 
	   	
		numero_de_articulos = 0;	
		// Nota: se inicializa el conteo actual del numero de articulos en memoria
	    
		do
	    {
	       	
	       	// printf("\n");
	       	
	       	// Incremento del contador de numero_de_articulos
			numero_de_articulos++;
	       	
	       	//
	       	clave_articulo = numero_de_articulos;			
	
	       	// Lectura de la linea Codigo
			c = fscanf(fichero, "%s", BUFFER);
	       
	       	if (c != EOF)
		   	{	   				   		
				// printf("\nCodigo %i: %s", numero_de_articulos, &BUFFER);
				strcpy(articulo_entrante.codigo, BUFFER);
			} 	
	      
	      	// Lectura de la linea Nombre
			c = fscanf(fichero, "%s", BUFFER);
	       
	       	if (c != EOF)
		   	{
				// printf("\nNombre %i: %s", numero_de_articulos, &BUFFER);
				strcpy(articulo_entrante.nombre, BUFFER);
			} 
		   	  	
			// Lectura de la linea Precio
			c = fscanf(fichero, "%s", BUFFER);
	       
	       	if (c != EOF)
		   	{
				// printf("\nPrecio %i: %s", numero_de_articulos, &BUFFER);			
				float precio;
				sscanf(BUFFER, "%f", &precio); 
			    articulo_entrante.precio = precio;
	   		}     	
	      
			// Lectura de la linea Cantidad
			c = fscanf(fichero, "%s", BUFFER);
	       
	       	if (c != EOF)
		   	{	   				   		
				// printf("\nCantidad %i: %s", numero_de_articulos, &BUFFER);			
			    int cantidad = atoi(BUFFER);
			    articulo_entrante.cantidad = cantidad;	
			} 
			
			if (c != EOF)
		   	{	   				   		
				// printf("\nIngresando en Lista Articulo %i: ", numero_de_articulos);				
				Lista = Insertar_Articulo_En_Cabeza(clave_articulo, articulo_entrante, Lista);
				//	
			}
			
			//		
			       
	    } while (c != EOF); 
	    
	    
	    //
		numero_de_articulos--;
	    // Esto es porque el incremento de numero_de_articulos lo hago al principio del bucle 
		// y dado que la linea actual es EOF decremento entonces en uno al numero_de_articulos 
	    
		//
		fclose(fichero); 
	
		printf("\nArchivo de Articulos Cargado en Memoria Dinamica.");
		printf("\n");	
		printf("Lista: nodo_articulo ");
		printf("(%i Articulos Leidos)", numero_de_articulos);
		printf("\n");
		   
		return Lista;    
	}		
	// ---------------------------------------------------------------------
		
	// ---------------------------------------------------------------------
	// guardar_archivo_articulos
	// ---------------------------------------------------------------------	
	void guardar_archivo_articulos (nodo_articulo * Lista)
	{
		
		printf("\nActualizando Archivo de Articulos...");
		
		int i;
		
		char cadena_codigo[numero_de_columnas_archivo];
		char cadena_nombre[numero_de_columnas_archivo];	
		char cadena_precio[numero_de_columnas_archivo];
		char cadena_cantidad[numero_de_columnas_archivo];
		
	    FILE* fichero;
	    fichero = fopen(ARCHIVO_ARTICULOS, "wt");
	    
	    // Impresion de Cabecera (Linea 0) el el Archivo
		fputs("ARTICULOS", fichero);
		fputs("\n", fichero);
		
		 //
		
		  if( Lista == NULL )
		  {
		    cout<<"\nLista de Articulos Vacia..!\n\n";
		    // 
		    return;
		  }
		
		  while( Lista != NULL )
		  {
		  
				// Codigo
				strcpy( cadena_codigo, Lista->articulo.codigo );
				
				// Nombre
				strcpy( cadena_nombre, Lista->articulo.nombre );
			
				// Precio
				sprintf( cadena_precio, "%.2f", Lista->articulo.precio );
				
				// Cantidad
				sprintf( cadena_cantidad, "%i", Lista->articulo.cantidad );
				
				//	
				// Grabación de la linea Codigo		
			    fputs(cadena_codigo, fichero);
			    fputs("\n", fichero);
			    
			    // Grabación de la linea Nombre	
			    fputs(cadena_nombre, fichero);
			    fputs("\n", fichero);
			    
			    // Grabación de la linea Precio	
			    fputs(cadena_precio, fichero);
			    fputs("\n", fichero);
			    
			    // Grabación de la linea Cantidad	
			    fputs(cadena_cantidad, fichero);	
				fputs("\n", fichero);
				//	  	
			//     
			Lista = Lista->siguiente;	  
		  
		  }
	  
		
		fclose(fichero);
	
	    printf("\nArchivo de Articulos Actualizado..!");
		printf("\n");	
		printf("\nLista: nodo_Articulo ");
		printf("(%i Articulos Guardados)", numero_de_articulos);
		printf("\n");
		
	
	} 
	

// ---------------------------------------------------------------------
// END Modulos y Funciones de Ejemplo
// ---------------------------------------------------------------------
									 
			
// ---------------------------------------------------------------------
// Programa Principal
// ---------------------------------------------------------------------									
int main() {
    
    //
    int i;
    
	int opcion;
		
	system("cls");
	
	printf("\nINICIALIZANDO TIENDA DE ARTICULOS...\n"); 
	
	// leer archivo articulos
	Lista_Articulos = cargar_archivo_articulos(Lista_Articulos); // En Lista
	
	//
	Lista_Articulos = Voltear_Lista_Articulo( Lista_Articulos );	
	// mostrar_articulos(Lista_Articulos);
	
	//
	Lista_Vendedores = cargar_archivo_vendedores( Lista_Vendedores );	
	//
    
	do
	{
    	printf("\n");
		printf("\nTIENDA DE ARTICULOS\n"); 
		printf("-----------\n");
        //
		printf(" 1. Ingresar (Crear) Nuevo Articulo \n");
        // printf(" 2. Voltear Lista Articulos \n");
        printf(" 2. Modificar (Editar) Articulo \n");
        printf(" 3. Eliminar Articulo\n");
        printf("\n");
        //
		printf(" 4. Menu Gestion de Facturas \n");
		//
		printf(" 5. Menu Gestion de Clientes \n");
		printf(" 6. Menu Gestion de Descuentos \n");
		printf(" 8. Menu Gestion de Bonos \n");
		printf(" 7. Menu Gestion de Comisiones \n");
        printf(" 9. Menu Gestion de Vendedores \n");
		printf("\n");
        printf(" 10. Busqueda de Articulos\n");
        printf(" 11. Ingreso de Stock al Inventario\n");
		printf(" 12. Ver Articulos \n");
        printf("\n");
		printf(" 0. Salir \n");
        printf("------------\n");
       
	    printf("Seleccione Opcion: ");
        scanf("%i",&opcion);
        
		switch(opcion)
		{	
            
			case 1:
                //
                // ingresar o crear nuevo articulo
				//
				// Incremento del contador de numero_de_articulos
				numero_de_articulos++;
	       		//
	       		clave_articulo = numero_de_articulos;			
				//
				// printf("\n Ingresar Articulo Clave: %d", clave_articulo);
				//	
				// Carga de Datos (Ejemplo)			
				strcpy(articulo_entrante.codigo, "B0005");
				strcpy(articulo_entrante.nombre, "Pelota_de_SoftBall");
				articulo_entrante.precio = 4.99;
				articulo_entrante.cantidad = 28;
				//
				Crear_Articulo(clave_articulo, articulo_entrante, Lista_Articulos);		
				//
				mostrar_articulos(Lista_Articulos);
				//
				break;
                
            case 2: 
				//
				printf(" Desarrollar \n");
				//
				// Nota: Esta opción lo que hace ahora es voltear la Lista Articulos, a modo de Ejemplo...
				//
				Lista_Articulos = Voltear_Lista_Articulo( Lista_Articulos ); 
				//
				mostrar_articulos(Lista_Articulos);
				//
                break;    
            
			case 3:
				 //
				printf(" Desarrollar \n");
				//
				break;
					
            case 4: 
				//
				printf(" Desarrollar \n");
				//
                break;

			case 5: 
				//
				printf(" Desarrollar \n");
				//
                break;
			
			case 6: 			
				//
				printf(" Desarrollar \n");
				//
                break;

			case 7: 
				//
				printf(" Desarrollar \n");
				//
                break;
													
            case 8: 
				//
				printf(" Desarrollar \n");
				//
                break;
					
            case 9: 
				//
				// Carga de Datos (Ejemplo)			
				strcpy(vendedor_entrante.nombre, "Alicia");
				strcpy(vendedor_entrante.ci, "26.158.032");
				vendedor_entrante.fechaing.dia = 20;
				vendedor_entrante.fechaing.mes = 11;
				vendedor_entrante.fechaing.anio = 2023;
				vendedor_entrante.comision = 20;
				//
				Lista_Vendedores = Insertar_Vendedor( vendedor_entrante, Lista_Vendedores );
				//
				mostrar_vendedores(Lista_Vendedores);
				//
				printf("Nuevo Vendedor Ingresado al Inicio de la Lista.");
				printf("\n\n");	
				//
                break;
				
			case 10: 
				//
				printf(" Desarrollar \n");
				//
                break;
						            
			case 11: 
				//
				printf(" Desarrollar \n");
				//
                break;
				
			case 12: 
				//
                mostrar_articulos(Lista_Articulos);
				break;
								        
			case 0: 
				// Salida...
				break;
					
            default: 
				printf("Opcion no valida...!\n");
                break;
    		//    
		}
        
        //
        
    } while(opcion!=0);
    
    guardar_archivo_articulos( Lista_Articulos );
    printf("\nFin del Programa.\n\n");
    system("pause");
    
	return 0;
	
}
// ---------------------------------------------------------------------
// End Programa Principal
// ---------------------------------------------------------------------	
