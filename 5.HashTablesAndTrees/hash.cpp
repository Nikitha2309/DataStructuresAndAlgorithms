#include<iostream>
using namespace std;

struct Pair {
    string key;
    string val;

    Pair(string k, string v): key(k), val(v) {}
};

class Hashtable {
    Pair* buckets[26];
public:
    Hashtable() {
        for(int i=0; i<26; i++)     
			buckets[i] = NULL;
    }

    int hash_function(string key) {
        return (tolower(key[0]) - 'a');
    }

    void insert(string key, string val) {
        int hash = hash_function(key);
        for(int i=0; i<26; i++) {
            int ind = (hash + i)%26;
            if(buckets[ind] == NULL) {
                buckets[ind] = new Pair(key, val);
                return;
            }
        }
        cout << "Table Full\n";
    }

    void remove(string key) {
        int hash = hash_function(key);
        for(int i=0; i<26; i++) {
            int ind = (hash + i)%26;
            if(buckets[ind] == NULL) {
                cout << "Key Not Found\n";
                return;
            }
            else if(buckets[ind]->key == key) {
                Pair* temp = buckets[ind];
                buckets[ind] = NULL;
                delete(temp);
                return;
            }
        }
        cout << "Key Not Found\n";
    }

    string get(string key) {
        int hash = hash_function(key);
        for(int i=0; i<26; i++) {
            int ind = (hash + i)%26;
            if(buckets[ind] == NULL) {
                return "Key Not Found";
            }
            else if(buckets[ind]->key == key) {
                return buckets[ind]->val;
            }
        }
        return "Key Not Found";
    }
};

int main()
{
    Hashtable niharika = Hashtable();
    niharika.insert("name", "Niharika");
    niharika.insert("roll_num", "190102054");
    niharika.insert("hostel", "Dhansiri");
    niharika.insert("group_num", "7");
    niharika.insert("hobby", "Reading");
    niharika.insert("phone", "9154384500");

    Hashtable neha = Hashtable();
    neha.insert("name", "Neha");
    neha.insert("roll_num", "190102084");
    neha.insert("hostel", "Dhansiri");
    neha.insert("group_num", "7");
    neha.insert("hobby", "Movies");
    neha.insert("phone", "8164564517");
	
	Hashtable preetham = Hashtable();
    preetham.insert("name", "Preetham");
    preetham.insert("roll_num", "190108045");
    preetham.insert("hostel", "Kapili");
    preetham.insert("group_num", "7");
    preetham.insert("hobby", "Fun");
    preetham.insert("phone", "8328434698");

    cout << niharika.get("phone") << endl; // print phone
    cout << niharika.get("hobby") << endl; // print hobby
    niharika.remove("hobby");              // remove hobby
    cout << niharika.get("hobby") << endl; // try to print hobby
	cout << preetham.get("phone") << endl;
    return 0;
}