# libro.py
class Libro:
    def __init__(self, cod_libro, titulo, año, tomo, autor, categoria):
        self.cod_libro = cod_libro
        self.titulo = titulo
        self.año = año
        self.tomo = tomo
        self.autor = autor
        self.categoria = categoria

    def obtener_informacion(self):
        return f"Código: {self.cod_libro}, Título: {self.titulo}, Año: {self.año}, Tomo: {self.tomo}, Autor: {self.autor.nombre}, Categoría: {self.categoria}"
