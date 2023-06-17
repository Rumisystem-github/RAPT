/**
 * RAPT V1.0
 * By るみさん(Rumi's)
*/

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "ENV.h"

void HELP(){
	PRINT("┌─[RAPTコマンド ヘルプ]");
	PRINT("│update/-Syy");
	PRINT("│→パッケージリストを更新します");
	PRINT("│upgrade/-Syyu");
	PRINT("│→パッケージを更新します");
	PRINT("│");
	PRINT("│");
	PRINT("│");
	PRINT("│");
}

int UPDATE(String SETTING){
	String REQ_URI = JSON_PARSE("URI", SETTING);//リクエスト先URI

	PRINT("[ *** ]GET:" + REQ_URI);
	String REPO_INDEX_DATA = HTTP_REQUEST(REQ_URI + "/index.json");//リクエスト送信
	if(REPO_INDEX_DATA != ""){//エラーチェック
		//成功
		PRINT("[ OK ]GET:" + REQ_URI);

		//リポジトリの設定情報を解析
		String REPO_INDEX_PLU = JSON_PARSE("PAC_LIST_URI", REPO_INDEX_DATA);//パッケージリストのリクエスト先
		PRINT("[ LOG ]PAC LIST URI:" + REPO_INDEX_PLU);
		String REPO_INDEX_PU = JSON_PARSE("PAC_URI", REPO_INDEX_DATA);//パッケージ本体の取得先
		PRINT("[ LOG ]PAC URI:" + REPO_INDEX_PLU);

		//パッケージリストを取得
		PRINT("[ *** ]GET:" + REQ_URI + "/" + REPO_INDEX_PLU);
		String REPO_LIST_DATA = HTTP_REQUEST(REQ_URI + "/" + REPO_INDEX_PLU);//リクエスト送信
		if(REPO_LIST_DATA != ""){//エラーチェック
			//成功
			PRINT("[ OK ]" + std::to_string(JSON_PARSE_ARRAY_COUNT(REPO_LIST_DATA)) + "件のパッケージが見つかりました");
			PRINT("[ *** ]アップデートのチェックをしています。。。");
		}else{
			//エラー
			PRINT("[ ERR ]失敗 GET:" + REQ_URI + "/" + REPO_INDEX_PLU);
			PRINT("要求したサーバーは、index.jsonの設定がしっかりとされていません。\n管理者に問い合わせてください");
			return 1;
		}
	}else{
		//エラー
		PRINT("[ ERR ]失敗 GET:" + REQ_URI + "/index.json");
		PRINT("要求したサーバーは、本当にRAPTのリポジトリサーバーですか？確認してください。");
		return 1;
	}

	return 0;
}

//mainはintでやる決まりでも有るんかな
int main(int argc, char* argv[]){
	if(argc <= 1){//コマンドライン引数があったか
		HELP();
		return 0;
	}
	
	/*ここから設定ファイル読み込み*/
	String SETTING = FILE_GET("./BIN/SETTING.json");//設定ファイルを読み込み
	if(SETTING != ""){//エラーチェック
		String CMD = std::string(argv[1]);
		if(CMD == "update" || CMD == "-Syy"){
			return UPDATE(SETTING);
		}else if (CMD == "upgrade" || CMD == "-Syyu"){
			PRINT("実装中");
		}else if (CMD == "install"){
			PRINT("実装中");
		}
	}else{
		PRINT("設定ファイルが異常です、確認してください");
	}
	return 0;
}