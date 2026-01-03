#ifndef READ_CSV_FILE
#define READ_CSV_FILE

#include<string>
#include<vector>

class FindModelsFit {
    public:
        static void modelsThatFit(int availableMemoryInGB);
    private:
        static std::vector<std::string> stringToCSV(const std::string& line);
};

#endif