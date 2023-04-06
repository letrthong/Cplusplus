
#include <iostream>
 #include <unistd.h>
//#include <fstream>
#include <string>
#include <stdlib.h>
#include <fcntl.h>
using namespace std;
#include "wave.h"

#include "acoustic_db.h"
#include <unistd.h>
     
     
#define AUDIO_SAMPLING_FREQUENCY 16000
#define PCM_BUFFERIN_SIZE 256

 
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


     AcousticDB_Handler_t DB_Handler;  
    AcousticDB_Config_t DB_Config;   

    uint32_t error_value = 0;  
	DB_Handler.sampling_frequency = AUDIO_SAMPLING_FREQUENCY;
	error_value = AcousticDB_Init(&DB_Handler);
	if(error_value != 0)
	{
		printf("AcousticDB_Init failed \n\r " );
	}
	
	DB_Config.offset = 0;
	error_value = AcousticDB_setConfig(&DB_Handler,&DB_Config);
	if(error_value != 0)
	{
		printf("AcousticDB_setConfig failed \n\r " );
	}

    int32_t tempValue = 0;
   char pcm_buffer[PCM_BUFFERIN_SIZE];

    int count = 0;
	while(1) {
		//printk("Hello World! %d \n\r ", count++);
		usleep(1000);
		if(AcousticDB_Data_Input(pcm_buffer, PCM_BUFFERIN_SIZE, &DB_Handler))
		{
			AcousticDB_Process(&tempValue, &DB_Handler); 
			printf("%d tempValue=%d \n\r ",  count++, tempValue);  
		}
	}  
    return 0;
}

 
