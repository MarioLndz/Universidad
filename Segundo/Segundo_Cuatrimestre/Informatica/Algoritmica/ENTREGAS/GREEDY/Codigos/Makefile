# Nombre archivo: Makefile
# Uso: make
# Descripción:	Construye los tres binarios de nombres generador, especifico y dyv, respectivamente.

#------------------------------------------------------------------#

# Variable que indica el compilador que se va a utilizar
CC=g++

# Variable que indica el directorio del proyecto Voraz
VORAZ= ./Voraz

# Variable que indica el directorio del proyecto Generador
GENERADOR_DIR= ./Generador

# Variable que indica el directorio del proyecto Pvc1
PVC1= ./Pvc1

# Variable que indica el directorio del proyecto Pvc2
PVC2= ./Pvc2

# Variable que indica el directorio del proyecto Pvc3
PVC3= ./Pvc3

# Variable que indica el directorio del proyecto Generador-pvc
GENERADOR_PVC_DIR= ./Generador-pvc

#------------------------------------------------------------------#

all: voraz pvc1 pvc2 pvc3 generador generador-pvc

# ---------- Voraz ----------
voraz: $(VORAZ)/main.cpp
	$(CC) $(VORAZ)/main.cpp -o voraz

# ---------- Pvc1 ----------
pvc1: $(PVC1)/pvc1.cpp
	$(CC) $(PVC1)/pvc1.cpp -o pvc1

# ---------- Pvc2 ----------
pvc2: $(PVC1)/pvc1.cpp
	$(CC) $(PVC2)/pvc2.cpp -o pvc2

# ---------- Pvc3 ----------
pvc3: $(PVC1)/pvc1.cpp
	$(CC) $(PVC3)/pvc3.cpp -o pvc3

# ---------- Generador ----------
generador: $(GENERADOR_DIR)/generador.cpp
	$(CC) $(GENERADOR_DIR)/generador.cpp -o generador

# ---------- Generador-pvc ----------
generador-pvc: $(GENERADOR_PVC_DIR)/generador-pvc.cpp
	$(CC) $(GENERADOR_PVC_DIR)/generador-pvc.cpp -o generador-pvc
