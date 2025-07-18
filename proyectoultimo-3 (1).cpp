#include <iostream>
#include <fstream>
using namespace std;

//int datosSemaforo[6] = {1, 1, 2, 2, 1, 0};
//int myArray[3]={3,3,4};
//char matriz[3][3] = {
//    {'C', 'C', 'C'},
//   {'A', 'C', 'A'},
//   {'M', 'C', 'C'},
//};

class Vehiculo {
public:
    int id; // New: Unique identifier for the vehicle
    static int nextId; // New: Static counter for unique IDs
    int tiempoMovimiento;
    int tiempoEspera;
    int indicadorChoque;
    int cambiosDireccion;
    char nomenclatura;
    int row; // Nueva: fila actual del vehículo
    int col; // Nueva: columna actual del vehículo
    int prev_row; // Nueva: fila anterior del vehículo
    int prev_col; // Nueva: columna anterior del vehículo
    int intended_row; // Nueva: fila a la que el vehículo intenta moverse
    int intended_col; // Nueva: columna a la que el vehículo intenta moverse
    int cicloChoque; // New: Cycle number when collision occurred, 0 if no collision

    Vehiculo(char n, int tm, int te, int ic, int cd, int r, int c) : nomenclatura(n), tiempoMovimiento(tm), tiempoEspera(te),
                                                       indicadorChoque(ic), cambiosDireccion(cd), row(r), col(c), prev_row(r), prev_col(c), intended_row(r), intended_col(c), cicloChoque(0) {
        id = nextId++; // Assign unique ID
    }
};

int Vehiculo::nextId = 1;

class Auto : public Vehiculo {
public:
    string tipo;
    int direccion = 0; // 0: izquierda, 1: derecha

    Auto(char n, int tm, int te, int ic, int cd, int r, int c) : Vehiculo(n, tm, te, ic, cd, r, c), tipo("Auto") {}

    void derecha() {
        cout << "El auto va a la derecha." << endl;
    }
    void izquierda() {
        cout << "El auto va a la izquierda." << endl;
    }

    void mostrarInfo() const {
        cout << nomenclatura << " ";
    }
};

class Moto : public Vehiculo
{
public:
    string tipo;
    int direccion = 0; // 0: abajo, 1: arriba

    Moto(char n, int tm, int te, int ic, int cd, int r, int c) : Vehiculo(n, tm, te, ic, cd, r, c), tipo("Moto") {}

    void subir() {
        cout << "La moto va subiendo." << endl;
    }
    void bajar() {
        cout << "La moto va bajando." << endl;
    }

    void mostrarInfo() const {
        cout << nomenclatura << " ";
    }
};

class Semaforo
{
public:
    bool isGreen; // true for green, false for red
    int coordenadas[2];
    char nomenclatura;

    Semaforo(int x, int y, bool initialColor = true) : nomenclatura('S'), isGreen(initialColor) {
        coordenadas[0] = x;
        coordenadas[1] = y;
    }

    void mostrarInfo() const {
        cout << nomenclatura << " ";
    }
};

class SemaforoData
{
    public:
    int ubicacionFila;
    int ubicacionColumna;
    int Elem;      
    int InicioPatron;  
    int* patronSemaforo;
    SemaforoData() : ubicacionFila(0), ubicacionColumna(0), Elem(0), InicioPatron(0), patronSemaforo(NULL) {}
    ~SemaforoData() {
        if (patronSemaforo != NULL) {
            delete[] patronSemaforo;
            patronSemaforo = NULL;
        }
    }
    SemaforoData(const SemaforoData&) = delete;
    SemaforoData& operator=(const SemaforoData&) = delete;
};

class Edificio {
public:
    int row; 
    int col;
    Edificio(int r = 0, int c = 0) : row(r), col(c) {}
};
bool esEdificio(int fila, int columna, Edificio* listaEdificios, int numeroEdificios) {
    for (int e = 0; e < numeroEdificios; ++e)
        if (listaEdificios[e].row == fila && listaEdificios[e].col == columna)
            return true;
    return false;
}

class Calle {
public:
    int coordenadas[2];
    char nomenclatura;

    Calle(int x, int y) : nomenclatura('C') {
        coordenadas[0] = x;
        coordenadas[1] = y;
    }

    void mostrarInfo() const {
        cout << nomenclatura << " ";
    }
};

string linea, texto;

int main(int argc, char* argv[]) {
    if (argc < 3) { // Expecting program_name, map_file, semaphore_file
        std::cerr << "Error: Uso incorrecto." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <ruta_archivo_mapa> <ruta_archivo_config_semaforos>" << std::endl;
        return 1; // Indicate an error
    }
        ifstream FileMap(argv[1]);
        int sizeFilas;
        int sizesColumnas;
        int tiempo;
        FileMap >> sizeFilas;
        FileMap >> sizesColumnas;
        FileMap >> tiempo;
        int numeroEdificios = 0;
        Edificio* listaEdificios = NULL;
        char** a = new char*[sizeFilas];
        for (int row = 0; row < sizeFilas; ++row){
        a[row] = new char[sizesColumnas];
        }
         for (int row = 0; row < sizeFilas; ++row) {
        for (int col = 0; col < sizesColumnas; ++col) {
            FileMap >> a[row][col];
        }
    }

        for (int i = 0; i < sizeFilas; ++i)
            for (int j = 0; j < sizesColumnas; ++j)
                if (a[i][j] == 'E')
                    ++numeroEdificios;

        listaEdificios = new Edificio[numeroEdificios];
        int indiceEdificio = 0;
        for (int i = 0; i < sizeFilas; ++i) {
        for (int j = 0; j < sizesColumnas; ++j) {
        if (a[i][j] == 'E') {
            listaEdificios[indiceEdificio++] = Edificio(i, j);
        }
    }
}
FileMap.close();

    ifstream SemaforosCont(argv[2]);
    int numeroSemaforos = 0;
    int tempUbicacionFila, tempUbicacionColumna, tempElem, tempInicioPatron;
    while(SemaforosCont >> tempUbicacionFila >> tempUbicacionColumna >> tempElem >> tempInicioPatron){
        for (int i = 0; i < tempElem; ++i) {
            int tempPatronVal;
            SemaforosCont >> tempPatronVal;
    }
    numeroSemaforos++;
}
    SemaforosCont.close();

    SemaforoData* todosLosSemaforos = new SemaforoData[numeroSemaforos];

    ifstream SemaforosC(argv[2]);
    for (int i = 0; i < numeroSemaforos; i++) {
        SemaforoData& currentSemaforo = todosLosSemaforos[i];
        SemaforosC >> currentSemaforo.ubicacionFila;
        SemaforosC >> currentSemaforo.ubicacionColumna;
        SemaforosC >> currentSemaforo.Elem;
        SemaforosC >> currentSemaforo.InicioPatron;
        currentSemaforo.patronSemaforo = new int[currentSemaforo.Elem];
        for (int j = 0; j < currentSemaforo.Elem; ++j) {
            SemaforosC >> currentSemaforo.patronSemaforo[j];
        }
    }
    SemaforosC.close();
    std::cout << "\n--- Valores de los Semaforos Cargados ---" << std::endl;

    // Recorremos el arreglo principal 'todosLosSemaforos'
    for (int i = 0; i < numeroSemaforos; ++i) {
        // Obtenemos una referencia al objeto SemaforoData actual
        SemaforoData& semaforoActual = todosLosSemaforos[i];

        std::cout << "Semaforo " << i + 1 << ":" << std::endl;
        std::cout << "  Ubicacion: (" << semaforoActual.ubicacionFila << ", " << semaforoActual.ubicacionColumna << ")" << std::endl;
        std::cout << "  Cantidad de Elementos (Elem): " << semaforoActual.Elem << std::endl;
        std::cout << "  Inicio del Patron: " << semaforoActual.InicioPatron << std::endl;

        std::cout << "  Patron de Semaforo: [";
        // Recorremos el arreglo dinámico 'patronSemaforo' dentro del semáforo actual
        for (int j = 0; j < semaforoActual.Elem; ++j) {
            std::cout << semaforoActual.patronSemaforo[j];
            if (j < semaforoActual.Elem - 1) { // Para no imprimir la coma después del último elemento
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }


    //intento de lectura 
    //const char* mapaFilePath = "C:/Ruta/Al/Archivo/mapa.in";
    //ifstream mapa(mapaFilePath);
    //while (getline(mapa, linea)) {
    //   texto=texto+linea;
   // }
    //cout<< texto<<endl;
    //cout<< "--------------"<<endl;

    int contadorVehiculos=0;
    
    for (int i = 0; i < sizeFilas; i++){ // Contar vehículos en la matriz
        for (int j = 0; j < sizesColumnas; j++){
            if (a[i][j] == 'A' || a[i][j] == 'M') {
                contadorVehiculos++;
            }
        }
    }

    // Usamos un arreglo de punteros a void para almacenar diferentes tipos de objetos
    void **calle = new void *[contadorVehiculos];
    int contadorPosicionVehiculo=0;
    for (int i = 0; i < sizeFilas; i++) {
        for (int j = 0; j < sizesColumnas; j++) {
            if (a[i][j] == 'A') {
                calle[contadorPosicionVehiculo] = new Auto('A', 0, 0, 0, 0, i, j);
                contadorPosicionVehiculo++;
            }
            if (a[i][j] == 'M') {
                calle[contadorPosicionVehiculo] = new Moto('M', 0, 0, 0, 0, i, j);
                contadorPosicionVehiculo++;
            }
        }
    }

    // Mostrar la calle
    for (int i = 0; i < sizeFilas; i++) {
        for (int j = 0; j < sizesColumnas; j++) {
            bool foundVehicle = false;
            for (int k = 0; k < contadorVehiculos; k++) {
                Vehiculo *currentVehiculo = static_cast<Vehiculo *>(calle[k]);
                if (currentVehiculo->row == i && currentVehiculo->col == j) {
                    cout << currentVehiculo->nomenclatura << " ";
                    foundVehicle = true;
                    break;
                }
            }
            if (!foundVehicle) {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Encontrar la posición del semáforo (una vez fuera del bucle principal)
    int semaforoRow = -1;
    int semaforoCol = -1;
    bool semaforoEncontrado = false;
    for (int i = 0; i < sizeFilas; i++) {
        for (int j = 0; j < sizesColumnas; j++) {
            if (a[i][j] == 'S') {
                semaforoRow = i;
                semaforoCol = j;
                semaforoEncontrado = true;
                break;
            }
        }
        if (semaforoRow != -1) break;
    }

    Semaforo semaforo(semaforoRow, semaforoCol); // Crear el semáforo una vez

    int contador = 0;
    int contador_semaforo = todosLosSemaforos[0].InicioPatron -1;
    while (contador < tiempo) {
        contador++;
        cout << "\n--- Ciclo " << contador << " ---" << endl;

        // Limpiar la matriz para el nuevo ciclo
        for (int i = 0; i < sizeFilas; i++) {
            for (int j = 0; j < sizesColumnas; j++) {
                a[i][j] = 'C'; // Asumimos que todo es calle por defecto
            }
        }
        // Volver a colocar el semáforo en la matriz después de limpiar
        if (semaforoEncontrado) {
            a[semaforoRow][semaforoCol] = 'S'; // Cambiar color en cada ciclo
                if(contador_semaforo == todosLosSemaforos[0].Elem)
                contador_semaforo = 0;
                if(todosLosSemaforos[0].patronSemaforo[contador_semaforo] == 1){
                semaforo.isGreen = 1;
                } else {
                semaforo.isGreen = 0;
                }
                contador_semaforo = (contador_semaforo + 1)% todosLosSemaforos[0].Elem;
                
        }

        // Lógica del semáforo
        if (semaforoEncontrado && !semaforo.isGreen) {
            cout << "Semaforo en ROJO. Los autos esperan." << endl;
        } else {
            cout << "Semaforo en VERDE. Los autos se mueven." << endl;
        }

        for (int k = 0; k < contadorVehiculos; k++) {
            Vehiculo *vehiculoPtr = static_cast<Vehiculo *>(calle[k]);
            if (vehiculoPtr->nomenclatura == 'A') {
                Auto *autoPtr = static_cast<Auto *>(vehiculoPtr);
                if (autoPtr->cicloChoque != 0) {
                    autoPtr->tiempoEspera++;
                    a[autoPtr->row][autoPtr->col] = autoPtr->nomenclatura;
                    continue; // Saltar al siguiente vehículo
                }
                autoPtr->prev_row = autoPtr->row;
                autoPtr->prev_col = autoPtr->col;
                autoPtr->intended_row = autoPtr->row;
                autoPtr->intended_col = autoPtr->col;
                
                // --- INICIO: impedir paso sobre edificio (Auto) ---
                int filaDestinoA = autoPtr->row;
                int colDestinoA  = autoPtr->col + (autoPtr->direccion == 0 ? -1 : +1);
                if (esEdificio(filaDestinoA, colDestinoA, listaEdificios, numeroEdificios)) {
                    autoPtr->direccion = 1 - autoPtr->direccion;
                    autoPtr->cambiosDireccion++;
                    autoPtr->tiempoEspera++;
                    continue;
                }
// --- FIN: impedir paso sobre edificio (Auto) ---

                

                if (semaforo.isGreen) { // Solo se mueven si el semáforo está en verde
                    if (autoPtr->direccion == 0) { // Mover a la izquierda
                        if (autoPtr->intended_col > 0) {
                            autoPtr->intended_col--;
                            autoPtr->izquierda();
                            autoPtr->tiempoMovimiento++;
                        } else {
                            // Si ya está en col 0 no puede moverse a la izquierda cambia dirección
                            autoPtr->direccion = 1; // Cambiar dirección a derecha
                            autoPtr->tiempoEspera++;
                            autoPtr->cambiosDireccion++;
                        }
                    } else { // Mover a la derecha
                        if (autoPtr->intended_col < sizesColumnas - 1) { 
                            autoPtr->intended_col++;
                            autoPtr->derecha();
                            autoPtr->tiempoMovimiento++;
                        } else {
                            // Si  está en la última columna no puede moverse a la derecha cambia dirección
                            autoPtr->direccion = 0; // Cambiar dirección a izquierda
                            autoPtr->tiempoEspera++; // Todavía esperando ya que no pudo moverse
                            autoPtr->cambiosDireccion++;
                        }
                    }
                } else { 
                    autoPtr->tiempoEspera++; 
                    if (autoPtr->col == 0 || autoPtr->col == sizesColumnas - 1) {
                        if (autoPtr->direccion == 0) { // Si la dirección es izquierda
                            autoPtr->direccion = 1; // Cambiar a derecha
                        } else { // Si la dirección es derecha
                            autoPtr->direccion = 0; // Cambiar a izquierda
                        }
                        autoPtr->cambiosDireccion++;
                    }
                }
            }
            else if (vehiculoPtr->nomenclatura == 'M') {
                Moto *motoPtr = static_cast<Moto *>(vehiculoPtr);
                if (motoPtr->cicloChoque != 0) {
                    motoPtr->tiempoEspera++;
                    a[motoPtr->row][motoPtr->col] = motoPtr->nomenclatura;
                    continue; // Saltar al siguiente vehículo
                }
                motoPtr->prev_row = motoPtr->row;
                motoPtr->prev_col = motoPtr->col;
                motoPtr->intended_row = motoPtr->row;
                motoPtr->intended_col = motoPtr->col;

                if (semaforo.isGreen) { // Solo se mueven si el semáforo está en verde
        if (motoPtr->direccion == 0) { //  hacia arriba 0
            if (motoPtr->intended_row > 0) { // Si no está en la fila 0
                motoPtr->intended_row--;
                motoPtr->subir();
                motoPtr->tiempoMovimiento++;
            } else {
                // Si ya está en la fila 0, no puede subir más, cambia dirección
                motoPtr->direccion = 1; // Cambiar dirección a abajo
                motoPtr->tiempoEspera++; 
                motoPtr->cambiosDireccion++;
            }
        } else { 
            if (motoPtr->intended_row < sizeFilas - 1) { 
                motoPtr->intended_row++;
                motoPtr->bajar();
                motoPtr->tiempoMovimiento++;
            } else {
                // Si ya está en la última fila no puede bajar más cambia dirección
                motoPtr->direccion = 0; // Cambia arriba
                motoPtr->cambiosDireccion++;
            }
        }
    } else { 
        motoPtr->tiempoEspera++;
        if (motoPtr->row == 0 || motoPtr->row == sizeFilas - 1) { 
            if (motoPtr->direccion == 0) { // Si actual es arriba
                motoPtr->direccion = 1; // Cambiar a abajo
            } else { // Si actual es abajo
                motoPtr->direccion = 0; // Cambiar a arriba
            }
            motoPtr->cambiosDireccion++;
        }
}
    }
}

        // Detección de colisiones
        for (int i = 0; i < contadorVehiculos; ++i) {
            Vehiculo *vehiculo1 = static_cast<Vehiculo *>(calle[i]);

            for (int j = i + 1; j < contadorVehiculos; ++j) {
                Vehiculo *vehiculo2 = static_cast<Vehiculo *>(calle[j]);

                if (vehiculo1->intended_row == vehiculo2->intended_row && vehiculo1->intended_col == vehiculo2->intended_col) {
                    // Colisión detectada

                    if (vehiculo1->nomenclatura == vehiculo2->nomenclatura) {
                        // Si son del mismo tipo, el segundo vehículo cambia de dirección y se queda en su posición anterior
                        if (vehiculo2->nomenclatura == 'A') {
                            Auto *autoPtr = static_cast<Auto *>(vehiculo2);
                            autoPtr->direccion = (autoPtr->direccion == 0) ? 1 : 0; // Cambiar dirección
                            autoPtr->cambiosDireccion++;
                        } else if (vehiculo2->nomenclatura == 'M') {
                            Moto *motoPtr = static_cast<Moto *>(vehiculo2);
                            motoPtr->direccion = (motoPtr->direccion == 0) ? 1 : 0; // Cambiar dirección
                            motoPtr->cambiosDireccion++;
                        }
                        vehiculo2->intended_row = vehiculo2->prev_row;
                        vehiculo2->intended_col = vehiculo2->prev_col;
                        vehiculo2->tiempoEspera++;
                        vehiculo2->tiempoMovimiento--;
                        cout << "\n!COLISION (mismo tipo) DETECTADA en el ciclo " << contador << " entre Vehiculo " << vehiculo1->id << " y Vehiculo " << vehiculo2->id << "!" << endl;
                    } else {
                        vehiculo1->cicloChoque = contador;
                        vehiculo2->cicloChoque = contador;
                        // Si son de tipo opuesto, el segundo vehículo se queda en su posición anterior
                        vehiculo2->intended_row = vehiculo2->prev_row;
                        vehiculo2->intended_col = vehiculo2->prev_col;
                        vehiculo2->tiempoEspera++;
                        vehiculo2->tiempoMovimiento--;
                        cout << "\n¡COLISION (tipo opuesto) DETECTADA en el ciclo " << contador << " entre Vehiculo " << vehiculo1->id << " y Vehiculo " << vehiculo2->id << "!" << endl;
                    }
                }
            }
        }

        // Actualizar posiciones finales de los vehículos y reconstruir la matriz
        for (int i = 0; i < sizeFilas; i++) {
            for (int j = 0; j < sizesColumnas; j++) {
                a[i][j] = 'C'; // Limpiar la matriz
            }
        }
        if (semaforoEncontrado) {
            a[semaforoRow][semaforoCol] = 'S';
        }

        for (int k = 0; k < contadorVehiculos; k++) {
            Vehiculo *vehiculoPtr = static_cast<Vehiculo *>(calle[k]);
            vehiculoPtr->row = vehiculoPtr->intended_row;
            vehiculoPtr->col = vehiculoPtr->intended_col;
            a[vehiculoPtr->row][vehiculoPtr->col] = vehiculoPtr->nomenclatura;
        }

        // Mostrar la calle después de cada iteración
        for (int i = 0; i < sizeFilas; i++) {
            for (int j = 0; j < sizesColumnas; j++) {
                bool foundVehicle = false;
                for (int k = 0; k < contadorVehiculos; k++) {
                    Vehiculo *currentVehiculo = static_cast<Vehiculo *>(calle[k]);
                    if (currentVehiculo->row == i && currentVehiculo->col == j) {
                        cout << currentVehiculo->nomenclatura << " ";
                        foundVehicle = true;
                        break;
                    }
                }
                if (!foundVehicle) {
                    cout << a[i][j] << " ";
                }
            }
            cout << endl;
        }

        ofstream outFile("C:\\Ruta\\Al\\Archivo\\log_simulacion.out");
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    outFile << a[i][j] << " ";
                }
                outFile << endl;
            }
        ofstream statsoutFile("C:\\Ruta\\Al\\Archivo\\estadisticas.out");
        // Mostrar resumen de vehiculos al final de cada ciclo
        for (int k = 0; k < contadorVehiculos; k++) {
            Vehiculo *vehiculoPtr = static_cast<Vehiculo *>(calle[k]);
            statsoutFile << vehiculoPtr->id << " ";
            if (vehiculoPtr->nomenclatura == 'A') {
                Auto *autoPtr = static_cast<Auto *>(vehiculoPtr);
                statsoutFile << autoPtr->tipo << " ";
            } else if (vehiculoPtr->nomenclatura == 'M') {
                Moto *motoPtr = static_cast<Moto *>(vehiculoPtr);
                statsoutFile << motoPtr->tipo << " ";
            }
            statsoutFile << vehiculoPtr->tiempoMovimiento << " ";
            statsoutFile << vehiculoPtr->tiempoEspera << " ";
            statsoutFile << vehiculoPtr->cambiosDireccion << " ";
            statsoutFile << vehiculoPtr->cicloChoque << endl;
        }
        statsoutFile << endl;
    }

    return 0;
}
