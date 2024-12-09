# Nombre del compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -Wall -std=c++17

# Nombre del ejecutable
TARGET = testMochila

# Regla para compilar y generar el binario
$(TARGET): mochila.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) mochila.cpp

# Regla para ejecutar el binario
testMochila: $(TARGET)
	./$(TARGET)
