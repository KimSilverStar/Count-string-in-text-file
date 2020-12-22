#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	string fileName, word;	// �Է¹��� ���� �̸�(���), �˻��� �ܾ�
	string text;		// ���� ������ ������ string ��ü
	size_t fSize = 0, count = 0;	// ���� ũ��, �˻��� �ܾ ������ Ƚ��

	cout << "Input file name(path): ";	cin >> fileName;
	cout << "Input word: ";			cin >> word;
	cout << endl;

	ifstream readFile(fileName);
	if (!readFile.is_open()) {
		cout << "File name(path) is not correct" << endl;
		exit(-1);
	}

	readFile.seekg(0, ios::end);
	fSize = readFile.tellg();		// �ؽ�Ʈ ������ ũ�� ����
	readFile.seekg(0, ios::beg);

	text.resize(fSize);				// string ��ü(text)�� �����̳� ũ�⸦ ���� ũ�⿡ ����
	readFile.read(&text[0], fSize);	// �ؽ�Ʈ ���� ���� string�� ����

	size_t i = text.find(word);		// �ؽ�Ʈ ������ ������ ����� string ��ü(text)���� �ܾ� �˻�
	while (i != string::npos) {		// �˻��� �ܾ �� �̻� ������ ���������� �˻� ����
		count++;
		i = text.find(word, i + 1);	// �ܾ �˻��Ǹ�, �ش� ��ġ(index) �� �������� �˻� ����
	}

	cout << "Searched word \"" << word << "\" appears "
		<< "\"" << count << "\"" << " tiems" << endl;

	readFile.close();

	system("pause");
	return 0;
}