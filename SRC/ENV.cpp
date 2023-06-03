/**
 *ここにはライブラリみたいに色々書くよ〜
 *便利機能だね！！
*/

#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "ENV.h"//これENV.hの二重ロードになりそうだけどええんかな

/*
 *JSON解析
*/
String JSON_PARSE(String KEY, String JSON_DATA){
	//nlohmannはChatGPTによると標準ライブラリらしい、ほんとかあ？

	nlohmann::json json = nlohmann::json::parse(JSON_DATA);
	
	return json[KEY];
}

/**
 *ファイル取得
*/
String FILE_GET(String PATH){
	std::ifstream file(PATH);  // ファイルを開く

	if (file.is_open()) {  // ファイルが正常に開けた場合
		std::stringstream buffer;//ばっふぁー？らしい
		buffer << file.rdbuf();  // ファイルの内容をバッファに読み込む
		String fileContent = buffer.str();  // バッファから文字列を取得

		file.close();  // ファイルを閉じる

		return fileContent;//ファイルを返り血として返す

		/*
		//実験用コード
		while (std::getline(file, line)) {  // 1行ずつ読み込む
			std::cout << line << std::endl;  // 読み込んだ行を表示する
		}
		*/
	} else {
		return "";
	}
	return "";
}

/**
 *文字列出力
*/
void PRINT(String TEXT){
	std::cout << TEXT << std::endl;
}

//「メモリに受け取るためのコールバック関数」らしい
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
	size_t totalSize = size * nmemb;
	response->append(static_cast<char*>(contents), totalSize);
	return totalSize;
}
/**
 * HTTPリクエスト
*/
String HTTP_REQUEST(String URI){
	CURL* curl;
	CURLcode res;
	std::string response;

	// CURLセットアップ
	curl = curl_easy_init();
	if (curl) {
		// URL指定
		curl_easy_setopt(curl, CURLOPT_URL, URI.c_str());

		// 応答をメモリに受け取る設定
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		// リクエスト送信
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			return "";
		}
		
		// CURLクリーンアップ
		curl_easy_cleanup(curl);

		// 応答返す
		return response;
	}else{
		return "";
	}
}