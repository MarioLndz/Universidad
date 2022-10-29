/**
 * @file main.cpp
 * @author MP
 */
#include <iostream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
#include "Histogram.h"

using namespace std;

/**
 * @brief It waits until the key [INTRO] [RETURN] is pressed
 */
void pressReturnToContinue();

/**
 * @brief It breaks the program due to some error and shows a message
 * @param errorcode The type of error as declared in Image.h
 * @param errordata A message trying to describe the error
 */
void errorBreak(int errorcode, const string & errordata);

enum class Accion {nothing, zoom, hide_text, show_text, hide_image, show_image};

/** 
 * Structs usados para almacenar los parámetros del main
 */
struct Argumentos {
	string input;
	string output;
	int zoom;
	
	int plane;
	
	string hide_text;
	
	string hide_image;
	
	Accion accion;
	
	
};

/**
 * @brief It validates and returns the arguments given to main
 * @param num_arg Number of arguments given to main
 * @param arg An "array of char string". It contains the arguments that will be revise
 */
Argumentos CheckArgumentos(int num_arg, char **arg);

/**
 * @brief It breaks the program due to a main's argument error and shows a message
 */
void ErrorBreakArgumentos (bool comp, string error_code);

int main(int argc, char **argv) {
   Argumentos args = CheckArgumentos(argc, argv);
	
	cout << "Carrier Image ... " << args.input << endl;
	cout << "Output to ... ";
	
	if (args.accion == Accion::show_text && args.output == ""){
		cout << "screen" << endl;
	} else if ((args.accion == Accion::show_image || args.accion == Accion::hide_image ||
				args.accion == Accion::hide_image || args.accion == Accion::zoom) &&
				args.output == ""){
		cout << "data/new.pgm" << endl;
	} else {
		cout << args.output << endl;
	}
	
	cout << endl;
	
	Image im_input, im_output;
	
	//Lectura de la imagen
	cout << endl;
	cout << "...Reading image from " << args.input << endl;
    int res = im_input.readFromFile(args.input.c_str());
    if (res != Image::IMAGE_DISK_OK) {
        errorBreak(res, args.input);
    }
	
	cout << im_input.width() << "x" << im_input.height() << endl;
	cout << endl;
	
	
	switch (args.accion){
		case(Accion::zoom):{
			//Zoom de la imagen
			if (args.zoom == 1){			//Zoom In
				cout << endl << "...Zooming in" << endl;

				im_input = im_input.zoomIn();


			} else if (args.zoom == -1){	//Zoom Out
				cout << "...Zooming out" << endl;

				im_input = im_input.zoomOut();


			}
			
			im_output = im_input;
			
			break;	//Fin Zoom
		}
		
		case (Accion::hide_text):{
			ifstream file;
			file.open(args.hide_text.c_str());
			
			string text;
			
			if (file) {
				while(file){
					string aux;
					getline(file, aux);
					text = text + aux + "\n";
				}
				text.pop_back();
				
				cout << "...Hiding text" << endl;
				bool hide = im_input.hideText(text.c_str(), args.plane);
				
				if (!hide){
					cout << "Error hiding text" << endl;
					std::exit(1);
				}
				
				file.close();
				
				im_output = im_input;
				
			} else {
				file.close();
				cout << "Error opening file " << args.hide_text << endl;
				std::exit(1);
				
			}
			
			
			break;	//Fin Hide_Text
		}
		
		case (Accion::show_text):{
			int tamanio = (im_input.width() * im_input.height()) / 8; 
            char *source = new char [tamanio];
			
			cout << "...Seeking text at plane " << args.plane << endl;
						
			bool show = im_input.showText(source, tamanio, args.plane);
			
			
			if (show){
				cout << "...Showing text ..." << endl;
				
				string s = source;
				cout << "...Found " << s.length() << " bytes" << endl;
				
				if(args.output.length() != 0){ //Si se ha introducido un argumento de salida, guardo el texto en ese archivo 
                    ofstream file;
					file.open(args.output.c_str());
					
					cout << "...Saved " << s.length() << " bytes of text in " << args.output << endl;
                    file << s;
                    
                    file.close();
                    
                } else {	//Si no, lo muestro por pantalla
					cout << endl << "Showing text found:" << endl << endl;
					cout << s << endl << endl;
				}
                
				
			} else {
				cout << "No text found" << endl;
                delete [] source; //Liberamos la memoria reservada
                std::exit(1); 
				
			}
			delete [] source;
			
			break;	//Fin Show_Text
		}
		
		case (Accion::hide_image):{
			Image hideim;
            int error = hideim.readFromFile(args.hide_image.c_str());
			
			if(error != Image::IMAGE_DISK_OK){
				errorBreak(error, args.hide_image);
			
			} else {
				cout << "...Hiding image " << args.hide_image << " at plane " << args.plane << endl;
				bool hide = im_input.hideImage(args.plane, hideim);
				
				if (hide){
					cout << "...Hiding image " << hideim.width() << "x" << hideim.height() 
                         << " = " << hideim.width()*hideim.height() << " bytes" << endl;
                    cout << "OK" << endl;
					
					im_output = im_input;
					
				} else {
					cout << "Error hiding image" << endl;
                    std::exit(1);
				}
				
			}
			break;
		}
		
		case (Accion::show_image):{
			cout << "...Seeking image at plane " << args.plane << endl;
            		
			bool show = im_input.showImage(args.plane, im_output); 
			
			if (show){
				cout << "...Showing image in plane " << args.plane << endl;
				cout << "...Found " << im_output.width() << "x" << im_output.height() << " pixels" << endl;
				
			} else {
				cout << "No image found" << endl;
                std::exit(1);
				
			}
			
			break;
		}
		
		default:{	//Nothing
			break;
		}
	}
	
	//Como no disponemos del método showInWindow, siempre la imagen deberá ser guardada en un fichero
	//Guardado de la imagen resultante
    if (args.accion == Accion::show_image || args.accion == Accion::hide_image || 
		args.accion == Accion::hide_text || args.accion == Accion::zoom){
		
		if (args.output.length() == 0){
			args.output = "./data/new.pgm";
		}
		
		cout << endl << "...Saving image into " << args.output << endl << endl;
		int save = im_output.saveToFile(args.output.c_str());
		
		if (save != Image::IMAGE_DISK_OK){
			errorBreak(save, args.input);
		}
	}

    pressReturnToContinue();
    return 0;
}
        

void pressReturnToContinue() {
    char aux[10];
    cout << "Press [RETURN] to continue ...";
    cin.getline(aux, 1, '\n');
}

void errorBreak(int errorcode, const string & errordata) {
    switch (errorcode) {
        case Image::IMAGE_ERROR_OPEN:
            CVAL << endl << "Error opening file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_DATA:
            CVAL << endl << "Data error in file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_FORMAT:
            CVAL << endl << "Unrecognized format in file " << errordata << endl;
            break;
		case Image::IMAGE_TOO_LARGE:
			CVAL << endl << "The image is too large and it does not fit into memory " << errordata << endl;
			break;
    }
    std::exit(1);
}

Argumentos CheckArgumentos(int num_args, char **argumentos){
	const int TOTAL_ID = 8;
	const string ARGID [TOTAL_ID] = {"-i", "-o", "-z", "-p", "-ht", "-st", "-hi", "-si"};
	
	const int TOTAL_ARGS = (TOTAL_ID * 2) + 1;
	
	string args[TOTAL_ARGS];
	
	if (num_args <= TOTAL_ARGS){
		for (int i = 0; i < num_args; i++){
			args[i] = argumentos[i];
		}
	}
	
	Argumentos arg;
	//Booleanos y argumentos por defecto
	bool i_found = false;
	arg.input = "";
	
	bool o_found = false;
	arg.output = "";
	
	bool z_found = false;
	arg.zoom = 0;
	
	bool p_found = false;
	arg.plane = 0;
	
	bool ht_found = false;
	arg.hide_text = "";
	
	bool st_found = false;
	
	bool hi_found = false;
	arg.hide_image = "";
	
	bool si_found = false;
	
	bool args_ok = true;
	
	
	if (num_args >= 2 && num_args <= TOTAL_ARGS){
		for (int i = 1; i < num_args && args_ok; i++){
			if (args[i] == ARGID[0]){			//"-i" --> input
				if (!i_found){
					i_found = true;
					i++;
					
					if (i == num_args) {
						args_ok = false;
						ErrorBreakArgumentos (args_ok, "Error in call: Missing input direction");
					}
					
					//Comprobamos el siguiente parametro: Deberia ser la direccion de input
					for (int j = 0; j < TOTAL_ID; j++){
						if (args[i] == ARGID[j]){	//Input en blanco: Error
							args_ok = false;
						}

					}

					if (args_ok){
						arg.input = args[i];
					}
				} else {	//Argumento repetido
					args_ok = false;
				}


			} else if (args[i] == ARGID[1]){	//"-o" --> output
				if (!o_found){
					o_found = true;
					i++;
					
					if (i == num_args) {
						args_ok = false;
						ErrorBreakArgumentos (args_ok, "Error in call: Missing output direction");
					}
					
					//Comprobamos el siguiente parametro: Deberia ser la direccion de output
					for (int j = 0; j < TOTAL_ID; j++){
						if (args[i] == ARGID[j]){	//Output en blanco: Error
							args_ok = false;
						}

					}

					if (args_ok){
						arg.output = args[i];
					}
				} else {	//Argumento repetido
					args_ok = false;
				}
				
			} else if (args[i] == ARGID[2]){	//"-z" --> zoom
				if (!z_found){
					z_found = true;
					i++;
					
					if (i == num_args) {
						args_ok = false;
						ErrorBreakArgumentos (args_ok, "Error in call: Missing zoom value");
					}
					
					//Comprobamos que el parámetro no esté en blanco
					for (int j = 0; j < TOTAL_ID; j++){
						if (args[i] == ARGID[j]){	//Zoom en blanco: Error
							args_ok = false;
						}

					}

					//Comprobamos el valor del zoom
					if (args_ok){
						if (args[i] == "-1" || args[i] == "0" || args[i] == "1"){
							arg.zoom = stoi(args[i]);
							
						} else {
							args_ok = false;
						}

					}
				} else {	//Argumento repetido
					args_ok = false;
				}

			} else if (args[i] == ARGID[3]) {	//"-p" --> Plano
				if (!p_found){
					p_found = true;
					i++;
					
					if (i == num_args) {
						args_ok = false;
						ErrorBreakArgumentos (args_ok, "Error in call: Missing plane value");
					}
					
					//Comprobamos el siguiente parametro: Deberia ser el numero de plano
					for (int j = 0; j < TOTAL_ID; j++){
						if (args[i] == ARGID[j]){	//Plano en blanco: Error
							args_ok = false;
						}

					}
					
					//Comprobamos el valor del plano
					if (args_ok){
						args_ok = false;
						
						int num = 0;
						while (num < Byte::NUM_BITS && !args_ok){
							string cad = to_string(num);
							
							if (args[i] == cad){
								args_ok = true;
							}
							
							num++;
						}
						
						if (args_ok){
							arg.plane = stoi(args[i]);
						}
					}
					
				} else {	//Argumento repetido
					args_ok = false;
				}
				
			} else if (args[i] == ARGID[4]) {	//"-ht" --> Hide_text
				if (!ht_found){
					ht_found = true;
					i++;
					
					if (i == num_args) {
						args_ok = false;
						ErrorBreakArgumentos (args_ok, "Error in call: Missing text direction");
					}
					
					//Comprobamos el siguiente parametro: Deberia ser la direccion del texto a esconder
					for (int j = 0; j < TOTAL_ID; j++){
						if (args[i] == ARGID[j]){	//Hide_text en blanco: Error
							args_ok = false;
						}

					}
					
					//Comprobamos
					if (args_ok){
						arg.hide_text = args[i];
					}
				} else {	//Argumento repetido
					args_ok = false;
				}
				
			} else if (args[i] == ARGID[5]) {	//"-st" --> Show_text
				if (!st_found){
					st_found = true;
					
				} else {	//Argumento repetido
					args_ok = false;
				}
				
				
			} else if (args[i] == ARGID[6]) {	//"-hi" --> Hide_image
				if (!hi_found){
					hi_found = true;
					i++;
					
					if (i == num_args) {
						args_ok = false;
						ErrorBreakArgumentos (args_ok, "Error in call: Missing image direction");
					}

					//Comprobamos el siguiente parametro: Deberia ser la direccion de la imagen a esconder
					for (int j = 0; j < TOTAL_ID; j++){
						if (args[i] == ARGID[j]){	//Hide_imagen en blanco: Error
							args_ok = false;
						}

					}
					
					//Comprobamos
					if (args_ok){
						arg.hide_image = args[i];
					}
				} else {	//Argumento repetido
					args_ok = false;
				}
				
			} else if (args[i] == ARGID[7]) {	//"-si" --> Show_image
				if (!si_found){
					si_found = true;
					
				} else {	//Argumento repetido
					args_ok = false;
				}
				
			} else {						//Argumento mal escrito
				args_ok = false;
			}

		}		
				
	} else {
		args_ok = false;
		ErrorBreakArgumentos (args_ok, "Error in call: Too many or not enough arguments");
	}
	
	ErrorBreakArgumentos (args_ok, "Error in call: wrong arguments");
	ErrorBreakArgumentos (i_found, "Error in call: Missing input file");
	
	
	bool z_ok = z_found && !ht_found && !st_found && !si_found && !hi_found;
	bool ht_ok = ht_found && !st_found && !hi_found && !si_found && !z_found;
	bool st_ok = st_found && !ht_found && !si_found && !hi_found && !z_found;
	bool hi_ok = hi_found && !ht_found && !st_found && !st_found && !z_found;
	bool si_ok = si_found && !ht_found && !st_found && !hi_found && !z_found;
	
	if (z_ok){
		arg.accion = Accion::zoom;
	} else if (ht_ok) {
		arg.accion = Accion::hide_text;
	} else if (st_ok) {
		arg.accion = Accion::show_text;
	} else if (hi_ok) {
		arg.accion = Accion::hide_image;
	} else if (si_ok) {
		arg.accion = Accion::show_image;
	} else {
		arg.accion = Accion::nothing;
	}
	
	
	return (arg);
	
}


void ErrorBreakArgumentos (bool comp, string error_code){
	if (!comp){
		cout << endl;
		cout << error_code << endl;
        cout << "Please use: -i <input> [-o <output> -z <zoom> -p <k> -ht <textSource> -st -hi <imageSource> -si]" << endl;
        cout << "-i <imageCarrier> : Input image from <input>" << endl;
        cout << "-o <output> : Output image to <output> " << endl;
		cout << "-z <zoom> : Level of zoom wanted [-1: Zoom Out / 1: Zoom In]" << endl;
		cout << "-p <plane> : bit-plane to deal with. Its default is 0" << endl;
		cout << "-ht <textSource> : Hide text comtained in the file" << endl;
		cout << "-st : Showing the text encoded in the file" << endl;
		cout << "-hi <imageSource> : Hide image comtained in the file" << endl;
		cout << "-si : Showing the image encoded in the file" << endl;
		
		std::exit(1);
	}
	
}