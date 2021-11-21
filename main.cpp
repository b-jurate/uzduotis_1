#include <iostream>
#include <map>

using namespace std;

/* Užduotis:
 * Convert Roman numbers to Arabic number.
 * There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */


int romanToArab(string s) {
    /*
     sukuriama struktura "map", kurioje yra romenisku simboliu reiksmes (arabiski)
     su raktais (romeniski skaiciai)
    */
    map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int suma = 0;
    cout << s << " ";

    // jeigu ivedamas per ilgas skaicius
    if (s.length() > 15) {
        cout << "Romėniškas skaičius gali būti max 15 elementų." << endl;
    }

    // einama per ivesti ir tikrinami po viena simboliai
    for (int i = 0; i < s.size() ; ++i) {
        if (
                !(s[i] == 'I' ||
                  s[i] == 'V' ||
                  s[i] == 'X' ||
                  s[i] == 'L' ||
                  s[i] == 'C' ||
                  s[i] == 'D' ||
                  s[i] == 'M')
                ) {
            cout << "Romėniškas skaičius neegzistuoja" << endl;
            return -1;
        }
        // jei esamas elementas mazesnis uz sekanti
        if (roman[s[i]] < roman[s[i+1]]) {
            // tikrinamos romeniskos taisykles, ar skaicius tinkamas
            if (
                    (roman[s[i]] == roman['I'] && (roman[s[i+1]] == roman['L']
                                                   || roman[s[i+1]] == roman['C']
                                                   || roman[s[i+1]] == roman['D']
                                                   || roman[s[i+1]] == roman['M']
                                                    )
                    ) || (roman[s[i]] == roman['X'] && (roman[s[i+1]] == roman['D']
                                                        || roman[s[i+1]] == roman['M']
                                                        )
                    )
                ) {
                cout << "romeniskas skaicius neegzistuoja" << endl;
                return -1;
            }
            // atliekamas skaiciavimas atimant
            suma -= roman[s[i]];
        } else {
            // atliekamas skaiciavimas pridedant
            suma += roman[s[i]];
        }
    }

    cout << "suma = " << suma << endl;

    return suma;
}

int main() {
    string str;
//    skirta testuoti programa
//    string str_tests[7] = {
//            "IV",
//            "VI",
//            "VX",
//            "X",
//            "II",
//            "K",
//            "IL",
//    };
//    for (int i = 0; i < sizeof(str_tests)/sizeof(str_tests[0]); i++) {
//        romanToArab(str_tests[i]);
//    }

// skirta ivesti vartotojui
    cout << "Programa pakeičia romėnišką skaičių į arabišką." << endl;
    cout << "Įveskite romėnišką skaičių:" << endl;
    cin >> str;
    romanToArab(str);

    return 0;
}
