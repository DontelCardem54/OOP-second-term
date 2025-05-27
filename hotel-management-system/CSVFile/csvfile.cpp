#include "TVector.h"
#include "csvfile.h"
#include <fstream>
#include <sstream>


CSVFile::CSVFile(const std::string& path) : _file_path(path), _columns_count(0), _sep(',') {
    calculate_columns_count();
}

std::string CSVFile::get_value(const std::string& id, int column_index) {
    TVector<std::string> line_values;
    std::ifstream input_file(_file_path);

    if (column_index > _columns_count - 1 || column_index <= 0) {
        throw std::runtime_error("Column with need index not found");
    }

    if (!input_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    std::getline(input_file, line);

    while (std::getline(input_file, line)) {
        std::istringstream iss(line);

        for (int i = 0; i < _columns_count; i++) {
            std::string value;
            std::getline(iss, value, _sep);
            line_values.push_back(value);
        }

        if (line_values[0] == id) {
            return line_values[column_index];
        }
    }

    throw std::runtime_error("Row with need id not found");
}

void CSVFile::set_value(const std::string& id, int column_index, const std::string& new_value) {
    TVector<std::string> lines;
    TVector<std::string> line_values;
    std::ifstream input_file(_file_path);

    if (column_index > _columns_count - 1 || column_index <= 0) {
        throw std::runtime_error("Column with need index not found");
    }

    if (!input_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    std::getline(input_file, line);
    lines.push_back(line);
    bool found = false;

    while (std::getline(input_file, line)) {
        std::istringstream iss(line);

        for (int i = 0; i < _columns_count; i++) {
            std::string value;
            std::getline(iss, value, _sep);
            line_values.push_back(value);
        }

        if (line_values.size() != _columns_count) {
            throw std::runtime_error("Invalid CSV format in line");
        }

        if (line_values[0] == id) {
            std::ostringstream oss;

            for (int i = 0; i < _columns_count - 1; i++) {
                if (i == column_index) {
                    oss << new_value << _sep;
                }
                else {
                    oss << line_values[i] << _sep;
                }
            }

            if (_columns_count - 1 == column_index) {
                oss << new_value;
            }
            else {
                oss << line_values[_columns_count - 1];
            }

            lines.push_back(oss.str());
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Row with need id not found");
    }

    std::ofstream output_file(_file_path);

    if (!output_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for writing");
    }

    for (const auto& l : lines) {
        output_file << l << "\n";
    }
}

void CSVFile::remove(const std::string& id) {
    TVector<std::string> lines;
    std::ifstream input_file(_file_path);

    if (!input_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(input_file, line)) {
        std::istringstream ss(line);
        std::string current_id;

        std::getline(ss, current_id, ',');
        if (current_id == id) {
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Row with need id not found");
    }

    std::ofstream output_file(_file_path);
    if (!output_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for writing");
    }

    for (const auto& l : lines) {
        output_file << l << "\n";
    }
}

void CSVFile::calculate_columns_count() {
    std::ifstream input_file(_file_path);

    if (!input_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    std::getline(input_file, line);
    std::stringstream ss(line);
    std::string value;
    size_t count = 0;

    while (std::getline(ss, value, _sep)) {
        count++;
    }

    _columns_count = count;
}
