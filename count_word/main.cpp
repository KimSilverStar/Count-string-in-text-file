#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	string fileName, word;	// 입력받을 파일 이름(경로), 검색할 단어
	string text;		// 파일 내용을 저장할 string 객체
	size_t fSize = 0, count = 0;	// 파일 크기, 검색한 단어가 나오는 횟수

	cout << "Input file name(path): ";	cin >> fileName;
	cout << "Input word: ";			cin >> word;
	cout << endl;

	ifstream readFile(fileName);
	if (!readFile.is_open()) {
		cout << "File name(path) is not correct" << endl;
		exit(-1);
	}

	readFile.seekg(0, ios::end);
	fSize = readFile.tellg();		// 텍스트 파일의 크기 저장
	readFile.seekg(0, ios::beg);

	text.resize(fSize);				// string 객체(text)의 컨테이너 크기를 파일 크기에 맞춤
	readFile.read(&text[0], fSize);	// 텍스트 파일 내용 string에 저장

	size_t i = text.find(word);		// 텍스트 파일의 내용이 저장된 string 객체(text)에서 단어 검색
	while (i != string::npos) {		// 검색한 단어가 더 이상 나오지 않을때까지 검색 진행
		count++;
		i = text.find(word, i + 1);	// 단어가 검색되면, 해당 위치(index) 그 다음부터 검색 진행
	}

	cout << "Searched word \"" << word << "\" appears "
		<< "\"" << count << "\"" << " tiems" << endl;

	readFile.close();

	system("pause");
	return 0;
}