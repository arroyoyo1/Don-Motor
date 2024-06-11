# Don Motor (Vehicle Rental Simulator)

## ¿Cuál es el objetivo del programa? 
El objetivo de este proyecto es simular una agencia de renta de vehículo en la cual se pueden agregar distintos tipos, siendo los posibles: autos, motocicletas y camiones, mostrar la lista de vehículos disponibles, agregar clientes y mostrar la lista de clientes registrados, alquilar vehículos, guardar y gestionar dichos alquileres así como devolver los vehículos una vez finalizado el periodo de renta. El proyecto busca aplicar principios de herencia, agregación y composición para modelar las relaciones entre las distintas clases del sistema, demostrando un diseño robusto y escalable para aplicaciones complejas basadas en objetos, así como la herramienta de polimorfismo que ofrece el paradigma de programación orientada a objetos.

## Identifica de manera correcta las clases a utilizar para solucionar el problema

El proyecto utiliza varias clases interrelacionadas para gestionar un sistema de alquiler de vehículos. La clase principal es Negocio, que actúa como una interfaz para administrar vehículos, clientes y alquileres. La clase Vehiculo es la superclase abstracta de la cual heredan las clases Auto, Motocicleta y Camion. Estas clases representan los diferentes tipos de vehículos disponibles para alquilar y cada una implementa el método mostrarInfo() de su propia manera para mostrar su información específica. La clase Cliente representa a los clientes que alquilan vehículos y la clase Alquiler gestiona los alquileres individuales, vinculando un vehículo y un cliente durante un período de tiempo determinado. La clase Negocio utiliza instancias de estas clases para agregar, mostrar y alquilar vehículos, así como para administrar clientes y alquileres. En conjunto, estas clases permiten la gestión eficiente de un sistema de alquiler de vehículos. 


## Identifica los casos que harían que el proyecto deje de funcionar (a fecha del 10/06)

1. Faltan algunas validaciones de inputs del usuario, ya que en varias partes del código, se asume que el usuario ingresará datos válidos. Por ejemplo, al ingresar el número de puertas para un automóvil, no se valida si se ingresa un número válido y en caso de poner una letra, por ejemplo, el programa se cicla infinitamente. Falta agregar verificaciones para asegurarse de que los datos ingresados por el usuario sean correctos.

2. El manejo de fechas podría mejorarse utilizando bibliotecas especializadas o implementando funciones de validación de fechas para garantizar que se ingresen fechas válidas y para manejar adecuadamente las operaciones de comparación entre fechas. Se podría argumentar que es válido que un usuario alquile y devuelva el mismo día pero se siente raro.


## Genera un diagrama de clases UML correcto y y explico su relación con el problema de forma clara 

El diagrama de clases UML proporciona una representación visual clara de la estructura del sistema y las relaciones entre sus componentes, lo que es esencial para entender y comunicar el diseño del sistema. La relación que tiene con el problema se indica mediante el diseño del diagrama es decir, mediante las relaciones indicadas entre clases y la multiplicidad que sirve para dar más información de la arquitectura del proyecto.

/// detallar las relaciones entre clases 





