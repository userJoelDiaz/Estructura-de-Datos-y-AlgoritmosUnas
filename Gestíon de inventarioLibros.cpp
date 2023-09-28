#include <iostream> 
#include <vector> // Biblioteca para trabajar con vectores dinámicos
#include <string> // Biblioteca para manejar cadenas de texto (strings)
#include <ctime> // Biblioteca para trabajar con fechas y tiempos
#include <limits> // Biblioteca para el manejo de excepciones y límites
#include <fstream> // Biblioteca para trabajar con archivos de texto
#include <cstring> // Biblioteca para el manejo de cadenas de caracteres 

using namespace std;
//Funciones para el manejo de excepciones
int obtenerEnteroValido()
{
    int num;
    while (true)
    {
        try {
            if (!(cin >> num))
            {
                throw "Error. Ingresa un valor entero válido.";
            }
            break;
        } catch (const char* message) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message << " Vuelve a intentarlo: ";
        }
    }
    return num;
}

float obtenerFloatValido()
{
    float num;
    while (true)
    {
        try {
            if (!(cin >> num))
            {
                throw "Error. Ingresa un valor flotante válido.";
            }
            break;
        } catch (const char* message) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message << " Vuelve a intentarlo: ";
        }
    }
    return num;
}

string obtenerStringValido()
{
    string input;
    while (true)
    {
        try {
            cin >> input;
            if (input.empty())
            {
                throw "Error. Ingresa una cadena válida.";
            }
            break;
        } catch (const char* message) {
            cout << message << " Vuelve a intentarlo: ";
        }
    }
    return input;
}

//Clase Padre Persona 
class Persona{
private:
  string nombre, apellidos;
  int edad;
  
public:
  //Constructor Persona
  Persona(const string& nombre, const string& apellidos, const int& edad)
    : nombre(nombre), apellidos(apellidos), edad(edad) {}
   void mostrarPersona();
  //Método set nombre
  void set_Nombre(string nombre) {
    this->nombre = nombre;
  }
  //Método get nombre
  string get_Nombre(){
    return this->nombre;
  }
  //método set apellidos
  void set_Apellidos(string apellidos) {
    this->apellidos = apellidos;
  }
  //Método get apellidos
  string get_Apellidos() {
    return this->apellidos;
  }
};

//Método mostrar Persona
void Persona::mostrarPersona(){
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " <<apellidos << endl;
    cout << "Edad: " << edad << endl;
}

// Clase Bibliotecario hereda de Persona
class Bibliotecario : public Persona {
private:
    string area;
    static string claveAcceso;

public:
    Bibliotecario(const string& nombre, const string& apellidos, int edad, const string& area)
        : Persona(nombre, apellidos, edad), area(area) {} // constructor

    // Métodos get y set para área
    void set_Area(const string& area) {
        this->area = area;
    }

    string get_Area() {
        return this->area;
    }

    // Método para verificar la clave de acceso
    bool verificarClave(const string& clave) const {
        return clave == claveAcceso;
    }

    // Método para mostrar información del bibliotecario
    void mostrarBibliotecario() {
        Persona::mostrarPersona();
        cout << "Área: " << area << endl;
    }

    // Método estático para establecer la clave de acceso
    static void establecerClaveAcceso(const string& clave) {
        claveAcceso = clave;
    }
};
// Inicializa la clave estática fuera de la clase (por ejemplo, en el main)
string Bibliotecario::claveAcceso = "";

//Clase cliente hereda de Persona
class Cliente : public Persona {
private:
  string id_cliente;
  int telefono;
  string direccion;
public:
  Cliente(const string& nombre, const string& apellidos, const int& edad, const string& id_cliente, int telefono, const string& direccion)
    : Persona(nombre, apellidos, edad), id_cliente(id_cliente), telefono(telefono), direccion(direccion) {}

  // Métodos get y set para id_cliente
  void set_IdCliente(const string& id_cliente) {
    this->id_cliente = id_cliente;
  }

  string get_IdCliente() {
    return this->id_cliente;
  }

  // Métodos get y set para telefono
  void set_Telefono(int telefono) {
    this->telefono = telefono;
  }

  int get_Telefono() {
    return this->telefono;
  }

  // Métodos get y set para direccion
  void set_Direccion(const string& direccion) {
    this->direccion = direccion;
  }

  string get_Direccion() {
    return this->direccion;
  }

  void mostrarCliente(){
    Persona::mostrarPersona();
    cout << " ID del cliente: " << id_cliente << endl;
    cout << " Telefono del cliente: " << telefono<< endl;
    cout << " Direccion del cliente: " << direccion << endl;
  }
};

// Clae libro
class Libro{
private:
  string titulo_libro, autor_libro, categoria_libro;
  float precio_libro;
  int cantidad, codigo;
  
public:
  Libro(string, string, string, float, int, int); //Constructor
  void mostrarLibro();
  
  // get and set
  // Método set titulo_libro
  void set_titulo_libro(string titulo_libro) {
    this->titulo_libro = titulo_libro;
  }
  string get_titulo_libro() {
    return this->titulo_libro;
  }
  //Método set autor_libro
  void set_autor_libro(string autor_libro) {
    this->autor_libro = autor_libro;
  }
  //Método get autor_libro
  string get_autor_libro() {
    return this->autor_libro;
  }
  //Metodo set categoria libro
  void set_categoria_libro(string categoria_libro) {
    this->categoria_libro = categoria_libro;
  }
  //Método get categoria libro
  string get_categoria_libro() {
    return this->categoria_libro;
  }
  // Método set precio libro
  void set_precio_libro(float precio_libro) {
    this->precio_libro = precio_libro;
  }
  //Método get precio libro
  float get_precio_libro() {
    return this->precio_libro;
  }
  // set and get cantidad
  void set_cantidad(int cantidad) {
    this->cantidad = cantidad;
  }
  int get_cantidad() {
    return this->cantidad;
  }

  void set_codigo(int codigo) {
    this->codigo = codigo;
  }

  int get_codigo() {
    return this->codigo;
  }
};

//Constructor Libro
Libro::Libro(string titulo_libro, string autor_libro, string categoria_libro, float precio_libro, int cantidad, int codigo){
  this->titulo_libro = titulo_libro;
  this->autor_libro = autor_libro;
  this->categoria_libro = categoria_libro;
  this->cantidad = cantidad;
  this->precio_libro = precio_libro;
  this->codigo = codigo;
}

void Libro::mostrarLibro(){
    cout << "Titulo: " << titulo_libro << endl;
    cout << "Autor: " << autor_libro << endl;
    cout << "Categoria: " << categoria_libro << endl;
    cout << "Precio: " << precio_libro << " USD" << endl;
    cout << "Cantidad en stock: " << cantidad << endl;
    cout << "Codigo: " << codigo << endl;
}
// Clase stock
class Stock {
private:
    Libro* libro; // apunta a un objeto de la clase libro 
    int cantidadVendida;
    string fechaVenta;
    Cliente cliente; // instancia para usar los atributos de la clase cliente

public:
    Stock(Libro* libro, int cantidadVendida, const Cliente& cliente)
        : libro(libro), cantidadVendida(cantidadVendida), cliente(cliente) {
        // Obtener la fecha actual
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        fechaVenta = buffer;
    }

    void imprimirBoleta() {
        cout << "Boleta de Venta" << endl;
        cout << "---------------------------" << endl;
        cout << "Fecha de Venta: " << fechaVenta << endl;
        cout << "Cliente: " << cliente.get_Nombre() << " " << cliente.get_Apellidos() << endl; // Imprimir datos del cliente
        cout << "Producto Vendido: " << libro->get_titulo_libro() << endl;
        cout << "Cantidad Vendida: " << cantidadVendida << endl;
        cout << "Precio Unitario: " << libro->get_precio_libro() << " USD" << endl;
        cout << "Total: " << cantidadVendida * libro->get_precio_libro() << " USD" << endl;
        cout << "---------------------------" << endl;
    }

    void actualizarStock() {
        int stockActual = libro->get_cantidad();
        if (cantidadVendida <= stockActual) {
            libro->set_cantidad(stockActual - cantidadVendida);
        } else {
            cout << "Error: No hay suficiente stock para la venta." << endl;
        }
    }
};

void Menu() { // menu principal
 cout << "\033[1;32m\nMENU DE OPCIONES\n \033[0m" << endl;
 cout << "\033[1;32m[1]. Entrar a la galeria de libros.\033[0m" << endl;
 cout << "\033[1;32m[2]. Vender libro.\033[0m" << endl;
 cout << "\033[1;32m[3]. Salir..\033[0m" << endl;
}

void menu_galeria() { // Menu listar libros
 cout << "\nMENU DE OPCIONES\n " << endl;
 cout << "[1]. Agregar un nuevo libro. " << endl;
 cout << "[2]. Listar todos los libros. " << endl;
 cout << "[3]. Listar libros por autor. " << endl;
 cout << "[4]. Editar libro. " << endl;
 cout << "[5]. Eliminar libro. " << endl;
 cout << "[6]. Salir.. " << endl;
}

void menu_venta() { // Menu ventas
	cout << "\nMENU DE OPCIONES\n " << endl;
	cout << "[1]. Listar libros disponibles por titulo. " << endl;
	cout << "[2]. Mostrar segun autor.. " << endl;
	cout << "[3]. Salir.. " << endl;
}

vector<Libro> libros; // vector para almacenar libros
//Prototipos de funciones
void agregar_libros();
void listar_todos_libros();
void listar_libros_segunAutor();
void editar_libros();
void eliminar_libros();
void vender_libros();
void vender_libro_por_autor();
void Cargar_Galeria_TXT();
void Guardar_Galeria_TXT();
// main
int main() {
    Cargar_Galeria_TXT();
    // Crea una instancia de Bibliotecario (cambiar los valores según corresponda)
    Bibliotecario bibliotecario("Joel", "Diaz Gupioc", 18, "Bibliotecario");

    // Establece la clave de acceso después de crear la instancia
    bibliotecario.establecerClaveAcceso("proyecto");

    int intentosMaximos = 3; // Número máximo de intentos permitidos
    int intentos = 0; // Contador de intentos

    while (intentos < intentosMaximos) {
        cout << "Ingrese su clave de acceso: ";
        string claveIngresada;
        cin >> claveIngresada;

        if (bibliotecario.verificarClave(claveIngresada)) {
            cout << "Acceso permitido." << endl;
            system("cls");
            
            int opcion;
            do {
                Menu(); // menu principal
                cout << "Ingrese una opcion: ";
                opcion = obtenerEnteroValido();
                system("cls");

                switch (opcion) {
                    case 1:
                        int op;
                        do {
                            menu_galeria(); // menu para manipular la galeria de libros
                            cout << "Ingrese una opcion: ";
                            op = obtenerEnteroValido();

                            switch (op) {
                                case 1: // agregar libros a la galeria
                                    agregar_libros();
                                    Guardar_Galeria_TXT();
                                    system("pause");
                                    system("cls");
                                    break;
                                case 2: // listar toda la galeria
                                    listar_todos_libros();
                                    system("pause");
                                    system("cls");
                                    break;
                                case 3: // listar libros segun autor
                                    listar_libros_segunAutor();
                                    system("pause");
                                    system("cls");
                                    break;
                                case 4:
                                    editar_libros(); // Editar libros por codigo
                                    Guardar_Galeria_TXT();
                                    system("pause");
                                    system("cls");
                                    break;
                                case 5:
                                	eliminar_libros(); // eliminar libro
                                	Guardar_Galeria_TXT;
                                	system("pause");
                                	system("cls");
                                	break;
                                default:
                                	cout << " Ingrese una opcion valida.. " << endl;
                                    break;
                            }
                        } while (op != 6);
                        break;
                        
                    case 2:
                    	int op_venta;
                    	do {
                    		menu_venta(); // menu para la venta de libros
                    		cout << "Ingrese una opcion: ";
                    		op_venta = obtenerEnteroValido();
                    		system("cls");
                    		
                    		switch (op_venta) {
                    			case 1: 
                    			    vender_libros(); // venta de libros por título
                    			    Guardar_Galeria_TXT();
                    			    system("pause");
                    			    system("cls");
                    			
                    			case 2:
                    				vender_libro_por_autor(); // venta de libros por autor
                    				Guardar_Galeria_TXT();
                    				system("pause");
                    				system("cls");
                    			break;
                    			default:
                    				cout << "Ingrese una opcion valida.. " << endl;
                    			break;
							}
						} while (op_venta != 3);
                        break;
                    default:
                        break;
                }
            } while (opcion != 3); // Salir del programa si se selecciona la opción 3
            break; // Sale del bucle si la clave es correcta
        } else {
            cout << "Clave incorrecta. Acceso denegado." << endl;
            intentos++;

            if (intentos < intentosMaximos) {
                cout << "Intentos restantes: " << intentosMaximos - intentos << endl;
                system("pause");
                system("cls");
            } else {
                cout << "Número máximo de intentos alcanzado. Programa terminado." << endl;
            }
        }
    }

    return 0;
}
//Funcion para agregar un libro
void agregar_libros() {
    string titulo_libro, autor_libro, categoria_libro;
    float precio_libro;
    int cantidad, codigo;
     
    // Solicita el título del libro
    cout << "Ingrese el titulo del libro: ";
    cin.ignore(); // Limpiar el buffer del teclado
    getline(cin, titulo_libro);
               
    // Verifica si ya existe un libro con el mismo título
    bool libroExistente = false;
    for (Libro& libro : libros) {
        if (libro.get_titulo_libro() == titulo_libro) {
            libroExistente = true;
            // Si el libro ya existe, solicita la cantidad adicional
            cout << "Ingrese la cantidad a agregar: ";
            int cantidadNueva = obtenerEnteroValido();
            libro.set_cantidad(libro.get_cantidad() + cantidadNueva);
            cout << "Se ha actualizado el stock del libro." << endl;
            return;  // Regresar al menú principal
        }
    }
  
    if (!libroExistente) {
        // Si el libro no existe, solicita los detalles adicionales
        cout << "Ingrese el autor del libro: ";
        autor_libro = obtenerStringValido();
        cout << "Ingrese la categoria del libro: ";
        categoria_libro = obtenerStringValido();
        cout << "Ingrese el precio del libro: ";
        precio_libro = obtenerFloatValido();
        cout << "Ingrese la cantidad del libro: ";
        cantidad = obtenerEnteroValido();
        cout << "Ingrese el código del libro: ";
        codigo = obtenerEnteroValido();

        // Crea un nuevo libro y agrégalo a la lista de libros
        Libro nuevoLibro(titulo_libro, autor_libro, categoria_libro, precio_libro, cantidad, codigo);
        libros.push_back(nuevoLibro);
        cout << "Se ha agregado un nuevo libro al inventario." << endl;
    }
}
//Funcion para listar toda la galeria de libros
void listar_todos_libros() {
	
	if(libros.empty()){ // Verifica si hay libros en el vector
		cout <<"Lista de libros vacia " << endl;
	}else{
	    cout << "\nLista de libros en la galeria. "<< endl;
		for(int i = 0; i < libros.size(); i++){ 
		cout << "Libro " << i + 1 << endl;
		libros[i].mostrarLibro();
		cout << "\n";
		}
	}
}
//Funcion para listar libros por autor
void listar_libros_segunAutor() {
  string Autor_ingresado;
  cout << "Ingrese el autor de los libros a listar:";
  Autor_ingresado = obtenerStringValido();
  
  for (int i = 0; i < libros.size(); i++) {
    if (Autor_ingresado == libros[i].get_autor_libro()) {
      libros[i].mostrarLibro();
    }
  }
}
//Funcion para eliminar libros por codigo
void eliminar_libros() {
   int opcion_eliminar; 
   string autor_libro;
   int codigo_libro;
   
   cout << " \nLista de libros en la galeria, Elija cual eliminar\n";
   for (int i = 0; i < libros.size(); i++) {
   	 cout << " libro " << i + 1 << endl;
   	 libros[i].mostrarLibro();
   	 cout << "\n";
   }
   
   cout << "\n";
   do {
   	 cout << "1. Eliminar por codigo " << endl;
     cout << "2. Eliminar por autor "	 << endl;
     cout << "3. Volver.. " << endl;
     cout << "Elije una opcion para eliminar libro: ";
     opcion_eliminar = obtenerEnteroValido();
     system("cls");
     
        switch (opcion_eliminar) {
     	 case 1:
             cout << "Ingrese el codigo del libro a eliminar: ";
             codigo_libro = obtenerEnteroValido(); 
            for (int i = 0; i < libros.size(); i++)
            {
                if (libros[i].get_codigo() == codigo_libro)
                {
                    libros.erase(libros.begin() + i);
                    cout << "El libro se elimino correctamente." << endl;
                    cout << "\n******\n" << endl;
                    system("cls");
                    break;
                }
                if (i == libros.size() - 1)
                {
                    cout << "No se encontro ningun libro con ese codigo." << endl;
                    cout << "\n******\n" << endl;
                }
            }
            break;
         case 2:
         	 cout << "Ingrese el autor del libro a eliminar: ";
         	 autor_libro = obtenerStringValido();
         	 for (int i = 0; i < libros.size(); i++)
            {
                if (libros[i].get_autor_libro() == autor_libro)
                {
                    libros.erase(libros.begin() + i); 
                    cout << "El libro se elimino correctamente." << endl;
                    cout << "\n******\n" << endl;
                    system("cls");
                    break;
                }
                if (i == libros.size() - 1)
                {
                    cout << "No se encontro ningun libro con ese autor." << endl;
                    cout << "\n******\n" << endl;
                }
            }
            break;
            default:
            	cout << "Ingrese una opcion valida.. ";
            break;
	    }
    } while (opcion_eliminar != 3);
}
//Funcion para editar librO
void editar_libros(){
  int codigo_ingresado;
  cout << " Ingrese el codigo del libro a editar: ";
  codigo_ingresado = obtenerEnteroValido();
  //varaibles locales 
  string titulo_libro, autor_libro, categoria_libro;
  float precio_libro;
  int cantidad, codigo;

  for (int i = 0; i < libros.size(); i++) {
    if (libros[i].get_codigo() == codigo_ingresado) {
      cout << "\n MODIFICAR DETALLES DEL LIBRO\n " << endl;
      cout << " Nuevo titulo del libro: ";
      titulo_libro = obtenerStringValido();
      cout << " Nuevo autor del libro: ";
      autor_libro = obtenerStringValido();
      cout << " Nueva categoria del libro: ";
      categoria_libro = obtenerStringValido();
      cout << " Nuevo precio de libro: ";
      precio_libro = obtenerFloatValido();
      cout << " Nuevo stock del libro: ";
      cantidad = obtenerEnteroValido();
      cout << " Nuevo codigo del libro: ";
      codigo = obtenerEnteroValido();
      
      libros[i].set_titulo_libro(titulo_libro); 
      libros[i].set_autor_libro(autor_libro);
      libros[i].set_categoria_libro(categoria_libro);
      libros[i].set_precio_libro(precio_libro);
      libros[i].set_cantidad(cantidad);
      libros[i].set_codigo(codigo);
    }
  }
}
//Función para vender un libro
void vender_libros() {
    if (libros.empty()) { //verifica si hay libros en la lista
        cout << "La lista de libros está vacía." << endl;
        return;
    }
     
    cout << "Libros disponibles para la venta:" << endl;
    for (int i = 0; i < libros.size(); i++) {
        cout << i + 1 << ". " << libros[i].get_titulo_libro() << " (Cantidad en stock: " << libros[i].get_cantidad() << ")" << endl;
    }
    
    int seleccion; // variable que almacena el numero selecionado por el usuario
    cout << "Seleccione el libro que desea comprar (Ingrese el número): ";
    seleccion = obtenerEnteroValido();
    
    if (seleccion < 1 || seleccion > libros.size()) {
        cout << "Selección no válida." << endl;
        return;
    }
    
    // Restar 1 porque el índice de vector comienza desde 0
    int indiceSeleccionado = seleccion - 1;

    Libro& libroSeleccionado = libros[indiceSeleccionado];

    if (libroSeleccionado.get_cantidad() == 0) {
        cout << "Lo siento, el libro seleccionado está agotado." << endl;
        return;
    }
    
    cout << "Ingrese la cantidad que desea comprar: ";
    int cantidadComprar = obtenerEnteroValido();
    
    if (cantidadComprar <= 0 || cantidadComprar > libroSeleccionado.get_cantidad()) {
        cout << "Cantidad no válida." << endl;
        return;
    }

    // Solicitar los datos del cliente
    cout << "Ingrese el nombre del cliente: ";
    string nombreCliente = obtenerStringValido();
    cout << "Ingrese los apellidos del cliente: ";
    cin.ignore();
    string apellidosCliente = obtenerStringValido();
    cout << "Ingrese la edad del cliente: ";
    int edadCliente = obtenerEnteroValido();
    cout << "Ingrese el ID del cliente: ";
    string idCliente = obtenerStringValido();
    cout << "Ingrese el teléfono del cliente: ";
    int telefonoCliente = obtenerEnteroValido();
    cout << "Ingrese la dirección del cliente: ";
    string direccionCliente = obtenerStringValido();

    // Crear una instancia de Cliente con los datos ingresados
    Cliente cliente(nombreCliente, apellidosCliente, edadCliente, idCliente, telefonoCliente, direccionCliente);

    // Crear una instancia de Stock para representar la venta
    Stock venta(&libroSeleccionado, cantidadComprar, cliente);
    system("cls"); 
    // Imprimir la factura de venta
    cout << "Venta realizada exitosamente." << endl;
    venta.imprimirBoleta(); // estan en la clase stock
    // Actualizar el stock del libro vendido
    venta.actualizarStock();
}
// Funcion para vender libros segun el autor
void vender_libro_por_autor() {
	if (libros.empty()) { //verifica si hay libros en la lista
        cout << "La lista de libros está vacía." << endl;
        return;
    }
    string autor_ingresado; 
    
    cout << " Ingrese el autor del libro que desea comprar: ";
    autor_ingresado = obtenerStringValido();
    
    for(int i = 0; i < libros.size(); i ++) {
    	if (libros[i].get_autor_libro() == autor_ingresado) {
    		cout << "Libros disponibles del autor " << autor_ingresado << " para la venta:" << endl;
            cout << i + 1 << ". " << libros[i].get_titulo_libro() << " (Cantidad en stock: " << libros[i].get_cantidad() << ")" << endl;
        }	
	}
	
    int seleccion; // variable que almacena el numero selecionado por el usuario
    cout << "Seleccione el libro que desea comprar (Ingrese el número): ";
    seleccion = obtenerEnteroValido();

    if (seleccion < 1 || seleccion > libros.size()) {
        cout << "Selección no válida." << endl;
        return;
    }

    // Restar 1 porque el índice de vector comienza desde 0
    int indiceSeleccionado = seleccion - 1;

    Libro& libroSeleccionado = libros[indiceSeleccionado];

    if (libroSeleccionado.get_cantidad() == 0) {
        cout << "Lo siento, el libro seleccionado está agotado." << endl;
        return;
    }

    cout << "Ingrese la cantidad que desea comprar: ";
    int cantidadComprar = obtenerEnteroValido();

    if (cantidadComprar <= 0 || cantidadComprar > libroSeleccionado.get_cantidad()) {
        cout << "Cantidad no válida." << endl;
        return;
    }

    // Solicitar los datos del cliente
    cout << "Ingrese el nombre del cliente: ";
    string nombreCliente = obtenerStringValido();
    cout << "Ingrese los apellidos del cliente: ";
    string apellidosCliente = obtenerStringValido();
    cout << "Ingrese la edad del cliente: ";
    int edadCliente = obtenerEnteroValido();
    cout << "Ingrese el ID del cliente: ";
    string idCliente = obtenerStringValido();
    cout << "Ingrese el teléfono del cliente: ";
    int telefonoCliente = obtenerEnteroValido();
    cout << "Ingrese la dirección del cliente: ";
    string direccionCliente = obtenerStringValido();

    // Crear una instancia de Cliente con los datos ingresados
    Cliente cliente(nombreCliente, apellidosCliente, edadCliente, idCliente, telefonoCliente, direccionCliente);

    // Crear una instancia de Stock para representar la venta
    Stock venta(&libroSeleccionado, cantidadComprar, cliente);

    // Imprimir la factura de venta
    venta.imprimirBoleta();

    // Actualizar el stock del libro vendido
    venta.actualizarStock();

    cout << "Venta realizada exitosamente." << endl;
}
// Guardar en el txt
void Guardar_Galeria_TXT() {
    // Guardar los productos del arreglo al txt
    ofstream Libreria; 
    Libreria.open("Libreria.txt", ios::out); 
    if (Libreria.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        for (int i = 0; i < libros.size(); i++) {
        	cout << "\n";
            Libreria << "DETALLES DEL LIBRO " << i + 1 << "\n";
            Libreria << "Codigo:" << libros[i].get_codigo() << "\n";
            Libreria << "Titulo:" << libros[i].get_titulo_libro() << "\n";
            Libreria << "Autor:" << libros[i].get_autor_libro() << "\n";
            Libreria << "Categoria:" << libros[i].get_categoria_libro() << "\n";
            Libreria << "Cantidad:" << libros[i].get_cantidad() << "\n";
            Libreria << "Precio $:" << libros[i].get_precio_libro() << "\n";
        }
    }
    Libreria.close(); // cerrar
}
// cargar del txt al iniciar el programa
void Cargar_Galeria_TXT() {
    libros.clear(); // Limpiamos el vector antes de cargar los datos
    ifstream Libreria;
    string Cadena;
    Libreria.open("Libreria.txt", ios::in);
    if (Libreria.fail()) {
        cout << "No se pudo abrir el archivo Libreria.txt, o no existe." << endl;
        return; // Salir de la función si falla la apertura del archivo
    }
    else {
        cout << "Se pudo abrir el archivo Libreria.txt" << endl;
    }

    if (Libreria.is_open()) {
        int line_number = 0;
        Libro Libro_Temporal("", "", "", 0, 0, 0); // Declarar una instancia de Libro aquí
        while (getline(Libreria, Cadena)) {
            line_number++;
            if (line_number == 2) {
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                if (token != nullptr) {
                    token = strtok(NULL, "\n");
                    if (token != nullptr) {
                        Libro_Temporal.set_codigo(atoi(token));
                    }
                }
            }
            if (line_number == 3) {
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                if (token != nullptr) {
                    token = strtok(NULL, "\n");
                    if (token != nullptr) {
                        Libro_Temporal.set_titulo_libro(token);
                    }
                }
            }
            if (line_number == 4) {
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                if (token != nullptr) {
                    token = strtok(NULL, "\n");
                    if (token != nullptr) {
                        Libro_Temporal.set_autor_libro(token);
                    }
                }
            }
            if (line_number == 5) {
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                if (token != nullptr) {
                    token = strtok(NULL, "\n");
                    if (token != nullptr) {
                        Libro_Temporal.set_categoria_libro(token);
                    }
                }
            }
            if (line_number == 6) {
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                if (token != nullptr) {
                    token = strtok(NULL, "\n");
                    if (token != nullptr) {
                        Libro_Temporal.set_cantidad(atoi(token));
                    }
                }
            }
            if (line_number == 7) {
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                if (token != nullptr) {
                    token = strtok(NULL, "\n");
                    if (token != nullptr) {
                        Libro_Temporal.set_precio_libro(stof(token));
                        libros.push_back(Libro_Temporal);
                        line_number = 0;  // Reiniciar el contador de líneas
                    }
                }
            }
        }
    }
}