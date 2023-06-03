/**
 * RAPT V1.0
 * By るみさん(Rumi's)
*/

#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "ENV.h"

int main(int argc, char* argv[]){
	//mainはintでやる決まりでも有るんかな
	String SETTING = FILE_GET("./BIN/SETTING.json");
	if(SETTING != ""){
		PRINT(JSON_PARSE("URI", SETTING));
		PRINT(HTTP_REQUEST(JSON_PARSE("URI", SETTING)));
	}else{
		PRINT("OMG..... SETTING FILE LOAD ERR!");
	}
	return 0;
}
