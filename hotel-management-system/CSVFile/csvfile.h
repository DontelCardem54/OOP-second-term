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
    std::string get_value_by_column(int compare_column_index, const std::string& compare_value, int value_column_index);
    std::string get_row(const std::string& id);
    void set_value(const std::string& id, int column_index, const std::string& new_value);
    void remove(const std::string& id);
    void clear();
    bool has_row(const std::string& id);
    void add_row(const std::string& row);

private:
    void calculate_columns_count();
};