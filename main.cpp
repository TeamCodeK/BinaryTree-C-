#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include "binarytree.h"
using namespace std;

std::vector<std::string> split(std::string input, std::string str) {
    std::vector<std::string> o;
	std::string s;
	input.push_back(str[0]);
	for (int i=0; i != input.length(); i++) {
	    if (input[i] == str[0]) {
	    	o.push_back(s);
		    s = "";
	    } else {
	        s.push_back(input[i]);
	    }
	}
	return o;
};

void sayHello() {
    cout << "\e[1;34m";
    cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << endl;
    cout << "[                                               ]" << endl;
    cout << "[                BINARY TREE                    ]" << endl;
    cout << "[                                               ]" << endl;
    cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << endl;
    cout << "\e[0m";
}

int menu() {
    sayHello();
    cout << "       \e[1;33m"<<"["<<"\e[1;31m"<<0<<"\e[1;33m"<<"]"<<"\e[0m"<<" Exit!" << endl;
    cout << "       \e[1;33m"<<"["<<"\e[1;31m"<<1<<"\e[1;33m"<<"]"<<"\e[0m"<<" Make a new Binary Tree" << endl;
    cout << "       \e[1;33m"<<"["<<"\e[1;31m"<<2<<"\e[1;33m"<<"]"<<"\e[0m"<<" Add Node" << endl;
    cout << "       \e[1;33m"<<"["<<"\e[1;31m"<<3<<"\e[1;33m"<<"]"<<"\e[0m"<<" Show Tree" << endl;
    cout << "       \e[1;33m"<<"["<<"\e[1;31m"<<4<<"\e[1;33m"<<"]"<<"\e[0m"<<" Delete Node" << endl;
    cout << "Your choose: ";
    int choose;
    cin >> choose;
    return choose;
}

inline void wait() {
    cin.ignore(1000, '\n');
    while(true) {
        char k = getchar();
        if (k == '\n')
            break;
    }

}

int main() {
    system("clear");
    NODE* root = NULL;

    while(true) {

        system("clear");
        switch(menu()) {
            case 0:
                system("clear");
                exit(0);
            case 1: {
                // Tạo cây mới
                std::string nembers;

                cout << "Enter nembers: ";
                cin >> nembers;

                std::vector<std::string> vector_nember = split(nembers, "|");

                for (int i = 0; i < vector_nember.size(); i++)
                    insertNode(root, std::atoi(vector_nember[i].c_str()));
                cout << "\e[1;37m";
                NLR(root);
                wait();
                cout << endl;
                break;
            }
            case 2: {
                // Thêm node cho cây 
                std::string newNember;   
                cout << "Enter new nember: ";
                cin >> newNember;
                insertNode(root, std::atoi(newNember.c_str()));
                cout << "\e[1;37m";
                NLR(root);
                wait();
                cout << endl;
                break;
            }
            case 3: {
                // Duyệt cây nhị phân
                int c;
                cout << "Type [0] NLR, [1] NRL: ";
                cin.ignore();
                cin >> c;
                cout << "\e[1;37m";
                if (c == 0) {
                    NLR(root);
                    cout << " ";
                }
                if (c == 1) {
                    NRL(root);
                    cout << " ";
                }
                wait();
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
