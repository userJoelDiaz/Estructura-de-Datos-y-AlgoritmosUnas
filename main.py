# main.py
import datetime
from persona import Persona
from autor import Autor
from libro import Libro
from categoria import Categoria

# Función para cargar los libros desde el archivo "libros.txt"
def cargar_libros_desde_archivo():
    libros = []
    try:
        with open("libros.txt", "r") as file:  # Intentar abrir el archivo "libros.txt" en modo lectura ("r") y leer sus líneas.
            for line in file: # Iterar a través de cada línea en el archivo
                # Dividir cada línea en partes utilizando ", " como separador y eliminar espacios en blanco adicionales.
                parts = line.strip().split(", ")
                if len(parts) == 6:  
                    cod_libro, titulo, año, tomo, autor_info, categoria = parts
                    # Dividir la información del autor en partes
                    autor_parts = autor_info.split(": Autor: ")
                    if len(autor_parts) == 2:
                        autor_nombre = autor_parts[1]
                        libros.append(Libro(cod_libro, titulo, año, tomo, Autor(cod_autor=cod_libro, nombre=autor_nombre), categoria))
    except FileNotFoundError:
        pass  # El archivo no existe, se creará cuando se guarden libros
    return libros

# Función para generar un informe de libros
def generar_reporte_libros():
    try:
        with open("libros.txt", "r") as file:
            lines = file.readlines()

        if not lines:
            print("No hay libros en el archivo para generar un informe.")
        else:
            # Obtener la fecha y hora actual
            fecha_actual = datetime.datetime.now().strftime("%Y-%m-%d %H_%M_%S")  # Cambiar ':' por '_'

            # Crear el nombre de archivo para el informe
            nombre_archivo = "reporte.txt"

            # Generar el informe en un archivo separado
            with open(nombre_archivo, "a") as reporte_file:
                reporte_file.write(f"Informe de Libros - Fecha y Hora: {fecha_actual}\n\n")
                for line in lines:
                    reporte_file.write(line)

            print(f"Informe de libros generado en el archivo '{nombre_archivo}'")
    except FileNotFoundError:
        print("El archivo 'libros.txt' no existe o no se puede abrir.")

# Función para guardar libros en el archivo "libros.txt"
def guardar_libros(libros):
    with open("libros.txt", "a") as file:
        for libro in libros:
            file.write(f"{libro.cod_libro}, {libro.titulo}, {libro.año}, {libro.tomo}, Autor: {libro.autor.nombre}, {libro.categoria}\n")
            
# Función para eliminar un libro por su código
def eliminar_libro(cod_libro):
    try:
        # Abre el archivo "libros.txt" en modo lectura ("r") y lee todas las líneas del archivo, almacenándolas en una lista llamada "lines".
        with open("libros.txt", "r") as file:
            lines = file.readlines()

        # Inicializa una variable llamada "libro_encontrado" como None. Se usará para verificar si se encontró y eliminó un libro.
        libro_encontrado = None

        # Abre el archivo "libros.txt" en modo escritura ("w"). A partir de este punto, se escribirá en el archivo para realizar la eliminación.
        with open("libros.txt", "w") as file:
            # Itera sobre cada línea en la lista "lines".
            for line in lines:
                # Divide cada línea en partes utilizando "strip()" y "split(", ")". Verifica si la línea tiene 6 partes (información de libro).
                parts = line.strip().split(", ")
                if len(parts) == 6:
                    # Comprueba si el código del libro coincide con el código proporcionado ("cod_libro").
                    if parts[0] == cod_libro:
                        # Marca "libro_encontrado" como True.
                        libro_encontrado = True
                    else:
                        # Escribe la línea original en el archivo, ya que no coincide con el código proporcionado.
                        file.write(line)

        # Verifica si "libro_encontrado" es True. Si es así, muestra un mensaje indicando que el libro se eliminó con éxito.
        # Si no se encontró el libro, muestra un mensaje que indica que no se encontró ningún libro con el código proporcionado.
        if libro_encontrado:
            print(f"Libro con código '{cod_libro}' eliminado exitosamente.")
        else:
            print(f"No se encontró un libro con el código '{cod_libro}'.")

    except FileNotFoundError:
        # Maneja la excepción si el archivo 'libros.txt' no existe o no se puede abrir, mostrando un mensaje apropiado.
        print("El archivo 'libros.txt' no existe o no se puede abrir.")

# función para editar libros
def editar_libro_en_archivo(cod_libro):
    try:
        # Abre el archivo "libros.txt" en modo lectura ("r")
        with open("libros.txt", "r") as file:
            # Lee todas las líneas del archivo y las almacena en una lista llamada "lines"
            lines = file.readlines()

        # Inicializa una variable llamada "libro_encontrado" como None
        libro_encontrado = None # false

        # Abre el archivo "libros.txt" en modo escritura ("w")
        with open("libros.txt", "w") as file:
            # Itera sobre cada línea del archivo
            for line in lines:
                # Divide cada línea en partes separadas por ", "
                parts = line.strip().split(", ")
                # Verifica si la línea tiene 6 partes (información de libro)
                if len(parts) == 6:
                    # Comprueba si el código del libro coincide con el código proporcionado
                    if parts[0] == cod_libro:
                        # Imprime un mensaje de edición y solicita nuevos valores al usuario
                        print(f"Editando libro con código '{cod_libro}':")
                        nuevo_titulo = input(f"Nuevo título ({parts[1]}): ") or parts[1]
                        nuevo_año = input(f"Nuevo año ({parts[2]}): ") or parts[2]
                        nuevo_tomo = input(f"Nuevo tomo ({parts[3]}): ") or parts[3]
                        # Obtiene el nuevo nombre del autor desde el usuario o utiliza el valor existente
                        nuevo_autor_nombre = input(f"Nuevo nombre del autor ({parts[4].split(': Autor: ')[-1]}): ") or parts[4].split(': Autor: ')[-1]
                        nueva_categoria = input(f"Nueva categoría ({parts[5]}): ") or parts[5]

                        # Escribe la línea editada en el archivo
                        file.write(f"{cod_libro}, {nuevo_titulo}, {nuevo_año}, {nuevo_tomo}, Autor: {nuevo_autor_nombre}, {nueva_categoria}\n")
                        
                        # Marca que se encontró y editó el libro
                        libro_encontrado = True
                    else:
                        # Si el código no coincide, escribe la línea original en el archivo
                        file.write(line)

        # Verifica si se encontró y editó un libro
        if libro_encontrado:
            print("Libro editado exitosamente.")
        else:
            print(f"No se encontró un libro con el código '{cod_libro}'.")

    except FileNotFoundError:
        print("El archivo 'libros.txt' no existe o no se puede abrir.")

# Función principal que muestra el menú
def menu():
    libros = []  # Lista para almacenar los libros en memoria
    libros = cargar_libros_desde_archivo()  # Cargar libros desde el archivo "libros.txt"

    while True:
        print("\nMenú de Opciones:")
        print("1. Ingresar Libros")
        print("2. Guardar Libros")
        print("3. Eliminar Libros")
        print("4. Generar Informe de Libros")
        print("5. Editar libro por codigo")
        print("6. Salir")
        
        opcion = input("Seleccione una opción: ")
        
        if opcion == "1":
            # Código para ingresar los datos de un libro
            cod_libro = input("Ingrese el código del libro: ")
            titulo = input("Ingrese el título del libro: ")
            año = input("Ingrese el año del libro: ")
            tomo = input("Ingrese el tomo del libro: ")

            autor_cod = input("Ingrese el código del autor: ")
            autor_nombre = input("Ingrese el nombre del autor: ")

            categoria = input("Ingrese la categoría del libro: ")

            # Crear un nuevo objeto Autor
            autor = Autor(cod_autor=autor_cod, nombre=autor_nombre, pais=None, editorial=None)
            libro = Libro(cod_libro=cod_libro, titulo=titulo, año=año, tomo=tomo, autor=autor, categoria=categoria)
            libros.append(libro)
            print("Libro ingresado exitosamente.")
            
        elif opcion == "2":
            # Código para guardar los libros
            if not libros:
                print("No hay libros ingresados para guardar.")
            else:
                guardar_libros(libros)
                print("Libros guardados en 'libros.txt'")
            
        elif opcion == "3":
            # Código para eliminar un libro por código
            cod_libro = input("Ingrese el código del libro que desea eliminar: ")
            eliminar_libro(cod_libro)  # Llama a la función eliminar_libro con el código del libro como argumento
            
        elif opcion == "4":
            # Generar el informe de libros
            generar_reporte_libros()
            
        elif opcion == "5":
            # Código para editar un libro por código en el archivo "libros.txt"
            cod_libro = input("Ingrese el código del libro que desea editar: ")
            editar_libro_en_archivo(cod_libro)
        
        elif opcion == "6":
           # Salir del programa y guardar los libros en el archivo
            guardar_libros(libros)
            break
if __name__ == "__main__":
    menu()
