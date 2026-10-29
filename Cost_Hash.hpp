#include <string>
#include <unordered_map>
#include <ranges>
#include <algorithm>
#include <random>
#include <stdexcept>
 
class Hash 
{
    private:
        std::string Data = "";
        std::unordered_map<char,std::string> set;
        std::string al = "qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-= ABCDEFGHIJKLMNOPQRSTUVWXYZ><{}`~|";
        int getRandInt(int min,int max) 
        {   
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(min,max);
            return distr(gen);
        }
    public:
       
        void data(const std::string& data) 
        {
            this->Data = data;
        }

        void seed() 
        {
            std::ranges::for_each(al,[&](char c)
            {   
                std::string hash_code = "";
                for (int i = 0;i < 3;++i)
                {
                    hash_code.push_back(al[getRandInt(0,al.size()-1)]);
                }      
                set[c] = hash_code;    
            });
        }

        std::string hash()
        {   
            std::string result = "";
            std::ranges::for_each(Data,[&](char c)
            {
                auto it = set.find(c);

                if (it == set.end()) return;
                
                result.append(it->second);
            });

            return result;
        }
        std::string rehash(const std::string& hashString)
        {   
            std::string temp = "";
            std::string result = "";
            std::ranges::for_each(hashString,[&](char c)
            { 
                temp.push_back(c);
                if (temp.length() == 3) 
                {

                    auto it = std::find_if(set.begin(), set.end(),
                        [&](const auto& pair) 
                        {
                            return pair.second == temp;
                        });
                    
                    if (it == set.end()) throw std::runtime_error("Char not found");

                    result.push_back(it->first);

                    temp.clear();
                }
    
               
        
            });
            return result;
        }
};