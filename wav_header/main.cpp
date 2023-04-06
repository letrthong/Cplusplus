
#include <iostream>
 #include <unistd.h>
//#include <fstream>
#include <string>
#include <stdlib.h>
#include <fcntl.h>
using namespace std;
#include "wave.h"

 
int  readFile(const char* pathName, char* data) {
    int FileHandle = open(pathName, O_RDONLY);
     int len = -1;
    if (FileHandle == -1) {
        return len;
    }
    /*ssize_t bytes_read;*/
    len = read(FileHandle, data, 1024);
    if (len == -1) {
        close(FileHandle);
        return len;
    }

    close(FileHandle);
    return len;
}

int main(){
    cout<< "hello world "<<endl;
     
   char header[1024];
 
	 int len = readFile("sammple/StarWars60.wav", header);
   //int len = readFile("sammple/CantinaBand3.wav", header);
    
    if(len >= 48){
        WAVFile wav_header = WAV_ParseFileData((uint8_t const*) header);
        cout<< "--------------Start Show header information  "<<endl;
	 
	cout<< "header file_size="<<wav_header.header.file_size <<endl;
	cout<< "header sample_rate="<<wav_header.header.sample_rate <<endl;
	cout<< "header format="<<wav_header.header.format <<endl;
	
	
	cout<< "header audio_format="<<wav_header.header.audio_format <<endl;
	if(wav_header.header.audio_format == 1){
	   cout<< "Type of format (1 is PCM)"<< endl;
	}
	
	cout<< "header number_of_channels="<<wav_header.header.number_of_channels <<endl;
	
	
        cout<< "--------------End Show header information  "<<endl;
    }

    return 0;
}

 
