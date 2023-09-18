# categoria.py
from libro import Libro

class Categoria:
    def __init__(self, cod_categoria, categoria, libros=None):
        self.cod_categoria = cod_categoria
        self.categoria = categoria
        self.libros = libros if libros else []
    
    def agregar_libro(self, libro):
        self.libros.append(libro)
    
    def eliminar_libro(self, libro):
        self.libros.remove(libro)
