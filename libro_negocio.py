from libro import Libro
from autor import Autor

class LibroNegocio:
    def __init__(self, archivo_libros):
        self.archivo_libros = archivo_libros
        self.listado_libros = []

    def obtener_libros(self):
        listado_libros = []
        try:
            with open(self.archivo_libros, "r") as file:
                for line in file:
                    parts = line.strip().split(", ")
                    if len(parts) == 6:
                        cod_libro, titulo, año, tomo, autor_info, categoria = parts
                        autor_parts = autor_info.split(": Autor: ")
                        if len(autor_parts) == 2:
                            autor_nombre = autor_parts[1]
                            listado_libros.append(Libro(cod_libro, titulo, año, tomo, Autor(cod_autor=cod_libro, nombre=autor_nombre), categoria))
        except FileNotFoundError:
            print('El archivo no existe')
        return listado_libros

    def registrar_libro(self, cod_libro, titulo, año, tomo, autor_nombre, categoria):
        self.listado_libros = self.obtener_libros()
        autor = Autor(cod_autor=cod_libro, nombre=autor_nombre)  # Crear un objeto Autor
        libro = Libro(cod_libro, titulo, año, tomo, autor, categoria)
        self.listado_libros.append(libro)

    def guardar_libros(self):
        if len(self.listado_libros) > 0:
            with open(self.archivo_libros, "a") as file:
                for libro in self.listado_libros:
                    file.write(f"{libro.cod_libro}, {libro.titulo}, {libro.año}, {libro.tomo}, Autor: {libro.autor.nombre}, {libro.categoria}\n")
            return 'Se registraron los libros correctamente.'
        else:
            return 'Hubo un error al registrar los libros.'

    def eliminar_libro(self, cod_libro):
        try:
            with open(self.archivo_libros, "r") as file:
                lines = file.readlines()

            libro_encontrado = None

            with open(self.archivo_libros, "w") as file:
                for line in lines:
                    parts = line.strip().split(", ")
                    if len(parts) == 6:
                        if parts[0] == cod_libro:
                            libro_encontrado = True
                        else:
                            file.write(line)

            if libro_encontrado:
                print(f"Libro con código '{cod_libro}' eliminado exitosamente.")
            else:
                print(f"No se encontró un libro con el código '{cod_libro}'.")

        except FileNotFoundError:
            print("El archivo 'libros.txt' no existe o no se puede abrir.")

    def editar_libro(self, cod_libro, nuevo_titulo, nuevo_año, nuevo_tomo, nuevo_autor_nombre, nueva_categoria):
        try:
            with open(self.archivo_libros, "r") as file:
                lines = file.readlines()

            libro_encontrado = None

            with open(self.archivo_libros, "w") as file:
                for line in lines:
                    parts = line.strip().split(", ")
                    if len(parts) == 6:
                        if parts[0] == cod_libro:
                            libro_encontrado = True
                            nuevo_autor = Autor(cod_autor=cod_libro, nombre=nuevo_autor_nombre)
                            file.write(f"{cod_libro}, {nuevo_titulo}, {nuevo_año}, {nuevo_tomo}, Autor: {nuevo_autor.nombre}, {nueva_categoria}\n")
                        else:
                            file.write(line)

            if libro_encontrado:
                print(f"Libro con código '{cod_libro}' editado exitosamente.")
            else:
                print(f"No se encontró un libro con el código '{cod_libro}'.")

        except FileNotFoundError:
            print("El archivo 'libros.txt' no existe o no se puede abrir.")
