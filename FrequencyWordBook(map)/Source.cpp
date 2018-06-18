#include"LIbrary.h"
string& toLowerString(string &s) {
	for (int i = 0; i < s.size();i++)
		s[i] = tolower(s[i]);
	return s;
}

int main() {
	setlocale(LC_ALL, "Russian");

	/*1.	ѕрограмма проверки правильности слов в текстовом файле. ѕроверка правильности осуществл€етс€
	с помощью частотного словар€. ƒл€ реализации частотного словар€ использовать класс map<string, int>\
	( лючом €вл€етс€ строка, значение Ц частота повторени€ слова). „астотный словарь формируетс€ на основе
	некоторого текстового документа, который считаетс€ орфографически правильным. (Ётот файл открываетс€,
	каждое слово читаетс€ и сохран€етс€ в vector<string> (или list<string> или deque<string>).
	«атем все слова перевод€тс€ в нижний регистр и перенос€тс€ в частотный словарь map<string, int>,
	который сохран€етс€ в файл.)
	ѕри проверке текста указываетс€ им€ файла, содержащего текст дл€ проверки.
	ѕрограмма открывает этот файл, и, извлека€ из него слова, осуществл€ет их поиск в частотном словаре.
	≈сли слово в словаре не найдено, то пользователю предлагаетс€ или заменить это слово на другое
	(вводит пользователь) или добавить слово в частотный словарь. ѕровер€емый файл должен сохран€тьс€
	с изменени€ми, которые внес в него пользователь.
	¬ реализации программы приветствуетс€ наличие удобного пользовательского интерфейса
	(приложение консольное), а также наличие самосто€тельно разработанных дл€ решени€ поставленной задачи классов.
	*/

	map<string, int> dict;
	ifstream in_file("First.txt");
	string word,word2;
	vector<string>words;

	int count = 0;
	if (!in_file) {
		cout << "File open error" << endl;
	}
	else {
		while (!in_file.eof()) {
			in_file >> word;
			words.push_back(word);
		}
	}
	for (int i = 0;i < words.size();i++) {
		toLowerString(words[i]);
	}
	for (int i = 0;i < words.size();i++) {
		dict[words[i]]++;
	}
	for (auto it = dict.begin();it != dict.end();it++)
		cout << it->first << "\t" << it->second << endl;
	in_file.close();


	in_file.open("Second.txt");
	if (!in_file) {
		cout << "File open error" << endl;
	}
	else {
		while (!in_file.eof()) {
			in_file >> word2;
			toLowerString(word2);
			count = 0;
			for (auto it = dict.begin();it != dict.end();it++) {
				if (word2 == it->first) {
					count++;
				}
			}
			
			if (count == 0) {
				cout << " Word not found." << endl;
				int k;
				cout << "1. replace the word, "<<endl;
				cout << "2. add to the dictionary "<<endl;
				cin >> k;
				switch (k)
				{
					// cin -1 word, getline- sentence
				case 1: {
					string newWord;
					cout << "Enter a newWord: ";
					cin >> newWord;
					dict[newWord]++;
					
				}break;

				case 2: {
					dict[word2]++;
					
				}break;
				}
			}
		}
	}
	for (auto it = dict.begin();it != dict.end();it++)
		cout << it->first << "\t" << it->second << endl;
	in_file.close();

	ofstream out;
	out.open("Third.txt");
	for (auto it = dict.begin();it != dict.end();it++)
		out << it->first << "\t" << it->second << endl;
	out.close();

	system("pause");
	return 0;
}

