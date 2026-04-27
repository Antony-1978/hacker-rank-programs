#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map<string, string> hrml_data;
    vector<string> tag_stack;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            // Closing tag: remove last tag from hierarchy
            tag_stack.pop_back();
        } else {
            // Opening tag: remove brackets and parse
            line = line.substr(1, line.length() - 2);
            stringstream ss(line);
            string tag_name, attr_name, eq, attr_val;

            ss >> tag_name;
            tag_stack.push_back(tag_name);

            // Construct current path
            string current_path = "";
            for (int j = 0; j < tag_stack.size(); ++j) {
                current_path += (j == 0 ? "" : ".") + tag_stack[j];
            }

            // Parse attributes: attr_name = "value"
            while (ss >> attr_name >> eq >> attr_val) {
                // Strip quotes from value
                if (attr_val.back() == '>') attr_val.pop_back(); // Handle edge cases
                string clean_val = attr_val.substr(1, attr_val.find_last_of('"') - 1);
                hrml_data[current_path + "~" + attr_name] = clean_val;
            }
        }
    }

    // Process Queries
    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);
        if (hrml_data.count(query)) {
            cout << hrml_data[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
