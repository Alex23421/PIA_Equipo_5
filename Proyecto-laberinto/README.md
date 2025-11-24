# Juego de Laberinto Controlado por Arduino

**Repositorio del Proyecto:** [https://github.com/Alex23421/PIA_Equipo_5](https://github.com/Alex23421/PIA_Equipo_5

## Descripción

Sistema interactivo que combina hardware y software para controlar físicamente un laberinto mediante servomotores, permitiendo guiar una esfera a través de un recorrido.

### Problema que resuelve

Demostrar principios de mecatrónica básica mediante un sistema interactivo que integra control electrónico y mecánica, resolviendo la necesidad de crear una interfaz física entre el usuario y un entorno controlado.

### Propósito

Desarrollar un juego de laberinto físico controlado electrónicamente que permita a los usuarios guiar una esfera a través de un recorrido mediante el control de servomotores usando un joystick.

### Contexto y Alcance

- **Contexto:** Proyecto académico para la materia de Cómputo Integrado
- **Alcance:** Sistema completo que incluye electrónica, programación y estructura mecánica
- **Limitaciones:** Control básico de 2 ejes, materiales accesibles para estudiantes

## Cómo está construido el proyecto

### Arquitectura general

El sistema se compone de tres módulos principales:

1. **Módulo de Entrada:** Joystick analógico envía señales (X,Y) a los pines A0,A1
2. **Módulo de Procesamiento:** Arduino Uno convierte lecturas analógicas a PWM
3. **Módulo de Actuación:** Servomotores inclinan la plataforma en dos ejes

### Diagrama de arquitectura

Joystick (X,Y) → Señales analógicas (A0, A1) → Arduino Uno → PWM (pines 3 y 5) → Servomotores (X,Y) → Inclinación mecánica → Movimiento de la esfera

### Diagrama pictórico

# Componentes Principales y su Ubicación:

Base del Laberinto: Plataforma rectangular de material rígido que sostiene todo el sistema

**Servomotor Eje X:** Ubicado en el lado izquierdo de la base, conectado al borde para controlar la inclinación lateral

**Servomotor Eje Y:** Posicionado en la parte posterior, controla la inclinación frontal-trasera

**Plataforma Móvil:** Superficie superior donde se encuentra el laberinto impreso, conectada a ambos servomotores

**Esfera:** Pequeña bola metálica o de acero que se desplaza sobre la plataforma del laberinto

# Conexiones Eléctricas:

**Arduino Uno:** Centrado en la base, funciona como cerebro del sistema

**Joystick Analógico:** Posicionado en la parte frontal para fácil acceso del usuario

# Conexiones a Servomotores:

Servo X → Pin 3 (PWM) de Arduino

Servo Y → Pin 5 (PWM) de Arduino

# Conexiones a Joystick:

Eje X → Pin A0 (Analógico)

Eje Y → Pin A1 (Analógico)

Alimentación → 5V y GND de Arduino

## Tecnologías usadas

### Hardware

- Arduino Uno
- 2 servomotores
- Joystick analógico
- Jumpers
- Base rígida, cartulina, fomi

### Software

- Arduino IDE

## Estructura de carpetas del proyecto

PROYECTO-LABERINTO/
├── docs/
│ └── diagramas/
│ ├── diagrama_de_arquitectura.png
│ ├── diagrama_de_flujo.png
│ └── diagrama_pictorico.png
├── firmware/
│ └── Proyecto_Laberinto.ino
└── README.md

## Cómo usar el proyecto (Instalación y ejecución)

### Prerrequisitos

- Tener instalado Arduino IDE
- Placa Arduino Uno
- Componentes listados en la sección de materiales

### Instalación paso a paso

Paso 1: Entrar a la página oficial de arduino, y presionar el botón descargar
Paso 2: Seleccionar ubicación de donde se guardará y presionar el botón “Guardar”
Paso 3: Abrir el instalador de Arduino y presionar “Acepto”
Paso 4: Presionar siguiente en la ventana de “Elegir opciones de instalación”
Paso 5: Seleccionar la carpeta de destino y presionar “Instalar”
Paso 6: Verificar el programa
Paso 7: Subir el programa
Paso 8: Probar el proyecto

## Código y decisiones técnicas

### Fragmento principal

```cpp
#include <Servo.h>

Servo servo1, servo2;
int joyX = 0, joyY = 1;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
}

void loop() {
  // Control eje X (invertido)
  int servoVal = analogRead(joyX);
  servoVal = map(servoVal, 1023, 0, 130, 180);
  servo1.write(servoVal);

  // Control eje Y
  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 130, 180);
  servo2.write(servoVal);

  delay(50);
}
```
