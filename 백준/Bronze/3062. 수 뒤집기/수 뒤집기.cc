#include <iostream>
#include <string>
#include <algorithm>


int main()
{
    int N;
   
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string str;
        
        

        std::cin >> str;

        int index = str.length();
        
        std::string strev(str);
        std::reverse(strev.begin(), strev.end());

        int result = (std::stoi(str)+ std::stoi(strev));

        std::string check = std::to_string(result);

        index = check.length();

        int yesorno = 0;

        for (int i = 0; i < (index / 2); ++i) {
            if (check[i] != check[index - i - 1]) {
                yesorno++;

            }
        }

        if (yesorno == 0) printf("YES\n");
        else printf("NO\n");

     



    }

}