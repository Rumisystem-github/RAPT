#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "ENV.h"

int main(int argc, char* argv[]){
	String SETTING = FILE_GET("./BIN/SETTING.json");
	if(SETTING != ""){
		PRINT(JSON_PARSE("URI", SETTING));
	}else{
		PRINT("OMG..... SETTING FILE LOAD ERR!");
	}
/*
	CURL* curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if(curl) {
		// リクエストを設定
		curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
	
		// 必要に応じて他の設定を追加
	
		// リクエストを送信
		res = curl_easy_perform(curl);
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
	
		// クリーンアップ
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();

*/
	return 0;
}
