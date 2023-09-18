# persona.py
class Persona:
    def __init__(self, cod_persona, nombre, apellido_paterno="", apellido_materno="", fecha_nacimiento=""):
        self.cod_persona = cod_persona
        self.nombre = nombre
        self.apellido_paterno = apellido_paterno
        self.apellido_materno = apellido_materno
        self.fecha_nacimiento = fecha_nacimiento
