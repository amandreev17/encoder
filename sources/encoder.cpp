#include "header.h"

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        cerr << "Error: Use three parameters\n";
        return 5;
    }
    const string mode(argv[1]);
    const string file_name(argv[2]);
    if (mode != "encryption" && mode != "decryption") {
        cerr << "Error: Invalid mode\n";
        return 9;
        if (mode == "encryption") {
            cout << "Enter the text" << endl;
            ofstream out(file_name, ios_base::binary);
            if (!out.is_open()) {
                cerr << "Error:: File does not exist\n";
                return 1;
            }
            string text_in;
            cout << "Enter the text" << endl;
            getline(cin, text_in);
            int key;
            cout << "Enter the key" << endl;
            cin >> key;
            char* text_out = new char[text_in.size()];
            int len = text_in.size();
            encoder_decoder(text_in.c_str(), text_out, len, key);
            out << len << endl;
            out << text_out;
            out.close();
        }
        else if (mode == "decryption") {
            std::ifstream in(file_name, ios_base::binary);
            if (!in.is_open()) {
                cerr << "Error: File does not exist\n";
                return 1;
            }
            int len;
            in >> len;
            in.ignore(2, '\n');
            string text_out;
            getline(in, text_out);
            int key;
            cout << "Enter a key\n";
            cin >> key;
            char* text_out_2 = new char[len + 1];
            encoder_decoder(text_out.c_str(), text_out_2, len, key, false);
            text_out_2[len] = 0;
            cout << text_out_2 << endl;
            in.close();
        }
        return 0;
    }
}
