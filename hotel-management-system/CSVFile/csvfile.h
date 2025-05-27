#pragma once
#include <string>

class CSVFile {
private:
    const std::string _file_path;
    int _columns_count;
    char _sep;
public:
    CSVFile(const std::string&);

    std::string get_value(const std::string& id, int column_index);
    void set_value(const std::string& id, int column_index, const std::string& new_value);
    void remove(const std::string& id);

private:
    void calculate_columns_count();
};