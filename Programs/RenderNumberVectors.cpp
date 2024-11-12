#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& numbers) {
    string output = "";
    if (numbers.size() == 0)
      return output;

    for (int element : numbers)
        output += to_string(element) + " ";

    output.pop_back();

  return output;
}
