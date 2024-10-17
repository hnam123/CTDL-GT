#include <bits/stdc++.h>
#include<string.h>
using namespace std;
class Solution {
  public:
    bool pallan(int n) {
    	int i = 0, j = 0, sum = 0, d = 0, flag = 0;

        char str[10]; // Array to store individual digits of the number

        char s[80]; // Array to store the characters formed by adding the individual
                    // digits

        while (n > 0) {
            int r = n % 10;
            n = n / 10;
            str[i++] = 'a' + r - 0;
            // Converting digits to characters and adding them to the array
            sum += r;
            // Calculating the sum of all digits
            d++;
        }
        str[i] = '\0';
        // Adding null character at the end of the array

        // Swapping characters to reverse the order of the array
        i = 0;
        j = d - 1;
        while (i < j) {
            char t = str[i];
            str[i] = str[j];
            str[j] = t;
            i++;
            j--;
        }

        // Forming a string by repeating the characters based on the sum of digits
        for (int j = 0; j < sum; j++)
            s[j] = str[j % d];

        i = 0;
        j = sum - 1;

        // Checking if the string formed is a pallan string by comparing characters from
        // both ends
        while (i < j) {
            if (s[i] != s[j]) {
                flag = 1;
                break;
            }
            i++;
            j--;
        }

        // Returning true if the string is a pallan string, else returning false
        if (flag == 0)
            return true;
        else
            return false;
    }
    
};
int main()
{
		int n;
		cin >> n;
		Solution ob;
		if(ob.pallan(n)){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
    return 0;
}

