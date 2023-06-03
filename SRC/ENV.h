/**
 *ここに、定義とかを書くよ、
 *とある動画では、これを使って全部ロシア語で記述してたりしたなあ
*/

#ifndef STRING_UTILS_H//なんこれ
#define STRING_UTILS_H//なんよこれ

#include <string>//stringをインクル

typedef std::string String;//std::stringをStringとして省略

String RAPT_PRC = "1.0";

void PRINT(String TEXT);//文字列出力用
String FILE_GET(String PATH);//ファイル取得
String JSON_PARSE(String KEY, String JSON_DATA);//JSON解析
String HTTP_REQUEST(String URI);//HTTPリクエスト

#endif  // STRING_UTILS_H
