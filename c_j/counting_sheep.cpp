#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int count_sheep(int N) {
    vector <bool> found(10, false);
    int last = 0;
    if (N != 0) {
	    bool find_a = false;
	    while (!find_a) {
	        int next = last = last + N;
	        while (next) {
	            found[next % 10] = true;
	            next /= 10;
	        }
	        find_a = true;
	        for (int i = 0; i < 10; ++i) {
	            if (found[i] == false) {
	                find_a = false;
	                break;
	            }
	        }
	    }
	}    
    return last;
}

int main() {
	fstream myfile("A-large-practice.txt", ios_base :: in);
	
	ofstream f;
    f.open("out.txt");
    int a, b = 0, i;
	while (myfile >> a) {
		if (b == 0) {
			b = 1;
			i = 0;
        	continue;
        } else {
        	int ans = count_sheep(a);
        	if (ans == 0) {
            	f << "Case #" << ++i << ": " << "INSOMNIA\n";
	        } else {
	        	f << "Case #" << ++i << ": " << ans << endl;
	        }	
        }

    }
    return 0;
}