/**
 * @file Image.cpp
 * @note To be implemented by students 
 * @author MP-DGIM, MP-IADE, MP-II (grupo B)
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
using namespace std;

//===========================================
//	Imaging 1

//--------------------------
//	Constructores

Image::Image() {
	_data = nullptr;
	
	_width = 0;
	_height = 0;
	
}

Image::Image(int width, int height) 
	:	_data(nullptr)
{
	setSize (width, height);
	
}

//--------------------------
//	Getters y Setters

int Image::height() const{
	return (_height);
}

int Image::width() const{
	return (_width);
}

void Image::setPixel(int x, int y, Byte v){
	
	if (x < width() && x >= 0 && y < height() && y >= 0){
		_data[y][x] = v;
	}
}

int Image::getPixel (int x, int y) const {
	int result = -1;
	
	if (x <= width() && x >= 0 && y <= height() && y >= 0){
		result = _data[y][x].getValue();
	}
	
	return (result);
}

void Image::setPos (int i, Byte v){
	int ancho = width();
	
	setPixel(i%ancho, i/ancho, v);
	
}

int Image::getPos (int i) const {
	int ancho = width();
	
	return (getPixel(i%ancho, i/ancho));
}

void Image::flatten (Byte b){
	int w = width();
	int h = height();
	
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			setPixel(x, y, b);
		}
	}
	
}

void Image::showInWindow(string title) const {
    string tempname = "data"+SLASH+".hidden_" + title + ".pgm";

    mpSavePGMImage(tempname, (const unsigned char *)_data, _width, _height);
    mpDisplayImage(tempname, title);
    
}

string Image::inspect() const {
    string result = "";
    result = std::to_string(_width) + "x" + std::to_string(_height) + " " + std::to_string(mphash((const unsigned char*) _data, _height * _width));
    return result;
}

//--------------------------------------------------
//	Imaging 2

//--------------------------
//	Lectura y Guardado en un archivo

int Image::readFromFile(const char filename[]){
	const int NUM_FORMATOS = 2;
	const string formatos[NUM_FORMATOS] = {"P2", "P5"};
	
	int result = IMAGE_DISK_OK;
	
	string type;
	
	ifstream file;
	file.open(filename);
	
	//¿Se ha abierto correctamente el archivo?
	if (file){
		
		//¿Es correcto el formato de la imagen?
		file >> type;
		
		bool formato_ok = false;
		
		for (int i = 0; i < NUM_FORMATOS && !formato_ok; i++){
			formato_ok = (formatos[i] == type);
				
		}
		
		if (formato_ok){
			//¿Es correcto el tamaño de la imagen?
			int width, height;
			file >> width >> height;
			
			if (width >= 0 && height >= 0) {
				int tamanio_imagen = width * height;
				
				//¿Es la imagen demasiado grande?
				if (tamanio_imagen <= IMAGE_MAX_SIZE) {
					//Compruebo si aparece el 255 (valor maximo de la escala de grises)
					int max_gris;
					file >> max_gris;
					
					if (max_gris == 255){
						//¿Es correcto el numero de bits de la imagen?						
						setSize(width, height);
						
						for (int i = 0; i < tamanio_imagen; i++){
							int value;
							file >> value;
							
							if (file.eof()) {
								result = IMAGE_ERROR_DATA;
							} else {
								
								setPos(i, Byte(value));
								
								
							}
						}
						

					} else {
						result = IMAGE_ERROR_FORMAT;

					}

				} else {
					result = IMAGE_TOO_LARGE;
				}

			} else {
				result = IMAGE_ERROR_FORMAT;
				
			}
			
		} else {
			result = IMAGE_ERROR_FORMAT;
			
		}
		
	} else {
		result = IMAGE_ERROR_OPEN;
		
	}
	
	file.close();
	
	return result;
}

int Image::saveToFile(const char filename[]) const {
	int result = IMAGE_DISK_OK;
	
	ofstream file;
	file.open(filename);
	
	if (file){
		file << "P2\n";
		file << width() << " " << height() << "\n";
		file << "255\n";
		
		int tamanio_max = width()*height();
		
		for (int i = 0; i < tamanio_max; i++){
			file << getPos(i) << "\n";
			
		}
		
	} else {
		result = IMAGE_ERROR_OPEN;
	}
	
	file.close();
	
	return (result);
}

Histogram Image::getHistogram() const {
	Histogram histograma;
	int tamanio = height()*width();
	
	for (int i = 0; i < tamanio; i++){
		Byte b = getPos(i);
		int npixeles = histograma.getLevel(b)+1;
		
		histograma.setLevel(b, npixeles);
		
	}
	
	return (histograma);
}

Image Image::depictsHistogram() const{
	Histogram histograma = getHistogram();
	
	int w = 256, h = 160, b = 1, c = 9, a = h -(b+c)-2;
    int normal, max=-1;
    Image result(w, h);
	
	max = histograma.getMaxLevel();
	
    result.flatten(Byte(255));
    for (int x = 0; x <256; x++) {
        for (int y = 0; y < c; y++) {
            result.setPixel(x, h-1-y, x);
        }
        normal = (histograma.getLevel(Byte(x)) * a) / max;
        for (int y = 0; y <= normal; y++) {
            result.setPixel(x, h-c-b-y-1, 0);
        }
	}	
    return result;
}

void Image::extractObjects(Image set[], int &nimages, int maximages, double tolerance) const{    
    Histogram histogram=getHistogram();
    int max=histogram.getMaxLevel();
    
    bool buscandoSupTolerancia=true;
    nimages=0;
    vector <int> posIniciales; //posición más a la izquierda de cada bloque
    vector <int> posFinales;//posición más a la derecha de cada bloque
    
    for(int level=Histogram::HISTOGRAM_LEVELS-1; level>=0 && nimages<maximages; level--){
        if(buscandoSupTolerancia){
            if(histogram.getLevel(Byte(level))>=(max*tolerance)){
                posFinales.push_back(level);
                buscandoSupTolerancia=!buscandoSupTolerancia;
                
                if(level==0){
                    posIniciales.push_back(level);
                    nimages++;
                }
            }  
        }else{
            if(histogram.getLevel(Byte(level))<(max*tolerance) || level==0){
                /*if(level==0) posIniciales.push_back(level);
                else posIniciales.push_back(level-1);*/
                posIniciales.push_back(level);
                nimages++;
                buscandoSupTolerancia=!buscandoSupTolerancia;
            }
        } 
    }
    //Creo las imagenes
    for(int i=0; i<nimages; i++){
        Image image(width(), height());
        for(int x=0; x<width(); x++){
            for(int y=0; y<height(); y++){
                if(getPixel(x,y)>=posIniciales.at(i) && getPixel(x,y)<=posFinales.at(i)){
                    image.setPixel(x,y, Byte(getPixel(x,y)));
                }
            }
        }
        set[i]=image;
    }  
    
    for(int i=0; i<nimages; i++){
        cout << "Found object " << to_string(i) << " in " << "[" << to_string(posIniciales.at(i))
             << "," << to_string(posFinales.at(i)) << "]" << endl;
    }
    cout << "Found " << to_string(nimages) << " objects" << endl << endl;
}

//--------------------------------------------------
//	Imaging 3

Image Image::threshold(int t) const{
	
	Histogram hist = getHistogram();
	Image result (width(), height());
	
	if (t == -1){
		t = hist.getBalancedLevel();
	}
	
	int tamanio = width()*height();
	
	for (int i = 0; i < tamanio; i++){
		if (getPos(i) > t){
			result.setPos(i, Byte(255));
		} else {
			result.setPos(i, Byte(0));
		}
	}
	
	return (result);
}

Image Image::copyArea(int x, int y, int w, int h) const{
	//Compruebo la coordenada x
	if (x < 0){
		w = w + x;
		x = 0;
		
	} else if (x < _width){
		if (x+w > _width){
			w = w - ((x+w)-_width);
		}
		
	} else {
		w = 0;
	}
	
	//Compruebo la coordenada y
	if (y < 0){
		h = h + y;
		y = 0;
		
	} else if (y < _height){
		if (y+h > _height){
			h = h - ((y+h) - _height);
		}
		
	} else {
		h = 0;
		
	}

	Image result(w, h);

	for (int f = 0; f < w; f++){
		for (int c = 0; c < h; c++){
			result.setPixel(f, c, getPixel(x+f, y+c));
		}
	}
	
	return (result);
}

void Image::pasteArea(int x, int y, const Image &from, int toneup, int merge){
    //Variables con las medidas ya comprobadas, que no se salga del limite
    int w = from.width();
	int h = from.height();
    
    //Compruebo la coordenada x
	if (x < 0){
		w = w + x;
		x = 0;
		
	} else if (x < _width){
		if (x+w > _width){
			w = w - ((x+w)-_width);
		}
		
	} else {
		w = 0;
	}
	
	//Compruebo la coordenada y
	if (y < 0){
		h = h + y;
		y = 0;
		
	} else if (y < _height){
		if (y+h > _height){
			h = h - ((y+h) - _height);
		}
		
	} else {
		h = 0;
		
	}
    
    //Se pega la imagen, por pegado selectivo y gradual
    if(toneup<0 || toneup>255) toneup=0; //si no es correcto, se coge cero para pegar todos los pixeles
    if(merge<0 || merge>100) merge=100; //si no es correcto, se coge 100 para nomodificar la imagen
    
    if(w>0 && h>0){
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                if(from.getPixel(i,j)>=toneup){
                    //Se crea el pixel a copiar, que es la mezcla del original y la imagen from
                    Byte a_copiar(getPixel(x+i, y+j));
                    a_copiar.mergeByte(from.getPixel(i,j),merge);
                    setPixel(x+i, y+j, a_copiar);
                }
            }
        }
    }
}

Image::~Image(){
	clear();
	
}

Image::Image(const Image & from){
	_data = nullptr;
	copy(from);
	
}

Image & Image::operator=(const Image &rhs){
	if (&rhs != this){
		copy(rhs);
	}
	
	return *this;
	
}

Image Image::zoomIn() const{
	int w = 2 * width();
	int h = 2 * height();
	
	Image zoom_in(w, h);
	
	
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			if (x%2 == 0 && y%2 == 0){
				//Rellenamos solo las posiciones pares en columnas y filas con los pı́xeles 
				//originales de input.
				
				zoom_in.setPixel(x, y, Byte (getPixel(x/2, y/2)));
				
			} else {
				//Rellenar los puntos restantes con una interpolación de los puntos de
				//alrededor
				zoom_in.setPixel(x, y, Byte(copyArea((x/2)-1, (y/2)-1, 3, 3).getHistogram().getBalancedLevel()));
			
			}
		}
	}
	
	return (zoom_in);
	
}

Image Image::zoomOut() const{
	int w = width()/2;
	int h = height()/2;
	
	Image zoom_out (w, h);
	
	//Rellenamos cada pı́xel con una interpolación de los puntos de alrededor
	//en la imagen original.
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			zoom_out.setPixel(x, y, Byte(copyArea(x*2-1, y*2-1, 3, 3).getHistogram().getBalancedLevel()));
		}
		
	}
	
	return (zoom_out);
}

bool Image::showImage(int k, Image &result) const{
	const char IMG[3] = {'I', 'M', 'G'};
	
	bool image_found = true;
	int indice = 0;
	//Compruebo si se encuentra el indicador "IMG"
	for (int i = 0; i < 3 && image_found; i++, indice++){
		if (IMG[i] != showByteAt(indice, k).getValue()){
			image_found = false;
		}
	}
	
	if (image_found){
		int w = showByteAt(indice, k).getValue();
		indice++;
		
		int h = showByteAt(indice, k).getValue();
		indice++;
		
		int img_size = width() * height();
		
		//Compruebo que la imagen puede contener la imagen oculta
		if (img_size >= (((w*h) + 5) * Byte::NUM_BITS)){
			Image hidden_img(w, h);
			int size = w * h;
			
			for (int i = 0; i < size; i++){
				Byte b = showByteAt (indice, k);
				indice++;
				
				hidden_img.setPos(i, b);
				
			}
			
			result = hidden_img;
			
		} else {
			image_found = false;
		}
		
	}
	
	return (image_found);
}


bool Image::hideImage(int k, const Image &from){
	const char IMG[3]={'I', 'M', 'G'};
	
	//Comprobamos las condiciones para poder ocultar la imagen
	//	1. La imagen debe ser máximo de 255x255 (MAX_BYTE = 256)
	//	2. input tiene al menos (copyfrom.width()*copyfrom.height() + 5)*8 pixeles
	bool image_hidden = from.width() < Byte::MAX_BYTE && from.height() < Byte::MAX_BYTE && 
						width() * height() >= Byte::NUM_BITS * (5 + from.width()*from.height());
	
	if (image_hidden){
		int indice = 0;
		
		//Identificador
		for (int i = 0; i < 3; i++, indice++){
			hideByteAt(indice, k, IMG[indice]);
		}
		
		//Dimensiones
		hideByteAt(indice, k, from.width());
		indice++;
		
		hideByteAt(indice, k, from.height());
		indice++;
		
		//Data
		for (int i = 0; i < from.width(); i++){
			for (int j = 0; j < from.height(); j++){
				hideByteAt(indice, k, from.getPixel(j,i));
				indice++;
				
			}
		}
	}
	
	
	return (image_hidden);
}

bool Image::hideText(const char source [], int k){
	const char TXT[3] = {'T', 'X', 'T'};
	const char FIN= '\0';
	
	//Calculamos la longitud de la cadena
    int longitud = 0;
    
    while(source[longitud] != FIN){
        longitud++;
    }
	
	bool text_hidden = (width() * height() >= (longitud + 4) * 8);
	
	if (text_hidden){
		int indice = 0;
		
		//Identificador
        for(int i = 0; i < 3; i++, indice++){
            hideByteAt(indice, k, TXT[i]);
        }
		
		//Texto
		for (int i = 0; i <= longitud; i++, indice++){
			hideByteAt(indice, k, source[i]);
		}
		
	}
	
	return(text_hidden);
}

bool Image::showText(char hidden [], int max, int k) const {
	const char TXT[3] = {'T', 'X', 'T'};
	const char FIN = '\0';
	
	bool text_found = true;
	
	int indice = 0;
	
	//Comprobamos el identificador
	for (int i = 0; i < 3 && text_found; i++, indice++){
		if (TXT[i] != showByteAt(indice, k).getValue()){
			text_found = false;
		}
	}
	
	if (text_found){
		text_found = false;
		
		int img_size = width() * height();
		
		int num_pix = indice * Byte::NUM_BITS;
		int leidos = 0;
		while ((num_pix < img_size) && (leidos < max) && (!text_found)){
			hidden[leidos] = showByteAt(indice, k).getValue();
			
			if (hidden[leidos] == FIN){
				text_found = true;
			
			} else {
				leidos++;
				indice++;
			}
			
			num_pix += Byte::NUM_BITS;
		}
		
	}
	
	return (text_found);
}

//--------------------------------------------------
//	MÉTODOS PRIVADOS

void Image::clear(){
	if (_data != nullptr){
		
		for (int i = 0; i < _height; i++){
			delete [] _data[i];
		}
		
		delete [] _data;
		
		_data = nullptr;
	}
	
	_height = 0;
	_width = 0;
	
}

void Image::copy(const Image &rhs){
	int size = rhs.height() * rhs.width();
	
	setSize(rhs.width(), rhs.height());
	
	for (int i = 0; i < size; i++){
		setPos(i, Byte(rhs.getPos(i)));
	}
	
}

void Image::setSize(int width, int height){
	if (width >= 0 && height >= 0){
		clear();
		
		_width = width;
		_height = height;
		
		_data = new Byte * [height];
		
		for (int i = 0; i < height; i++){
			_data[i] = new Byte [width];
		}
		
		flatten(Byte (0));
	}
}

Byte Image::showByteAt (int i, int k) const {
	bool byte[Byte::NUM_BITS];   
    int inic = i * Byte::NUM_BITS;
    
    for(int j=0; j<Byte::NUM_BITS; j++){
        byte[j]=Byte(getPos(inic + j)).getBit(k);
    }

    Byte b;
    b.encodeByte(byte);
    
    return b;
}

void Image::hideByteAt (int i, int k, Byte b) {
	int inic = i * Byte::NUM_BITS;
	
	for (int j = (Byte::NUM_BITS - 1); j >= 0; j--){
		int pos = inic + 7 - j;
		Byte aux (getPos(pos));
		
		if (b.getBit(j)){	//Bit encendido --> 1
			aux.onBit(k);
			
		} else {			//Bit apagado --> 0
			aux.offBit(k);
			
		}
		
		setPos(pos, aux);
		
	}
}